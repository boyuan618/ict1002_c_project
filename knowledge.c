/*
 * ICT1002 (C Language) Group Project.
 *
 * This file implements the chatbot's knowledge base.
 *
 * knowledge_get() retrieves the response to a question.
 * knowledge_put() inserts a new response to a question.
 * knowledge_read() reads the knowledge base from a file.
 * knowledge_reset() erases all of the knowledge.
 * knowledge_write() saves the knowledge base in a file.
 *
 * You may add helper functions as necessary.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chat1002.h"



/*
 * Get the response to a question.
 *
 * Input:
 *   intent   - the question word
 *   entity   - the entity
 *   response - a buffer to receive the response
 *   n        - the maximum number of characters to write to the response buffer
 *
 * Returns:
 *   KB_OK, if a response was found for the intent and entity (the response is copied to the response buffer)
 *   KB_NOTFOUND, if no response could be found
 *   KB_INVALID, if 'intent' is not a recognised question word
 */
int knowledge_get(const char *intent, const char *entity, char *response, int n) {
  // 3 linked list, one for each of the WHO WHERE WHAT

  // WHO
  // printf("1\n");
  // printf("%s\n", intent);
  // printf("%s\n", entity);
  // debug ^
  if (compare_token(intent, "who") == 0){
    //ptr to head of the linked list
    who_ptr = head_who;
    while (who_ptr != NULL){
      // if node with same entity exists, strncpy to response
      if (compare_token(who_ptr->entity,entity) == 0){
        // printf("%p", who_ptr);
        // this was for debugging
        strncpy(response, who_ptr->response, n);
        return KB_OK;
      }
      // implicit else, iterate through the linked list
      who_ptr = who_ptr->next;
    }
    // if cannot find the same entity match or header = NULL
    // (linked list doesnt exist) return KBnotfound
    return KB_NOTFOUND;
  } 

  // WHAT
  else if (compare_token(intent, "what") == 0){
    //ptr to head of the linked list
    what_ptr = head_what;
    while (what_ptr != NULL){
      // if node with same entity exists, strncpy to response
      if (compare_token(what_ptr->entity,entity) == 0){
        strncpy(response, what_ptr->response, n);
        return KB_OK;
      }
      // implicit else, iterate through the linked list
      what_ptr = what_ptr->next;
    }
    // if cannot find the same entity match or header = NULL
    // (linked list doesnt exist) return KBnotfound
    return KB_NOTFOUND;
  }
	
  // WHERE
  else if (compare_token(intent, "where") == 0){
    //ptr to head of the linked list
    where_ptr = head_where;
    while (where_ptr != NULL){
      // if node with same entity exists, strncpy to response
      if (compare_token(where_ptr->entity,entity) == 0){
        strncpy(response, where_ptr->response, n);
        return KB_OK;
      }
      // implicit else, iterate through the linked list
      where_ptr = where_ptr->next;
    }
    // if cannot find the same entity match or header = NULL
    // (linked list doesnt exist) return KBnotfound
    return KB_NOTFOUND;
  }

  // if no intent, return INVALID state
	else return KB_INVALID;

}


/*
 * Insert a new response to a question. If a response already exists for the
 * given intent and entity, it will be overwritten. Otherwise, it will be added
 * to the knowledge base.
 *
 * Input:
 *   intent    - the question word
 *   entity    - the entity
 *   response  - the response for this question and entity
 *
 * Returns:
 *   KB_FOUND, if successful (OK, as FOUND not defined)
 *   KB_NOMEM, if there was a memory allocation failure
 *   KB_INVALID, if the intent is not a valid question word
 */
