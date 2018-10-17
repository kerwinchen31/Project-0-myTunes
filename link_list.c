struct song_node * insert_front(struct song_node *head, char[] nombre, char[] artista){
  struct song_node *n;
  n->name = nombre;
  n->artist = artista;
  //int x = ((insertee->name)[0]) - 'a';
  //data += x;
  n->next = *head;
  head = n;
  return *head;
}

struct song_node * insert_ordered(struct song_node *head, struct song_node *insertee){
  //int x = ((insertee->name)[0]) - 'a';
  //data += x;
  while(strcmp(insertee->artist, head->artist) > 0 ) {
    head = head->next;
  }
  if(!strcmp(insertee->artist, head->artist)){
    while(strcmp(insertee->name, head->name) > 0 ) {
      head = head->next;
    }
  }
  return song_node * insert_front(head, insertee);
}

int print_list(struct song_node *head){
  while(head->next){
    printf("%s : %s |", head->artist, head->name);
  }
  return 0;
}

