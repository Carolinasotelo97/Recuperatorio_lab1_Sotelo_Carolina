/*
 * rodado.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include "rodado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int listarrodados(eRodado rodados[],int tamR)
{
    int retorno=-1;

    if(rodados!=NULL&&tamR>0)
    {
        printf("  ID       rodados\n");
        for(int i=0;i<tamR;i++)
        {
            mostrarTipo(rodados[i]);
            retorno=0;
        }
    }

    return retorno;
}

void mostrarTipo(eRodado tipo)
{
    printf(" %d %10s\n",tipo.id,tipo.desc);
}

int validarTipo(eRodado rodados[],int tamR,int id)
{

    int retorno=-1;

    if(rodados!=NULL&&tamR>0)
    {
        if(id>999&&id<1005)//los ids de tipo van de 1000 a 1004
        {
            retorno=0;
        }
    }

    return retorno;

}

int cargarDescTipo(char str[],eRodado rodados[],int tamR,int id)
{
    int retorno=-1;

    if(rodados!=NULL&&tamR>0)
    {
        for(int i=0;i<tamR;i++)
        {
            if(rodados[i].id==id)
            {
                strcpy(str,rodados[i].desc);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
