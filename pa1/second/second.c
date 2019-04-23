#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
} node;



//malloc for creating new node
node *createNewNode(int data, node *front) {
	struct node *createNewNode = malloc(sizeof(node));
	createNewNode->data = data;
	createNewNode->next = front;
	return createNewNode;
	//free(createNewNode);
}
	
int search(int data, node *front) {
	
	struct node *ptr = front;
	
	while (ptr != NULL) {
		
		if (ptr->data == data) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

node *delete(int data, node *front) {
		
		//nothing to delete
		if (front == NULL) {
			return front;
		}
		
		//delete first node in list
		if (front->data == data) {
			
			//list is only one node
			if (front->next == NULL) {
				front = front->next;
				return front;
			}
			
			front = front->next;
		}
		
		
		struct node *ptr = front->next;
		struct node *prev = front;
		
		//delete node in middle of list
		while (ptr != NULL) {
			
			//found target node
			if (ptr->data == data) {
				prev->next = ptr->next;
			}
			
			prev = ptr;
			ptr = ptr->next;
		}
		
		
		return front;
	}
	
	
	
int lengthOfLL(node *front) {

		
		//list is empty
		if (front == NULL) {
			return 0;
		}
		
		
		struct node *ptr = front;
		int count = 0;
		
		while (ptr != NULL) {
			ptr = ptr->next;
			count++;
		}
		
		
		return count;
	}
	
	
	
node *sortAscending(node *front) {
		
		int temp;
		struct node *ptr;
		struct node *least;
		
		struct node *prev = front;
		
		while (prev != NULL) {
			ptr = prev->next;
			least = prev;
			
			while (ptr != NULL) {
				
				if (ptr->data < least->data) {
					least = ptr;
				}
				
				ptr = ptr->next;
			}
			
			//swap values
			temp = prev->data;
			prev->data = least->data;
			least->data = temp;
			
			
			prev = prev->next;
		}
		
		return front;
	}
	
	
int main(int argc, char** argv) {
	
	struct node *front = NULL;
	struct node *ptr = NULL;
	
	int num;
	char func;
	int count;
	int bool;
	int x = 0;
	
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	
	//file doesn't exist
	if (fptr == NULL) {
		printf("error\n");
		return 0;
	}
	
	
	while (fscanf(fptr, "%c\t%d\n", &func, &num) != EOF) {
		bool = search(num, front);
		if (func == 'i') {
			if (bool == 1) {
				x++;
				continue;
			}
			front = createNewNode(num, front);
			
		} else if (func == 'd') {
			front = delete(num, front);
		}
	}
	
	ptr = front;
	count = lengthOfLL(ptr) + x;
	
	//linked list is empty
	if (count == 0) {
		printf("%d\n", count);
		return (0);
	}
	
		printf("%d\n", count);
	
		front = sortAscending(front);
			
	while (ptr != NULL) {
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	
	
	fclose(fptr);
	
		
	free(front);
	return 0;
}



		//ptr = front;

	/*while (point != NULL) {
		while (prev != NULL) {
			if (point->data == prev->data) {
					delete(prev->data, point);
					}
					prev = prev->next;
				}
				point = point->next;
			}
			*/



/*
typedef struct node Node;

struct Node {
	int data;
	Node *next;
};


void insert(Node front, int data) {
	Node temp;
	temp = (Node *)malloc(sizeof( Node));
	temp->data = data;
	temp->next = NULL;
	front->next = temp;
	
}
*/



/*
int main(int argc, char **argv) {

FILE *fptr;
char *filename = argv[1];
fptr = fopen(filename, "r");
int number;
char character;
//int numsread;

Node *front = NULL;
Node *ptr = NULL;
Node *prev = NULL;

while (!feof(fptr)) {
*/
/*int numsread = */
/*
fscanf(fptr, "%c\t%d", &character, &number);

if (character == 'i') {

}
//printf("%c\t%d\n", character, number);



}

fclose(fptr);
return 0;
}
*/
