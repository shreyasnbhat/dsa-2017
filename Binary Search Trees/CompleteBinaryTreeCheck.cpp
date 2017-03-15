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
    cout << "Node Created at " << temp << " and Data is " << temp->data << endl;
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
static int counter = 0;
void storeInArray(TreeNode * root,int a[],int i){

	if(root == NULL){
		return;
	}
	else {
		a[i] = root->data;
		if(i > counter)counter = i;
		storeInArray(root->left,a,2*i+1);
		storeInArray(root->right,a,2*i+2);
	}
}		
	
	
	
//Main Function	
int main(){

	struct TreeNode *root = NULL;
        int n;
        cin >> n;
        int t;
        cin >> t;
        root = insertIntoBST(t,root);
	for(int i = 0 ; i < n-1 ; i++){
		int t;
		cin>>t;
		insertIntoBST(t,root);
	}	
	int a[100000];
	storeInArray(root,a,0);
	if ( counter + 1 == n ) {
		cout << "Is a complete binary tree " << endl;
	}
	else{
		cout << "Isn't a complete binary tree " << endl;
	}		
	
	return 0;
}
