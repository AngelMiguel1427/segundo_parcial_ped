/* Ejercicio 2.1. Eliminar elementos consecutivos repetidos de una pila

Una pila contiene números enteros. Implemente una función que elimine los elementos repetidos que aparecen consecutivamente al leer la pila desde el tope hacia el fondo. De cada grupo de valores consecutivos iguales, debe conservarse solamente uno.

Ejemplo:

Pila inicial, desde el tope hacia el fondo:

5 5 5 8 8 3 7 7 2 2

Pila resultante, desde el tope hacia el fondo:

5 8 3 7 2

Otro ejemplo:

Pila inicial:    4 4 6 4 4 9
Pila resultante: 4 6 4 9

Requisitos:

1. Utilice las operaciones de `std::stack`, como `top`, `pop` y `push`.
2. No utilice arreglos ni vectores.
3. Los valores iguales que no sean consecutivos deben conservarse como elementos separados.
4. Puede utilizar pilas auxiliares.*/
/////////////////////////////////////////////////////////////////////////////////////////////

#include <stack>
#include <iostream>

void RemoveConsecutiveDuplicates(std::stack<int>& values) {
  std::stack<int> aux;
  int last = 0;
  bool first = true;

  while (!values.empty()) {
    int current = values.top();
    values.pop();
    // si el primer elemento diferente del último agregado lo agregamos a la pila auxiliar
    if (first || current != last) {
      aux.push(current);
      last = current;
      first = false;
    }
  }

  // transferimos los elementos de la pila auxiliar de vuelta a la pila original
  while (!aux.empty()) {
    values.push(aux.top());
    aux.pop();
  }
}

int main() {
  std::stack<int> values;

  // pila inicial
  values.push(5);
  values.push(5);
  values.push(5);
  values.push(8);
  values.push(8);
  values.push(3);
  values.push(7);
  values.push(7);
  values.push(2);
  values.push(2);

  RemoveConsecutiveDuplicates(values);

  std::cout << "Pila resultante, desde el tope hacia el fondo:" << std::endl;
  // imprimimos la pila resultante
  while (!values.empty()) {
    std::cout << values.top() << " ";
    values.pop();
  }
  std::cout << std::endl;

  return 0;
}   