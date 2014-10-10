typedef struct song{ 
  char nam[256];
  char art[256];
  struct song *next;
} song;

int print_songs(song* t);
int print_song(song* t);
song *new_song(char* n, char* a);
song *insert_front(song* t,song* s);
song *insert_order(song* t,song s);
song *free_songs(song* t);
song *first_art_song(char* name);
song *find_song(song* t,char* name);
int remove_song(song target);
song *add_song(song s);
