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

/*
int print_art_songs(song** t,char* name){
  song* temp=find_art_t(t,name);
  if(temp){
    song* head;
    head=new_song(temp->nam,temp->art);
    int first=0;
    while(temp){
      if(first){
	insert_order(head,new_song(temp->nam,temp->art));
      }else{
	first=1;
      }
      t=delete_song(t,temp->nam);
      temp=find_art_t(t,name);
    }
    print_songs(head);
    free_songs(head);
  }return 0;
}
*/

int print_art_songs(song** t,char* name){
  int first=1;
  int i=0;
  song* temp2=t[i];
  while(i<26){
    song* temp=first_art_song(temp2,name);
    if(temp){
      if(strcmp(temp->art,name)==0){
	if(first){
	  printf("%s",temp->nam);
	  first=0;
	}else{
	  printf(", %s",temp->nam);
	}
	temp2=t[i]->next;
      }else{
	i++;
	temp2=t[i];
      }
    }else{
      i++;
      temp2=t[i];
    }
  }printf("\n");
  return 0;
}
