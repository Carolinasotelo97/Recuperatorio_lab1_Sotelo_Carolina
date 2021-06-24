/*
 * marca.h
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
    int id;
    char desc[20];
}eMarca;

#endif /* MARCA_H_ */

/** \brief muestra el listado
 *
 * \param array con los elementos a mostrar
 * \param tamanio del array
 *
 */
int listarmarcases(eMarca marcas[],int tamM);


/** \brief muestra un elemento
 *
 * \param elemento a mostrar
 *
 */
void mostrarmarcas(eMarca marcas);

/** \brief Busca el id pasado por parametro
 *
 * \param vec el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 0 si se encontro el id,sino -1
 *
 */
int validarmarcas(eMarca marcas[],int tamM,int id);

/** \brief carga la desce del elmento con el id pasado
 *
 * \param cadena en la que se carga el elemento
 * \param array
 * \param tam del array
 * \param id del elemento a cargar
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int cargarDescmarcas(char str[],eMarca marcas[],int tamM,int id);
