int get_index(char letter);

struct song_node* get_list(char letter);

void print_lib();

void print_letter(char letter);

void add_song(char* name, char * artist);

struct song_node* find_artist(char* artist);

void print_artist(char* artist);

void remove_song(char* name, char* artist);

void shuffle();

void clear();
