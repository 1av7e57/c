/*declara una variable de tipo entero para almacenar tu edad.
luego imprime si tienes mas o menos de 18 años.*/

#include <math.h>
#include <stdio.h>

int main()
{
    int eda;
    printf("dime tu edad: \n");
    scanf("%d", &eda);
    if (eda < 18){
        printf("eres menor de edad \n");
    }else{
        printf("eres mayor de edad \n");
    }
    return 0;
}