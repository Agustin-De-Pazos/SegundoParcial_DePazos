/*
 ============================================================================
 Name        : Parcial_2Lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Linkedlist.h"
#include "menu.h"
#include "controller.h"


int main(void) {
	setbuf(stdout, NULL);
	char salir = 'n';
	char path[20];
	int flag = 0;
	int flag2 = 0;

	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditorial = ll_newLinkedList();
	do
	{
	        switch(menu())
	        {
	            case 1:
	            	if(controller_LibroLoadFromText(path , listaLibros))
	            	{
	            		flag = 1;
	            	}
	            	break;
	            case 2:
	            	if(controller_EditorialLoadFromText(path , listaEditorial))
	            	{
	            		flag2 = 1;
	            	}
	            	break;
	            case 3:
	            	if(flag && flag2)
	            	{
	            		if(!controller_SortAutor(listaLibros))
	            		{
	            			printf("ERROR\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Primero debe cargar la opcion 1 y 2\n");
	            	}
	            	break;
	            case 4:
	            	if(flag && flag2)
	            	{
	            		if(!controller_ListLibros(listaLibros,listaEditorial))
	            		{
	            			printf("ERROR\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Primero debe cargar la opcion 1 y 2\n");
	            	}
	            	break;
	            case 5:
	            	if(flag && flag2)
	            	{
	            		if(!controller_saveAsTextMinotauro(path ,  listaLibros))
	            		{
	            			printf("ERROR\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Primero debe cargar la opcion 1 y 2\n");
	            	}
	            	break;
	            case 6:
	            	if(flag && flag2)
	            	{
	            		if(!controller_saveAsTextDescuento(path , listaLibros))
	            		{
	            			printf("Error\n");
	            		}
	            	}
	            	else
	            	{
	            		printf("Primero debe cargar la opcion 1 y 2\n");
	            	}
	            	break;
	            case 7:
	              printf("Confirma salida?: ");
	              fflush(stdin);
	              salir = getchar();
	              break;
	              default:
	              printf("Opcion invalida \n");
	      }
	      system("pause");
	}while(salir == 'n');
	ll_deleteLinkedList(listaLibros);
	ll_deleteLinkedList(listaEditorial);

	return EXIT_SUCCESS;
}
