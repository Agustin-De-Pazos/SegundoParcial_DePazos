#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Linkedlist.h"
#include "menu.h"
#include "controller.h"
#include "parser.h"
#include "libros.h"

/** \brief Carga los datos del libro desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_LibroLoadFromText(char* path , LinkedList* pArrayListLibro)
{
	FILE* F;
	int todoOk = 0;

	if(path != NULL && pArrayListLibro != NULL)
	{
        printf("ingrese path para cargar (libros.csv): ");
        fflush(stdin);
        gets(path);
        F = fopen(path, "r");
		if(F == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			parser_LibroFromText(F, pArrayListLibro);
			fclose(F);
			todoOk = 1;
		}
	}
	printf("\nNumero de libros cargados: %d\n",ll_len(pArrayListLibro));
    return todoOk;
}

/** \brief Carga los datos la editorial desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_EditorialLoadFromText(char* path , LinkedList* pArrayListEditorial)
{
	FILE* F;
	int todoOk = 0;

	if(path != NULL && pArrayListEditorial != NULL)
	{
        printf("ingrese path para cargar (editorial.csv): ");
        fflush(stdin);
        gets(path);
		F = fopen(path,"r");
		if(F == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			parser_EditorialFromText(F, pArrayListEditorial);
			fclose(F);
			todoOk = 1;
		}
	}
	printf("\nNumero de editoriales cargados: %d\n",ll_len(pArrayListEditorial));
    return todoOk;
}

/** \brief Ordena ascendente los libros por autor.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_SortAutor(LinkedList* pArrayListLibro)
{
	int todoOk = 0;
	if(pArrayListLibro != NULL)
	{
		if(ll_sort(pArrayListLibro, Libros_SortAutor, 1) == 0)
		{
			printf("Ordenamiento con exito\n");
		}
		else
		{
			printf("ERROR\n");
		}
	}
	return todoOk;
}

/** \brief Muestra los datos de cada libro
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListLibros(LinkedList* pArrayListLibro,LinkedList* pArrayListEditorial)
{
    eLibro* auxLibro = NULL;
    int isOkey = 0;
    int len;
    if(pArrayListLibro != NULL && pArrayListEditorial != NULL)
    {
    	isOkey = 1;
    	len = ll_len(pArrayListLibro);
    	printf("Id             Titulo                            Autor                       Precio    Id Editorial     Nombre Editorial\n");
        for(int i = 0; i<len; i++)
        {
        	auxLibro = (eLibro*) ll_get(pArrayListLibro, i);
            if(mostrarLibro(auxLibro,pArrayListEditorial))
            {
                printf("\n");
            }
        }
        if(isOkey == 0)
        {
            printf("No hay empleados cargados\n");
        }
        printf("\n\n");

    }
    return isOkey;
}

/** \brief Guarda los datos de los libros con la editorial minotauro
 * en el archivo elegido
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsTextMinotauro(char* path , LinkedList* pArrayListLibro)
{
    int todoOk = 0;
    int cant;
    int id;
    int precio;
    char titulo[40];
    char autor[40];
    int idEditorial;

    int len;
    FILE* f;
    LinkedList* pArrayListMinotauro = ll_newLinkedList();
    eLibro* aux;

    if(pArrayListLibro!= NULL && path != NULL && pArrayListMinotauro != NULL)
    {
    	pArrayListMinotauro = ll_filter(pArrayListLibro, libros_editorialMinotauro);
    	len = ll_len(pArrayListMinotauro);
    	if(len > 0)
    	{
			printf("Ingrese path para guardar (descuentos.csv) ");
			fflush(stdin);
			gets(path);
			f = fopen(path,"w");
			if(f == NULL)
			{
				printf("No se logro crear un archivo\n");
			}
			else
			{
				fprintf(f,"Id,Titulo,Autor,Precio,IdEditorial\n");
				len = ll_len(pArrayListMinotauro);
				for(int i = 0; i < len; i++)
				{
					aux = ll_get(pArrayListMinotauro,i);
					if(libro_getId(aux, &id)
						&& libro_getTitulo(aux, titulo)
						&& libro_getAutor(aux, autor)
						&& libro_getPrecio(aux,&precio)
						&& libro_getIdEditorial(aux, &idEditorial))
					{
						cant = fprintf(f,"%d,%s,%s,%d, %d\n",id ,titulo,autor,precio,idEditorial);
					}
					if(cant < 1)
					{
						break;
					}
				}
			}
			fclose(f);
			todoOk = 1;
    	}
    }
    return todoOk;
}
int controller_saveAsTextDescuento(char* path , LinkedList* pArrayListLibro)
{
    int todoOk = 0;
    int cant;
    int id;
    int precio;
    char titulo[40];
    char autor[40];
    int idEditorial;

    int len;
    FILE* f;
    LinkedList* pArrayListDescuentos = ll_newLinkedList();
    eLibro* aux;

    if(pArrayListLibro!= NULL && path != NULL && pArrayListDescuentos != NULL)
    {
    	pArrayListDescuentos = ll_map(pArrayListLibro, descuentosPlanetaSigloEd);
    	len = ll_len(pArrayListDescuentos);
    	if(len > 0)
    	{
			printf("Ingrese path para guardar en (descuento.csv ");
			fflush(stdin);
			gets(path);
			f = fopen(path,"w");
			if(f == NULL)
			{
				printf("No se logro crear un archivo");
			}
			else
			{
				fprintf(f,"Id,Titulo,Autor,Precio,IdEditorial\n");
				len = ll_len(pArrayListDescuentos);
				for(int i = 0; i < len; i++)
				{
					aux = ll_get(pArrayListDescuentos,i);
					if(libro_getId(aux, &id)
						&& libro_getTitulo(aux, titulo)
						&& libro_getAutor(aux, autor)
						&& libro_getPrecio(aux,&precio)
						&& libro_getIdEditorial(aux, &idEditorial))
					{
						cant = fprintf(f,"%d,%s,%s,%d, %d\n",id ,titulo,autor,precio,idEditorial);
					}
					if(cant < 1)
					{
						break;
					}
				}
			}
			fclose(f);
			todoOk = 1;
    	}
    }
    return todoOk;
}
