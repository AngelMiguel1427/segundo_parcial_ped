/* Ejercicio 1.1. Invertir una lista doblemente enlazada

Implemente la función:

La función debe invertir el orden de todos los nodos de la lista sin crear ni eliminar nodos y sin modificar los valores almacenados.

Ejemplo:

Antes

10

20

30

40

Después

40

30

20

10

Requisitos:

- Debe modificar correctamente la función de los enlaces `next` y `prev` de cada nodo.
- Debe funcionar con una lista vacía y una lista con un solo nodo.
- El objetivo es invertir la lista, no crear una función que solamente imprima los resultados en sentido inverso.*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
struct Node {
  int data;
  Node* next;
  Node* prev;
};
void ReverseList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;
    
    while (current != nullptr) {
        // intercambiar los punteros
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
    
        //movemos al siguiente nodo que es el anterior
        current = current->prev;
    }
    
    // ajustamos el head de la lista
    if (temp != nullptr) {
        head = temp->prev;
    }
}

int main () {
  Node* head = nullptr;
  const int values[] = {10, 20, 30, 40};
  Node* tail = nullptr;

  // cremaos la lista doblemente enlazada
  for (int value : values) {
    Node* node = new Node{value, nullptr, tail};
    if (tail != nullptr) {
      tail->next = node;
    } else {
      head = node;
    }
    tail = node;
  }

  ReverseList(head);

  // y por ultimo creamos la lista invertida
  for (Node* current = head; current != nullptr; current = current->next) {
    if (current != head) {
      std::cout << " <-> ";
    }
    std::cout << current->data;
  }
  std::cout << "" << std::endl ;

}