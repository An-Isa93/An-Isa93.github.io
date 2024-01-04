#include <iostream>

using namespace std;

const int MAX_TAMANO_COLA = 5;  // Tamaño máximo de la cola

class Cola {
private:
    int cola[MAX_TAMANO_COLA];
    int frente;  // Puntero al frente de la cola
    int fin;     // Puntero al final de la cola

public:
    Cola() : frente(-1), fin(-1) {}

    // Función para verificar si la cola está vacía
    bool estaVacia() {
        return frente == -1;
    }

    // Función para verificar si la cola está llena
    bool estaLlena() {
        return (fin + 1) % MAX_TAMANO_COLA == frente;
    }

    // Función para encolar un elemento
    void encolar(int elemento) {
        if (estaLlena()) {
            cout << "La cola está llena. No se puede encolar más elementos." << endl;
            return;
        }

        if (estaVacia()) {
            frente = 0;  // Si la cola estaba vacía, ajustar el frente
        }

        fin = (fin + 1) % MAX_TAMANO_COLA;  // Ajustar el puntero al final
        cola[fin] = elemento;
        cout << "Elemento " << elemento << " encolado correctamente." << endl;
    }

    // Función para desencolar un elemento
    void desencolar() {
        if (estaVacia()) {
            cout << "La cola está vacía. No se puede desencolar." << endl;
            return;
        }

        int elementoDesencolado = cola[frente];
        cout << "Elemento " << elementoDesencolado << " desencolado correctamente." << endl;

        if (frente == fin) {
            // Si solo había un elemento, ajustar frente y fin
            frente = fin = -1;
        } else {
            frente = (frente + 1) % MAX_TAMANO_COLA;  // Ajustar el puntero al frente
        }
    }

    // Función para mostrar el contenido de la cola
    void mostrarCola() {
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return;
        }

        cout << "Cola: ";
        int i = frente;
        do {
            cout << cola[i] << " ";
            i = (i + 1) % MAX_TAMANO_COLA;
        } while (i != (fin + 1) % MAX_TAMANO_COLA);

        cout << endl;
    }
};

int main() {
    Cola miCola;

    miCola.encolar(1);
    miCola.encolar(2);
    miCola.encolar(3);
    miCola.encolar(4);
    miCola.encolar(5);

    miCola.mostrarCola();  // Salida esperada: Cola: 1 2 3 4 5

    miCola.encolar(6);  // Intentar encolar más elementos de lo que el arreglo puede contener

    miCola.desencolar();
    miCola.mostrarCola();  // Salida esperada: Cola: 2 3 4 5

    return 0;
}
