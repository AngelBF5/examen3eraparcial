#include <stdio.h>
#include <stdlib.h>

int level = 0;

struct node{
	struct node* left_child;
	struct node* right_child;
	
	int data;
};

struct node* newNode(int data){
	size_t node_size = sizeof(struct node);
	struct node* new_Node = (struct node*) malloc(node_size);
	new_Node -> data = data;
	new_Node -> left_child = NULL;
	new_Node -> right_child = NULL;
	
	return new_Node;
}
	
	void insertNode(struct node* nd, int data){
		if(data>nd->data){
			if(nd->right_child==NULL){
				nd->right_child=newNode(data);
			}else{
				insertNode(nd->right_child,data);
			}
		}else{
			if(nd->left_child==NULL){
				nd->left_child=newNode(data);
			}else{
				insertNode(nd->left_child,data);
			}
		}
	}
		
		void SearchNode(struct node* nd, int num){
			level++;
			if(num == nd->data){
				printf("\nEl numero %d si esta en el arbol\nSe encunetra en el nivel %d \n", num, level);
			}else if(num < nd->data && nd->left_child != NULL){
				SearchNode(nd->left_child, num);
			}else if(num > nd->data && nd->right_child != NULL){
				SearchNode(nd->right_child, num);
			}else{
				printf("Número no encontrado. \n");
			}
		}
			
			int main(){
				int num=0;
				struct node* raiz=NULL;
				raiz=newNode(6);
				insertNode(raiz,5);
				insertNode(raiz,11);
				insertNode(raiz,4);
				insertNode(raiz,8);
				insertNode(raiz,12);
				insertNode(raiz,3);
				insertNode(raiz,9);
				insertNode(raiz,21);
				
				printf("Ingrese el numero que desea buscar: \n");
				scanf("%d", &num);
				
				SearchNode(raiz,num);
				
				return 0;
			}
