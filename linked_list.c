#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

struct song_node * insert_front(struct song_node *head, char *song, char *artist) {
	struct song_node *new = malloc(sizeof(struct song_node));
 	strcpy(new->song, song);
 	strcpy(new->artist, artist);
 	new->next = head;
	return new;
}

struct song_node * insert_ordered(struct song_node *head, char *song, char *artist) {
	struct song_node *first = head;
  	if (strcmp(artist, head->artist) < 0 ) {
 		insert_front(head,song,artist);
 	}
 	else {
 		while (head->next) { 
 			if (strcmp(artist, (head->next)->artist) > 0 ) {
    			head = head->next;
  			}
  			else {
  				while (strcmp(song, (head->next)->song) > 0 ) {
      				head = head->next;
      			}
    		}
  		}
  	}
  	struct song_node *new = malloc(sizeof(struct song_node));
 	strcpy(new->song, song);
 	strcpy(new->artist, artist);
 	new->next = (head->next)->next;
 	head->next = new;
	return first;
}

void print_list(struct song_node *head) {
  	while(head)	{
    	printf("|%s by %s |\n", head->song, head->artist);
    	head = head->next;
  	}
}

struct song_node *find_node(struct song_node *head, char *song, char *artist) {
	while (head) {
		if (!strcmp(song, head->song) && !strcmp(artist, head->artist) ) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}


struct song_node * random_node(struct song_node *head) {
	srand( time(NULL) );
	int max = rand();
	struct song_node *temp = head;
	while (max) {
		max--;
		if (!head->next) {
			head = temp;
		}
		head = head->next;
	}
	return head;
}


struct song_node *remove_node(struct song_node *head, char *song, char *artist) {
  struct song_node *first = head; 
  if (head && !strcmp(head->artist, artist) && !strcmp(head->song, song)) {
    head = head->next;
    free(first);
    return head;
  }
  struct song_node *temp = head; 
  struct song_node *more_back = head;
  while (temp) {
    if (strcmp(temp->artist, artist) || strcmp(temp->song, song)) {
      more_back = temp;
      temp = temp->next;
    } 
    else {
      break;
    }
  }
  if (temp) {
    if (!(temp->next)) {
      more_back->next = NULL;
      free(temp);
      temp = NULL;
    } 
    else {
      more_back->next = temp->next;
    }
  } 
  else {
    printf("%s by %s doesn't exist\n", song, artist);
  }
  return head;
}
/*
struct song_node * free_list(struct song_node *head) {
	struct song_node *temp; 
	while (head) {
		temp = head->next; 
		free(head);
		head = NULL;
		head = temp;
	}
	return head;
}
*/

struct song_node * free_list(struct song_node *head) {
	struct song_node *temp; 
	while (head) {
		temp = head; 
		head = head->next;
		free(temp);
		temp = NULL;
	}
	return head;
	}/*
struct song_node * free_list(struct song_node *head) {
  struct song_node *temp; 
  while (head) {
    temp = head; 
    head->song = NULL;
    head->artist = NULL;
    head->next = NULL;
    head = NULL;
    free(head);
    head = temp->next;
  }
  return head;
}
	   */
