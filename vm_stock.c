/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_stock.h"

/**
 * Some example functions:
 * create list, free list, create node, free node, insert node, etc...
 */

List* createEmptyList(){
    List* newList = (List*)malloc(sizeof(List));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

Node* create(Stock * data, Node* next)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;
 
    return new_node;
}

Node* getLastNode(Node* head)
{
    Node* cursor;
    cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
    return cursor;
}
 
void append(List* list, Stock* data)
{
    if(list->head == NULL)
        list->head = create(data,NULL);
    else{
        Node* lastNode = getLastNode(list->head);
        Node* new_node =  create(data,NULL);
        lastNode->next = new_node;
    }
}

Boolean loadStockData(VmSystem* system, char* fileLocation)
{
    List* list = createEmptyList();
    FILE *fp;
    char line[256];

    char * price = NULL;
    int counter = 0;

    fp = fopen(fileLocation, "r");

    if (fp == NULL) {
        return FALSE;
    }

    while ( fgets(line, sizeof(line), fp) ) {
        Stock * newItem = (Stock*)malloc(sizeof(Stock));
        strcpy( newItem->id,strtok(line, STOCK_DELIM) );
        strcpy( newItem->name,strtok(NULL, STOCK_DELIM) );
        strcpy( newItem->desc,strtok(NULL, STOCK_DELIM) );
        price = strtok(NULL, STOCK_DELIM);
        newItem->onHand = (unsigned int)atoi( strtok(NULL, STOCK_DELIM) );
        newItem->price.dollars = (unsigned int)atoi( strtok(price, ".") );
        newItem->price.cents = (unsigned int)atoi( strtok(NULL, "") );

        append(list, newItem);

        counter++;
    }

    system->itemList = list;

    return TRUE;
}

Stock* getItemById(VmSystem* system, char* id) {
    List* list = system->itemList;
    Node* currentNode = list->head;

    while(currentNode != NULL) {
        if(strcmp(currentNode->data->id, id) == 0){
            return currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

Boolean decreaseStockCount(VmSystem* system, Stock* item) {
    if (item->onHand > 0){
        item->onHand = item->onHand-1;
        return TRUE;
    }
    return FALSE;
}