#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

int main(){
  printf("\nTESTS_FOR_INITIAL_NODES________________________\n\n");
  song *head=new_song("Eye of the Tiger","That band");
  head=insert_front(head,new_song("Everlong","Foo Fighters"));
  printf("Added 2 songs (insert front):\n");
  print_songs(head);
  head=insert_order(head,new_song("Sweet Home Alabama","Those Guys"));
  head=insert_order(head,new_song("Abyss","Klaypex"));
  head=insert_order(head,new_song("ZZZZZ","One Republic"));
  head=insert_order(head,new_song("Swarmy","Pirates"));
  head=insert_order(head,new_song("I got it goin tonight","Gotcha"));
  head=insert_order(head,new_song("Everlong","Foo Fighters"));
  printf("Added 5 songs (insert order):\n");
  print_songs(head);
  printf("Removed Abyss, Pirates' first song, ZZZZZ and Random text\n");
  head=remove_song(head,(find_song(head,"Abyss"))->nam);
  print_songs(head);
  head=remove_song(head,(first_art_song(head,"Pirates"))->nam);
  print_songs(head);
  head=remove_song(head,(find_song(head,"ZZZZZ"))->nam);
  print_songs(head);
  head=remove_song(head,"Eye of th");
  print_songs(head);
  printf("Looked for Everlong and Everlog\n");
  print_song(find_song(head,"Everlong"));
  print_song(find_song(head,"Everlog"));
  printf("Looked for first song by Foo Fighters and Food Fighters\n");
  print_song(first_art_song(head,"Foo Fighters"));
  print_song(first_art_song(head,"Food Fighters"));
  printf("Freed songs:\n");
  free_songs(head);
  printf("\nTESTS_FOR_FULL_TABLE________________________\n\n");
  song **table;
  table=malloc(sizeof(song*)*26);
  printf("Created table and added a few songs: \n");
  table=add_song(table,new_song("In the End","Linkin Park"));
  table=add_song(table,new_song("In the End","Linkin Park"));
  table=add_song(table,new_song("Down the Road","C2C"));
  table=add_song(table,new_song("When I'm Gone","Eminem"));
  table=add_song(table,new_song("Hit Me","Klaypex"));
  table=add_song(table,new_song("Finding You","Speaker of the House"));
  table=add_song(table,new_song("I Walk Alone","Klaypex"));
  table=add_song(table,new_song("Misery","Green Day"));
  table=add_song(table,new_song("Best of You","Foo Fighters"));
  table=add_song(table,new_song("it ain't over till it's over","Falling In Reverse"));
  table=add_song(table,new_song("The Cell","C2C"));
  print_t_songs(table);
  printf("\nSongs starting with i: ");
  print_letter(table,'i');
  printf("\nLooked for I Walk Alone: ");
  print_song(find_song_t(table, "I Walk Alone"));
  printf("\nLooked for first song by Klaypex: ");
  print_song(find_art_t(table, "Klaypex"));
  printf("\nRemoved an In the End: I: ");
  table=delete_song(table,"In the End");
  print_letter(table,'i');
    
  printf("\nDeleting Table: \n");
  delete_table(table);
  printf("\nEND_OF_TESTS________________________\n\n");
}
