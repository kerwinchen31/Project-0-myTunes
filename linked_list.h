#ifndef LINKED_LIST_H
#define LINKED_LIST_H 

struct song_node { 
	char song[100];
	char artist[100];
	struct song_node *next; 
};

struct song_node * insert_front(struct song_node *head, char *song, char *artist);

struct song_node * insert_ordered(struct song_node *head, char *song, char *artist);

void print_list(struct song_node *head);

struct song_node *find_node(struct song_node *head, char *song, char *artist);

struct song_node * random_node(struct song_node *head);

struct song_node * remove_node(struct song_node *head, char *song, char *artist);

struct song_node * free_list(struct song_node *head);

#endif 
