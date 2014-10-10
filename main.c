#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

int main(){
  printf("\nTESTS________________________\n\n");
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
  printf("\nTESTS________________________\n\n");
}
