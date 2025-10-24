/*Ejercicio 4: Contar Vocales
Escribe un programa que pida al usuario ingresar una cadena y luego cuente
cuántas vocales contiene.

Requisitos:
Usar std::string para almacenar la cadena.
Considerar las vocales tanto en minúsculas como en mayúsculas.*/

#include <iostream>
#include <string>
#include <cctype> // Para usar toupper()

int main() {
    std::string cadena;
    int contadorVocales = 0;

    std::cout << "Ingresa una cadena: ";
    std::getline(std::cin, cadena);

    for (int i = 0; i < cadena.length(); ++i) {
        char c = cadena[i];
        char upperChar = std::toupper(c);
        if (upperChar == 'A' || upperChar == 'E' || upperChar == 'I' ||
            upperChar == 'O' || upperChar == 'U') {
            contadorVocales++;
        }
    }

    std::cout << "La cadena contiene " << contadorVocales << " vocales." << std::endl;
    return 0;
}