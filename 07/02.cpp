/*Ejercicio 2: Invertir una Cadena
Escribe un programa que pida al usuario ingresar una cadena y luego imprima
la cadena en orden inverso.

Requisitos:
Usar un std::string para almacenar la cadena.
Imprimir la cadena en orden inverso utilizando un bucle for.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    //Declaramos un std::string para almacenar la cadena
    string cadena;
    cout << "Ingrese una cadena: ";
    //almacenamos la cadena en el std::string
    getline(cin, cadena);
    cout << "Cadena invertida: ";
    //usamos un bucle for para acceder a los caracteres de la cadena en orden inverso
    for (int i = cadena.length() - 1; i >= 0; i--) {
    //imprimimos la cadena desde el final hacia el principio
        cout << cadena[i];
    }
    cout << endl;
    return 0;
}