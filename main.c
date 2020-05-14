#include "list.h"


int main(void) {
    int List_Size = 0;
    List* head = create_list(); 

    append_to_list(head, 10);
    append_to_list(head, 20);
    append_to_list(head, 30);
    insert_to_list(head, 100, 1);

    List_Size = count_elements(head);
    for(int i = 0; i < List_Size; i++)
    {
        printf("list[%i]=%d\n", i, get_nth_element(head, i));
    }

    
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

