/*Ejercicio 5: Búsqueda de Palabra en Texto
Escribe un programa que pida al usuario ingresar un texto largo y luego
ingrese una palabra. El programa debe decir si la palabra existe en el texto y
en qué posición aparece la primera vez.

Requisitos:
Usar std::string y el método .find().*/

#include <iostream>
#include <string>

int main() {
    std::string texto, palabra;
    
    // Pedir al usuario que ingrese un texto largo
    std::cout << "Ingresa un texto largo: ";
    std::getline(std::cin, texto);
    
    // Pedir al usuario que ingrese una palabra
    std::cout << "Ingresa una palabra: ";
    std::getline(std::cin, palabra);
    
    // Buscar la posición de la primera aparición de la palabra en el texto
    size_t posicion = texto.find(palabra);
    
    // Verificar si la palabra fue encontrada
    if (posicion != std::string::npos) {
        //Sumamos 1 para que el resultado muestre la posicion contando desde 1 y no desde 0
        std::cout << "La palabra \"" << palabra << "\" fue encontrada en la posición: " << (posicion + 1) << std::endl;
    } else {
        std::cout << "La palabra \"" << palabra << "\" no fue encontrada en el texto." << std::endl;
    }
    
    return 0;
}