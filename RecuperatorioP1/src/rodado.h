/*
 * rodado.h
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */

#ifndef RODADO_H_
#define RODADO_H_


typedef struct
{
    int id;
    char desc[20];
}eRodado;

#endif /* RODADO_H_ */

/** \brief muestra el listado
 *
 * \param array con los elementos a mostrar
 * \param tamanio del array
 *
 */
int listarRodados(eRodado rodados[],int tamR);

/** \brief muestra un elemento
 *
 * \param elemento a mostrar
 *
 */
void mostrarRodado(eRodado rodado);

/** \brief Busca el id pasado por parametro
 *
 * \param vec el array donde buscar
 * \param tam Tamanio del array
 * \param id El id que se va a buscar
 * \return 0 si se encontro el id,sino -1
 *
 */
int validarRodado(eRodado rodados[],int tamR,int id);

/** \brief carga la desce del elmento con el id pasado
 *
 * \param cadena en la que se carga el elemento
 * \param array
 * \param tam del array
 * \param id del elemento a cargar
 * \return 0 si se pudo cargar y -1 si no
 *
 */
int cargarDescTipo(char str[],eRodado rodados[],int tamR,int id);
