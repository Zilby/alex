#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

song *add_song(song**t,song* s){
  if((s->nam)[0]<91){
    //print_songs(t[(s->nam[0])-65]);
    t[(s->nam[0])-65]=insert_order(t[(s->nam[0])-65],s);
  }else{
    t[(s->nam[0])-65]=insert_order(t[(s->nam[0])-97],s);
  }
  return t;
}

int print_t_songs(song** t){
  char alph[256]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i=0;
  while(i<26){
    printf("%c: ",alph[i]);
    print_songs(t[i]);
    i++;
  }return 0;
}
