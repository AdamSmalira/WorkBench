#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int List_Size = 0;
    List* head = create_list(); 

    append_to_list(head, 10);
    append_to_list(head, 20); 
    append_to_list(head, 30); 
    append_to_list(head, 40); 
    

    printf("\n");
  
  reverse_list(head);
   
    //List_Size = count_elements(head); //blad bo zapetlony revers_list
    printf("\n\n");
     for(int i = 0; i < 10; i++)
    {
        printf("list[%i]=%d\n", i-1, get_nth_element(head, i));
    }
   
    //destroy_list(&head); 

  


   return 0;
}

