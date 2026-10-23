/* Ejercicio 3.1. Ordenamiento por paridad

Se proporciona una implementación de ordenamiento por inserción que organiza un arreglo de menor a mayor:

Modifique el algoritmo para que el arreglo cumpla estas condiciones:

1. Todos los números pares deben aparecer antes que los impares.
2. Los números pares deben quedar ordenados de menor a mayor.
3. Los números impares también deben quedar ordenados de menor a mayor.
4. Debe utilizar el algoritmo de ordenamiento por inserción como base.

Ejemplo:

Entrada:

8 5 2 7 4 1 6

Salida esperada:

2 4 6 8 1 5 7

No se permite resolverlo llamando a otro algoritmo de ordenamiento.*/
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
    
            // Movemos los elementos según la paridad y el valor.
            while (j >= 0 && ((arr[j] % 2 == 0 && arr[j] > key) || (arr[j] % 2 != 0 && key % 2 == 0))) {
                arr[j + 1] = arr[j];
                j--;
            }
    
            arr[j + 1] = key;
        }  
}

int main() {
    int arr[] = {8, 5, 2, 7, 4, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    // imprimos el arreglo ordenado
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}