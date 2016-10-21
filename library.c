#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

song_node * table[26];

song_node * add_song(char *a, char *b){
  table = insert_order(table, a, b);
  return table;
}

song_node * search_song(char *b){
  return find_song(table, b);
}

song_node * search_artist(char *a){
  return find_artist(table, a);
}

void print_letter(char *letter){
  int x = 0;
  while (table[x]){
    if ((table[x] -> artist)[0] == letter)
      printf("%s entries:%s\n", letter, table[x]);
  }
}

void print_songs(char *artist){
  int x = 0;
  while (table[x]){
    if ((table[x] -> artist) == artist)
      printf("%s song: %s\n",artist, table[x]);
  }
}

void print_library(){
  print_list(table);
}

void shuffle(){
  printf("random song:%s\n", random_node(table) -> name);
}

song_node * delete_song(char *b){
  int x = 0;
  while (table[x]){
    if ((table[x] -> name) == b)
      remove_node(table, table[x]);
  }
  return table;
}

void delete_all(){
  free_list(table);
}
