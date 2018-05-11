#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"


void cargarPersona(ePersona personas[])
{
    int i;
    int hayLugar;

    for(i=0; i<TAM; i++) //recorre a todas las perrsonas
    {
        if(personas[i].estado==0)
        {
            hayLugar=i;
            break;
        }

    }

    printf("Ingrese el nombre de la persona: ");
    fflush(stdin);
    scanf("%[^\n]",personas[hayLugar].nombre);
    printf("Ingrese d n i: ");
    fflush(stdin);
    scanf("%d", &personas[hayLugar].dni);
    printf("Ingrese su edad: ");
    fflush(stdin);
    scanf("%d",&personas[hayLugar].edad);

    while(personas[hayLugar].edad<1 || personas[hayLugar].edad > 105)
    {
        printf("\nPor favor ingrese una edad valida 1 a 100 : ");
        fflush(stdin);
        scanf("%d",&personas[hayLugar].edad);
    }

    personas[hayLugar].estado = 1;
}

void borrarPersona(ePersona borrar[])
{
    int i,dni;

    int flag=0;
    char opcion;

    printf("Ingrese el dni de la persona que quiere borrar: ");
    scanf("%d",&dni);

    for(i=0; i<TAM; i++)
    {
        if(dni==borrar[i].dni)
        {
            flag=1;
            printf("\nPersona encontrada con exito!\n\n");
            printf("Desea borrarlo?: s/n\n");
            fflush(stdin);
            opcion=getch();
            if(opcion=='s')
            {
                borrar[i].estado=0;
                printf("\nPersona borrada!\n");
                break;

            }
            else
            {
                if(opcion!='s')
                {
                    printf("\nAccion cancelada!\n");
                    break;
                }

            }
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        printf("\n No se ha registrado ninguna persona, intente nuvamente\n:");
    }
}

void ordenar(ePersona ordenar[])
{

    int i, x;
    ePersona aux;

for(i=0; i<TAM-1; i++)
    {
        for(x=i+1; x<TAM; x++)
        {
            if(strcmp(ordenar[i].nombre, ordenar[x].nombre)>0)
            {
                aux= ordenar[i];
                ordenar[i]=ordenar[x];
                ordenar[x]=aux;
            }
        }
    }
}


void mostrarPersonas(ePersona mostrar[])
{
    int i;

for(i=0; i<TAM; i++)
{
        if(mostrar[i].estado == 1)
        {
            printf("\nNombre: %s D.N.I: %d Edad: %d\n", mostrar[i].nombre,  mostrar[i].dni,  mostrar[i].edad);
        }
}
}

void grafico(ePersona personas[])
{
    int i;
    int cont18 = 0;
    int cont19a35 = 0;
    int cont35 = 0;
    int flag=0;
    int maximo;

for(i = 0; i < 20; i ++)
{
        if(personas[i].estado == 1)
        {
            if(personas[i].edad <= 18)
            {
                cont18 ++;
            }
            else
            {
                if(personas[i].edad <= 35 && personas[i].edad >= 19)
               {
                    cont19a35 ++;
                }
                else
                {
                    if(personas[i].edad > 35)
                    {
                        cont35 ++;
                    }
                }
            }
        }
}

    if(cont35 >= cont19a35 && cont35 >= cont18)
    {
        maximo = cont35;
    }
else
{
        if(cont19a35 >= cont18 && cont19a35 >= cont35)
        {
            maximo = cont19a35;
        }
        else
        {
            maximo = cont18;
        }
}

    printf("\nGRAFICO DE EDADES\n");
    printf("\n\n\n\n");

for(i=maximo; i>0; i--)
{
        printf("%02d  ",i);

        if(i<= cont18)
        {
            printf("*");
        }
        if(i<= cont19a35)
        {
            flag=1;
            printf("\t*");
       }
        if(i<= cont35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
}
    printf("\n    <18\t19a35\t>35 \n");

}
