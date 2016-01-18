#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"

void test_create_linkedList(){
  LinkedList list = createList();
  assert(list.length == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);
};

void test_to_add_element_at_the_end(){
  LinkedList list = createList();
  int a = 10;
  int newList = add_to_list(&list,&a);
  assert(newList == 1);
};

void test_to_add_element_at_the_end_whn_there_is_value(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  int newList1 = add_to_list(&list,&a);
  int newList2 = add_to_list(&list,&b);
  int newList3 = add_to_list(&list,&c);
  assert(newList3 == 3);
};

void test_Get_first_element_of_a_list(){
  LinkedList list = createList();
  int a = 10;
  int newList = add_to_list(&list,&a);
  Element *element = (Element *)get_first_element(list);
  assert(element->value == &a);
};

void test_Get_first_element_of_a_list_when_there_is_more_element(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  Element *element = (Element *)get_first_element(list);
  assert(element->value == &a);
};

void test_Get_last_element_of_a_list(){
  LinkedList list = createList();
  int a = 10;
  int newList = add_to_list(&list,&a);
  Element *element = (Element *)get_last_element(list);
  assert(element->value == &a);
};

void test_Get_last_element_of_a_list_when_there_is_more_element(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  Element *element = (Element *)get_last_element(list);
  assert(element->value == &c);
};

void increment(void *num){
  int *number = (int *)num;
  (*number)++;
};

void test_forEach_to_increment_by_1(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  forEach(list,&increment);
  Element *element = (Element *)get_first_element(list);
  assert(element->value == &a);
};

void test_getElementAt_returns_the_value_of_given_position(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  Element *e1 = (Element *)getElementAt(list, 2);
  assert(e1->value == &b);
};

void test_indexOf_returns_the_position_of_an_element(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  int value = indexOf(list, &a);
  assert(value == 0);
};

void test_delete_an_element_according_to_the_position(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  int deletedValue = *(int *)deleteElementAt(&list,2);
  assert(deletedValue == 20);
};

void test_asArray_add_elements_to_an_array_from_a_given_list(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  void *arr = malloc(sizeof(int));
  assert(asArray(list,arr,3) == 3);
};

void test_asArray_add_elements_of_float_type_to_an_array_from_a_given_list(){
  LinkedList list = createList();
  float a = 10;
  float b = 20;
  float c = 30;
  float d = 40;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  void *arr = malloc(sizeof(float));
  assert(asArray(list,arr,4) == 4);
};

int isDivisible(void *hint,void *item){
  return *(int *)item % *(int *)hint == 0;
};

void test_filter_a_given_linked_list_according_to_the_condition(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  int hint = 4;
  LinkedList filteredList;
  filteredList = filter(list,&isDivisible,&hint);
  assert(2==filteredList.length);
};

void test_reverse_which_reverse_the_given_list(){
  LinkedList list = createList();
  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  add_to_list(&list,&a);
  add_to_list(&list,&b);
  add_to_list(&list,&c);
  add_to_list(&list,&d);
  LinkedList reversedList = reverse(list);
  assert(4 == reversedList.length);
  Element *e1 = reversedList.head,*e2;
  assert(40 == *(int *)(e1->value));
  e2 = e1 -> next;
  e2 = e2->next;
  e2 = e2->next;
  assert(10 == *(int *)e2->value);
};

int main() {
  test_create_linkedList();
  test_to_add_element_at_the_end();
  test_to_add_element_at_the_end_whn_there_is_value();
  test_Get_first_element_of_a_list();
  test_Get_first_element_of_a_list_when_there_is_more_element();
  test_Get_last_element_of_a_list();
  test_Get_last_element_of_a_list_when_there_is_more_element();
  test_forEach_to_increment_by_1();
  test_getElementAt_returns_the_value_of_given_position();
  test_indexOf_returns_the_position_of_an_element();
  test_delete_an_element_according_to_the_position();
  test_asArray_add_elements_of_float_type_to_an_array_from_a_given_list();
  test_filter_a_given_linked_list_according_to_the_condition();
  test_reverse_which_reverse_the_given_list();
  printf("Passing\n");
  return 0;
};
