struct song_node * insert_front(struct song_node *head, struct song_node *insertee){
  //int x = ((insertee->name)[0]) - 'a';
  //data += x;
  insertee->next = *data;
  data = insertee;
  return *data;
}

struct song_node * insert_ordered(struct song_node *head, struct song_node *insertee){
  //int x = ((insertee->name)[0]) - 'a';
  //data += x;
  while(!strcmp(insertee->name,head->name)

