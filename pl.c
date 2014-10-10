#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

int main(){
  song *head=new_song("Eye of the Tiger","That band");
  head=insert_front(head,new_song("Everlong","Foo Fighters"));
  print_songs(head);
  print_song(find_song(head,"Everlong"));
  print_song(find_song(head,"Everlog"));
  free_songs(head);
  //tests
  //printf("Current List: ");
  //print_list(head);
  //head=insert_front(head,'t');
  //printf("List with 't' added: ");
  //print_list(head);
  //head=free_list(head);
}

song *new_song(char* n, char* a){
  song *s;
  s=(song*)malloc(sizeof(song));
  strcpy(s->nam,n);
  strcpy(s->art,a);
  return s;
}

int print_songs(song* t){
  while(t){
    if(t->next){
      printf("%s, ",t->nam);
    }else{
      printf("%s",t->nam);
    }
    t=t->next;
  }
  printf("\n");
  return 0;
}

int print_song(song* t){
  if(t){
    printf("Name: %s, Artist: %s\n",t->nam,t->art);
  }else{
    printf("No song found\n");
  }
  return 0;
}


song *insert_front(song* t,song* s){
  s->next=t;
  return s;
}


song *free_songs(song* t){
  song *temp;
  while(t){
    temp=t;
    t=t->next;
    printf("Freeing the node: %s\n",temp->nam);
    free(temp);
    if(t){
      printf("List after free: ");
      print_songs(t);
    }
  }
  return t;
}

song *find_song(song* t,char* name){
  while(t){
    if(strcmp((t->nam),name)==0){
      return t;
    }else{
      t=t->next;
    }
  }
  return t;
}

