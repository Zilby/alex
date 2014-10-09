#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

int main(){
  foo *head;
  head=(foo *)malloc(sizeof(foo));
  head->c='z';
  head=insert_front(head,'y');
  head=insert_front(head,'x');
  head=insert_front(head,'w');
  head=insert_front(head,'v');
  head=insert_front(head,'u');
  
  //tests
  printf("Current List: ");
  print_list(head);
  head=insert_front(head,'t');
  printf("List with 't' added: ");
  print_list(head);
  head=free_list(head);
}

int print_list(foo* h){
  while(h){
    printf("%c",h->c);
    h=h->next;
  }
  printf("\n");
  return 0;
}

foo *insert_front(foo* h,char c){
  foo *g;
  g=(foo *)malloc(sizeof(foo));
  g->c=c;
  g->next=h;
  return g;
}

foo *free_list(foo* h){
  foo *temp;
  while(h){
    temp=h;
    h=h->next;
    printf("Freeing the node: %c\n",temp->c);
    free(temp);
    if(h){
      printf("List after free: ");
      print_list(h);
    }
  }
  return h;
}
