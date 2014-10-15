#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

song **add_song(song**t,song* s){
  if((s->nam)[0]<91){
    t[(s->nam[0])-65]=insert_order(t[(s->nam[0])-65],s);
  }else{
    t[(s->nam[0])-97]=insert_order(t[(s->nam[0])-97],s);
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

int print_letter(song** t,char c){
  if(c<91){
    print_songs(t[c-65]);
  }else{
    print_songs(t[c-97]);
  }return 0;
}

song *find_song_t(song** t,char* name){
  int i=0;
  while(i<26){
    song* temp=find_song(t[i],name);
    if(temp){
      if(strcmp(temp->nam,name)==0){
	return temp;
      }
    }else{
      i++;
    }
  } return 0;
}

song *find_art_t(song** t,char* name){
  int i=0;
  while(i<26){
    song* temp=first_art_song(t[i],name);
    if(temp){
      if(strcmp(temp->art,name)==0){
	return temp;
      }
    }else{
      i++;
    }
  } return 0;
}

song** delete_song(song** t,char* name){
  int i=0;
  while(i<26){
    song* temp=find_song(t[i],name);
    if(temp){
      if(strcmp(temp->nam,name)==0){
	t[i]=remove_song(t[i],name);
	return t;
      }
    } i++;
  }return 0;
}

int delete_table(song** t){
  int i=0;
  while(i<26){
    free_songs(t[i]);
    i++;
  }
  t=0;
  free(t);
}
