/* Ejercicio 3.2. Búsqueda binaria del mayor elemento menor que el objetivo

Se tiene un arreglo ordenado de menor a mayor:


int values[] = {2, 4, 4, 7, 9, 12, 15};


Modifique una implementación de búsqueda binaria para que devuelva el índice del mayor elemento estrictamente menor que `target`.

Si no existe un elemento menor que `target`, debe devolver `-1`.

Requisitos:

- Debe conservar la búsqueda binaria.
- Debe funcionar aunque existan valores repetidos.
- No debe utilizar un recorrido secuencial del arreglo.*/
///////////////////////////////////////////////////////////////


#include <iostream>
int FindLargestSmaller(
    const int values[],
    int n,
    int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    // busqueda binaria para encontrar el mayor elemento menor que target
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (values[mid] < target) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result;
}

int main() {
  int values[] = {2, 4, 4, 7, 9, 12, 15};
  int n = sizeof(values) / sizeof(values[0]);

// probamos la función con diferentes valores de target
  int targets[] = {6, 4, 2, 20};
  for (int target : targets) {
    int index = FindLargestSmaller(values, n, target);
    std::cout << "Target: " << target << ", Index: " << index << std::endl;
  }

  return 0;
}