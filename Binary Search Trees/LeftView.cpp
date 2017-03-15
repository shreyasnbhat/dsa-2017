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
	else if(data < root->data){
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
static int currentLevel = 0;
void LeftView(TreeNode * root,int nextLevel){
	
	
	if(currentLevel < nextLevel && root!=NULL){
		
		cout << root->data << " ";
		currentLevel = nextLevel;
		
	}
	if (root!=NULL){
		LeftView(root->left,nextLevel+1);
		LeftView(root->right,nextLevel+1);	
	}
}
//Main Function	
int main(){

	struct TreeNode *root = NULL;
        int n;
        cin>>n;
        int t;
        cin>>t;
       	root = insertIntoBST(t,root);
	for(int i = 0 ; i  < n-1 ; i++ ){
        
        	int t;
        	cin>>t;
        	insertIntoBST(t,root);
        }
        
     	cout << "InOrder Traversal :" ;
     	inOrderTraversal(root);
     	cout<< endl;   
     	LeftView(root,1);
     	return 0;
}
