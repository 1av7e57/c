/*Ejercicio 3: Comparar Cadenas
Escribe un programa que pida al usuario ingresar dos cadenas y luego
determine si son iguales o diferentes. Realiza esto con C-strings y con
std::string.

Requisitos:
Usar C-strings para la primera parte.
Usar std::string para la segunda parte.*/

//version alternativa convirtiendo el c-string a std::string antes de comparar

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    // Declaramos un C-string para almacenar la primera cadena
    char cstr1[100];
    // Declaramos un std::string para almacenar la segunda cadena
    string sstr1;

    cout << "Ingresa la primera cadena: ";
    // Almacenamos la primera cadena en el C-string
    cin.getline(cstr1, 100);

    cout << "Ingresa la segunda cadena: ";
    // Almacenamos la segunda cadena en el std::string
    getline(cin, sstr1);

    // Convertimos el C-string a std::string para comparar
    string sstr2(cstr1);

    // Comparamos ambas cadenas
    if (sstr1 == sstr2) {
        cout << "Las cadenas son iguales.\n";
    } else {
        cout << "Las cadenas son diferentes.\n";
    }

    return 0;
}