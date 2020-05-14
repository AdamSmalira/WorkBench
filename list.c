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
    /* przesuwam sie od zerowego idx listy na ostatni idx" */ 
    while(list->next != 0 )
    {
        list = list->next;
        puts("skok");
    }

    /* na ostatnim list[idx]
    list->dane = wartosc
    list->next = mallock() */
    list->dane = elem;
    if( (list->next = (List*)malloc(sizeof(List)) ) == 0 )
    {
        printf("Bad alloc\n");
        exit (-1);
    }
}

// return amount of elements in list
int count_elements(List * list)
{
    int counter = 0;
    while(list->next != 0)
    {
        counter++;
        list = list->next;
    }
    return counter;
}

// elements are indexed from 0
int get_nth_element(List * list, int index)
{
    int counter = 0;
    while(list->next != 0)
    {
        counter++;
        if(counter == index)
            {break;}

        list = list->next;
    }
    return list->dane;
}

//-- insert element to list at specified index,
// indexed from 0, elements are shifted
void insert_to_list(List * list, int elem, int index)
{

}

