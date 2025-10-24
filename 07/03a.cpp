/*Ejercicio 3: Comparar Cadenas
Escribe un programa que pida al usuario ingresar dos cadenas y luego
determine si son iguales o diferentes. Realiza esto con C-strings y con
std::string.

Requisitos:
Usar C-strings para la primera parte.
Usar std::string para la segunda parte.*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    //Declaramos un c-string para almacenar la primera cadena
    char str1 [100];
    //Declaramos un std::string para almacenar la segunda cadena
    std::string str2;

    cout << "Ingresa la primera cadena: ";
    //Almacenamos la primera cadena en el c-string
    cin.getline(str1, 100);

    cout << "Ingresa la segunda cadena: ";
    //Almacenamos la segunda cadena en el std::string
    getline(std::cin, str2);
    
    //comparamos ambas cadenas e imprimimos el resultado
    if (str1 == str2) {
        cout << "Las cadenas son iguales.\n";
    } else {
        cout << "Las cadenas son diferentes.\n";
    }

    return 0;
}