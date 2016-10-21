typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(song_node *list, char *a, char *b);

song_node * insert_order(song_node *list, char *a, char *b);

void print_list(song_node *list);

song_node * find_song(song_node *list, char *b);

song_node * find_artist(song_node *list, char * a);

song_node * random_node(song_node *list);

song_node * remove_node(song_node *list, song_node *a);

void free_list(song_node *list);
