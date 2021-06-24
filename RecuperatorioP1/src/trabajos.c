/*
 * trabajos.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo trabajos[],int tamT)
{
    int retorno=-1;

    for(int i=0;i<tamT;i++)
    {
        trabajos[i].isEmpty=1;//pongo todos los isEmpty de trabajo en true
        retorno=0;
    }

    return retorno;
}

int buscarLibreTrabajo(eTrabajo trabajos[],int tamT)
{
    int retorno=-1;

    for(int i=0;i<tamT;i++)
    {
        if(trabajos[i].isEmpty==1)//me fijo que el lugar no este ocupado
        {
            retorno=i;
            break;//salgo del bucle si encutnro un lugar vacio
        }
    }

    return retorno;
}

int altaTrabajo(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eBicicleta bici[],int tamB,eMarca marcas[],int tamM,eRodado rodados[],int tamR,int proxId)
{
    int retorno=-1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(bici!=NULL&&tamB>0&& marcas!=NULL&&tamM>0&&rodados!=NULL&&tamR>0&&trabajos!=NULL&&tamT>0&&servicios!=NULL&&tamS>0)
    {
        indice=buscarLibreTrabajo(trabajos,tamT);
        if(indice!=-1)
        {
            system("cls");
            printf("   ***ALTA TRABAJO***\n\n");
            nuevoTrabajo.id=proxId;
            listarbici(bici,tamB,marcas,tamM,rodados,tamR);
            printf("______________________________________________\n");
            nuevoTrabajo.id = getInt("Ingrese id de bici: ","Ingrese id valido:");
            while(buscarMascotaXId(bici,tamB,nuevoTrabajo.id)==-1)//valido que el id sea de una mascota existente
            {
                nuevoTrabajo.id=getInt("Ingrese id valido:","Ingrese id valido:");
            }
            listarServicios(servicios,tamS);
            printf("______________________________________________\n");
            nuevoTrabajo.idServicio=getInt("Ingrese id de servicio:","Ingrese id valido:");
            while(validarServicio(servicios,tamS,nuevoTrabajo.idServicio)==-1)//valido que el servicio sea existente
            {
                nuevoTrabajo.idServicio=getInt("Ingrese id valido:","Ingrese id valido:");
            }
            printf("\nFecha:\n");
            nuevoTrabajo.fecha.dia=getInt("-DIA.Ingrese dia:","Ingrese dia valido:");
            while(nuevoTrabajo.fecha.dia<1||nuevoTrabajo.fecha.dia>31)//valido el ida
            {
                nuevoTrabajo.fecha.dia=getInt("Ingrese dia valido:","Ingrese dia valido:");
            }
            nuevoTrabajo.fecha.mes=getInt("-MES.Ingrese mes:","Ingrese mes valido:");
            while(nuevoTrabajo.fecha.mes<1||nuevoTrabajo.fecha.mes>12)//valido el mes
            {
                nuevoTrabajo.fecha.mes=getInt("Ingrese mes valido:","Ingrese mes valido:");
            }
            nuevoTrabajo.fecha.anio=getInt("-ANIO.Ingrese anio:","Ingrese anio valido:");
            while(nuevoTrabajo.fecha.anio<1980||nuevoTrabajo.fecha.anio>2020)//anio puede ser despues de 1980 hasta 2020
            {
                nuevoTrabajo.fecha.anio=getInt("Ingrese anio valido:","Ingrese anio valido:");
            }

            nuevoTrabajo.isEmpty=0;//pongo el isEmpty del nuevo elemento en false
            trabajos[indice]=nuevoTrabajo;//guardo el nuevo trabajo en el array de trabajos

            retorno=0;
        }
    }

    return retorno;
}

int listarTrabajos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamS,eBicicleta bici[],int tamMas)
{
    int retorno=-1;
    int flag=0;

    if(trabajos!=NULL&&tamTrabajos>0&&servicios!=NULL&&tamS>0)
    {
        printf(" ID      MASCOTA MASCOTA(ID)  SERVICIO   FECHA\n");
        for(int i=0;i<tamTrabajos;i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS,bici,tamMas);
                flag=1;
            }
        }

        if(!flag)//muestro un mensaje si no habia trabajos cargados
        {
            printf("\nNo hay trabajos que listar\n");
        }
    }

    return retorno;
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS,eBicicleta bici[],int tamMas)
{
    char servicio[25];
    char bicicleta[20];
    int indiceBicicleta=buscarBiciXId(bici,tamMas,trabajo.id);

    cargarDescServicio(servicio,servicios,tamS,trabajo.idServicio);

    if(indiceBicicleta!=-1)
    {
        strcpy(bici,bici[indiceBicicleta].descripcion);//muestro el nombre de la mascota
    }else
    {
        strcpy(bici,"");//si la mascota esta dada de baja muestro una cadena vacia
    }

    printf(" %d %10s %8d %13s %02d/%02d/%d\n",trabajo.id,bici,trabajo.id,servicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}
