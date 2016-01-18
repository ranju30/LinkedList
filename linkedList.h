typedef struct {
  void *value;
  void *next;
} Element;

typedef struct {
  Element *head;
  Element *tail;
  int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);
typedef int MatchFunc(void* hint, void* item);
typedef void ConvertFunc(void *,void *,void *);
typedef void *Reducer(void* hint, void* previousItem, void* item);


LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void *getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
LinkedList filter(LinkedList, MatchFunc, void*);
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void * );
void *reduce(LinkedList, Reducer, void *hint, void *initialValue);
