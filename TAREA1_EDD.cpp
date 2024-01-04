/*ANA ISABEL LOERA GIL
JOSHUA ALEXANDER AGUIRRE MIRANDA
JULIO CESAR TORRES MARQUEZ*/
#include<iostream>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define maxchar 50
using namespace std;
int matricula=999,n=0;//declaracion de variable global n (numero de estudiantes)
float suma=0;
struct Alumno{
    char nombre[maxchar];
    int matricula;
    float promedio,anio_escolar;
    struct Alumno*sig;
};
typedef struct  Alumno *Alista;
void menu()
{
   system("cls");
   cout<<"                    MENU PRINCIPAL\n\n";
   cout<<"   1. ALTA DE DATOS"<<endl;
   cout<<"   2. REPORTES"<<endl;
   cout<<"   3. BUSQUEDA DE ESTUDIANTES"<<endl;
   cout<<"   4. BAJA DE ESTUDIANTES"<<endl;
   cout<<"   5. SALIR "<<endl;
}
void menuR()//sub menu de los reportes
{
   system("cls");
   cout<<"         REPORTES "<<endl;
   cout<<"   1. CALCULO DE PROMEDIO GENERAL DEL PLANTEL "<<endl;
   cout<<"   2. CALCULO DE PROMEDIO GENERAL DEL AÃ‘O ESCOLAR "<<endl;
   cout<<"   3. LISTADO DE ESTUDIANTES TALENTO  "<<endl;
   cout<<"   4. LISTADO DE TODOS LOS ALUMNOS  "<<endl;
   cout<<"   5. SALIR "<<endl;
}
void menuB()// Sub menu busqueda 
{
	  system("cls");
   cout<<"         BUSQUEDA "<<endl;
   cout<<"   1. POR MATRICULA "<<endl;
   cout<<"   2. POR NOMBRE "<<endl;
   cout<<"   3. SALIR "<<endl;
}
int mat()
{
   
   matricula++;
   return matricula;
   
}
void alta(Alista &lista)
{
    Alista p,q=new (struct Alumno);
     q->promedio=-1;
	 cout<<"CAPTURE LOS SIGUIENTES DATOS\n";
	 cin.ignore(); cout<<"NOMBRE: ";
    cin.getline(q->nombre,maxchar); 
    while(q->anio_escolar<1||q->anio_escolar>3||q->anio_escolar-trunc(q->anio_escolar)!=0)//valida que el aÃ±o escolar no sea menor a 1 ni mayor a 3 y ademas que no sea decimal
    {
           cout<<"ANIO ESCOLAR: ";
           cin>>q->anio_escolar;
    }
    q->matricula=mat();//llama a la funcion matricula para asignarle una al alumno
    while(q->promedio<0 ||q->promedio>100)//valida que el promedio no sea negativo ni mayor a 90
    {
         cout<<"PROMEDIO: ";
         cin>>q->promedio;
    }
    system("cls");
    q->sig = NULL; // Inicializa el puntero siguiente a NULL
    if(lista==NULL)
    {
        lista = q;// Si la lista estÃ¡ vacÃ­a, asigna q como el primer elemento
    }
    else
    {
        p = lista;
   
     while(p->sig!=NULL)
     {
        p = p->sig; // Avanza al siguiente nodo
     }
        p->sig = q;// Agrega q al final de la lista
    }
        cout<<"AGREGADO CORRECTAMENTE"<<endl<<"MATRICULA: "<<q->matricula<<endl;
        n++;
        suma+=q->promedio;//se van sumando los promedios de todos los alumnos 
         
}
void busqueda_nombre(Alista lista,char dato[maxchar])
{

   int bandera=0,i=1;
	Alista q=lista;//q apunta a lista
	while(q!=NULL)
	{
		if(strcmp(q->nombre,dato)==0)//compara si algun nombre en la lista es igual al ingresado
		 {
			cout<<"Nombre: "<<q->nombre<<endl<<"Promedio: "<<q->promedio<<endl<<"Anio Escolar: "<<q->anio_escolar<<endl;// se imprimen los datos (Nombre,Promedio,AÃ±o Escolar)
         bandera=1;
		 }
       q=q->sig;
       i++;
	}
   if(bandera==0)
   {
      cout<<"REGISTRO NO ENCONTRADO"<<endl;
   }
}
void busqueda_matricula(Alista lista,int mat)
{
   int bandera=0,i=1;
   Alista q=lista;
   while(q!=NULL)
   {
      if(q->matricula==mat)
      {
         cout<<"Matricula: "<<q->matricula<<endl<<"Promedio: "<<q->promedio<<endl<<"Anio Escolar: "<<q->anio_escolar<<endl;// se imprimen los datos (Nombre,Promedio,AÃ±o Escolar)
         bandera=1;
      }
      q=q->sig;
      i++;
   }
   if(bandera==0)
   {
      cout<<"REGISTRO NO ENCONTRADO"<<endl;
   }

}
void listado(Alista lista)
{
   int i=1;
   Alista q=lista;
   while (q!=NULL)
   {
      cout<<"Matricula: "<<q->matricula<<", Nombre: "<<q->nombre<<", Promedio: "<<q->promedio<<", Anio Escolar: "<<q->anio_escolar<<endl;// se imprimen los datos (Nombre,Promedio,AÃ±o Escolar)
      q=q->sig;
      i++;
   }
   if(lista==NULL)
   {
      cout<<"NO HAY ESTUDIANTES REGISTRADOS"<<endl;
   }
}
double promedio_plantel(Alista lista)
{
	 double suma = 0.0; // Variable para almacenar la suma de los promedios.
    int contador = 0; // Variable para contar la cantidad de estudiantes.
    
     // Recorre la lista de estudiantes mientras haya nodos válidos.
    while (lista) {
        suma += lista->promedio; // Agrega el promedio del estudiante a la suma.
        contador++;              // Incrementa el contador de estudiantes.
        lista = lista->sig;       // Avanza al siguiente estudiante en la lista.
    }
    
    // Calcula el promedio general dividiendo la suma por la cantidad de estudiantes.
    // Devuelve 0.0 si no hay estudiantes en la lista para evitar divisiones por cero.
    return contador > 0 ? suma / contador : 0.0;
}

