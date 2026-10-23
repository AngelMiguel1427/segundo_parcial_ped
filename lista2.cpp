
/*Ejercicio 1.2. Intercambiar nodos adyacentes

Implemente la función:
SwapAdjacentPairs

La función debe intercambiar físicamente los nodos adyacentes de dos en dos, comenzando desde el principio de la lista. No debe intercambiar únicamente sus valores.

Requisitos:

1. Reasigne los enlaces de los nodos para realizar los intercambios.
2. Actualice `head` cuando corresponda.
3. Mantenga correctamente los enlaces `next` y `prev`.
4. Si existe un número impar de nodos, el último debe permanecer en su posición.
5. No cree ni elimine nodos, y no modifique los valores almacenados.*/
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

struct Node {
  int data;
  Node* next;
  Node* prev;
};

void SwapAdjacentPairs(Node*& head) {
  Node* current = head;

    // intercambiar nodos adyacentes
  while (current != nullptr && current->next != nullptr) {
    Node* first = current;
    Node* second = current->next;
    Node* previous = first->prev;
    Node* next = second->next;

    second->prev = previous;
    second->next = first;
    first->prev = second;
    first->next = next;

    // ajustar los enlaces de los nodos adyacentes
    if (previous != nullptr) {
      previous->next = second;
    } else {
      head = second;
    }

    if (next != nullptr) {
      next->prev = first;
    }

    current = next;
  }
}

int main() {
  Node* head = nullptr;
  const int values[] = {10, 20, 30, 40};
  Node* tail = nullptr;

    // crear la lista doblemente enlazada
  for (int value : values) {
    Node* node = new Node{value, nullptr, tail};
    if (tail != nullptr) {
      tail->next = node;
    } else {
      head = node;
    }
    tail = node;
  }

  SwapAdjacentPairs(head);
 
  // imprimimops la lista despues de intercambiar nodos adyacentes
  for (Node* current = head; current != nullptr; current = current->next) {
    if (current != head) {
      std::cout << " <-> ";
    }
    std::cout << current->data;
  }
  std::cout << "" << std::endl ;

  while (head != nullptr) {
    Node* next = head->next;
    delete head;
    head = next;
  }

  return 0;
}
