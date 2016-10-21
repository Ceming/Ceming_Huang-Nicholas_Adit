#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

song_node * insert_front(song_node *list, char *a, char *b){
  song_node *newList = (song_node *)malloc(sizeof(song_node));
  newlist -> artist = a;
  newList -> name = b;
  newList -> next = list;
  return newList;
}

song_node * insert_order(song_node *list, char *a, char *b){
  if (((strcmp(list -> artist, a) == 0) && (strcmp(list -> name, b) > 0))||
      (strcmp(list -> arist, a) > 0))
    return insert_front(list, a, b);
  else{
    while (list -> next){
      if (strcmp(list -> artist, a) < 0){
	if (strcmp(list -> next -> artist, a) > 0)
	  list -> next = insert_front(list -> next, a, b);
	if (strcmp(list -> next -> artist, a) == 0){
	  if (strcmp(list -> next -> name, b) > 0)
	    list -> next = insert_front(list -> next, a, b);
	}
	if (list -> next == NULL)
	  list -> next = insert_front(list -> next, a, b);
      }
      if (strcmp(list -> artist, a) == 0){
	if (strcmp(list -> next -> artist, a) == 0){
	  if ((strcmp(list -> name, b) < 0) &&
	      (strcmp(list -> next -> name, a) > 0)){
	    list -> next = insert_front(list -> next, a, b);
	  }
	}
	if (strcmp(list -> next -> artist, a) > 0){
	  list -> next = insert_front(list -> next, a, b);
	}
	if (list -> next == NULL)
	  list -> next = insert_front(list -> next, a, b);
      }
      list = list -> next;
    }
    return list;
  }
}

void print_list(song_node *list){
  printf("%d", list -> i);
  while (list -> next){
    list = list -> next;
    printf(", %d", list -> i);
  }
  printf("\n");
  return 0;
}

song_node * find_song(song_node *list, char *b){
  song_node *node = list;
  while (node){
    if (strcmp(node -> song, b) == 0)
      return node;
    node = node -> next;
  }
  return NULL;
}

song_node * find_artist(song_node *list, char * a){
  song_node *node = list;
  while (node){
    if (strcmp(node -> artist, a) == 0){
      return node -> song;
    }
    node = node -> next;
  }
  return NULL;
}

song_node * random_node(song_node *list){
  int length = 0;
  song_node *node = list;
  while (node){
    length++;
    node = node -> next;
  }
  int random = rand() % length;
  song_node *search = list;
  while (random){
    search = search -> next;
    random--;
  }
  return search;
}

song_node * remove_node(song_node *list, song_node *a){
  song_node *previous = list;
  song_node *current = list -> next;
  if ((previous -> artist == a -> artist) && (previous -> name == a -> name)){
      list = list -> next;
      free (previous);
  }
  while (current){
    if ((current -> artist == a -> artist) && (current -> name == a -> name)){
      previous -> next = current -> next;
      free(current);
    }
    current = current -> next;
    previous = previous -> next;
  }
  return previous;
}

void free_list(song_node *list){
  struct node *holder = list;
  while (list){
    holder = list -> next;
    list -> next = NULL;
    free (list);
    list = holder;
  }
}
      


      
	  
	    
      
