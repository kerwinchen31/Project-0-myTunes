#include <stdlib.h>
#include <stdio.h>
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
  struct song_node *head = insert_ordered(NULL, "sober", "big bang");
  head = insert_ordered(head, "hello", "adele");
  head = insert_ordered(head, "baby", "justin beiber");
  print_list(head);

  return 0;
}
