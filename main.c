#include "list.h"


int main(void) {
    
    List* head = NULL; 
    List* start = create_list();
    printf("main: %p start\n", start);
    head = start;

    append_to_list(head, 10);
    append_to_list(head, 20);
    append_to_list(head, 30);
    printf("ilosc el w liscie: %d\n", count_elements(head));
    printf("start: %p\n", start);
    printf("head : %p\n", start);

    
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

