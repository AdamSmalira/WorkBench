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
    printf("list[1]=%d\n", get_nth_element(head, 1));
    printf("list[3]=%d\n", get_nth_element(head, 3));
    printf("list[2]=%d\n", get_nth_element(head, 2));

    
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

