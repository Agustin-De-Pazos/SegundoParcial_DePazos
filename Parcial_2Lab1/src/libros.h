/*
 * libros.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Agustin
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Linkedlist.h"

typedef struct
{
    int id;
	char titulo[40];
	char autor[40];
	int precio;
	int idEditorial;
}eLibro;

#endif /* LIBROS_H_ */
eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr);
int libro_setId(eLibro* this,int id);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, int precio);
int libro_setIdEditorial(eLibro* this, int idEditorial);

int libro_getId(eLibro* this,int* id);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_getAutor(eLibro* this, char* autor);
int libro_getPrecio(eLibro* this, int* precio);
int libro_getIdEditorial(eLibro* this,int* idEditorial);

int mostrarLibro(eLibro* unLibro,LinkedList* thisE);
int Libros_SortAutor(void* item1, void* item2);
int libros_editorialMinotauro(void* element);
int descuentosPlanetaSigloEd(void* element);
