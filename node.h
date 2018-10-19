
struct song_node {
  char* name;
  char* artist;
  struct song_node* next;
};

void print_list(struct song_node* head);

int get_size(struct song_node* head);

char* convert_lower(char* string);

int songcmp(struct song_node* song1, struct song_node* song2);

struct song_node * insert_front(struct song_node* head, char*name, char* artist);

struct song_node* insert_in_order(struct song_node* head, char* name, char* artist);

struct song_node * free_list(struct song_node* node);

struct song_node* find_song(struct song_node* head, char* name, char* artist);

struct song_node* find_song_by_artist(struct song_node* head, char* artist);

struct song_node* random_node(struct song_node* head);

struct song_node* remove_node(struct song_node* head, struct song_node* node);
