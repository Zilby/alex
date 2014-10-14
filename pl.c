#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pl.h"

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

song *insert_order(song* t,song* s){
  song* temp;
  song* head=t;
  int first=1;
  while(t){   
    song* temp=t->next;
    if(first){
      if(strcmp(t->nam,s->nam)>0){
	s->next=t;
	return s;
      }
    }
    else if(t->next==0){
      t->next=s;
      return head;
    }
    else if((strcmp(t->nam,s->nam)<=0)&&(strcmp(temp->nam,s->nam)>0)){
      t->next=s;
      s->next=temp;
      return head;
    }
    t=t->next;
    if(first){
      first=0;
    }
  } return head;
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

song *first_art_song(song* t,char* name){
  while(t){
    if(strcmp((t->art),name)==0){
      return t;
    }else{
      t=t->next;
    }
  }
  return t;
}

song *remove_song(song* t,char* name){
  if(name==0){
      return head;
  }
  int first=1;
  song* prior=t;
  song* head=t;
  while(t){
    if(strcmp((t->nam),name)==0){
      if(first){
	return t->next;
      }else{
	prior->next=t->next;
	return head;
      }
    }
    prior=t;
    t=t->next;
    first=0;
  }
  return head;
} 
