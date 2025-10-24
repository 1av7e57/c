/*Ejercicio 6: Desafío Final: Variables Globales, Locales y Estáticas en Acción
Objetivo: Combinar todos los conceptos aprendidos.

1. Declara una variable global resultado que almacene el resultado de una operación.
2. Dentro de una función calcular(), declara una variable local resultado que se actualice con una suma. Usa también una variable estática contador para llevar la cuenta de cuántas veces se ha llamado a calcular().
3. Muestra el valor de resultado (tanto local como global) y el valor de contador cada vez que se llama a la función.

Preguntas:
¿Qué diferencia notas entre la variable resultado local y la global después de cada llamada?
¿Cómo se comporta la variable estática contador?*/

#include <iostream>
using namespace std;
int resultado = 100; // Variable global
void calcular() {
int resultado = 10; // Variable local
static int contador = 0; // Variable estática
contador++;
resultado += 5;
::resultado += 5; // Modifica la variable global
cout << "Resultado local: " << resultado << endl;
cout << "Resultado global: " << ::resultado << endl;
cout << "Contador de llamadas: " << contador << endl;
}
int main() {
calcular();
calcular();
calcular();
return 0;
}