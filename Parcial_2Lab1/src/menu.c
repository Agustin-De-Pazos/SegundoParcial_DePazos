#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;

    system("cls");

    printf("\n   *** MENU  *** \n\n");
    printf("1.Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades eLibro\n");
    printf("2.Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades eEditorial.\n");
    printf("3.Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de ordenamiento �Autor� de manera ascendente. \n");
    printf("4.Imprimir por pantalla todos los datos de los libros.\n");
    printf("5.Realizar un listado de los libros de la editorial MINOTAURO.\n");
    printf("6.Guardar descuentos.\n");
    printf("7.Salir\n");
    printf("\n ingrese opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;

}
