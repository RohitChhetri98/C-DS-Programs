// BINARY SEARCH TREE
#include<stdio.h>
#include<stdlib.h>
typedef struct binary_search_tree{
	int data;
	struct binary_search_tree *left;
	struct binary_search_tree *right;
}node;
node *root=NULL;
node* createNode(int data){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void insert(node *current, node *temp){
	if(root==NULL) root = temp;
	else{
		if(temp->data < current->data){
			if(current->left == NULL) 
				current->left = temp;
			else
				insert(current->left, temp);
		}else{
			if(current->right == NULL)
				current->right = temp;
			else
				insert(current->right, temp);
		}
	}
}
void inOrder(node *current){
	if(current==NULL) return;
	inOrder(current->left);
	printf(" %d |", current->data);
	inOrder(current->right);
}
void preOrder(node *current){
	if(current==NULL) return;
	printf(" %d |", current->data);
	preOrder(current->left);
	preOrder(current->right);
}
void postOrder(node *current){
	if(current==NULL) return;
	postOrder(current->left);
	postOrder(current->right);
	printf(" %d |", current->data);
}
void printTree(node *current, int spaces){
	int i;
	if(current==NULL) return;
	printTree(current->right, spaces+5);
	for(i=1; i<=spaces; i++)
		printf(" ");
	printf(" %d ", current->data);
	printf("\n");
	printTree(current->left, spaces+5);
}
node* minimum(node *current){
	while(current->left!=NULL)	
		current = current->left;
	return current;
}
node* maximum(node *current){
	while(current->right!=NULL)
		current = current->right;
	return current;
}
node* delete(node *current, int data){
	node *temp;
	if(current==NULL) return NULL;
	else{
		if(data < current->data)
			current->left = delete(current->left, data);
		else if(data > current->data)
			current->right = delete(current->right, data);
		else{
			if(current->left==NULL){
				temp = current->right;
				free(current);
				return temp;
			}else if(current->right==NULL){
				temp = current->left;
				free(current);
				return temp;
			}else{
				temp = maximum(current->left);
				current->data = temp->data;
				current->left = delete(current->left, temp->data);
			}
		}
		return current;
	}
}
node* search(node *current, int data){
	node *temp;
	if(current==NULL) return NULL;
	else{
		printf("\n Checking: %d", current->data);
		if(data < current->data)
			temp = search(current->left, data);
		else if(data > current->data)
			temp = search(current->right, data);
		else temp = current;
		return temp;
	}
}
int main(){
	int x;
	node *temp;
	while(1){
		system("cls");
		printf("\n Binary Search Tree");
		printf("\n Menu: 1. Insert 2. Inorder 3. Preorder 4. Postorder 5. Print Tree 6. Delete 7. Search. 8. Find Minimum 9. Find Maximum 0. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("\n Enter element: ");
				scanf("%d",&x);
				temp = createNode(x);
				insert(root, temp);
				break;
			case 2:
				printf("\n Inorder Traversal: ");
				inOrder(root);
				break;
			case 3:
				printf("\n Preorder Traversal: ");
				preOrder(root);
				break;
			case 4:
				printf("\n Postorder Traversal: ");
				postOrder(root);
				break;
			case 5:
				printf("\n Printing Tree: \n");
				printTree(root, 0);
				break;
			case 6:
				printf("\n Enter key to delete: ");
				scanf("%d",&x);
				temp = delete(root, x);
				if(temp==NULL) printf("\n Not Found");
				else printf("\n Deleted.");
				break;
			case 7:
				printf("\n Enter key to search: ");
				scanf("%d",&x);
				temp = search(root, x);
				if(temp==NULL) printf("\n Not found.");
				else printf("\n Found.");
				break;
			case 8:
				temp = minimum(root);
				if(temp==NULL) printf("\n Tree is empty.");
				else printf("\n Minimum = %d", temp->data);
				break;
			case 9:
				temp = maximum(root);
				if(temp==NULL) printf("\n Tree is empty.");
				else printf("\n Maximum = %d", temp->data);
				break;
			case 0:
				exit(0);
				break;
			default: printf("\n Wrong choice.");
		}
		printf("\n Enter any key to continue...");
		scanf("%d", &x);
	}
	return 0;
}
