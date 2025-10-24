/*Ejercicio 7: Palíndromo
Escribe un programa que determine si una cadena es un palíndromo (se lee
igual de adelante hacia atrás y viceversa).

Pista: Usa el método .substr() y .length() para comparar partes de
la cadena.*/

#include <iostream>
#include <string>
using namespace std;

bool esPalindromo(string cadena) {
    int longitud = cadena.length();
    for (int i = 0; i < longitud / 2; i++) {
        if (cadena.substr(i, 1) != cadena.substr(longitud - i - 1, 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    string entrada;
    cout << "Ingresa una cadena: ";
    getline(cin, entrada);

    if (esPalindromo(entrada)) {
        cout << "La cadena es un palíndromo." << endl;
    } else {
        cout << "La cadena no es un palíndromo." << endl;
    }

    return 0;
}