#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
  LinkedList list;
  list.head = list.tail = NULL;
  list.length = 0;
  return list;
};

int add_to_list(LinkedList *list, void *value){
  Element *e1;
  e1 = (Element *)malloc(sizeof(Element));
  e1->value = value;
  e1->next = NULL;
  if(list->length == 0){
    list->head=list->tail = e1;
  }
  else{
    list->tail->next = e1;
    list->tail = e1;
  }
  list->length++;
  return list->length;
};

void *get_first_element(LinkedList list){
  return list.head;
};

void *get_last_element(LinkedList list){
  return list.tail;
};

void forEach(LinkedList list, ElementProcessor e){
  Element *item= list.head;
  for(int i=1;i<=list.length;i++){
    (e)(item -> value);
    item = item -> next;
  }
};

void *getElementAt(LinkedList list,int index){
  Element *item = list.head;
  for(int i=1;i<=list.length;i++){
    if(index == i){
      return item;
    }
    item = item->next;
  }
  return NULL;
};

int indexOf(LinkedList list,void *val){
  Element *item = list.head;
  for(int i=0;i<list.length;i++){
    if(item->value == val)
      return i;
  }
  return -1;
};

void *deleteElementAt(LinkedList *list,int pos){
  Element *item = list->head;
  Element *temp;
  for (int i = 1; i <= list->length; i++) {
    if(i == pos-1){
      temp = item->next;
      item->next = temp->next;
      free(temp);
      list->length--;
      return temp->value;
    }
    else{
      item = item->next;
    }
  };
  return NULL;
};

int asArray(LinkedList list, void ** arr, int maxElements){
  Element *e1 = list.head;
  if(list.length >= maxElements){
    arr = realloc(arr,maxElements);
    for(int i=0;i<maxElements;i++){
      arr[0] = e1->value;
      e1 = e1->next;
    }
    return maxElements;
  }
  arr = realloc(arr,list.length);
  for(int i=0;i<list.length;i++){
      arr[0] = e1->value;
      e1 = e1->next;
    }
    return list.length;
};

LinkedList filter(LinkedList list,MatchFunc *fun,void *hint){
  LinkedList filteredList = createList();
  Element *e1 = list.head;
  for(int i=1;i<=list.length;i++){
    if(fun(hint,(e1->value))){
      add_to_list(&filteredList,e1->value);
    }
    e1 = e1->next;
  };
  return filteredList;
};

LinkedList reverse(LinkedList list){
  LinkedList reversedList = createList();
  Element *e1 = list.head;
  for(int i=0;i<list.length;i++){
    if(i == list.length-1){
      add_to_list(&reversedList,e1->value);
      list.length--;
      i=-1;
      e1 = list.head;
    }else{
      e1 = e1->next;
    }
  }
  return reversedList;
};
