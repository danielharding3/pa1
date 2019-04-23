#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int data;
	struct node* next;
} node;



typedef struct hashTable {
	int size;
	struct node **list;
} hashTable;



hashTable *createHashTable(int size) {
	int i;
	
	struct hashTable *table = (struct hashTable*)malloc(size*sizeof(struct node*));
	
	table->size = size;
	
	table->list = malloc(size*sizeof(struct node*));
		
	for (i = 0; i < size; i++) {
		table->list[i] = NULL;
	}
	
	return table;
	//free(table);
}

node *createNewNode(int data, struct node *front) {
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = front;
	front = temp;
	
	return front;
	//free(temp);
}

int search(struct hashTable *table, int num) {
	
	int key;
	
	if (num < 0) {
		key = (num* - 1) % table->size;
		
	} else {
		key = num % table->size;
	}
	
	if (table->list[key] == NULL) {
		return 0;
	}
	
	if (table->list[key]->data == num) {
		return 1;
	}
	
	struct node *ptr = table->list[key];
	
	
	while (ptr->next != NULL) {
		if (ptr->next->data == num) {
			return 1;
		}
		
		ptr = ptr->next;
	}
	
	return 0;
} 

int insert(struct hashTable *table, struct node *temp) {
	int key;
	int data = temp->data;

	if (data < 0) {
		key = (data* - 1) % table->size;
	} else {
		key = data % table->size;
	}
	
	
	//struct node *ptr;
	
	
	if (table->list[key] == NULL) {
		table->list[key] = temp;
		return 1;
	}
	
	if (table->list[key]->data == data) {
		return 0;
	}
	
	struct node *ptr;
	
	ptr = table->list[key];
	
	
	while (ptr->next != NULL) {
		if (ptr->next->data == data) {
			return 0;
		}
		
		ptr = ptr->next;
	}
	
	
	ptr->next = temp;
	
	return 1;
}




int main(int argc, char** argv) {

	FILE *fptr;
	fptr = fopen(argv[1], "r");
	
	if (fptr == NULL) {
		printf("error\n");
		return 0;
	}
	
	
	char func;
	int num;
	
	int bool1;
	int bool2;
	
	struct node *temp = NULL;
	
	struct hashTable *table = createHashTable(10000);
	
	int collisions = 0;
	int searches = 0;
	
	
	while (fscanf(fptr, "%c\t%d\n", &func, &num) != EOF) {
		if (func == 'i') {
			temp = NULL;
			temp = createNewNode(num, temp);
			bool1 = insert(table, temp);
			
			if (bool1 == 0) {
				collisions++;
			}
		}
		
		
		if (func == 's') {
			bool2 = search(table, num);
			
			if (bool2 == 1) {
				searches++;
			}
		}
	}
	
	
		printf("%d\n%d", collisions, searches);
		


	
	fclose(fptr);
	free(table);
	free(temp);
	return 0;
}
