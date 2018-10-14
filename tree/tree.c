#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct tag_node{
	struct tag_node* left;
	struct tag_node* right;
	char data;
}sbt_node;

sbt_node* create_node(char d);
void delete_node(sbt_node* node);
void  delete_tree(sbt_node* node);

void print_preorder(sbt_node* root);
void print_inorder(sbt_node* root);
void print_postorder(sbt_node* root);

sbt_node* find_parent(sbt_node* root,char data);
 
int main()
{
	int node_num;
	int i,j;
	char tmp[3];
	sbt_node* root = create_node('A');
	sbt_node* parent= root;
	scanf("%d",&node_num);
	
	printf("%d\n\n",node_num);
	for(i=0; i< node_num ; i++)
	{
		printf("%d\n",i);
		printf("%d\n\n",node_num);


        scanf("%c %c %c",&tmp[0],&tmp[1],&tmp[2]);


		
		parent = find_parent(root,tmp[0]);
		switch(tmp[1])
		{
			case '.': 
                parent->left= NULL; 
                break;
			default:
                parent->left->data = tmp[1];
		}
		
		switch(tmp[2])
		{
			case '.':
                parent->right = NULL;
                break;
			default:
                parent->right->data = tmp[2];
		}
	}
	
	for(i=0;i<3;i++)
	{
		print_preorder(root);
		print_inorder(root);
		print_postorder(root);
	}
	
	return 0;
}

sbt_node* create_node(char d)
{
	sbt_node* new_node = (sbt_node*)malloc(sizeof(sbt_node));
	
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = d;
	
	return new_node;
}

void delete_node(sbt_node* node)
{
	free(node);
}

void delete_tree(sbt_node* root)
{
	if(root == NULL)
		return;
	
	delete_node(root->left);
	delete_node(root->right);
	delete_node(root);
}

void print_preorder(sbt_node* root)
{
	if(root==NULL)
		return;
	
	printf("%c",root->data);
	print_preorder(root->left);
	print_preorder(root->right);

}
void print_inorder(sbt_node* root)
{
	if(root==NULL)
		return;
	
	print_inorder(root->left);
	printf("%c",root->data);
	print_inorder(root->right);
}
void print_postorder(sbt_node* root)
{
	if(root==NULL)
		return;
	
	print_postorder(root->left);
	print_postorder(root->right);
	printf("%c",root->data);
}


sbt_node* find_parent(sbt_node* parent,char data)
{

    printf("Hi");
	if(parent == NULL)
		return NULL;
	
	while(data != parent->data)
	{
		if(data ==find_parent(parent->left,data)->data)
			return parent->left;
		if(data == find_parent(parent->right,data)->data)
			return parent->right;
	}
}

