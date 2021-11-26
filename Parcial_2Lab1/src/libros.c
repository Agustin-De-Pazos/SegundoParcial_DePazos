#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "editorial.h"
#include "Linkedlist.h"


eLibro* libro_new()
{
    eLibro* newLibro  = (eLibro*) malloc(sizeof(eLibro));
    if(newLibro != NULL)
    {
    	libro_setId(newLibro, 0);
    	libro_setTitulo(newLibro, " ");
    	libro_setAutor(newLibro, " ");
    	libro_setPrecio(newLibro, 0);
    	libro_setIdEditorial(newLibro, 0);
    }

    return newLibro;
}

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* newLibro = libro_new();

    if(newLibro != NULL)
    {
        if(!(libro_setId(newLibro, atoi(idStr)) &&
           libro_setTitulo(newLibro, tituloStr) &&
		   libro_setAutor(newLibro, autorStr) &&
		   libro_setPrecio(newLibro, atoi(precioStr)) &&
		   libro_setIdEditorial(newLibro, atoi(idEditorialStr))))
           {
               free(newLibro);
               newLibro = NULL;
           }
    }
    return newLibro;
}

int libro_setId(eLibro* this,int id)
{
	int isOkey = 0;

	if (this != NULL && id > 0)
	{
		this->id = id;
		isOkey = 1;
	}
	return isOkey;
}

int libro_getId(eLibro* this,int* id)
{
	int isOkey = 0;

	if (this != NULL && id != NULL)
	{
		(*id) = this->id;
		isOkey = 1;
	}
	return isOkey;
}

int libro_setTitulo(eLibro* this,char* titulo)
{
	int isOkey = 0;
	if (this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		isOkey = 1;
	}
	return isOkey;
}

int libro_getTitulo(eLibro* this,char* titulo)
{
	int isOkey = 0;

	if (this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		isOkey = 1;
	}
	return isOkey;
}

int libro_setAutor(eLibro* this,char* autor)
{
	int isOkey = 0;

	if (this != NULL && autor != NULL)
	{
		strcpy(this->autor, autor);
		isOkey = 1;
	}
	return isOkey;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int isOkey = 0;

	if (this != NULL && autor != NULL)
	{
		strcpy(autor, this->autor);
		isOkey = 1;
	}
	return isOkey;
}

int libro_setPrecio(eLibro* this, int precio)
{
	int isOkey = 0;
	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		isOkey = 1;
	}
	return isOkey;
}
int libro_getPrecio(eLibro* this, int* precio)
{
	int isOkey = 0;

	if (this != NULL && precio != NULL)
	{
		(*precio) = this->precio;
		isOkey = 1;
	}
	return isOkey;
}

int libro_setIdEditorial(eLibro* this, int idEditorial)
{
	int isOkey = 0;
	if (this != NULL && idEditorial>=0)
	{
		this->idEditorial = idEditorial;
		isOkey = 1;
	}
	return isOkey;
}
int libro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int isOkey = 0;

	if (this != NULL && idEditorial != NULL)
	{
		(*idEditorial) = this->idEditorial;
		isOkey = 1;
	}
	return isOkey;
}

int mostrarLibro(eLibro* unLibro,LinkedList* thisE)
{
    int isOkey =0;
    int precio;
    int id;
    int idEditorial;
    char autor[40];
    char titulo[40];
    char nombreEditorial[40];

    if((libro_getId(unLibro,&id) &&
       libro_getAutor(unLibro,autor) &&
	   libro_getTitulo(unLibro,titulo) &&
	   libro_getPrecio(unLibro,&precio) &&
	   libro_getIdEditorial(unLibro, &idEditorial)))
    {
    	cargarNombreEditorial(idEditorial, thisE, nombreEditorial);
    	printf("%d        %-30s       %-25s        %4d      %4d         %15s", id, titulo, autor, precio,idEditorial, nombreEditorial);
        isOkey = 1;
    }
    return isOkey;
}


int Libros_SortAutor(void* item1, void* item2)
{
    int resultado;
	eLibro* Lb1;
    eLibro* Lb2;
    char autor1[40];
    char autor2[40];
    Lb1 = (eLibro*) item1;
    Lb2 = (eLibro*) item2;

    if(libro_getAutor(Lb1, autor1) &&
       libro_getAutor(Lb2, autor2))
    {
    	resultado = strcmp(autor1,autor2);
    }
    return resultado;
}

int libros_editorialMinotauro(void* element)
{
	int todoOk = 0;
	eLibro* Lb1;
	int idEditorial;

	Lb1 = (eLibro*) element;
	if(libro_getIdEditorial(Lb1, &idEditorial))
	{
		if(idEditorial == 4)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int descuentosPlanetaSigloEd(void* element)
{
	int todoOk = 0;
	eLibro* Lb1;
	int idEditorial;
	int precio;
	int descuento;

	Lb1 = (eLibro*) element;

	if(libro_getIdEditorial(Lb1, &idEditorial))
	{
		if(idEditorial == 1)//planeta 20%
		{
			if(libro_getPrecio(Lb1, &precio))
			{
				descuento = precio  - (precio * 20 /100);
				if(libro_setPrecio(Lb1, descuento))
				{
					todoOk = 1;
				}
			}
		}
		else
		{
			if(idEditorial == 2)// siglo editores 10%
			{
				if(libro_getPrecio(Lb1, &precio))
				{
					descuento = precio  - (precio * 10 /100);
					if(libro_setPrecio(Lb1, descuento))
					{
						todoOk = 1;
					}
				}

			}
		}
	}
	return todoOk;
}
