#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pair {
	const char *key;
	void *value;
	size_t size;
	int shard;
} Pair;

void dump_pair(Pair *pair, char *sep) {
	if(pair == NULL) return;
	printf("%s => %d[size:%lu;shard:%d]%s", pair->key, *((int *) pair->value), pair->size, pair->shard, sep);
}

typedef long(*HashFunc)(const char *);

int cmp_pair_key(Pair *p1, const char *key) {
	return strcmp(p1->key, key);
}

int cmp_pairs(Pair *p1, Pair *p2) {
	return cmp_pair_key(p1, p2->key);
}

Pair *new_pair(const char *key, void *value, size_t size, HashFunc hash_func, int shards) {
	//printf("new_pair(key:%s, value:%d, size:%lu, shards:%d)\n", key, *((int *)value), size, shards);
	Pair *new	= malloc(sizeof(Pair));
	new->size	= size;
	new->shard	= hash_func(key) % shards;
	new->key	= key;
	new->value	= malloc(size);
	memcpy(new->value, value, size);
	return new;
}

void delete_pair(Pair *pair) {
	free(pair->value);
}

typedef struct _node {
	Pair *pair;
	struct _node *left;
	struct _node *right;
} Node;

void dump_node(Node *node) {
	if(node == NULL) return;
	printf("[\n");
	dump_pair(node->pair, "\n");
	printf(" -> ");
	dump_node(node->left);
	printf(", ");
	dump_node(node->right);
	printf("]\n");
}

Node *new_node(Pair *pair) {
	//printf("new_node()\n");
	Node *new	= malloc(sizeof(Node));
	new->pair	= pair;
	new->left	= NULL;
	new->right	= NULL;
	return new;
}

int cmp_node_key(Node *n1, const char* key) {
	return cmp_pair_key(n1->pair, key);
}

int cmp_nodes(Node *n1, Node *n2) {
	return cmp_pairs(n1->pair, n2->pair);
}

void add_to_tree(Node **root, Node *node) {
	if(*root == NULL) {
		*root = node;
		return;
	}
	int cmp = cmp_nodes(*root, node);
	if(cmp == 0) {
		node->left	= (*root)->left;
		node->right	= (*root)->right;
		free(*root);
		*root = node;
	} else if(cmp > 0) {
		if((*root)->left == NULL) {
			(*root)->left = node;
		} else {
			add_to_tree(&((*root)->left), node);
		}
	} else {
		if((*root)->right == NULL) {
			(*root)->right = node;
		} else {
			add_to_tree(&((*root)->right), node);
		}
	}
}

Node *search_on_tree(Node *root, const char* key) {
	if(root == NULL) {
		return NULL;
	}
	int cmp = cmp_node_key(root, key);
	if(cmp > 0) return search_on_tree(root->left, key);
	else if(cmp < 0) return search_on_tree(root->right, key);
	else return root;
}

typedef struct _hash {
	int size;
	Node **nodes;
	HashFunc hash_func;
} Hash;

void dump_hash(Hash *hash) {
	printf("{\n");
	for(int i = 0; i < hash->size; i++) {
		if(*(hash->nodes + i) != NULL) dump_node(*(hash->nodes + i));
	}
	printf("}\n");
}

Hash *new_hash(int size, HashFunc hash_func) {
	//printf("new_hash(size:%d)\n", size);
	Hash *new	= malloc(sizeof(Hash));
	new->hash_func	= hash_func;
	new->nodes	= malloc(sizeof(Node *) * size);
	new->size	= size;
	memset(new->nodes, 0, size);
	return new;
}

long default_hash_func(const char *key) {
	long sum = 0;
	for(int i = 0; key[i] != 0; i++) {
		sum += i * key[i];
	}
	return sum;
}

Hash *new_hash_default_hash_func(int size) {
	//printf("new_hash_default_hash_func(size:%d)\n", size);
	return new_hash(size, default_hash_func);
}

void set(Hash *hash, const char *key, void *value, size_t size) {
	//printf("set(key:%s, value:%d, size:%lu)\n", key, *((int *)value), size);
	Pair *npair = new_pair(key, value, size, hash->hash_func, hash->size);
	//dump_pair(npair, "\n");
	Node *nnode = new_node(npair);
	//dump_node(nnode);
	add_to_tree(hash->nodes + npair->shard, nnode);
	//dump_hash(hash);
}

Pair *get(Hash *hash, const char *key) {
	//printf("get(key:%s)\n", key);
	HashFunc hash_func = hash->hash_func;
	int shard = hash_func(key) % hash->size;
	//dump_node(*(hash->nodes + shard));
	Node *node = search_on_tree(*(hash->nodes + shard), key);
	//dump_node(node);
	if(node == NULL) {
		printf("key '%s' not found", key);
		return NULL;
	}
	return node->pair;
}

