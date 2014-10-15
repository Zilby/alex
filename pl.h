typedef struct song{ 
  char nam[256];
  char art[256];
  struct song *next;
} song;

int print_songs(song* t); //x
int print_song(song* t); //x
song *new_song(char* n, char* a); //x
song *insert_front(song* t,song* s); //x
song *insert_order(song* t,song* s); //x
song *free_songs(song* t); //x
song *first_art_song(song* t,char* name);//x
song *find_song(song* t,char* name); //x
song *remove_song(song* t,char* name); //x

song **add_song(song**t,song* s); //x
song *find_song_t(song** t,char* name);//x
song *find_art_t(song** t,char* name); //x
int print_letter(song** t,char c); //x
int print_art_songs(song** t,char* name); //x
int print_t_songs(song** t); //x
int shuffle(song** t,int i);
song** delete_song(song** t,char* name); //x
int delete_table(song** t); //x
