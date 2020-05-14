#include "list.h"
#define COUNTER_TO_INDEX -1
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
    
    instancja->next=NULL;

    return instancja;
 
}

void append_to_list(List* list, int elem)
{
    /* shifitng from list[0] to list[last]" */ 
    while(list->next != 0 )
    {
        list = list->next;
    }

    /* working on list[last]
    list->dane = wartosc
    list->next = mallock() */
    list->dane = elem;
    list->next = create_list();
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
    int counter = COUNTER_TO_INDEX;

    /* shifitng from list[0] to list[index]" */ 
    while(list->next != 0)
    {
        counter++;
        if(counter == index)
            {break;}

        list = list->next;
    }

    /* guard "out of range" */
        if(counter < index)
    {
        printf("Pointed index doesn't exist\n");
        exit (-1);
    }

    return list->dane;
}

//-- insert element to list at specified index,
// indexed from 0, elements are shifted
void insert_to_list(List * list, int elem, int index)
{

    int counter = COUNTER_TO_INDEX;
    while(list->next != 0)
    {
        counter++;
        if(counter == index)
            {break;}

        list = list->next;
    }

    /* guard "out of range" */
        if(counter < index)
    {
        printf("Pointed index doesn't exist\n");
        exit (-1);
    }
    
    List* aux = create_list();
    aux->dane = list->dane;
    aux->next = list->next;
    
    list->dane = elem;
    list->next = aux;
}

