Analisis de codigos y complejidad

1.
int CountMatches(const int values[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (values[i] == j) {
                count++;
            }
        }
    }

    return count;
}

Preguntas:
1. ¿Cuál es la complejidad temporal Big-O?
R//
- El ciclo exterior se ejecuta n veces.
- Para cada i, el ciclo interior se ejecuta exactamente 3 veces (j = 0, 1, 2).
- Por lo tanto, el número total de evaluaciones del `if` es 3n.
- Como 3 es una constante, la complejidad se reduce a O(n).

2. Si `n` se duplica, ¿cómo cambia aproximadamente el número de comparaciones?
R//
- Antes: 3n comparaciones.
- Después: 3(2n) = 6n comparaciones.
- El número de comparaciones se duplica aproximadamente, porque la relación sigue siendo lineal.


2.
´´´int CountComparisons(const int values[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j += 2) {
      if (values[i] < values[j]) {
        count++;
      }
    }
  }

  return count;
}´´´
}


Preguntas:
1. ¿Cuál es la complejidad temporal Big-O?
R//
- El ciclo exterior se ejecuta n veces.
- El ciclo interior se ejecuta aproximadamente n/2 veces, porque j aumenta de 2 en 2 hasta llegar a n.
- Entonces, el total de iteraciones es aproximadamente n * (n/2) = n^2 / 2.
- Al ignorar constantes y términos menores, la complejidad es O(n^2).

2. Si `n` se duplica, ¿cómo cambia aproximadamente el número de comparaciones?
R//
- Antes: aproximadamente n^2 / 2 comparaciones.
- Después: aproximadamente (2n)^2 / 2 = 2n^2 comparaciones.
- Como 2n^2 / (n^2 / 2) = 4, el número de comparaciones aumenta aproximadamente 4 veces.

