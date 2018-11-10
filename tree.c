#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef char element_type;

typedef struct tag_node{
   struct tag_node *left;
   struct tag_node *right;
	element_type data;
}sbt_node;

sbt_node* create_node(element_type d);
void delete_node(sbt_node* node);
void delete_tree(sbt_node* node);

void print_preorder(sbt_node* root);
void print_inorder(sbt_node* root);
void print_postorder(sbt_node* root);

sbt_node* find_parent(sbt_node* root,element_type data);
 
int main()
{
	int node_num;
	int i,j;
	char tmp[3];
	sbt_node* root = create_node('A');
	sbt_node* parent = root;
	scanf("%d",&node_num);
	
	for(i=0; i< node_num ; i++)
	{
		printf("%d\n",i);
		printf("%d\n\n",node_num);

        
        scanf("%c %c %c",&tmp[0],&tmp[1],&tmp[2]);
      
        printf("%c %c %c",tmp[0],tmp[1],tmp[2]);

		//parent찾기 
	/*	parent = find_parent(root,tmp[0]);
		switch(tmp[1])
		{
			case '.': parent->left = NULL;break;
			default: parent->left->data = tmp[1];

		}
		
		switch(tmp[2])
		{
			case '.': parent->right=NULL;break;
			default: parent->right->data = tmp[1];
		}
	}
	
	for(i=0;i<3;i++)
	{
		print_preorder(root);
		print_inorder(root);
		print_postorder(root);
	}
*/
	return 0;
}
}
sbt_node* create_node(element_type d)
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


sbt_node* find_parent(sbt_node* parent,element_type data)
{
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

