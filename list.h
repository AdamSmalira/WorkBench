#ifndef __LIST
#define __LIST

typedef struct List List;


//OK create and returns instance of List
List * create_list(void);

//OK releases all memory used by list, list is set to NULL
void destroy_list(List ** list);

//OK return amount of elements in list
int count_elements(List * list);

//OK append element to list at the end
void append_to_list(List * list, int elem);

//OK elements are indexed from 0
int get_nth_element(List * list, int index);

//OK remove nth element - indexed from 0
void remove_nth_element(List * list, int index);

//OK clear list - remove all elements
void clear_list(List * list);

//OK insert element to list at specified index,
// indexed from 0, elements are shifted
void insert_to_list(List * list, int elem, int index);

//-- sort elements in list
void sort_list(List * list);

//-- reverse list
void reverse_list(List * list);

#endif// __LIST

