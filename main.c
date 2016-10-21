#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(){
	song_node library[26];
	library = malloc(26 * sizeof(song_node));
	song_node song1 = ("twenty one pilots","ride");
	add_song(song1,library);
	song_node song2 = ("twenty one pilots", "heathens");
	add_song(song2,library);
	song_node song3 = ("ariana grande", "side to side");
	add_song(song3, library);
	song_node song4 = ("ben king", "stand by me");
	add_song(song4, library);
	song_node song5 = ("adele", "hello");
	add_song(song5,library);
	print_library();
	shuffle();
	printf("points to %s\n" ,search_artist("bobby king"));
	printf("points to %s\n" ,search_artist("ben king"));
	printf("points to %s\n", search_song("stand by leg"));
	printf("points to %s\n", search_song("heathens"));
	songsbyartists("twenty one pilots", library);
	delete_song("hello");
	deleteall();
	
	return 1;
	}
