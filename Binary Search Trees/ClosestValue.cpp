#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
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

void closest(TreeNode * node,int data,int &minDiff,int &key){

	if(node == NULL){return;}
	int temp = abs(node->data - data);
	
	if(temp < minDiff ){
		
		minDiff = temp;
		key = node->data;
	}
	
	if(key == data){
		
		key = data;
		return;
		
	}		

	if(node->data < data ){
		
		closest(node->right,data,minDiff,key);	
		
	}	
	else if(node->data > data){
	
		closest(node->left,data,minDiff,key);
		
	}
}	
//Main Function	
int main(){

	struct TreeNode *root = NULL;
        root = insertIntoBST(10,root);
	insertIntoBST(7,root);
	insertIntoBST(8,root);
	insertIntoBST(14,root);
	insertIntoBST(1,root);
	insertIntoBST(12,root);
	insertIntoBST(23,root);
	int data;
	cin>>data;
	int minDiff = abs(root->data - data) + 1;
	int key = root->data;
	closest(root,data,minDiff,key);
	
	cout << "Key : " << key << endl;
	
	return 0;
}
