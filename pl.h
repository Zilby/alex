typedef struct song{ 
  char nam[256];
  char art[256];
  struct song *next;
} song;

int print_songs(song* t); //x
int print_song(song* t); //x
song *new_song(char* n, char* a); //x
song *insert_front(song* t,song* s); //x
song *insert_order(song* t,song s);
song *free_songs(song* t); //x
song *first_art_song(char* name);
song *find_song(song* t,char* name); //x
int remove_song(song target); 
song *add_song(song s);
