#include "list.h"
#define COUNTER_TO_INDEX -1

#include <stdio.h>
#include <stdlib.h>

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
    printf("ALOKUJE %p\n", instancja);
    return instancja;
 
}

void append_to_list(List* list, int elem)
{
    /* shifitng from list[0] to list[last] */ 
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
    
    List* aux = create_list();
    aux->dane = list->dane;
    aux->next = list->next;
    
    list->dane = elem;
    list->next = aux;
}

// clear list - remove all elements
void clear_list(List * list)
{
    int rozmiar = count_elements(list);
    List* temp = list;
    
    for(rozmiar; rozmiar > 0; rozmiar--)
    {
        list = temp;    
        
        while(list->next->next != 0)
        {
            list=list->next;
        }
        printf("DEALOKU %p\n", list->next);
        free(list->next);
        list->next = NULL;
    }
}

// releases all memory used by list, list is set to NULL
void destroy_list(List ** list)
{
    if( (*list)->next != 0 )
        clear_list(*list);

    printf("DEALOKU %p\n", *list);
    free(*list);
    *list = NULL;
}

// remove nth element - indexed from 0
void remove_nth_element(List * list, int index)
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
    
    List* temp = list->next->next;
    list->dane = list->next->dane;
    printf("DEALOKU %p\n", list->next);
    free(list->next);
    list->next = temp;
}

void reverse_list(List * list)
{
    List* head = list->next;
    List* prevNode;
    List* curNode;
    List* temp=head;
    printf("\n");
        
        printf("base %p\n", list); 
        /* czytam adresy */
        while(temp != 0)
        { 
            printf("head %p [%d]\n", temp, temp->dane); 
            temp=temp->next;
        }


    printf("\n");
    
        prevNode = list; 
        curNode = head; 

        prevNode->next = NULL; 
        
        while(head->next != 0)
        {   
            head = head->next;
            curNode->next = prevNode; 
              
            
            prevNode = curNode;
            curNode = head;                        
        }  
    head = prevNode;
    list->next = head;
    //Zapetlone wskazniki
    //Przesunac dane o wskaznik wczesniej
    
}
