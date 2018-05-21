/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#ifndef VM_STOCK_H
#define VM_STOCK_H

#include "vm_coin.h"
#include "unistd.h"
#include "vm_system.h"

/**
 * The default stock level that all new stock should start with and the value
 * to use when restting stock.
 **/
#define DEFAULT_STOCK_LEVEL 20

#define STOCK_DELIM "|"

#endif

Boolean loadStockData(VmSystem* system , const char* fileLocation);
Stock* getItemById(VmSystem* system, char id[ID_LEN+1]);
Node* getNodeByItemId(VmSystem* system, char* id);
Boolean decreaseStockCount(VmSystem* system, Stock* item);
Stock* getLastItem(VmSystem* system);
Boolean deleteNode(List* list, Node* nodeToDelete);
void appendToList(List* list, Stock* data);
