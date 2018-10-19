#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"

int main() {
  //char c;
  //for (c = 'a'; c < 'z'; c++){
  //add_song("hello", "adele");
    /*
    struct song_node *node = NULL;
    node = insert_front(node, c, c);
    lib[i] = node;
    a++;*/
  //}
  struct song_node *head = insert_front(NULL, "baby", "justin beiber");
  head = insert_front(head, "sober", "big bang");
  head = insert_front(head, "hello", "adele");
  printf("added 3 songs:\n");
  print_list(head);

  //find_node(head, "hello", "adele");
  //random_node(head);
  printf("\nremove sober by big bang:\n");
  remove_node(head, "sober", "big bang");
  print_list(head);
  //printf("\nfreeing list\n");
  //free_list(head);
  //print_list(head);

  struct song_node * table[27];
  add_song(table, "kiss","kay");
  //find_song("kiss","kay");
  return 0;
}
