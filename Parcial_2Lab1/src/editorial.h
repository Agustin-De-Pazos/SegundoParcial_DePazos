/*
 * editorial.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Agustin
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "LinkedList.h"

typedef struct
{
	int idEditorial;
	char nombre[40];
}eEditorial;


#endif /* EDITORIAL_H_ */
eEditorial* editorial_new();
eEditorial* editorial_newParametros(char* idStr,char* nombreStr);

int editorial_setId(eEditorial* this,int id);
int editorial_setNombre(eEditorial* this,char* nombre);

int editorial_getId(eEditorial* this,int* id);
int editorial_getNombre(eEditorial* this,char* nombre);

int cargarNombreEditorial(int id,LinkedList* editorial,char* nombreEditorial);
