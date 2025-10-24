/*Ejercicio 1: Longitud de una Cadena
Escribe un programa que pida al usuario ingresar una cadena de texto. Luego,
el programa debe mostrar la longitud de esa cadena utilizando un C-string y
un std::string.

Requisitos:
Usar un C-string para la primera parte del ejercicio.
Usar std::string para la segunda parte.*/

#include <iostream>
#include <string>
#include <cstring>  // Para cin.getline() con C-strings
using namespace std;

int main() {

    // Parte 1: Usar C-string
    char texto[100];
    cout << "Ingrese un texto: ";
    cin.getline(texto, 100);
    int longitudCstring = 0;

    // Contar longitud manualmente (sin usar strlen)
    while (texto[longitudCstring] != '\0') {
        longitudCstring++;
    }
    cout << "La longitud del C-string es: " << longitudCstring << endl;

    // Parte 2: Usar std::string
    string cadena;
    cout << "Ingrese otra cadena: ";
    std::getline(cin, cadena);
    cout << "La longitud del std::string es: " << cadena.length() << endl;

    return 0;
}