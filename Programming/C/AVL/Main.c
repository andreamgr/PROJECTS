#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *tree;
	struct node *right;
	struct node *left; //izq
	int data;
    int heightTree;
};

int heightTree(struct node *N) { 
    if (N== NULL) 
    return 0; 
    return N->heightTree; 
} 

int max (int a, int b){
    return a > b ? a: b;
}
void rightRotation ( struct node **tree){
    struct node *temp = (*tree)->left;
    (*tree)->left = temp -> right;
    temp -> right = (*tree);

    (*tree)->heightTree = max(heightTree((*tree)->left), heightTree((*tree)->right))+1;
    temp->heightTree = max(heightTree(temp->left),heightTree(temp->right))+1;

    (*tree) = temp;
}
void leftRotation ( struct node **tree){
    struct node *temp = (*tree)->right;
    (*tree)->right = temp -> left;
    temp -> left = (*tree);

    (*tree)->heightTree = max(heightTree((*tree)->left), heightTree((*tree)->right))+1;
    temp->heightTree = max(heightTree(temp->left),heightTree(temp->right))+1;

    (*tree) = temp;
}

//BALANCEAR

int balance(struct node *N){
   if (N == NULL) 
        return 0; 
    return heightTree(N->left) - heightTree(N->right); 
}


//INSERTA

struct node *insertTree (struct node *tree, int value){
    if (tree == NULL)
        //(*tree) -> left = (*tree)->right = NULL;
        //create_node(&(*tree));
       // return (create_node(tree, value));
    if (value < tree-> data){
        insertTree(&((tree)->left), value);
       
    }else if (value > tree-> data){
        insertTree(&((tree)->right), value);
       
    }else
    return tree;
    tree->heightTree=max(heightTree(tree->left), heightTree(tree->right))+1;

    int b = balance(tree);
     if (b > 1 && value < tree->left->data) 
        rightRotation(&(tree)); 
  
    // Right Right Case 
    if (b < -1 && value > tree->right->data) 
        leftRotation(&(tree));
  
    // Left Right Case 
    if (b> 1 && value > tree->left->data) 
    { 
        leftRotation(&((tree)->left));
        rightRotation(&(tree));
        //(*tree)->left =  leftRotation((*tree)->left); 
        //rightRotation(*tree); 
    } 
  
    // Right Left Case 
    if (b < -1 && value < tree->right->data) 
    { 
        // C program to construct an expression tree  
// from prefix expression 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 1024
  
// Represents a node of the required tree 
typedef struct node { 
    char data; 
    struct node *left, *right; 
} node; 
  
// Function to recursively build the expression tree 
char* add(node** p, char* a) 
{ 
  
    // If its the end of the expression 
    if (*a == '\0') 
        return NULL; 
  
    while (1) { 
        char* q = "null"; 
        if (*p == NULL) { 
  
            // Create a node with *a as the data and 
            // both the children set to null 
            node* nn = (node*)malloc(sizeof(node)); 
            nn->data = *a; 
            nn->left = NULL; 
            nn->right = NULL; 
            *p = nn; 
        } 
        else { 
  
            // If the character is an operand 
            if (*a >= '0' && *a <= '9') { 
                return a; 
            } 
  
            // Build the left sub-tree 
            q = add(&(*p)->left, a + 1); 
  
            // Build the right sub-tree 
            q = add(&(*p)->right, q + 1); 
  
            return q; 
        } 
    } 
} 
  
// Function to print the infix expression for the tree 
void inr(node* p) // recursion 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        inr(p->left); 
        printf("%c ", p->data); 
        inr(p->right); 
    } 
} 
  
// Function to print the postfix expression for the tree 
void postr(node* p) 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        postr(p->left); 
        postr(p->right); 
        printf("%c ", p->data); 
    } 
} 
  
// Driver code 
int main() {
        int values;
        node* s = NULL; 
        char a[] = "SIZE";
        scanf("%i", &values); 
        //add(&s, a); 
        for (int i = 0; i < values; ++i){
                scanf("%s", a);
                add(&s, a);
        }
        printf("The Infix expression is:\n "); 
        inr(s); 
        printf("\n"); 
        printf("The Postfix expression is:\n "); 
        postr(s); 
        return 0; 
}
        leftRotation(&(tree));
        //(*tree)->right = rightRotation((*tree)->right); 
        //leftRotation(*tree); 
    } 
    return tree;
}

//empiezan los 
void preOrderTraversal(struct node *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preOrderTraversal(tree->left);
		preOrderTraversal(tree->right);
	}
}
void inOrderTraversal(struct node *tree){
	if(tree != NULL){
		inOrderTraversal(tree->left);
		printf("%d ", tree->data);   
		inOrderTraversal(tree->right);
	}
}
void postOrderTraversal(struct node *tree){
	if(tree != NULL){
		postOrderTraversal(tree->left);
		postOrderTraversal(tree->right);
		printf("%d ", tree->data);
		
	}
}


struct node *create_node(struct node *tree, int value){
	if(tree==NULL){
		tree = (struct node *)malloc(sizeof(struct node));
		tree -> left = tree ->right = NULL;
		tree -> data = value;
        tree -> heightTree = 1;
		return tree;
	}else{
		if(value < tree->data)
			tree ->left = create_node(tree->left,value);
	else if(value > tree->data)
		tree->right=create_node(tree->right,value);
	else
		printf("ERROR\n");
	return(tree);
	}
};

int main(int argc, char const *argv[])
{	
	int value;
	int values=0;
	struct node *tree = NULL;
	scanf("%i", &values);
	for (int i = 0; i < values; ++i){
		scanf("%d", &value);
		tree = create_node(tree,value);
	}
	
    printf("\nPreOrden\n "); 
	preOrderTraversal(tree);
	printf("\nInOrden\n "); 
	inOrderTraversal(tree);
	printf("\nPostOrden\n "); 
	postOrderTraversal(tree);
	printf("\nPorNiveles\n "); 
	//order(tree);
    printf("\n"); 
    printf("\nPreOrden Convexo R D I\n "); 
	//preOrderTraversal(tree);
	printf("\nInOrden Convexo D R I\n "); 
	//inOrderTraversal(tree);
	printf("\nPostOrden Convexo D I R\n "); 
	//postOrderTraversal(tree);
    

	return 0;
}