typedef struct _stack {
	Node		*val;
	struct _stack	*next;
} Stack;

void push(Stack **stack, Node *new) {
	Stack *next	= (*stack)->next;
	*stack		= malloc(sizeof(Node));
	(*stack)->next	= next;
}

Node *pop(Stack **stack) {
	Stack *last	= *stack;
	Node *last_val	= last->val;
	*stack		= (*stack)->next;
	free(last);
	return last_val;
}

typedef struct _tree_iterator {
	Stack	*stack;
	Node	*current;
} TreeIterator;

TreeIterator *new_tree_iterator(Node *node) {
	if(!node) return NULL;
	TreeIterator *new	= malloc(sizeof(TreeIterator));
	new->stack		= NULL;
	new->current		= node;
	return new;
}

Node *tree_next(TreeIterator *iterator) {
	printf("2.9.1");
	if(!iterator) return NULL;
	printf("2.9.2");
	while(iterator->current != NULL) {
	printf("2.9.3");
		push(&(iterator->stack), iterator->current);
	printf("2.9.4");
		iterator->current = iterator->current->left;
	printf("2.9.5");
	}
	printf("2.9.6");
	Node *node = pop(&(iterator->stack));
	printf("2.9.7");
	iterator->current = node->right;
	printf("2.9.8");
	return node;
}

int tree_has_next(TreeIterator *iterator) {
	return iterator != NULL && (iterator->stack != NULL || iterator->current != NULL);
}

typedef struct _hash_iterator {
	Hash		*hash;
	int		shard;
	TreeIterator	*tree_iterator;
} HashIterator;

HashIterator *new_hash_iterator(Hash *hash) {
	HashIterator *new	= malloc(sizeof(HashIterator));
	new->hash		= hash;
	new->shard = 0;
	new->tree_iterator = new_tree_iterator(*(hash->nodes));
	return new;
}

Pair *hash_next(HashIterator *iterator) {
	printf("2.1\n");
	if(iterator == NULL) return NULL;
	printf("2.2\n");
	if(iterator->tree_iterator == NULL || !tree_has_next(iterator->tree_iterator)) {
	printf("2.3\n");
		if(iterator->tree_iterator)
	printf("2.4\n");
			free(iterator->tree_iterator);
	printf("2.5\n");
		while(*(iterator->hash->nodes + ++(iterator->shard)) == NULL && iterator->shard < iterator->hash->size);
	printf("2.6\n");
		if(iterator->shard >= iterator->hash->size)
			return NULL;
	printf("2.7\n");
		iterator->tree_iterator = new_tree_iterator(*(iterator->hash->nodes + iterator->shard));
	printf("2.8\n");
	}
	printf("2.9\n");
	Node *node = tree_next(iterator->tree_iterator);
	printf("2.10\n");
	dump_node(node);
	printf("2.11\n");
	return node->pair;
}

int hash_has_next(HashIterator *iterator) {
	if(!iterator) return 0;
	if(!tree_has_next(iterator->tree_iterator)) {
		free(iterator->tree_iterator);
		while(*(iterator->hash->nodes + ++(iterator->shard)) == NULL && iterator->shard < iterator->hash->size);
		if(iterator->shard >= iterator->hash->size)
			return 0;
		iterator->tree_iterator = new_tree_iterator(*(iterator->hash->nodes + iterator->shard));
	}
	return tree_has_next(iterator->tree_iterator);
}

int main() {
	Hash *hash = new_hash_default_hash_func(50);
	int val1 = 42;
	int val2 = 43;
	int val3 = 44;
	int val4 = 50;
	set(hash, "bla", (void *)&val1, sizeof(int));
	set(hash, "ble", (void *)&val2, sizeof(int));
	set(hash, "bli", (void *)&val3, sizeof(int));
	set(hash, "bli", (void *)&val3, sizeof(int));
	set(hash, "bli", (void *)&val4, sizeof(int));
	//dump_hash(hash);
	printf("hash{%s} == %d\n", "bla", *((int *)get(hash, "bla")->value));
	printf("hash{%s} == %d\n", "ble", *((int *)get(hash, "ble")->value));
	printf("hash{%s} == %d\n", "bli", *((int *)get(hash, "bli")->value));
	HashIterator *it = new_hash_iterator(hash);
	printf("1\n");
	while(hash_has_next(it)) {
	printf("2\n");
		Pair *pair = hash_next(it);
	printf("3\n");
		printf("%s: %d\n", pair->key, *((int *)pair->value));
	printf("4\n");
	}
	printf("the end\n");
}
