#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "editorial.h"
#include "LinkedList.h"


eEditorial* editorial_new()
{
    eEditorial* newEditorial  = (eEditorial*) malloc(sizeof(eEditorial));
    if(newEditorial != NULL)
    {
    	editorial_setId(newEditorial, 0);
    	editorial_setNombre(newEditorial, " ");
    }
    return newEditorial;
}

eEditorial* editorial_newParametros(char* idStr,char* nombreStr)
{
	eEditorial* newEditorial = editorial_new();
    if(newEditorial != NULL)
    {
        if(!(editorial_setId(newEditorial, atoi(idStr)) &&
           editorial_setNombre(newEditorial, nombreStr)))
           {
               free(newEditorial);
               newEditorial = NULL;
           }
    }
    return newEditorial;
}

int editorial_setId(eEditorial* this,int id)
{
	int isOkey = 0;

	if (this != NULL && id > 0)
	{
		this->idEditorial = id;
		isOkey = 1;
	}
	return isOkey;
}
int editorial_getId(eEditorial* this,int* id)
{
	int isOkey = 0;

	if (this != NULL && id != NULL)
	{
		(*id) = this->idEditorial;
		isOkey = 1;
	}
	return isOkey;
}
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int isOkey = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		isOkey = 1;
	}
	return isOkey;
}
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int isOkey = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		isOkey = 1;
	}
	return isOkey;
}

int cargarNombreEditorial(int id,LinkedList* editorial,char* nombreEditorial)
{
	int todoOk = 0;
	int len;
	int idEditorial;
	eEditorial* auxEditorial;

	if(editorial != NULL && nombreEditorial != NULL && id > 0)
	{
		len = ll_len(editorial);
		for(int i =0; i<len; i++)
		{
			auxEditorial = ll_get(editorial, i);
			editorial_getId(auxEditorial, &idEditorial);
			if(idEditorial == id)
			{
				editorial_getNombre(auxEditorial, nombreEditorial);
				break;
			}
		}
	}

	return todoOk = 1;
}
