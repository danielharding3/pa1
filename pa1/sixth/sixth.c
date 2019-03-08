#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	int height;
} node;



/*struct node* insert(node *head, int data) {
	if (data < head->data) {
		head->left = insert(head->left, data);
	} else if (data > head->data) {
		head->right = insert(head->right, data);
	} else {
		return head;
	}
	return head;

}*/


int insert(node *front, int data) {	
	struct node *ptr = front;
	struct node *prev = NULL;
	
	int height = 1;
	
	//inserting into an empty list
	if (front->height == 0) {
		front->left = NULL;
		front->right = NULL;
		front->height = 1;
		front->data = data;
		return 1;
	}
	
	
	struct node *temp = (node*)malloc(sizeof(node));
	
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 0;
	temp->data = data;
	
	
	while (ptr != NULL) {
		
		//no duplicates
		if (ptr->data == temp->data) {
			return 0;
		}
		
		if (ptr->data > temp->data) {
			prev = ptr;
			ptr = ptr->left;
			height++;
			
		} else {
			prev = ptr;
			ptr = ptr->right;
			height++;
		}
		
	}
	
		temp->height = height;
		
		
		if (prev->data > temp->data) {
			prev->left = temp;
			return temp->height;
			
		} else {
			prev->right = temp;
			return temp->height;
		}

		free(temp);
}





void inorder(node *front) {
	if (front == NULL) {
		return;
	}
		inorder(front->left);
		printf("%d\t", front->data);
		inorder(front->right);
	}




int main(int argc, char **argv) {

	FILE *fptr;
	fptr = fopen(argv[1], "r");

	if (fptr == NULL) {
		printf("error\n");
		return 0;
	}

	struct node *front = (node*)malloc(sizeof(node));
	char func;
	int data;
	//int duplicate = 0;
	int height2 = 0;

	while (fscanf(fptr, "%c\t%d\n", &func, &data) != EOF) {
			
		if (func == 'i') {
			/*if (duplicate != data) {
			insert(front, data);
			}*/
			
			height2 = insert(front, data);
			
			if (height2 == 0) {
				continue;
			}
		}

	}
	
	
	inorder(front);

	free(front);
	fclose(fptr);
	return 0;
}
