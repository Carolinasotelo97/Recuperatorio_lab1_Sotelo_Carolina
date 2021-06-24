/*
 * bici.h
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#ifndef BICI_H_
#define BICI_H_
#include "trabajos.h"
#include "servicio.h"

typedef struct
{
    int id;
    int desc;
    int idMarca;
    int idRodado;
    int idTrabajo;
    int idServicio;
    int idFecha;
    int isEmpty;
}eBicicleta;


#endif /* BICI_H_ */

/** \brief inicializa array poniendo los isEmpty en 0
 *
 * \param mascotas[] array a inicializar
 * \param tamMas tamanio del array
 * \return 0 si se pudo inicializar y -1 si no
 *
 */
int inicializarMascotas(eBicicleta bici[],int tamBi);

/** \brief busca un lugar libre en el array de mascotas
 *
 * \param mascotas[] array en el que buscar
 * \param tamMas tamanio del array
 * \return indice del lugar libre o -1 si ya no hay lugar
 *
 */
int buscarLibreMascota(eBicicleta bici[],int tamBi);

/** \brief cagra una nueva mascota en el array de mascotas
 *
 * \param mascotas[] array de mascotas
 * \param tamMas tamanio del array
 * \param colores[]
 * \param tamC
 * \param tipos[]
 * \param tamT
 * \param proxId El id que tendra la nueva mascota
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int altaBici(eBicicleta bici[],int tamBi, eTrabajo trabajos[],int tamT, eServicio servicio[],int tamS,int proxId);

/** \brief busca una mascota de acuerdo a un id pasado
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del aray
 * \param id id de la mascota a buscar
 * \return el indice en donde esta la mascota o -1 si no se encontro
 *
 */
int buscarBiciXId(eBicicleta bici[],int tamBi,int id);

/** \brief lista a las mascotas cargadas
 *
 * \param mascotas[] array de mascotas
 * \param tamMas tamanio del array
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se pudieron listar o -1 si no
 *
 */
int listarBicis(eBicicleta bici[],int tamBi, eTrabajo trabajos[],int tamT,eServicio servicio[],int tamS);

/** \brief muestra a una sola mascota
 *
 * \param mascota la mascota a mostrar
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void mostrarBici(eBicicleta bici, eTrabajo trabajos[],int tamT, eServicio servicio[],int tamS);

/** \brief muestra las opciones de modificacion y le pide al usuario que elija una
 *
 * \return char La opcion elegida
 *
 */
char menuModificar();

/** \brief le pide al usuario que elija una mascota y modifica lo que el usuario pide
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del array mascotas
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se puedo modificar,1 si el usuario no confirma o -1 si no se encontro el id de mascota
 *
 */
int modificarBici(eBicicleta bici[],int tamBi,eTrabajo trabajos[],int tamT,eServicio servicio[],int tamS);

/** \brief le pide al usuario que elija una mascota y modifica lo que el usuario pide
 *
 * \param mascotas[] array mascotas
 * \param tamMas tamanio del array mascotas
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se puedo hacer la baja,1 si el usuario no confirma o -1 si no se encontro el id de mascota
 *
 */
int bajaBici(eBicicleta bici[],int tamBi,eTrabajo trabajos[],int tamT,eServicio servicio[],int tamS);

/** \brief ordena las mascotas por tipo y nombre
 *
 * \param mascotas[] array a ordenar
 * \param tamMas tamanio del array
 * \param tipos[] eTipo
 * \param tamT int
 * \return 0 si se pudieron ordenar o -1 si no
 *
 */
int ordenarBici(eBicicleta bici[],int tamBi, eTrabajo trabajos[],int tamT);