double promedio_anioEscolar(Alista lista, int anio)
{
	double suma = 0.0;
    int contador = 0;
    bool alumnosEnAnio = false; // Variable para verificar si hay alumnos en el año especificado.

    // Valida que el año escolar esté en el rango (1-3) antes de realizar el cálculo.
    if (anio >= 1 && anio <= 3) {
        while (lista) {
            // Verifica si el año escolar del estudiante coincide con el año especificado.
            if (static_cast<int>(lista->anio_escolar) == anio) {
                suma += lista->promedio;
                contador++;
                alumnosEnAnio = true; // Al menos un alumno encontrado en el año especificado.
            }
            lista = lista->sig;
        }

        if (!alumnosEnAnio) {
            cout << "No hay alumnos dados de alta en el año escolar " << anio << "." << endl;
            return 0.0; // No hay alumnos en el año especificado, se devuelve 0.0 como promedio.
        }
    } else {
        cout << "Año escolar no válido. Debe estar en el rango (1-3)." << endl;
        return 0.0; // Año escolar no válido, se devuelve 0.0 como promedio.
    }

    // Calcula el promedio del año escolar especificado.
    return suma / contador;
}

void talentos(Alista lista)
{
	cout << "Estudiantes talento (promedio >= 95):\n";

    // Recorre la lista de estudiantes.
    while (lista) {
        // Verifica si el promedio del estudiante es mayor o igual a 95.
        if (lista->promedio >= 95) {
            // Muestra la matrícula, nombre y promedio del estudiante talentoso.
            cout << "Matricula: " << lista->matricula << ", Nombre: " << lista->nombre << ", Promedio: " << lista->promedio << endl;
        }

        // Avanza al siguiente estudiante en la lista.
        lista = lista->sig;
    }
}
void baja(Alista &lista)
{
   int matricula;
    cout << "Ingrese la matricula del estudiante a dar de baja: ";
    cin >> matricula;

    Alista p = lista;
    Alista anterior = NULL;

    // Buscar al estudiante en la lista
    while (p != NULL && p->matricula != matricula)
    {
        anterior = p;
        p = p->sig;
    }

    if (p == NULL)
    {
        cout << "Estudiante no encontrado. No se realizo ninguna baja." << endl;
        return;
    }

    // Caso 1: El estudiante a eliminar es el primer elemento
    if (anterior == NULL)
    {
        lista = p->sig;
        delete p;
    }
    // Caso 2: El estudiante a eliminar está en el medio o al final de la lista
    else
    {
        anterior->sig = p->sig;
        delete p;
    }

    cout << "Estudiante dado de baja exitosamente." << endl;

}
main()
{

	Alista lista= NULL;
    float opcion,opc;
    int op,r=0;
    do
    {
        opcion=6;
       while(opcion<1 ||opcion>5 ||opcion-trunc(opcion)!=0)
    {
       menu();
       cout<<"   Opcion: ";
       cin>>opcion;

    };
    op=floor(opcion);
    system("cls");
       switch(op)
    {
        case 1:
        cout<<"         ALTA DE DATOS "<<endl;
        alta(lista);
        break;
        case 2://REPORTES
        do
        {
          opc=6;
       while(opc<1 ||opc>5 ||opc-trunc(opc)!=0)
         {
            menuR();
            cout<<"   Opcion: ";
            cin>>opc;
         };
         op=floor(opc);
         system("cls");
        switch(op)
        {
             case 1:
             cout << "PROMEDIO GENERAL DEL PLANTEL: " << promedio_plantel(lista) << endl;
             break;
             
             case 2:
            	int anio;
                cout << "Ingrese el año escolar (1-3): ";
                cin >> anio;
                cout << "PROMEDIO GENERAL DEL ANIO ESCOLAR " << anio << ": " << promedio_anioEscolar(lista, anio) << endl;
             break;
             
             case 3:
             cout<<"   ESTUDIANTES TALENTO"<<endl;
             talentos(lista);
             break;
             
             case 4:
             cout<<"   LISTADO DE TODOS LOS ALUMNOS"<<endl<<endl;
             listado(lista);
             break;
            
        }
        
          system("PAUSE");
        } while (op!=5); 
        break;
         case 3://BUSQUEDA
        cout<<"         BUSQUEDA DE ESTUDIANTES"<<endl;
        do
        {
          opcion=6;
       while(opcion<1 ||opcion>3 ||opcion-trunc(opcion)!=0)
         {
            menuB();
            cout<<"   Opcion: ";
            cin>>opcion;
         };
         op=floor(opcion);
         system("cls");
        switch(op)
        {
           case 1:
             int mat;
             cout<<"   BUSQUEDA POR MATRICULA"<<endl;
             cout<<"Ingrese la matricula del estudiante: ";
             cin>>mat;
             busqueda_matricula(lista,mat);
             break;
             char nom[maxchar];
             case 2:
             cout<<"   BUSQUEDA POR NOMBRE"<<endl;
             cin.ignore();cout<<"Ingrese el nombre el estudiante: ";
             cin.getline(nom,maxchar);
             busqueda_nombre(lista,nom);
             break;    
        }
          system("PAUSE");
        } while (op!=3);
        break;
        case 4:
        cout<<"         BAJA DE ESTUDIANTES"<<endl;
        baja(lista);
        break;
        case 5:
        cout<<"Usted ha salido del programa :D"<<endl;
        exit(-1);
        break;
      

    }
       system("PAUSE");
    }while(opcion!=5);
    
}
