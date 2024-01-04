#include <iostream>
using namespace std;

int factorial(int n){ 
	if (n!=0){
        int c=n;
        
        if(n!=1)
        {
           	cout<<c<<"* ";
           
        }
        else
        {
           cout<<c<<" = ";
        }
		 return n*factorial(n-1);
          c--;
        	
       
	} else {
		return 1;	
	}
}

int main(){
	int n;
	cout << "Ingrese un numero ";
	cin >> n;	
	cout << factorial(n);	
	return 0;
}

