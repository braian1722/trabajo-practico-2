
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define TAM 20

int main()
{
    ePersona personas[20];

    int opcion, i;

    char seguir= 's';

    for(i=0; i<TAM; i ++)
    {
        personas[i].estado = 0;
    }

    do
    {


        printf("   Ingrese una opcion de 1 a 5:\n");
        printf("1 Agregar una persona\n");
        printf("2 Borrar una persona\n");
        printf("3 Imprimir lista ordenada por nombre\n");
        printf("4 Imprimir grafico de edades\n");
        printf("5 salir\n");



        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            cargarPersona(personas);
            break;

        case 2:

            borrarPersona(personas);
            break;

        case 3:
            ordenarpornombre(personas);
            mostrarPersonas(personas);
            break;

        case 4:
            graficodeEdades(personas);
            break;
        case 5:
            seguir = 'n';
            printf("programa finalizado\n");
            break;
        default:

            printf("Ingrese una opcion del menu!!!\n");
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
