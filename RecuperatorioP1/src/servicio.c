/*
 * servicio.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int listarServicios(eServicio servicios[],int tamS)
{
    int retorno=-1;

    if(servicios!=NULL&&tamS>0)
    {
        printf("  ID        SERVICIO PRECIO\n");
        for(int i=0;i<tamS;i++)
        {
            mostrarServicio(servicios[i]);
            retorno=0;
        }
    }

    return retorno;
}

void mostrarServicio(eServicio servicio)
{
    printf(" %d %13s %.2f\n",servicio.id,servicio.desc,servicio.precio);
}

int validarServicio(eServicio servicios[],int tamS,int id)
{

    int retorno=-1;

    if(servicios!=NULL&&tamS>0)
    {
        if(id>19999&&id<20003)//ids de servicio esetan entre 20000 y 20002
        {
            retorno=0;
        }
    }

    return retorno;

}

int cargarDescServicio(char str[],eServicio servicos[],int tamS,int id)
{
    int retorno=-1;

    if(servicos!=NULL&&tamS>0)
    {
        for(int i=0;i<tamS;i++)
        {
            if(servicos[i].id==id)
            {
                strcpy(str,servicos[i].desc);
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
