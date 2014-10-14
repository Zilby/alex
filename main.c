#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

int main(){
  printf("\nTESTS________________________\n\n");
  song *head=new_song("Eye of the Tiger","That band");
  head=insert_front(head,new_song("Everlong","Foo Fighters"));
  print_songs(head);
  head=insert_order(head,new_song("Sweet Home Alabama","Those Guys"));
  head=insert_order(head,new_song("Abyss","Klaypex"));
  head=insert_order(head,new_song("ZZZZZ","One Republic"));
  head=insert_order(head,new_song("Swarmy","Pirates"));
  head=insert_order(head,new_song("I got it goin tonight","Gotcha"));
  print_songs(head);
  head=remove_song(head,find_song(head,"Abyss"));
  print_songs(head);
  head=remove_song(head,first_art_song(head,"Pirates"));
  print_songs(head);
  head=remove_song(head,find_song(head,"ZZZZZ"));
  print_songs(head);
  head=remove_song(head,find_song(head,"Eye of th"));
  print_songs(head);
  print_song(find_song(head,"Everlong"));
  print_song(find_song(head,"Everlog"));
  print_song(first_art_song(head,"Foo Fighters"));
  print_song(first_art_song(head,"Food Fighters"));

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
