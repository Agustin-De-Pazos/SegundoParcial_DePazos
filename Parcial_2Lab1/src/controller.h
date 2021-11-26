/*
 * controller.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Agustin
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
int controller_LibroLoadFromText(char* path , LinkedList* pArrayListLibro);
int controller_EditorialLoadFromText(char* path , LinkedList* pArrayListEditorial);

int controller_ListLibros(LinkedList* pArrayListLibro,LinkedList* pArrayListEditorial);
int controller_SortAutor(LinkedList* pArrayListLibro);
int controller_saveAsTextMinotauro(char* path , LinkedList* pArrayListLibro);
int controller_saveAsTextDescuento(char* path , LinkedList* pArrayListLibro);
