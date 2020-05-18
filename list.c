#include "list.h"
#define COUNTER_TO_INDEX -1

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
};

struct List {
    Node* head;
};

List * create_list(void)
{
    List* list;
    if( (list = (List*)malloc(sizeof(List)) ) == 0 )
    {
        printf("Bad alloc\n");
        exit (-1);
    }
    
    list->head=NULL;
    printf("ALOKUJE %p\n", (void*)list);
    return list;
 
}

void append_to_list(List* list, int elem)
{
    Node* temp = list->head;
    printf("node: %p\n", (void*)temp);
    if(temp == NULL)
    {
        temp = (Node*)malloc(sizeof(Node)); //dopisać guarda
        temp->next = NULL;
        temp->data = elem;
        list->head = temp;
        
        puts("1");
    }
    else
    {
        printf("2: %p\n", (void*)temp);
        while(temp != NULL)
        {
            temp = temp->next;
            puts("obracam petla");
        }
        printf("3: %p\n", (void*)temp);
        temp = (Node*)malloc(sizeof(Node)); //dopisać guarda
        temp->data = elem;
        temp = temp->next;
        temp->next = NULL;
        printf("4: %p\n", (void*)temp);
    }
    
    
}

// return amount of elements in list
int count_elements(List * list)
{
    Node* node = list->head;
    int counter = 0;

    while(node != 0)
    {
        counter++;
        node = node->next;
    }
    return counter;
}
