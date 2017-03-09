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
