#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define ESC 27


// 6
// Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada
// de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.

int main ()
{
    int suma=0;
    int dato;
    Pila dada, aux, menor;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);

    char opcion;

    do /// Carga de datos
    {
        system("cls");
        printf("INGRESE UN DATO PARA DADA: ");
        scanf("%d", &dato);
        apilar(&dada, dato);

        printf("Presiones ESC para salir...\n");
        opcion = getch();
    }
    while( opcion != 27);

    printf("---------> DADA DESORDENADA <---------"); /// Mostramos la Pila Desordenada
    mostrar(&dada);

    system ("pause");

    while(!pilavacia(&dada))    ///CON ESTE WHILE HACEMOS EL PROCESO DE COMPARAR LOS TOPES Y PASAR DE AUX A DADA
    {

        apilar(&menor,desapilar(&dada));

        while(!pilavacia(&dada))
        {
            if(tope(&dada) <= tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor,desapilar(&dada));
            }
            else
            {
                apilar(&aux,desapilar(&dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada,desapilar(&aux));
        }
    }

    mostrar(&menor);
    return 0;

}


