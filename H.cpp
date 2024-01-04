#include <iostream>
#include <cmath>

using namespace std; // Utilizamos namespace std para simplificar el código

// Función para determinar en cuál de las tres posiciones se encuentra un disco en un movimiento dado
char posicionDelDisco(int n, int movimiento) {
    for (int p = 1; p <= n; p++) {
        int primerMovimiento = pow(2, p - 1);
        int ultimoMovimiento = pow(2, n) - pow(2, p - 1);

        // Verificar si el movimiento se encuentra en el rango del disco p-ésimo
        if (movimiento >= primerMovimiento && movimiento <= ultimoMovimiento) {
            int ciclo = movimiento - primerMovimiento;
            int posicionDeseada;

            int diferencia_np = n - p;
            if (diferencia_np % 2 == 0) {
                // Comportamiento cíclico: Una vez dos posiciones a la derecha y dos veces una posición a la izquierda.
                posicionDeseada = (ciclo % (2 * (int)pow(2, p))) - (int)pow(2, p - 1);
            } else {
                // Comportamiento cíclico: Dos veces una posición a la derecha y una vez dos posiciones a la izquierda.
                posicionDeseada = (ciclo % (2 * (int)pow(2, p))) < (int)pow(2, p - 1) ? (ciclo % (2 * (int)pow(2, p))) : (2 * (int)pow(2, p) - (ciclo % (2 * (int)pow(2, p))) - (int)pow(2, p - 1));
            }

            // Determinar la posición actual basada en la diferencia entre el ciclo y la posición deseada
            char posicionActual = (posicionDeseada == 0) ? 'A' : ((posicionDeseada == 1) ? 'B' : 'C');
            return posicionActual; // Devuelve la posición actual del disco en movimiento
        }
    }
    return '\0'; // En caso de que no se encuentre ningún disco en movimiento
}

int main() {
    int n = 5; // Número total de discos
    int movimiento = 12; // Número de movimiento que deseas verificar

    char posicion = posicionDelDisco(n, movimiento);

    if (posicion != '\0') {
        cout << "El disco en movimiento en el movimiento " << movimiento << " se encuentra en la posición " << posicion << "." << endl;
    } else {
        cout << "No se encuentra ningún disco en movimiento en el movimiento " << movimiento << "." << endl;
    }

    return 0;
}
