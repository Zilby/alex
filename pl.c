#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

int main(){
  song *head;
  head=(song *)malloc(sizeof(song));
  strcpy(head->nam,"Everlong");
  strcpy(head->art,"Foo Fighters");
  head=insert_front(new_song("Eye of the Tiger","That band"));
  
  //tests
  //printf("Current List: ");
  //print_list(head);
  //head=insert_front(head,'t');
  //printf("List with 't' added: ");
  //print_list(head);
  //head=free_list(head);
}

song new_song(char* n, char* a){
  song s;
  s.nam=n;
  s.art=a;
  return s;
}

int print_list(song* t){
  while(t){
    printf("%c",t->nam);
    t=t->next;
  }
  printf("\n");
  return 0;
}

/*
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
*/
