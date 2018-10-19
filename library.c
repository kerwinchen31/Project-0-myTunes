#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "node.h"
#include "library.h"

struct song_node* table[26];

int get_index(char letter) {
  if(letter < 97) {
    return letter - 65;
  }
  else {
    return letter - 97;
  }
}

struct song_node* get_list(char letter){
  int index = get_index(letter);
  return table[index];
}

void print_letter(char letter){
  printf("Print Letter %c: ", letter);
  print_list(get_list(letter));
}

void print_lib() {
  int i = 0;
  while(i < 27) {
    if(table[i]) {
      printf("List of %c \n: ", tolower((table[i] -> artist)[0]));
      print_list(table[i]);
    }
    i++;
  }
}

void add_song(char* name, char *artist){
  char* lower_artist = convert_lower(artist);
  int index = get_index(lower_artist[0]);
  free(lower_artist);
  table[index]= insert_in_order(table[index], name, artist);
}

struct song_node* find_artist(char* artist){
	struct song_node* head = get_list(artist[0]);
	return find_song_by_artist(head, artist);
}

void print_artist(char* artist){
  if(find_artist(artist)) {
    print_list(find_artist(artist));
  }
  else printf("Artist not in library\n");
}

struct song_node* find_song_lib(char* name, char* artist){
	struct song_node* head = get_list(artist[0]);
	return find_song(head, name, artist);
}

void remove_song(char* name, char* artist){
	struct song_node* song = find_song_lib(name, artist);
	struct song_node* head = get_list(artist[0]);
	table[get_index(artist[0])] = remove_node(head, song);
}

void shuffle(){
  for(int i=0; i < 3; i++){
    int random = rand() % 26;
    while(!table[random]) {
      random = (random + 1) % 26;
    }
    struct song_node* rando_node = random_node(table[random]);
    printf("%s by %s\n", rando_node -> artist, rando_node -> name);
  }
}

void clear(){
  for (int i = 0; i < 26; i++){
    if(table[i]){
      free_list(table[i]);
      table[i] = NULL;
    }
  }
}
