/*
 * bici.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include "bici.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializarbici(eBicicleta bici[],int tamB)
{
    int retorno=-1;

    if(bici!=NULL&&tamB>0)
    {
        for(int i=0; i<tamB; i++)
        {
            bici[i].isEmpty=1;//pongo todos los isEmmpty en 1
        }
        retorno=0;
    }

    return retorno;
}

int buscarLibreMascota(eBicicleta  bici[],int tamB)
{
    int retorno=-1;

    if(bici!=NULL&&tamB>0)
    {
        for(int i=0; i<tamB; i++)
        {
            if(bici[i].isEmpty==1)
            {
                retorno=i;
                break;//salgo del bucle si encontre unlugar libre
            }
        }
    }

    return retorno;
}

int altaMascota(eBicicleta bici[],int tamB, eMarca marcas[],int TamM,eRodado rodado[],int TamR,int proxId)
{
    int retorno=-1;
    int indice;//indice del lugar libre
    eBicicleta nuevaBici;

    system("cls");
    printf("   ***ALTAS***\n");

    if(bici!=NULL&&tamB>0&& marcas !=NULL&&TamM>0&&rodado !=NULL&&TamR>0)
    {
        indice=buscarLibreBici(bici,tamB);
        if(indice!=-1)//si el indice es -1 ya no hay mas lugar
        {
            nuevaBici.id=proxId;
            getString(nuevaBici.desc,sizeof(nuevaBici.desc),"\nIngrese descripcion de la bici:","Ingrese descripcion valido:");
            printf("\n");
            listarmarcas(marcas,TamM);
            printf("_____________________________\n");
            nuevaBici.idMarca=getInt("Ingrese trabajo de la bici(id):","Ingrese id valido:");
            while(validarTrabajo(marcas,TamM,nuevaBici.idMarca)==-1)//valido que sea un color existente
            {
                nuevaBici.idMarca=getInt("Ingrese id valido:","Ingrese id valido:");
            }
            printf("\n");
            listarrodados(rodado,TamR);
            printf("_____________________________\n");
            nuevaBici.idRodado=getInt("Ingrese id de rodado:","Ingrese id valido:");
            while(validarrodado(rodado,TamR,nuevaBici.idRodado)==-1)//valido que se ingrese un rodado existente
            {
                nuevaBici.idRodado=getInt("Ingrese id valido:","Ingrese id valido:");
            }
            nuevaBici.idFecha=getInt("Ingrese edad de la mascota:","Ingrese edad valida:");

            nuevaBici.isEmpty=0;//el isEmpty lo pongo como falso
            bici[indice]=nuevaBici;//cargo el nuevo elemento en el array

            retorno=0;//retorno 0 xq salio todo bien
        }
    }

    return retorno;
}

int buscarBiciXId(eBicicleta  bici[],int tamB,int id)
{
    int retorno=-1;

    if(bici!=NULL&&tamB>0)
    {
        for(int i=0; i<tamB; i++)
        {
            if(bici[i].id==id&&bici[i].isEmpty==0)//me fijo que sea ese el id y que no este dado de baja
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int listarBicis(eBicicleta  bici[],int tamB,eMarca marcas[],int TamM,eRodado rodados[],int TamR)
{
    int retorno=-1;

    if(bici!=NULL&&tamB>0&&marcas!=NULL&&TamM>0&& rodados!=NULL&&TamR>0)
    {
        printf(" ID     DESCRIPCION      TRABAJO      rodado   FECHA\n");
        ordenarBicis(bici,tamB,rodados,TamR);//ordeno las bici antes de mostrarlas
        for(int i=0; i<tamB; i++)
        {
            if(bici[i].isEmpty==0)//me fijo que ningun elemento este dado de baja
            {
                mostrarBici(bici[i],marcas,TamM,rodados,TamR);
            }
        }

        retorno=0;
    }

    return retorno;
}

void mostrarBici(eBicicleta  bici,eMarca marcas[],int TamM,eRodado rodado[],int TamR)
{
    char trabajo[20];
    char rodados[20];

    cargarDescTra(trabajo,marcas,TamM,bici.idMarca);//cargo el descripcion del color
    cargarDescSer(rodados,rodado,TamR,bici.idRodado);//cargo el descripcion del rodado
    printf(" %02d %10s %10s %10s   %2d\n",bici.id,bici.desc,trabajo,rodados,bici.idFecha);
}

int modificarBicis(eBicicleta bici[],int tamB,eMarca marcas[],int TamM,eRodado rodado[],int TamR)
{
    int retorno=-1;
    int bufferId;//guardo el id del elemento a modifica
    int indice;
    char confirma;//el usuario debe confirma la modificacion

    if(bici!=NULL&&tamB>0&& marcas !=NULL&&TamM>0&& rodado!=NULL&&TamR>0)
    {
        system("cls");//limpio la pantalla
        printf("   ***MODIFICACIONES***\n\n");
        listarBicis(bici,tamB,marcas,TamM,rodado,TamR);
        printf("______________________________________________\n");
        bufferId=getInt("Ingrese el id:","Ingrese id valido:");
        indice=buscarBiciXId(bici,tamB,bufferId);
        if(indice!=-1)
        {
            mostrarBici(bici[indice],marcas,TamM,rodado, TamR);//musetro el elemtno que eligio el usuario
            confirma=getCharTwoOptions("\nEs esta la mascota que desea modificar?","Ingrese s o n:",'s','n');//confirmo que sea ese el elemetno
            if(confirma=='s')
            {
                switch(menuModificar())
                {
                case 'a':
                    listarrodados(rodado,TamR);
                    printf("____________________________\n");
                    bici[indice].idRodado=getInt("Ingrese id de rodado:","Ingrese id valido:");
                    while(validarrodado(rodado,TamR,bici[indice].idRodado)==-1)//valido que el rodado exista
                    {
                        bici[indice].idRodado=getInt("Ingrese id valido:","Ingrese id valido:");
                    }
                    break;
                case 'b':
                    bici[indice].idFecha=getInt("Ingrese edad de la mascota:","Ingrese edad valida:");
                    break;
                default:
                    printf("Opcion no valida\n");
                    break;
                }

                retorno=0;
            }else
            {
                retorno=1;//si no confirmo
            }


        }

    }

    return retorno;
}

char menuModificar()
{
    char opcion;

    system("cls");
    printf("***MENU MODIFICACIONES***\n\n");

    printf("a.Modificar marca\n");
    printf("b.Modificar rodado\n");
    printf("_____________________________\n");

    opcion=getChar("Elija una opcion:","Elija una opcion valida:");

    return opcion;
}

int bajaMascota(eBicicleta  bici[],int tamB,eMarca marcas[],int TamM,eRodado rodados[],int TamR)
{
    int retorno=-1;
    int bufferId;//guardo el id del elemento a modificar
    int indice;
    char confirma;//confirmo que ese sea el elemtno a dar de baja

    if(bici!=NULL&&tamB>0&&marcas!=NULL&&TamM>0&& rodados!=NULL&&TamR>0)
    {
        system("cls");
        printf("   ***BAJAS***\n\n");
        listarBici(bici,tamB,marcas,TamM,rodados, TamR);
        printf("______________________________________________\n");
        bufferId=getInt("Ingrese el id de la mascota a dar de baja:","Ingrese id valido:");
        indice=buscarBiciXId(bici,tamB,bufferId);
        if(indice!=-1)
        {
            mostrarBicis(bici[indice],marcas,TamM,rodados,TamR);//muestro la mascota que se dara de baja
            confirma=getCharTwoOptions("\nEs esta la bici que desea dar de baja?","Ingrese s o n:",'s','n');
            if(confirma=='s')
            {
                bici[indice].isEmpty=1;//pongo el isEmpty de ese elemento en true
                retorno=0;

            }
            else
            {
                retorno=1;//si no confirmo
            }
        }

    }

    return retorno;
}

int ordenarBici(eBicicleta  bici[],int tamB,eRodado rodados[],int TamR)
{
    int retorno=-1;
    char rodadoI[20];//aca se cargaran las desc del for con I
    char rodadoJ[20];//aca se cargaran las desec del for con J
    eBicicleta  aux;//aux para el swappeo

    if(bici!=NULL&&tamB>0&& rodados!=NULL&&TamR>0)
    {
        for(int i=0;i<tamB-1;i++)
        {
            for(int j=i+1;j<tamB;j++)
            {
                if(bici[i].isEmpty==0&&bici[j].isEmpty==0)//chequeo que ambos elementos sean activos
                {
                    cargarDescServ(rodadoI,rodados,TamR,bici[i].idRodado);//cargo desc i
                    cargarDescServ(rodadoJ,rodados,TamR,bici[j].idRodado);//cargo desc j
                    if(stricmp(rodadoI,rodadoJ)>0)
                    {
                        aux=bici[i];
                        bici[i]=bici[j];
                        bici[j]=aux;
                    }else if(stricmp(rodadoI,rodadoJ)==0&&stricmp(bici[i].desc,bici[j].desc)>0)
                    {
                        aux=bici[i];
                        bici[i]=bici[j];
                        bici[j]=aux;
                    }
                }//fin if isEmpty
            }//fin if j
        }//fin if i

        retorno=0;
    }

    return retorno;
}
