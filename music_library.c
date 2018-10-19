#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"

void add_song(struct song_node *data, char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node *head = data[letter];
	data[letter] = insert_ordered(head, song, artist);
}

struct node *find_song(struct song_node *data, char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node *head = data[letter];
	return find_node(head, song, artist);
}

struct node *find_artist(struct song_node *data, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node *head = data[letter];
	while (head) {
		if (!strcmp(artist, head->artist) ) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void print_under_letter(struct song_node *data, char letter) {
	printf("Starting with %c\n", letter );
	print_list(data[letter - 'a']);
}

void print_under_artist(struct song_node *data, char *artist) {
	struct song_node *head = find_artist(artist);
	while (head) {
		if (!strcmp(head->artist, artist)) {
			printf("%s by %s\n",head->song, head->artist );
		}
		head = head->next;
	}
}

void print_all(struct song_node *data) {
	int i = 27;
	while (i) {
		if (data[27-i]) {
			printf("Starting with %c\n", 27 - i + 'a' );
			print_list(data[27-i]);
		}
		i--;
	}
}

void shuffle(struct song_node *data) {
	srand(time(NULL));
	int i = 27;
	while (i) {
		int rando = rand() % 27;
		if (random_node(data[rando])) {
			struct song_node *randoo = random_node(data[rando]);
			printf("%s by %s\n", randoo->song, randoo->artist );
			i--;
		}
	}
}

void delete_song(struct song_node *data, char *song, char *artist) {
	int letter = artist[0] - 'a';
	if (letter >= 27 || letter < 0) {
		letter = 26;
	}
	struct song_node *head = data[letter];
	remove_node(head, song, artist);
}

void clear(struct song_node *data) {
	int i = 27;
	while (i) {
		free_list(data[i]);
		data[i] = NULL;
		i--;
	}
}
	
