/*
 * marca.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int listarMarcas(eMarca marcas[],int tamM)
{
    int retorno=-1;

    if(marcas!=NULL&&tamM>0)
    {
        printf("  ID       COLOR\n");
        for(int i=0;i<tamM;i++)
        {
            mostrarColor(marcas[i]);
            retorno=0;
        }
    }

    return retorno;
}

void mostrarColor(eMarca marcas)
{
    printf(" %d %10s\n",marcas.id,marcas.desc);
}

int validarColor(eMarca marcas[],int tamC,int id)
{

    int retorno=-1;

    if(marcas!=NULL&&tamC>0)
    {
        if(id>4999&&id<5005)
        {
            retorno=0;
        }
    }

    return retorno;

}

int cargarDescColor(char str[],eMarca marcas[],int tamC,int id)
{
    int retorno=-1;

    if(marcas!=NULL&&tamC>0)
    {
        for(int i=0;i<tamC;i++)
        {
            if(marcas[i].id==id)
            {
                strcpy(str,marcas[i].desc);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
