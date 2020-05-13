#include "list.h"

struct List {
    int dane;
    List* next;
};

List * create_list(void)
{
    List* instancja;
    if( (instancja = (List*)malloc(sizeof(List)) ) == 0 )
    {
        printf("Bad alloc\n");
        exit (-1);
    }
    
    printf("alloc OK\n"); //Do usuniecia
    instancja->next=NULL;

    return instancja;
 
}

void append_to_list(List* list, int elem)
{
    
    list->dane = elem;

    if( (list->next = (List*)malloc(sizeof(List)) ) == 0 )
    {
        printf("Bad alloc\n");
        exit (-1);
    }
    printf("appd: %p IN\n", list);
    list = list->next;
    printf("appd: %p MID\n", list);
    list->next = NULL;
    printf("appd: %p OUT\n\n", list->next);
}

// return amount of elements in list
int count_elements(List * list)
{
    int counter = 0;
    while(list)
    {
        printf("licze: %p\n", list);
        counter++;
        list = list->next;
    }
    return counter;
}