int knowledge_put(const char *intent, const char *entity, const char *response) {

  // WHO
  if (compare_token(intent, "who") == 0){
    //ptr to head of the linked list
    who_ptr = head_who;
    while (who_ptr != NULL){
      // if node with same entity exists, overwrite
      if (compare_token(who_ptr->entity,entity) == 0){
        strcpy(who_ptr->response, response);
        return KB_OK;
      }
      if (who_ptr->next == NULL) {
        //last item already, to append.
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) {
          return KB_NOMEM;
        } else {
        strcpy(newnode->response, response);
        strcpy(newnode->entity, entity);
        strcpy(newnode->intent, intent);
        newnode->next = NULL;
        who_ptr->next = newnode;
        return KB_OK;
        }
      }
      // implicit else, iterate through the linked list
      who_ptr = who_ptr->next;
    }
    if (head_who == NULL) {
      //the linked list is empty
      node *newnode = (node *)malloc(sizeof(node));
      if(newnode == NULL) {
        return KB_NOMEM;
      } else {
      strcpy(newnode->response, response);
      strcpy(newnode->entity, entity);
      strcpy(newnode->intent, intent);
      newnode->next = NULL;
      head_who = newnode;
      return KB_OK;
      }
    }
  } 

  // WHAT
  else if (compare_token(intent, "what") == 0){
    //ptr to head of the linked list
    what_ptr = head_what;
    while (what_ptr != NULL){
      // if node with same entity exists, overwrite
      if (compare_token(what_ptr->entity,entity) == 0){
        strcpy(what_ptr->response, response);
        return KB_OK;
      }
      if (what_ptr->next == NULL) {
        //last item already, to append.
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) {
          return KB_NOMEM;
        } else {
        strcpy(newnode->response, response);
        strcpy(newnode->entity, entity);
        strcpy(newnode->intent, intent);
        newnode->next = NULL;
        what_ptr->next = newnode;
        return KB_OK;
        }
      }
      // implicit else, iterate through the linked list
      what_ptr = what_ptr->next;
    }
    if (head_what == NULL) {
      //the linked list is empty
      node *newnode = (node *)malloc(sizeof(node));
      if(newnode == NULL) {
        return KB_NOMEM;
      } else {
      strcpy(newnode->response, response);
      strcpy(newnode->entity, entity);
      strcpy(newnode->intent, intent);
      newnode->next = NULL;
      head_what = newnode;
      return KB_OK;
      }
    }
  }
	
  // WHERE
  else if (compare_token(intent, "where") == 0){
    //ptr to head of the linked list
    where_ptr = head_where;
    while (where_ptr != NULL){
      // if node with same entity exists, overwrite
      if (compare_token(where_ptr->entity,entity) == 0){
        strcpy(where_ptr->response, response);
        return KB_OK;
      }
      if (where_ptr->next == NULL) {
        //last item already, to append.
        node *newnode = (node *)malloc(sizeof(node));
        if(newnode == NULL) {
          return KB_NOMEM;
        } else {
        strcpy(newnode->response, response);
        strcpy(newnode->entity, entity);
        strcpy(newnode->intent, intent);
        newnode->next = NULL;
        where_ptr->next = newnode;
        return KB_OK;
        }
      }
      // implicit else, iterate through the linked list
      where_ptr = where_ptr->next;
    }
    if (head_where == NULL) {
      //the linked list is empty
      node *newnode = (node *)malloc(sizeof(node));
      if(newnode == NULL) {
        return KB_NOMEM;
      } else {
      strcpy(newnode->response, response);
      strcpy(newnode->entity, entity);
      strcpy(newnode->intent, intent);
      newnode->next = NULL;
      head_where = newnode;
      }
    }
  }

  // if no intent, return INVALID state
	return KB_INVALID;

}


/*
 * Read a knowledge base from a file.
 *
 * Input:
 *   f - the file
 *
 * Returns: the number of entity/response pairs successful read from the file
 */
int knowledge_read(FILE *f) {
	/* to be implemented */
  int valid_lines;
  // intent, entity, response array
  char intent[MAX_INPUT], entity[MAX_ENTITY], response[MAX_RESPONSE];
  size_t buf_size = MAX_RESPONSE + MAX_ENTITY + 1;
  // dynamic mem alloc
  char *buffer1 = (char *)malloc(buf_size * sizeof(char));
  // for token
  char *token;
  //while(getline(&buffer1, &buf_size, f) != KB_NOTFOUND){
  while(!feof(f)){
    // if what is detected while reading the lines, set the intent to WHAT
    fgets(buffer1, (int)buf_size, f);
    if (strstr(buffer1, "what")){
      strcpy(intent, "what");
    } 
    else if (strstr(buffer1, "where")){
      strcpy(intent, "where");
    }
    else if (strstr(buffer1, "who")){
      strcpy(intent, "who");
    }

    // now need to obtain entity/response pairs and call knowledge_put
    // in order to insert into the knowledge_put linked list
    if (strchr(buffer1, '=')){
      // first token entity
      token = strcpy(entity, strtok(buffer1, "="));
      // second token response
      // move on to second token
      token = strtok(NULL, "=");
      // remove trailing new line
      token[strcspn(token, "\n")] = 0;
      strcpy(response, token);
      knowledge_put(intent, entity, response);
      // update validlines count
      valid_lines++;
    }
  } 
  free(buffer1);


	return valid_lines;
}


/*
 * Reset the knowledge base, removing all know entitities from all intents.
 */
void knowledge_reset() {
	if (head_what != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_what;
    while (travel_ptr != NULL){
      head_what = travel_ptr;
      travel_ptr = travel_ptr->next;
      free(head_what);
    }
  }

	if (head_who != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_who;
    
    while (travel_ptr != NULL){
      head_who = travel_ptr;
      travel_ptr = travel_ptr->next;
      free(head_who);
    }
  }

	if (head_where != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_where;

    while (travel_ptr != NULL){
      head_where = travel_ptr;
      travel_ptr = travel_ptr->next;
      free(head_where);
    }
  }
}


/*
 * Write the knowledge base to a file.
 *
 * Input:
 *   f - the file
 */
void knowledge_write(FILE *f) {

	if (head_what != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_what;
    fprintf(f,"[what]\n");

    while (travel_ptr != NULL){
      //in the format entity=value
      if (travel_ptr->response[0] != '\0') {
        fprintf(f,"%s=%s\n", travel_ptr->entity, travel_ptr->response);
      }
      travel_ptr = travel_ptr->next;
    }
  }
	if (head_who != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_who;
    fprintf(f,"[who]\n");

    while (travel_ptr != NULL){
      //in the format entity=value
      if (travel_ptr->response[0] != '\0') {
        fprintf(f,"%s=%s\n", travel_ptr->entity, travel_ptr->response);
      }
      travel_ptr = travel_ptr->next;
    }
  }

	if (head_where != NULL){
    //create ptr to travel the linked list
    node *travel_ptr = head_where;
    fprintf(f,"[where]\n");

    while (travel_ptr != NULL){
      //in the format entity=value
      if (travel_ptr->response[0] != '\0') {
        fprintf(f,"%s=%s\n", travel_ptr->entity, travel_ptr->response);
      }
      travel_ptr = travel_ptr->next;
    }
  }
}
