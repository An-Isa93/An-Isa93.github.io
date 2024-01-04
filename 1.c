#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int n, opcion, posicion, elemento, i;

    printf("Ingrese la cantidad de elementos del arreglo (1-100): ");
    scanf("%d", &n);

    // Leer los elementos del arreglo
    for (i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &arr[i]);
        size++;
    }

    do {
        // Mostrar el contenido actual del arreglo
        printf("\nContenido actual del arreglo:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Mostrar el menú de opciones
        printf("\nElija una opcion:\n");
        printf("1. Ingresar un nuevo elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Ingresar un nuevo elemento en una posición específica
                printf("\nIngrese la posicion donde desea insertar el nuevo elemento (1-%d): ", size+1);
                scanf("%d", &posicion);
                if (posicion < 1 || posicion > size+1) {
                    printf("Error: la posicion debe estar entre 1 y %d\n", size+1);
                } else if (size == MAX_SIZE) {
                    printf("Error: el arreglo esta lleno\n");
                } else {
                    printf("Ingrese el valor del nuevo elemento: ");
                    scanf("%d", &elemento);
                    // Desplazar los elementos hacia la derecha para hacer espacio para el nuevo elemento
                    for (i = size-1; i >= posicion-1; i--) {
                        arr[i+1] = arr[i];
                    }
                    arr[posicion-1] = elemento;
                    size++;
                    printf("Elemento ingresado correctamente\n");
                }
                break;
            case 2:
                // Eliminar un elemento en una posición específica
                printf("\nIngrese la posicion del elemento que desea eliminar (1-%d): ", size);
                scanf("%d", &posicion);
                if (posicion < 1 || posicion > size) {
                    printf("Error: la posicion debe estar entre 1 y %d\n", size);
                } else {
                    // Desplazar los elementos hacia la izquierda para llenar el espacio vacío
                    for (i = posicion-1; i < size-1; i++) {
                        arr[i] = arr[i+1];
                    }
                    size--;
                    printf("Elemento eliminado correctamente\n");
                }
                break;
            case 3:
                // Salir del programa
                printf("\n");
        }
    }while (opcion!=3);
  
}

