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
   cout<<"   2. CALCULO DE PROMEDIO GENERAL DEL AÑO ESCOLAR "<<endl;
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
    while(q->anio_escolar<1||q->anio_escolar>3||q->anio_escolar-trunc(q->anio_escolar)!=0)//valida que el año escolar no sea menor a 1 ni mayor a 3 y ademas que no sea decimal
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
        lista = q;// Si la lista está vacía, asigna q como el primer elemento
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
			cout<<"Nombre: "<<q->nombre<<endl<<"Promedio: "<<q->promedio<<endl<<"Anio Escolar: "<<q->anio_escolar<<endl;// se imprimen los datos (Nombre,Promedio,Año Escolar)
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
         cout<<"Matricula: "<<q->matricula<<endl<<"Promedio: "<<q->promedio<<endl<<"Anio Escolar: "<<q->anio_escolar<<endl;// se imprimen los datos (Nombre,Promedio,Año Escolar)
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
      cout<<"Matricula: "<<q->matricula<<endl<<"Nombre: "<<q->nombre<<endl<<"Promedio: "<<q->promedio<<endl<<"Anio Escolar: "<<q->anio_escolar<<endl<<endl;// se imprimen los datos (Nombre,Promedio,Año Escolar)
      q=q->sig;
      i++;
   }
   if(lista==NULL)
   {
      cout<<"NO HAY ESTUDIANTES REGISTRADOS"<<endl;
   }
}
void promedios (Alista lista,int r)
{
   Alista q=lista;
   float a=-1;
   float sum=0,prom=0;
   int i=0,ne=0;
   if(r==1)
   {
      if(lista!=NULL)
       {
        cout<<"Promedio: "<<(suma/n)<<endl;
       }
       else
       {
         cout<<endl<<"NO HAY ESTUDUANTES REGISTRADOS"<<endl;
       }
   }
   else if(r==2)//promedio del año escolar ingresado
   { 
      while(a<1 || a>3)
      {
          cout<<"Ingrese el anio que desee: ";
          cin>>a;
      }

      while(q!=NULL)
      {
        if(q->anio_escolar==a)
        {
           sum+=q->promedio;
           ne++;
        }
         q=q->sig;
         i++;
      }
      prom=sum/ne;
      if(lista==NULL)
      {
          cout<<endl<<"NO HAY ESTUDUANTES REGISTRADOS"<<endl;
      }
      else
      {
          cout<<"Promedio del anio "<<a<<": "<<prom<<endl;
      }
      
   }
   else //r=3 listado de estudiantes talento
   {
      i=0;
      while (q!=NULL)
      {
         if(q->promedio>95)//estudiantes talento
         {
            cout<<"Matricula: "<<q->matricula<<endl<<"Nombre: "<<q->nombre<<endl<<"Promedio: "<<q->promedio<<endl<<endl;
         }
         q=q->sig;
         i++;
      }
   }
  
}

void baja(Alista &lista)
{
   Alista q=lista;
   float respuesta=-1;
 
   while(respuesta!=1 && respuesta!=2)
      {
           cout<<"¿Esta seguro de querer eliminar a todos los estudiantes (1=Si, 2=No): ";
           cin>>respuesta;
      }
      if(respuesta==1)
      {
         while(q!=NULL)
        {
           Alista aux=q;
           q=q->sig;
           delete (aux);
        }
        lista=NULL;
      }
   cout<<"REGISTROS ELIMINADOS CORRECTAMENTE"<<endl;

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
             r=1;
             cout<<"   PROMEDIO GENERAL DEL PLANTEL"<<endl;
             promedios(lista,r);
             break;
             case 2:
             r=2;
             cout<<"   PROMEDIO GENERAL DEL ANIO ESCOLAR"<<endl;
             promedios(lista,r);
             break;
             case 3:
             r=3;
             cout<<"   ESTUDIANTES TALENTO"<<endl;
             promedios(lista,r);
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
