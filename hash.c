#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define HASH_SIZE 50;

int hash_size = HASH_SIZE;

struct sPair{
   char         * key;
   void         * value;
   struct sPair * next;
   int            exists;
};
typedef struct sPair Pair;

Pair * hash[];

void print_pair(Pair * p, char * ident) {
   printf("%s- key   :   [%s]\n%s- value:   [%x]\n", ident, p->key, ident, p->value);
   if(p->next != NULL) print_pair(p->next, "   ");
}

void hash_dump() {
   int i;
   for(i = 0; i < hash_size; i++) {
      printf("hash[%d]:\n", i);
      print_pair(hash[i], "   ");
   }
}

int hash_func(char * key) {
   int i, sum = 0;
   int count = 1;
   for(i = 0; i < strlen(key); i++) {
      sum += key[i] * count++;
   }
   count = 1;
   return sum % hash_size;
}

Pair* insert_on_list(Pair ** list, Pair * new_pair){
	char * key  = new_pair->key;
	if(!(*list)->exists) {
		*list = new_pair;
		(*list)->exists = 1;
		return *list;
	}
	char * lkey = (*list)->key;
	if(strcmp(lkey, key) > 0) {
		Pair * tmp;
		tmp = *list;
		*list = new_pair;
		new_pair->exists = 1;
		new_pair->next = tmp;
		
		return new_pair;
	} else if(strcmp(lkey, key) < 0) {
			if((*list)->next == NULL)
			{
				(*list)->next = new_pair;
				new_pair->exists = 1;
				return new_pair;
			}
			else
			{
				new_pair->exists = 1;
				return insert_on_list(&((*list)->next), new_pair);
			}
	} else
	{
		(*list)->value = new_pair->value;
		return *list;
	}
}

Pair* insert_hash(char * key, void * value){

  int iKey = hash_func(key);
  //printf("iKey: [%d]\n", iKey);

  Pair * new_pair = malloc(sizeof(Pair));

  new_pair->key   = key;
  new_pair->value = value;

  //printf("key: [%s]; value: [%s]\n", new_pair->key, (char*)new_pair->value);
  
  //printf("hash[%d]: %x\n", iKey, hash[iKey]);
  Pair * inserted = insert_on_list(&hash[iKey], new_pair);
  //printf("hash[%d]: %x\n", iKey, hash[iKey]);
  
  return hash[iKey];
}

Pair* find_on_list(Pair* list, char * key){
	//printf("list: %x\n", list);
	Pair * actual = list;
	while(actual && strcmp(key, actual->key) > 0) {
		//printf("actual: [%s]\n", actual->key);
		actual = actual->next;
	}
	if(strcmp(actual->key, key) != 0) {
	   return (Pair *) NULL;
	}
	return actual;
}

void * find_on_hash(char* key){
	int ikey;
	ikey = hash_func(key);
	Pair* actual = find_on_list(hash[ikey], key);
	if(!actual) return (void *) NULL;
	return actual->value;
}

int create_hash(size){
   int total_size = hash_size = size;
   
   int i;
   for(i = 0; i < total_size; i++) {
   	  hash[i] = (Pair *) malloc(sizeof(Pair));
          memset(hash[i], 0, sizeof(Pair));
   }
   return total_size;
}

main() {
   create_hash(25);
   insert_hash("Blableblibloblu", (void *)"Valor do hash");
   insert_hash("Bleblablibloblu", (void *)"Valor 2 do hash");
   insert_hash("Blableblibloblu", (void *)"Valor 3 do hash");
   int num = 42;
   insert_hash("resposta", (void *)&num);
//hash_dump();

   printf("Valor na posicao 'Blableblibloblu': %s\n", (char *)find_on_hash("Blableblibloblu"));
   int * num_ptr = (int *)find_on_hash("resposta");
   printf("Valor na posicao 'resposta': %d\n", * num_ptr);
}

