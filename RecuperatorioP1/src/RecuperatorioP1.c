/*
 ============================================================================
 Name        : RecuperatorioP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajos.h"
#include "validaciones.h"
#include "rodado.h"
#include "marca.h"
#include "bici.h"
#include "servicio.h"


#define TAM_R 5
#define TAM_MAR 5
#define TAM_B 100
#define TAM_SERV 3
#define TAM_HARDCODEMASC 10
#define TAM_TRABAJO 150
#define TAM_HARDCODETRAB 6

/** \brief muestra un menu deopciones y le pide al usuario que elija una
 *
 * \return la opcion elegida
 *
 */
int menu();

/** \brief hardcodea al array de electrodomesticos
 *
 * \param array a hardcodear
 * \param tamanio del array
 * \return 0 si salio tod bien si no -1
 *
 */
int hardcodearbici(eBicicleta bici[],int tamB);

void servicioMasRealizado(eBicicleta bici, int tamB, eServicio servicios[], int tamS, int contadorBicisActivas);

void listadoBiciPorServYTra(eBicicleta bici, int tamS, eServicio servicios, int tamS, eTrabajo trabajos, int tamT, int contadorBicisActivas);
int main()
{
     char confirma='n';
     int proxIdBici=1;//ids de Bici empiezan en 1
     int proxIdTrabajo=500;//ids de trabajo empiezan en 500
     int flag=1;//flag esta en 1 por el hardcodeo
     int contadorBicisActivas = 0;
     eBicicleta bici[TAM_B];
     eMarca marcas[TAM_TRABAJO];
     eRodado rodados[TAM_R]={
                            {1},
                            {11},
                            {24},
                            {25},
                            {4}
                            };
    eMarca marcas[TAM_MAR]={
                                {5000,"bmw"},
                                {5001,"rx"},
                                {5002,"moon"},
                                {5003,"montain"},
                                {5004,"mix"}
                                };
    eRodado servicios[TAM_SERV]={
                                    {20000,"Limpieza",250},
                                    {20001,"Parche",300},
                                    {20002,"Centrado",400},
									{20003, "Cadena",350},
                                    };

    inicializarbici(bici,TAM_B);
    inicializarmarcas(marcas,TAM_TRABAJO);
    hardcodearbici(bici,TAM_HARDCODEMASC);
    proxIdBici+=TAM_HARDCODEMASC;//para que se pueden hacer altas y no se repita id

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaBici(bici,TAM_B,marcas,TAM_MAR,rodados,TAM_R,proxIdBici))
            {
                printf("\nAlta exitosa!\nEl id de esta Bici es:%d\n",proxIdBici);
                proxIdBici++;
                flag=1;//el flag de altas lo pongo en true

            }else
            {
                printf("Sistema completo\n");
            }
            break;
        case 2:
           if(flag)
            {
                switch(modificarBici(bici,TAM_B,marcas,TAM_MAR,rodados,TAM_R))
                {
                case -1:
                    printf("\nNo se encontro ese id de Bici\n");
                    break;
                case 0:
                    printf("\nModificaion exitosa!\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n");
                    break;
                }
            }else
            {
                printf("Primero debe cargar una Bici");
            }
            break;
        case 3:
            if(flag)
            {
                switch(bajaBici(bici,TAM_B,marcas,TAM_MAR,rodados,TAM_R))
                {
                case -1:
                    printf("\nNo se encontro ese id de Bici\n");
                    break;
                case 0:
                    printf("\nBaja exitosa!\n");
                    break;
                case 1:
                    printf("\nOperacion cancelada\n");
                    break;
                }
            }else
            {
                printf("Primero debe cargar una Bici\n");
            }
            break;
        case 4:
            if(flag)
            {
                system("cls");
                printf("   ***bici***\n\n");
                listarbici(bici,TAM_B,marcas,TAM_MAR,rodados,TAM_R);
            }else
            {
                printf("\nPrimero debe cargar una Bici\n");
            }
            break;
        case 5:
            system("cls");
            printf("   ***rodados***\n\n");
            listarrodados(rodados,TAM_R);
            break;
        case 6:
            system("cls");
            printf("   ***marcas***\n\n");
            listarmarcas(marcas,TAM_MAR);
            break;
        case 7:
            system("cls");
            printf("   ***SERVICIOS***\n\n");
            listarServicios(servicios,TAM_SERV);
            break;
        case 8:
            if(!altaTrabajo(marcas,TAM_TRABAJO,servicios,TAM_SERV,bici,TAM_B,marcas,TAM_MAR,rodados,TAM_R,proxIdTrabajo))
            {
                printf("\nAlta exitosa!\nEl id de este trabajo es:%d\n",proxIdTrabajo);
                proxIdTrabajo++;
            }else
            {
                printf("\nNo se pueden cargar mas marcas\n");
            }
            break;
        case 9:
            system("cls");
            printf("   ***Informes**\n\n");
            listarServicioMasElegido(bici, TAM_B, servicios, TAM_SERV, contadorBicisActivas);
            break;
        case 10:
            confirma=getCharTwoOptions("\nEsta seguro de que desea salir?","Ingrese s o n:",'s','n');
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        printf("\n\n");
        system("pause");//pauso la pantalla

    }while(confirma!='s');//mientras el usurio no confirme salir

    return 0;
}

