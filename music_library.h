#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

void add_song(struct song_node *data, char *song, char *artist);

struct node* find_song(struct song_node *data, char *song, char *artist);

struct node* find_artist(struct song_node *data, char *artist);

void print_under_letter(struct song_node *data, char letter);

void print_under_artist(struct song_node *data, char *artist);

void print_all(struct song_node *data);

void shuffle(struct song_node *data);

void delete_song(struct song_node *data, char *song, char *artist);

void clear(struct song_node *data);

#endif
