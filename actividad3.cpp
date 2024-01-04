//Ana Isabel Loera Gil Matricula: 1960117
/* Diseñe una solución en C++ que permita manipular una lista circular desplegando el siguiente menú: 
A) Inserción de elementos al final de la lista. 
B) Eliminación de elementos al final de la lista.
C) Mostrar la lista
D) Salir
Realice las validaciones necesarias
Almacene un dato entero en el campo de información de los nodos.*/
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>

using namespace std;
struct nodo{
    float dato;
    nodo* sig;
}*primero,*ultimo;//apuntadores al primer y ultimo elemento

void insertar()
{
   nodo* nuevo = new nodo();
   cout<<"Ingrese el dato que contedra el nodo: ";
   cin>>nuevo->dato;//se almacena el dato
   if(primero==NULL)//si el apuntador primero es NULL es una lista vacia
   {
      primero = nuevo;
      primero->sig=primero;//el apuntador de  nodo siguiente de primero que antes apuntaba a NULL ahora apunta a  el mismo
      ultimo = primero;//se posicion el apuntador ultimo en el primero
   }
   else
   {
     ultimo->sig=nuevo;
     nuevo->sig= primero;
     ultimo= nuevo;
   }
   cout<<"NODO INGRESADO"<<endl;
}
void eliminar()
{
    if (primero == NULL) {
      cout << "LISTA VACIA" << endl;
      return;//sale de la funcion si la lista esta vacia 
   }

   if (primero == ultimo) {
      delete primero;//elimina el unico elemento de la lista
      primero = ultimo = NULL;// establece el primero y ultimo como nullptr
      cout << "NODO ELIMINADO" << endl<<"LISTA VACIA"<<endl;
      return;
   }

   nodo* actual = primero;
   while (actual->sig != ultimo) //se mueve el apuntador actual hacia el ultimo nodo
   {
      actual = actual->sig;
   }

   nodo* temp = ultimo;// guarda la referencia del ultimo nodo
   actual->sig = primero;// actualiza el nodo anterior para que apunte al primero
   ultimo = actual; // Actualizar el puntero "ultimo" al nodo anterior

   delete (temp);//elimina el ultimo nodo
   cout <<"ELIMINADO CORRECTAMENTE"<<endl;
}

void listar()
{
    nodo* actual= new nodo();
    actual=primero;
    if(primero!=NULL)
    {
        do
        {
            cout<<" "<<actual->dato;
            actual= actual->sig;//se mueve el apuntador hacia el siguiente nodo
        } while (actual!=primero);
    }
    else
    {
       cout<<"LISTA  VACIA"<<endl<<endl;
      
    }

}
void menu()
{
    system("cls");
    cout<<"      \nMENU\n\n1.Insercion de elementos al final de la lista\n2.Eliminacion de elementos al final de la lista\n3.Mostrar lista\n4.Salir\nOpcion:"<<endl;
}
int main()
{
    float opcion;
    int op;

    do
    {
        menu();
    cin>>opcion;
    while(opcion<1 ||opcion>4 ||opcion-trunc(opcion)!=0)
    {
       menu();
       cin>>opcion;
    };
    op=floor(opcion);
    switch(op)
    {
        case 1:
        cout<<"INSERTAR NUEVO ELEMENTO"<<endl;
        insertar();
        system("pause");
        break;
        case 2:
        cout<<"ELIMINAR ELEMENTOS AL FINAL"<<endl;
        eliminar();
        system("pause");
        break;
        case 3:
        cout<<"DESPLEGAR LISTA"<<endl;
        listar();
        cout<<endl;
        system("pause");
        break;
        case 4:
        cout<<"HA SALIDO DEL PROGRAMA :D";
        exit(-1);
        break;

    }
    } while (opcion!=4);
    
    
    return 0;
}