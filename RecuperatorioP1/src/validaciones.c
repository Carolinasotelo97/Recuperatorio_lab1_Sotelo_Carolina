/*
 * validaciones.c
 *
 *  Created on: 24 jun. 2021
 *      Author: caroo
 */


#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Validates that a string has only numbers
 *
 * \param number The string to validate
 * \return 1 in case the string is only numbers and 0 if it's not
 *
 */
static int validatePositiveInteger(char number[]);

/** \brief Validates that a string has only numbers and one '.'
 *
 * \param numberFloat The string to validate
 * \return 1 in case the string is only numbers or number and one '.' and 0 if it's not
 *
 */
static int validatePositiveFloat(char numberFloat[]);

/** \brief Validates that a string has only letters
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and 0 if it's not
 *
 */
static int isOnlyLetters(char string[]);

/** \brief Validates that a string has only letters and numbers
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and numbers and 0 if it's not
 *
 */
static int isNumberAndLetters(char string[]);

int getInt(char message[],char errorMessage[])
{
    char strNumber[32];
    int number;

    puts(message);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    number=atoi(strNumber);

    return number;
}

float getFloat(char message[],char errorMessage[])
{
    char strFloat[32];
    float number;

    puts(message);
    fflush(stdin);
    fgets(strFloat,sizeof(strFloat),stdin);
    strFloat[strlen(strFloat)-1]='\0';

    while(!validatePositiveFloat(strFloat))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strFloat,sizeof(strFloat),stdin);
        strFloat[strlen(strFloat)-1]='\0';
    }

    number=atof(strFloat);

    return number;
}

static int validatePositiveInteger(char number[])
{
    int returnValue=1;

    for(int i=0;number[i]!='\0';i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}

static int validatePositiveFloat(char numberFloat[])
{
    int returnValue=1;
    int pointCounter=0;

    for(int i=0;numberFloat[i]!='\0';i++)
    {
        if(numberFloat[i]<'0'||numberFloat[i]>'9')
        {
            if(numberFloat[i]=='.'&&pointCounter==0)
            {
                pointCounter++;
            }else
            {
                returnValue=0;
                break;
            }
        }
    }

    return returnValue;
}

void getString(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isOnlyLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

static int isOnlyLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

char getChar(char message[],char errorMessage[])
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
    }

    return aux;
}

char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2)
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);//lo paso a toLower para no tener que pasarlo en el main

    while(aux!=option1&&aux!=option2)
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    return aux;
}

static int isNumberAndLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0'||string[i]>'9'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

void getStringWithNumbers(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isNumberAndLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}
