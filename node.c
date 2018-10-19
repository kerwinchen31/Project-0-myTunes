#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "node.h"

size_t size = sizeof(struct song_node);

void print_list(struct song_node* head) {
  if(!head) {
    printf("\n");
    return;
  }
  printf("%s by %s | ", head->name, head->artist);
  return print_list(head->next);
}

int get_size(struct song_node* head) {
  int i = 0;
  for(; head; i++) {
    head = head -> next;
  }
  return i;
}

char* convert_lower(char* string) {
  char* new = (char*) calloc(256, sizeof(char));
  int i=0;
  for(;string[i]; i++){
    new[i] = tolower(string[i]);
  }
  return new;
}

int songcmp(struct song_node* song1, struct song_node* song2) {
  char* name1 = convert_lower(song1->name);
  char* name2 = convert_lower(song2->name);
  char* artist1 = convert_lower(song1->artist);
  char* artist2 = convert_lower(song2->artist);
  int artist_cmp = strcmp(artist1, artist2);
  int song_cmp = strcmp(name1, name2);
  free(name1);
  free(name2);
  free(artist1);
  free(artist2);
  if(artist_cmp) {
    return artist_cmp;
  }
  return song_cmp;
}

struct song_node * insert_front(struct song_node* head, char*name, char* artist){
  struct song_node* temp = malloc(sizeof(struct song_node));
  temp->name = name;
  temp->artist = artist;
  temp->next = head;
  return temp;
}

struct song_node* insert_in_order(struct song_node* head, char* name, char* artist){
  if(head == NULL) {
    return insert_front(NULL, name, artist);
  }
  struct song_node* temp = malloc(sizeof(struct song_node));
  temp->name = name;
  temp->artist = artist;
  struct song_node* other = head;
  temp->next = NULL;
  while(other -> next ){
    int comp = songcmp(temp, other -> next);
    if(comp <= 0){
      (temp -> next)  = (other -> next);
      (other -> next) = temp;
      return head;
    }
    other = other -> next;
  }
  if(songcmp(temp, other) < 0) {
    return insert_front(other, temp-> name, temp-> artist);
  }
  else {
    other -> next = temp;
  }
  return head;
}

struct song_node * free_list(struct song_node* head){
  if(!head) {
    return head;
  }

  struct song_node* next = head -> next;
  free(head);
  return free_list(next);
}

struct song_node* find_song(struct song_node* head, char* name, char* artist){
  char* name_lower = convert_lower(name);
  char* artist_lower = convert_lower(artist);
  while(head){
    char* head_name = convert_lower(head -> name);
    char* head_artist = convert_lower(head -> artist);
    if(!strcmp(head_name, name_lower) && !strcmp(head_artist, artist_lower)){
      free(name_lower);
      free(artist_lower);
      free(head_name);
      free(head_artist);
      return head;
    }
    head = head -> next;
    free(head_name);
    free(head_artist);
  }
  free(name_lower);
  free(artist_lower);
  return NULL;
}

struct song_node* find_song_by_artist(struct song_node* head, char* artist){
  char* artist_lower = convert_lower(artist);
  while(head){
    char* head_artist = convert_lower(head -> artist);
    if(!strcmp(head_artist, artist_lower)){
      free(artist_lower);
      free(head_artist);
      return head;
    }
    free(head_artist);
    head = head -> next;
  }
  free(artist_lower);
  return NULL;
}

struct song_node* remove_node(struct song_node* head, struct song_node* removee){
  if(head == removee){
    struct song_node* new = head -> next;
    head -> next = NULL;
    free(head);
    return new;
  }
  struct song_node* temp = head;
  while(temp -> next){
    if(temp->next == removee) {
      temp->next = temp->next->next;
      removee -> next = NULL;
      free(removee);
      return head;
    }
    temp = temp -> next;
  }
  return head;
}

struct song_node* random_node(struct song_node* head){
  int size = get_size(head);
  int random = (rand() % size);
  int i;
  for(i = 0; i<random; i++){
    head = head->next;
  }
  return head;
}
