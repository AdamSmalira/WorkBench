#include "list.h"


int main(void) {
    int List_Size = 0;
    List* head = create_list(); 

    append_to_list(head, 10);
    append_to_list(head, 20);
    append_to_list(head, 30);
    append_to_list(head, 40);

    printf("\n\n");
   // remove_nth_element(head, 0);
   // remove_nth_element(head, 0);
   
    
    

    List_Size = count_elements(head);
    printf("\n\n");
    for(int i = 0; i < List_Size; i++)
    {
        printf("list[%i]=%d\n", i, get_nth_element(head, i));
    }
  
  reverse_list(head);
   
    List_Size = count_elements(head);
    printf("\n\n");
     for(int i = 0; i < List_Size; i++)
    {
        printf("list[%i]=%d\n", i, get_nth_element(head, i));
    }
   
    destroy_list(&head);
  /*   printf("rozmiar:%d\n",count_elements(head));
    clear_list(head);
    destroy,,,,_list(&head);
    //clear_list(head);
    printf("rozmiar:%d\n",count_elements(head));
    List_Size = count_elements(head);
   */ 

    
    
    /*
    List * list = create_list();
    count_elements(list);
    get_nth_element(list,0);

    insert_to_list(list,101,0);
    
    clear_list(list);
    append_to_list(list,101);
    remove_nth_element(list, 2);
    destroy_list(&list);
    */


   return 0;
}

