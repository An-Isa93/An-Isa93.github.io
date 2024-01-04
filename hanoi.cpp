/*ANA ISABEL LOERA GIL
JULIO CESAR TORRES MARQUEZ
JOSHUA ALEXANDER AGUIRRE MIRANDA*/
#include<iostream>
#include<math.h>
int m=1;//cuenta el numero de movientos en la funcion hanoi
using namespace std;
void hanoi(int n,char origen,char destino,char aux)
{
   if(n==1)
   {
      cout << m<<". Mueve el disco "<<n<<" de " << origen<< " a " << destino << endl ;
      m++;
   }
   else 
   {
       hanoi ( n - 1 , origen , aux , destino);// mueve el disco n-1 de la varilla origen a la varilla aux, utilizando destino como varilla auxiliar.
       cout <<m<< ". Mueve el disco " <<n<<" de "<< origen<< " a " << destino << endl ;
       m++;
       hanoi ( n - 1 , aux, destino , origen );//mueve el disco n-1  desde la varilla aux a la varilla destino, utilizando origen como varilla auxiliar.
   }
}
int main()
{
   int discos=12,movimientos=0;
   char origen='D',destino='E',aux;
   while(discos<1 || discos>10)
   {
       cout<<"Ingrese la cantidad de discos (1-10): ";
       cin>>discos;
   }
   while(origen!='A' && origen!='B' && origen!='C')
   {
       cout<<"Ingrese su torre de origen (A-C): ";
       cin>>origen;
   }
    while(destino!='A' && destino!='B' && destino!='C')
   {
       cout<<"Ingrese su torre de destino (A-C): ";
       cin>>destino;
   }
   if((origen=='A' && destino=='B')|| (origen=='B' && destino=='A'))
   {
      aux='C';
   }
   else if((origen=='A' && destino=='C') ||(origen=='C' && destino=='A'))
   {
       aux='B';
   }
   else
   {
       aux='A';
   }
   movimientos=(pow(2,discos))-1;//calcula el numeros de movimientos necesarios
   cout<<endl;
   hanoi(discos,origen,destino,aux);
   cout<<"Se necesitan "<<movimientos<<" movimientos";
   return 0;
}
