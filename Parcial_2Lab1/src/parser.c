#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libros.h"
#include "editorial.h"
#include "parser.h"

// brief Parsea los datos  de los libros desde el archivo data.csv (modo texto).
//
//param path char*
//param pArrayListLibro LinkedList*
//return int*
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
    int todoOk = 0;
    int cant;
    char buffer[5][50];
    eLibro* auxLibro = NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);
    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4]);
        if(cant == 5)
        {
        	auxLibro = libro_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

            if(auxLibro != NULL)
            {
            	ll_add(pArrayListLibro,auxLibro);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

// brief Parsea los datos  de las editoriales desde el archivo data.csv (modo texto).
//
//param path char*
//param pArrayListLibro LinkedList*
//return int*
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
    int todoOk = 0;
    int cant;
    char buffer[2][50];
    eEditorial* auxEditorial = NULL;

    fscanf(pFile,"%[^,],%[^\n]\n", buffer[0], buffer[1]);
    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^\n]\n", buffer[0], buffer[1]);
        if(cant == 2)
        {
        	auxEditorial = editorial_newParametros(buffer[0], buffer[1]);

            if(auxEditorial != NULL)
            {
                ll_add(pArrayListEditorial,auxEditorial);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
