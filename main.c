#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "library.h"
#include <unistd.h>
#include "node.h"

int main(){

  printf("Testing insert_in_order & print_list:\n");
  printf("Inserting [Zlion: whoah]\n");
  struct song_node* a = insert_in_order(NULL, "whoah", "Zlion");
  print_list(a);
  printf("Inserting [Xang: skyfu]\n");
  struct song_node* b = insert_in_order(a, "skyfu", "Xang");
  print_list(b);
  printf("Inserting [Yellow: Blacko]\n");
  struct song_node*c = insert_in_order(b, "Blacki", "Yellow");
  print_list(c);
  printf("Inserting [Dark: Edgy]\n");
  struct song_node*d = insert_in_order(c, "Edgy", "Dark");
  print_list(d);
  printf("Inserting [Dark: Edgy in another way]\n");
  struct song_node*e = insert_in_order(d, "Edgy in another way", "Dark");
  print_list(e);
  printf("Inserting [Zback to Z: spanish inquisition]\n");
  struct song_node*f = insert_in_order(e, "spanish inquisition", "Zback to Z");
  print_list(f);
  printf("Inserting [AAA: battery]\n");
  struct song_node*g = insert_in_order(f, "battery", "AAA");
  print_list(g);

  printf("\n=====================\n\n");
  printf("Testing find node:\n");
  printf("FIND AAA|battery: %s\n" , find_song(g, "battery", "AAA") -> name);
  printf("FIND BBB|ball: ");
  if(!find_song(g, "ball", "AAA")) printf("Song Not Found!");
  printf("\n=====================\n\n");

  printf("Testing find_artist:\n");
  printf("Looking for [%s] : ", "Xang");
  print_list( find_song_by_artist(g, "Xang"));
  printf("Looking for [%s] : ", "Zlion");
  print_list( find_song_by_artist(g, "Zlion"));
  printf("\n=====================\n\n");

  printf("Testing Random Node:\n");
  srand(time(NULL));
  struct song_node * random1 = random_node(g);
  printf("Random: %s:%s \n", random1 -> artist, random1 -> name );
  struct song_node * random2 = random_node(g);
  printf("Random: %s:%s \n", random2 -> artist, random2 -> name );
  struct song_node * random3 = random_node(g);
  printf("Random: %s:%s \n", random3 -> artist, random3 -> name );
  printf("\n=====================\n\n");

  printf("Testing Remove Node:\n");
  printf("Removing [%s:%s]:\n", a -> artist, a -> name);
  g = remove_node(g, a);
  print_list(e);
  printf("Removing [%s:%s]:\n", b -> artist, b -> name);
  g = remove_node(g, b);
  print_list(g);
  printf("Removing [%s:%s]:\n", g -> next -> artist, g -> next -> name);
  g = remove_node(g, g->next);
  print_list(g);
  printf("\n=====================\n\n");

  printf("Testing Free_List: ");
  print_list(g);
  g = free_list(g);
  printf("List after free: ");
  print_list(g);
  printf("\n=====================\n\n");

  printf("\n\nMUSIC LIBRARY TEST\n=====================\n\n");

  printf("Testing print_library & add song:\n");
  add_song("flower","tom");
  add_song("bee","bill");
  add_song("Ragdoll","Stuy");
  add_song("Power Rangers","Fittz");
  add_song("Jacket","Cold");
  add_song("King Lear","Hannon");
  add_song("never","in");
  add_song("gonna","tahmid");
  add_song("give","kerwin");
  add_song("you","and me");
  add_song("up","down");
  add_song("NEVER","GONNA");
  add_song("LET","U");
  add_song("DOWN","xd");
  add_song("enough","ALreADy");
  add_song("special","Man");
  add_song("special", "Woman");
  print_lib();
  printf("\n=====================\n\n");

  printf("Testing print_letter:\n");
  printf("A: \n");
  print_letter('A');
  printf("D: \n");
  print_letter('D');
  printf("E: \n");
  print_letter('E');
  printf("\n=====================\n\n");

  printf("Testing Find Artist:\n");
  printf("looking for [Man]\n");
  print_artist("Man");
  printf("looking for [Woman]\n");
  print_artist("Woman");
  printf("looking for [dante]\n");
  print_artist("dante");
  printf("\n=====================\n\n");

  printf("Testing remove_song:\n");
  printf("remove Man: special:\n");
  remove_song("special", "Man");
  print_lib();
  printf("Remove Hannon: King Lear:\n");
  remove_song("King Lear", "Hannon");
  print_lib();
  printf("\n=====================\n\n");

  printf("Testing Shuffle:\n");
  shuffle();
  printf("\n");
  shuffle();
  printf("\n=====================\n\n");

  printf("Testing Clear\n");
  clear();
  printf("Library After Clear: \n");
  print_lib();
  printf("\n=====================\n\n");



}
