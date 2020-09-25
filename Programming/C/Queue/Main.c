/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
	char data[1025];
	struct node *left, *right;
};

struct nodequeue{
	struct node *pointer;
	struct nodequeue *next;
	struct nodequeue *pre;
};

struct nodequeue *searchLast(struct nodequeue *head){
	while(head){
		if(head->next == NULL)
			return head;
		head = head->next;
	}
	return NULL;
}


struct node *deletenode(struct nodequeue **pth){
	struct node* x = NULL;
	struct nodequeue *p1 = *pth;
	x = (*pth)->pointer;
	if((*pth)->next!=NULL)
		(*pth) = (*pth)->next;
	else
		(*pth) = NULL;
	memset(p1,0,sizeof(struct nodequeue));
	free(p1);
	return x;
}

struct node *pop(struct nodequeue **pth){
	struct node* x = NULL;
	struct nodequeue *p1 = NULL;
	p1 = *pth;
	while(p1->next)
		p1 = p1->next;

	x = p1->pointer;
	if(p1->pre)
		p1->pre->next = NULL;
	else
		*pth = NULL;
	memset(p1,0,sizeof(struct nodequeue));
	free(p1);
	return x;
}

void ptr(char *c, char a){
	while(*c)
		c++;
	*c = a;
	*(c+1) = '\0';
}

int itsDigit(char* str){
	if (*str == 45)
		if ( isdigit(*(str+1)) )
			return 1;
	if ( isdigit(*str) )
			return 1;
	return 0;
}


//Inserts a nodequeue at the beginning

void insertnode(struct nodequeue **pth,struct node* ptr){
	struct nodequeue *tmp = (struct nodequeue*)malloc(sizeof(struct nodequeue));
	tmp->pointer = ptr;
	tmp->next= *pth;
	tmp->pre= NULL;
	*pth = tmp;
}

//nserts a nodequeue at the end

void push(struct nodequeue **pth,struct node* ptr){
	if(*pth==NULL)
		insertnode(pth,ptr);
	else{
		struct nodequeue *tmp = (struct nodequeue*)malloc(sizeof(struct nodequeue));
		tmp->pre = searchLast(*pth);
		tmp->pre->next = tmp;
		tmp->next =NULL;
		tmp->pointer=ptr;
	}
}

void check(struct nodequeue** queuePost,struct nodequeue** queueNums,struct nodequeue** queueOper, char *data){
	int negative = 0;
	while(*data){
		int parAbierto = 1;
		if (*data != 10 && *data != 41){
			if (*data == 40)
					parAbierto=0;
			struct node* temp = (struct node*)(malloc(sizeof(struct node)));
			if ( (*data == 40 || *data == 45 || *data == 42 ||*data == 43 || *data == 47) && !negative){
				if (*(data+1) == 45)
					negative=1;
				ptr(temp->data,*data);
				data++;
			}
			else{
				if (negative){
					ptr(temp->data,*data);
					negative=0;
					data++;
				}
				while(isdigit(*data)){
					ptr(temp->data,*data);
					data++;
				}
			}
			if (parAbierto){
				strcpy(temp->data,temp->data);
				if (itsDigit( temp->data)){
					push(queueNums,temp);
				}
				else
					push(queueOper,temp);
			}
		}
		else if(*data == 41){
			if(*queueNums){
				struct node* x1 = NULL;
				struct node* x2 = NULL;
				if (*queueNums)
					x1 = pop(queueNums);
				if (*queueNums)
					x2 = pop(queueNums);
				if(x2)
					push(queuePost,x2);
				if(x1)
					push(queuePost,x1);
			}
			if (*queueOper)
				push(queuePost,pop(queueOper));
			data++;
		}
		else
			data++;
	}
}


void oper(struct nodequeue** queue, char *data){
	while(*data){
		struct node* temp = (struct node*)(malloc(sizeof(struct node)));
		while( (*data == '*' || *data == '+' || *data == '-' || *data == '/') || (*data>='0' && *data <='9')  ){
			ptr(temp->data,*data);
			data++;
		}
		strcpy(temp->data,temp->data);
		push(queue,temp);
		data++;
	}
}

int insertPost(struct node** root, struct node* data){
	if(*root){
		if(!itsDigit(  (*root) -> data)  ){
			if(insertPost(&(*root)->right,data))
				return 1;
			if(insertPost(&(*root)->left,data))
				return 1;
		}
		else
			return 0;
	}
	else{
		*root = data;
		return 1;
	}
}

// inserts the data with postfix input

int insertPre(struct node** root, struct node* data){
	if(*root){
		if(!itsDigit( (*root) -> data) ){
			if(insertPre(&(*root)->left,data))
				return 1;
			if(insertPre(&(*root)->right,data))
				return 1;
		}
		else
			return 0;
	}
	else{
		*root = data;
		return 1;
	}
}

void PreF(struct node** root, char *data){;
	struct nodequeue* queue = NULL;
	oper
(&queue,data);
	while(queue){
		insertPre(root,deletenode(&queue));
	}
}

void InF(struct node **root, char *data){
	struct nodequeue * queueNums = NULL;
	struct nodequeue * queueOper = NULL;
	struct nodequeue * queuePost = NULL;
	check(&queuePost,&queueNums,&queueOper,data);
	while(queuePost){
		insertPost(root,pop(&queuePost));
	}
}

void PostF(struct node ** root, char *data){;
	struct nodequeue * queue = NULL;
	oper
(&queue,data);
	while(queue){
		insertPost(root,pop(&queue));
	}
}

void read(struct node** root ){
	char *data = (char *)(malloc(sizeof(char)));
	char *temp = (char *)(malloc(sizeof(char)));
	fgets(data,1024,stdin);
	if(*data == 40){ 
		InF(root,data);
	}
	else if(*data == 45){ 
		if (isdigit(*(data+1)))
			PostF(root,data);
	}
	else if (isdigit(*(data))){
		PostF(root,data);
	}
	else{ 
		PreF(root,data);
	}
}

void PreOrder(struct node *root){
	if(root){
		printf("%s ",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}	
}

void PostOrder(struct node *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%s ",root->data);
	}
}

void InOrder(struct node *root, int z){
	if(root){
		if(!z)
			printf("(");
		InOrder(root->left,0);
		printf("%s",root->data);
		InOrder(root->right,1);
		if(z==1)
			printf(")");
	}	
}

int solution(struct node* root){
	if(!itsDigit(root->data)){
		switch(*root->data){
			case 42:
				return solution(root->left)* 
				solution(root->right);
				break;
			case 43:
				return solution(root->left)+ 
				solution(root->right);
				break;
			case 45:
				return solution(root->left)- 
				solution(root->right);
				break;
			case 47:
				return solution(root->left)/
				solution(root->right);
				break;
		}
	}
	else{
		return atoi(root->data);
	}
}


int main(int argc, char const *argv[]){
	char *value  = (char *)(malloc(sizeof(char)));
	fgets(value,1024,stdin);
	for (int i = 0; i < atoi(value); ++i){
		printf("%d\n", i+1);
		struct node *root;
		root = NULL;
		read(&root);
		printf("The Prefix expression is:\n");
		PreOrder(root);
		printf("\n");
		printf("The Infix expression is:\n");
		InOrder(root,-1);
		printf("\n");
		printf("The Postfix expression is:\n");
		PostOrder(root);
		printf("\n");
		printf("Result: %d\n", solution(root) );
	
	}
	return 0;
}