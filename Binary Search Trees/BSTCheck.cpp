#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int order[100000];
bool flag=true;
int t=0;

void inOrder(int a[],int n,int i)
    {
    if(i>n)
        return;
    
    inOrder(a,n,2*i+1);
    
    order[t]=a[i];


    if(order[t]<order[t-1])
       {
        flag=false;
       }
    t++;
    inOrder(a,n,2*i+2);
    
}
int main() {
    
    	cin>>n;
    	int arr[n];
    	int i=0;
    	for(t=0;t<n;t++){
    	
        	cin>>arr[t];
	}
	
	inOrder(arr,n,0);
    		
     	if(flag){
        	cout<<"YES"<<endl;
        }
        else{
         	cout<<"NO"<<endl;
    	}
    	
    	
    	return 0;
    
    
}

