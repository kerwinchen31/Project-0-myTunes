#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

void add_song(char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node head = data[letter];
	data[letter] = insert_ordered(head, song, artist);
}

struct node* find_song(char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node head = data[letter];
	return find_node(head, song, artist);
}