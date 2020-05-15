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
    printf("ALOKUJE %p\n", instancja);
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
   List *prevNode;
   List *curNode;
  
   
   List* head;// = create_list(); //skopiowane wartosci glowy
 /*   head->dane = list->dane;
   head->next = list->next;
   printf("head %p\n\n", head); */
    puts("");
    head = list->next;
    
    
    printf("mama %p\n", list);
    printf("head %p\n\n", head);

    if(head != NULL){
        prevNode = head;
        head = head->next;
        curNode = head;
        
        
        printf("head %p\n", head);
        printf("prev %p\n", prevNode);
        printf("curr %p\n\n", curNode);
        

        prevNode->next = NULL; // Make first node as last node
        

            while(head != NULL)
            {
                head = head->next;
                curNode->next = prevNode;

                prevNode = curNode;
                curNode = head;
                printf("head %p PETLA\n", head);
                printf("preV %p PETLA\n", prevNode);
                printf("preVnext %p PETLA\n", prevNode->next);
                printf("curN %p PETLA\n\n", curNode);

            }
        printf("end of loop\n");
        head = prevNode;
        printf("head %p [%d]RE\n", head, head->dane);

    }   
            list->next = head;
    printf("list next %p RE\n\n", list->next);

    List* temp = list;
    int begin = list->dane;
    
    /* shifitng from list[0] to list[last]" */ 
    while(temp->next->next != 0 )
    {
        temp = temp->next;
        printf("check: temp[%d]\n", temp->dane);
    }

    temp->dane = begin;
    list->dane = temp->dane;
    printf("LIST[0]%d",list->dane);
    //https://codeforwin.org/2015/09/c-program-to-reverse-singly-linked-list.html
    
}