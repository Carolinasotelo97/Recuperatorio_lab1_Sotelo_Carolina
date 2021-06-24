/*
 * validaciones.h
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/** \brief Asks for a number and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated number
 * \return The number validated
 *
 */
int getInt(char message[],char errorMessage[]);

/** \brief Asks for a float and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated float number
 * \return The float number validated
 *
 */
float getFloat(char message[],char errorMessage[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters
 *
 */
void getString(char str[],int len,char message[],char errorMessage[]);

/** \brief Asks for a character,validates it and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't a letter
  * \return The character validated
 *
 */
char getChar(char message[],char errorMessage[]);

/** \brief Asks the user to choose an option between two characters, validates it's one of the options and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't one of the options
 * \return  The character validated
 *
 */
char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2);
/** \brief Asks for a number and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated number
 * \return The number validated
 *
 */
int getInt(char message[],char errorMessage[]);

/** \brief Asks for a float and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated float number
 * \return The float number validated
 *
 */
float getFloat(char message[],char errorMessage[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters
 *
 */
void getString(char str[],int len,char message[],char errorMessage[]);

/** \brief Asks for a character,validates it and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't a letter
  * \return The character validated
 *
 */
char getChar(char message[],char errorMessage[]);

/** \brief Asks the user to choose an option between two characters, validates it's one of the options and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't one of the options
 * \return  The character validated
 *
 */
char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
 * \param len The length of the string
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters and/or numbers
 *
 */
void getStringWithNumbers(char string[],int len,char message[],char errorMessage[]);
