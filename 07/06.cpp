/*Ejercicio 6: Remover Espacios en Blanco
Escribe un programa que elimine todos los espacios en blanco de una cadena.

Pista: Usar un bucle para recorrer la cadena y construir una nueva
cadena sin espacios.*/

#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Ingresa una cadena: ";
    std::getline(std::cin, input);

    std::string result;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] != ' ') {
            result += input[i];
        }
    }

    std::cout << "Cadena sin espacios en blanco: " << result << std::endl;
    return 0;
}