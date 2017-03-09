#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;
//Node for the BST
struct TreeNode{

	int data;
	TreeNode *left;
	TreeNode *right;

};

//New Node Creation
TreeNode * newNode(int item)
{
    struct TreeNode *temp =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
	return temp;
};

//Binary Search Tree Search Operation
//Time Complexity is O(logn)
//Worst Case is O(n)
TreeNode * searchInBST(int data,struct TreeNode *root){

	if(root==NULL){
		return NULL;
	}	
	else if(root->data == data){
		return root;
	}
	else if(root->data > data){
		return searchInBST(data,root->left);
	}
	else if(root->data < data){
		return searchInBST(data,root->right);
	}
	
}

//Insert only if root not null
//So after 1st insert this is used
//Returns node that has been newly added
//Time Complexity is O(logn)
//Worst Case is O(n)
struct TreeNode * insertIntoBST(int data,TreeNode *root){
	


		if(root == NULL){
			return newNode(data);
		}	
		else if(data > root->data){
			root->right = insertIntoBST(data,root->right);			
		}
		else if(data <= root->data){
			root->left = insertIntoBST(data,root->left);
		}
	
	
	return root;			

}

struct TreeNode * findMin(TreeNode *node){

	while(node->left=NULL){
		node = node->left;
	}
	return node;
}		

//Deletion Operation from a Binary Search Tree
//Time Complexity is O(logn)
//Worst Case is O(n)
TreeNode * deleteFromBST(int data,TreeNode *root){
	
	//If NULL return the node
	if(root == NULL){
		return root;
	}
	else if(data < root->data){
		root->left = deleteFromBST(data,root->left);
	}
	else if(data > root->data){
		root->right = deleteFromBST(data,root->right);
	}
	else{
		//Here now data == root->data
		//Effectively SearchOperation was done
		if(root->left == NULL){
			//Get right subtree
			TreeNode *temp = root->right;
			//Delete from memory
			free(root);				
			return temp;
		}
		else if(root->right == NULL){
			//Get left subtree
			TreeNode *temp = root->left;
			//Delete from memory
			free(root);
			return temp;
		}
		else{
			//Case when none of the children are null
			//Return min of right subtree
			TreeNode *temp =  findMin(root->right);
			root->data = temp->data;
			//Now delete min Node from Right subtree and store updated subtree in right pointer
			root->right = deleteFromBST(temp->data,root->right);
		}
	}
	
	return root;

}			
			
//Used to Traverse the Tree
//Results will appear in Sorted Order	
void inOrderTraversal(TreeNode *root){

	if(root!=NULL){
		
		inOrderTraversal(root->left);
		cout<<root->data << " ";
		inOrderTraversal(root->right);
	}
}
void preOrderTraversal(TreeNode *root){

	if(root!=NULL){
		
		cout<<root->data << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}
void postOrderTraversal(TreeNode *root){

	if(root!=NULL){
		
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout<<root->data << " ";
	}
}

//Main Function	
int main(){
	
	struct TreeNode *root = NULL;
	int n ;
	cin>>n;
	for(int i = 0; i < n ; i++ ){
		int t;
		cin>>t;
		if(i==0){
			root = insertIntoBST(t,root);
		}
		else{
			insertIntoBST(t,root);
		}
		
		
	}	
	
	inOrderTraversal(root);
	cout<<endl;	
	preOrderTraversal(root);
	cout<<endl;
	postOrderTraversal(root);
	cout<<endl;	

	
	
	
	return 0;
}
