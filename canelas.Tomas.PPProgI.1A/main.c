#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;


int aplicarDescuento(int precio);
int contarCaracteres(char cadena[], int tamC, char caracter);
int ordenarNotebooks(eNotebook notebooks[], int tamN);

int main()
{
    char caracter = 's';

    printf("El precio final es: %d\n", aplicarDescuento(1000));

    printf("\nLa cantidad de caracteres '%c' que hay en la cadena son: %d\n", caracter, contarCaracteres("sssss", 7, caracter));



    return 0;
}


int aplicarDescuento(int precio)
{
    int porcentajeDescuento = 5;
    int descuento;
    int precioFinal;

    descuento = (precio * porcentajeDescuento) / 100;
    precioFinal = precio - descuento;

    return precioFinal;
}


int contarCaracteres(char cadena[], int tamC, char caracter)
{
    int contadorCaracteres = 0;
    for(int i = 0; i < tamC; i++)
    {
        if(cadena[i] == caracter)
        {
            contadorCaracteres++;
        }
    }

    return contadorCaracteres;
}

int ordenarNotebooks(eNotebook notebooks[], int tamN)
{
    int todoOk = 0;

    int auxId;
    float auxPrecio;
    char auxString[50];


    if(notebooks != NULL && tamN > 0)
    {
        for(int i = 0; i < tamN - 1; i++)
        {
             for(int j = i + 1; j < tamN; j++)
             {
                 if((strcmp(notebooks[i].marca, notebooks[j].marca) > 0) || ((strcmp(notebooks[i].marca, notebooks[j].marca) == 0) && notebooks[i].precio > notebooks[j].precio))
                 {
                    strcpy(auxString, notebooks[i].marca);
                    strcpy(notebooks[i].marca, notebooks[j].marca);
                    strcpy(notebooks[j].marca, auxString);

                    auxPrecio = notebooks[i].precio;
                    notebooks[i].precio = notebooks[j].precio;
                    notebooks[j].precio = auxPrecio;

                    auxId = notebooks[i].id;
                    notebooks[i].id = notebooks[j].id;
                    notebooks[j].id = auxId;

                    strcpy(auxString,notebooks[i].procesador);
                    strcpy(notebooks[i].procesador, notebooks[j].procesador);
                    strcpy(notebooks[j].procesador, auxString);
                 }
             }
        }
    }

    return todoOk;
}
