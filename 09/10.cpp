/*Ejercicio 10: Manejo dinámico de arrays
-Usa new para crear un array dinámico de n
enteros, donde n es un valor proporcionado por
el usuario.
-Llena el array con valores proporcionados por
el usuario.
-Calcula el promedio de los valores usando un
puntero para recorrer el array.
-Muestra el promedio y libera la memoria del
array con delete[].*/

#include <iostream>
using namespace std;

int main() {
    int n;

    // Pedir al usuario el número de elementos
    cout << "Ingrese el número de elementos: ";
    cin >> n;

    // Crear un array dinámico con 'new'
    int* array = new int[n];

    // Llenar el array con valores proporcionados por el usuario
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> array[i];
    }

    // Calcular el promedio usando un puntero para recorrer el array
    int* ptr = array;
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += *ptr;
        ptr++;
    }
    double promedio = static_cast<double>(suma) / n;

    // Mostrar el promedio
    cout << "El promedio es: " << promedio << endl;

    // Liberar la memoria del array con 'delete[]'
    delete[] array;

    return 0;
}