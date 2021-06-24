/*
 * trabajos.h
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */



#ifndef TRABAJOS_H_
#define TRABAJOS_H_

#include "fecha.h"
#include "rodado.h"
#include "marca.h"
#include "servicio.h"

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif /* TRABAJOS_H_ */
int inicializarTrabajos(eTrabajo trabajos[],int tamT);

/** \brief busca un lugar libre en el array de trabajos
 *
 * \param trabajos[] array trabajos
 * \param tamT tamanio del array
 * \return el indice del lugar libre o -1 si ya no hay lugar
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tamT);

/** \brief carga un nuevo trabajo en el array trabajos
 *
 * \param trabajos[] array trabajos
 * \param tamT tamanio del array
 * \param servicios[] eServicio
 * \param tamS int
 * \param bici[] eBicicleta
 * \param tamB int
 * \param marcas[] eMarca
 * \param tamM int
 * \param rodados[] eRodado
 * \param tamR int
 * \param proxId el id del nuevo trabajo
 * \return 0 si se pudo hacer el alta o -1 si no
 *
 */
int altaTrabajo(eTrabajo trabajos[],int tamT,eServicio servicios[],int tamS,eBicicleta bici[],int tamB,eMarca marcas[],int tamM,eRodado rodados[],int tamR,int proxId);

/** \brief muestra un trabajo del array trabajos
 *
 * \param trabajo trabajo a mostrar
 * \param servicios[] eServicio
 * \param tamS int
 * \param bici[] eBicicleta
 * \param tamB int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamS,eBicicleta bici[],int tamB);

/** \brief lista todos los trabajos cargados
 *
 * \param trabajos[] eTrabajo
 * \param tamR int
 * \param servicios[] eServicio
 * \param tamS int
 * \param bici[] eBicicleta
 * \param tamB int
 * \return 0 si se pudieron listar o -1 si no
 *
 */
int listarTrabajos(eTrabajo trabajos[],int tamT, eServicio servicios[],int tamS,eBicicleta bici[],int tamB);
