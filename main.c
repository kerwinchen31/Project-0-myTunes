#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "music_library.h"

int main() {
  struct song_node *lib[27];
  int i;
  char c = 'a';
  for (i = 0; i < 27; i++){
    struct song_node *node = NULL;
    node = insert_front(node, c, c);
    lib[i] = node;
    a++;
  }

  
}
