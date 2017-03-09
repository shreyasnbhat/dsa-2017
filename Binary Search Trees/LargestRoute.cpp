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

	while(node->left!=NULL){
		node = node->left;
	}
	return node;
}

struct TreeNode * findMax(TreeNode *node){

	while(node->right!=NULL){
		cout << node->data << " ";
		node = node->right;
	}
	return node;
}			

			
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
	
	TreeNode * node = findMax(root);
	cout << node->data;

	
	
	
	return 0;
}
