#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

struct node *data[27];

void add_song(char *song, char *artist);

struct node* find_song(char *song, char *artist);

struct node* find_artist(char *artist);

void print_under_letter(char letter);

void print_under_artist(char *artist);

void print_all();

void shuffle();

void delete_song(char *song, char *artist);

void clear();

#endif


#endif 