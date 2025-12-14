/*Ejercicio 6: Uso de new y delete
Escribe un programa que:
-Use new para crear un entero en el montón y lo
inicialice en 50.
-Imprima el valor y la dirección de este entero.
-Libere la memoria usando delete y verifique que
ya no se puede acceder a ese valor.*/

#include <iostream>

int main() {
    // Usar new para crear un entero en el montón y inicializarlo en 50
    int* ptr = new int(50);

    // Imprimir el valor y la dirección del entero
    std::cout << "Valor: " << *ptr << std::endl;
    std::cout << "Dirección: " << ptr << std::endl;

    // Liberar la memoria usando delete
    delete ptr;

    // Verificar que ya no se puede acceder al valor
    // Esto puede provocar un comportamiento indefinido 

    std::cout << "Valor después de delete: " << *ptr << std::endl; // No recomendado

    return 0;
}

/*Nota: Acceder a un puntero después de usar delete es comportamiento indefinido en C++. 
No se debe hacer en programas reales.*/