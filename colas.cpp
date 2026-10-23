/* Ejercicio 2.2. Separar solicitudes de una cola

Una cola contiene solicitudes representadas por números enteros. Las solicitudes cuyo valor es múltiplo de 3 deben trasladarse a una segunda cola, conservando el orden en que aparecen. Las demás deben permanecer en la cola original, también en su orden relativo.

Implemente:

Ejemplo:

Cola inicial `requests`, desde el frente hacia el final:

4 6 9 2 12 5 7 3

Resultado esperado:

requests: 4 2 5 7
priority: 6 9 12 3


Requisitos:

- Utilice las operaciones de la biblioteca `std::queue`.
- No descarte elementos.
- Si `requests` está vacía, la función no debe fallar.

Suponga que `priority` está vacía al inicio de la llamada.*/

///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
void SeparateRequests(
    std::queue<int>& requests,
    std::queue<int>& priority) {
    std::queue<int> aux;
    // procesar cada solicitud en la cola requests

    while (!requests.empty()) {
        int current = requests.front();
        requests.pop();
        if (current % 3 == 0) {
            priority.push(current);
        } else {
            aux.push(current);
        }
    }
    requests = aux;
}   

int main() {
    std::queue<int> requests;
    std::queue<int> priority;

    // agregandos solicitudes a la cola requests
    requests.push(4);
    requests.push(6);
    requests.push(9);
    requests.push(2);
    requests.push(12);
    requests.push(5);
    requests.push(7);
    requests.push(3);

    SeparateRequests(requests, priority);

    // imprimimos la cola de solicitudes
    std::cout << "requests: ";
    while (!requests.empty()) {
        std::cout << requests.front() << " ";
        requests.pop();
    }
    std::cout << std::endl;

    // y aca la cola de prioridad
    std::cout << "priority: ";
    while (!priority.empty()) {
        std::cout << priority.front() << " ";
        priority.pop();
    }
    std::cout << std::endl;

    return 0;
}
