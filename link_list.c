struct song_node * insert_front(struct song_node *head, char[] nombre, char[] artista){
  struct song_node *n;
  n->name = nombre;
  n->artist = artista;
  n->next = *head;
  head = n;
  return *head;
}

struct song_node * insert_ordered(struct song_node *head, struct song_node *insertee){
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
  while(head){
    printf("%s : %s |", head->artist, head->name);
    head = head->next;
  }
  return 0;
}

struct song_node * random_node(struct song_node *head){
  
