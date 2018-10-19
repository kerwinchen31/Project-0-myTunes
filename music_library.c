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

struct node *find_song(char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node head = data[letter];
	return find_node(head, song, artist);
}

struct node *find_artist(char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node head = data[letter];
	while (head) {
		if (!strcmp(artist, head->artist) && !strcmp(song, head->song) ) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void print_under_letter(char letter) {
	printf("Starting with %c\n", letter );
	print_list(data[letter - 'a']);
}

void print_under_artist(char *artist) {
	struct node *head = find_artist(artist)
	while (head)
}