int menu()
{
    int opcion;

    system("cls");//limpio la pantalla
    printf("   ***ABM bici***\n\n");
    printf("1.Alta Bici\n");
    printf("2.Modificar Bici\n");
    printf("3.Baja Bici\n");
    printf("4.Listar bici\n");
    printf("5.Listar rodados\n");
    printf("6.Listar marcas\n");
    printf("7.Listar servicios\n");
    printf("8.Alta trabajo \n");
    printf("9.Listar servicios mas realizados\n");
    printf("10.Salir\n");
    printf("_______________________________\n");

    opcion=getInt("Elija una opcion:","Elija una opcion valida\n");

    return opcion;
}

int hardcodearbici(eBicicleta bici[],int tamB)
{
    int retorno=-1;

    if(bici!=NULL&&tamB>0)
    {
        for(int i=0;i<tamB;i++)
        {
            bici[i].id=ids[i];
            strcpy(bici[i].desc,desc[i]);
            bici[i].idMarca=idsMarca[i];
            bici[i].idRodado=idsRodados[i];
            bici[i].idFecha=idFecha[i];
            bici[i].isEmpty=0;//pongo los isEmpty de estas bici en false
        }
        retorno=0;
    }

    return retorno;
}

void servicioMasRealizado(eBicicleta bici, int tamB, eServicio servicios[], int tamS, int contadorBicisActivas){
	if (contadorBicisActivas > 0){
		mostrarServicioMasElegido(bici, tamB, servicios, tamS);
	}else{
		printf("No hay bicis activas!\n");
	}
}

void listadoBiciPorServYTra(eBicicleta bici, int tamB, eServicio servicios, int tamS, eTrabajo trabajos, int tamT, int contadorBicisActivas){
	int idServ;
	int idTra;
	int contadorServYTra;
	int indiceServ;
	int indiceTra;

	if(contadorBicisActivas >0){
		pedirServicio(servicios, tamS, &idServ);
		pedirTrabajo(trabajos, tamT, &idTra);
		contadorServYTra = contarServYTra(bici, tamB, idServ, idTra, trabajos, servicios, tamT, tamS);
		if(contadorServYTra ==0){
			printf("No hay bicis de esas caracteristicas! \n");
		}else{
			indiceServ = buscarIndicePorServicio(servicios, tamS, idServ);
			indiceTra = buscarIndicePorTrabajo(trabajos, tamT, idTra);
			printf("Hay %d bicis que realiza este servicio con este trabajo %s", contadorServYTra, servicios[indiceServ].desc, trabajos[indiceTra].id);
		}
	}else{
			printf("No hay bicis activas\n");
		}
	}

