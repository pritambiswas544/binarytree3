/*implementing binary search tree in c++ and using insert();display() and search() function*/


#include<iostream>
using namespace std;
	int n=1;
				//creating the node class
	class node{
	public:
		int data;
				//ptr to left and right
		node * left;
		node * right;
		node * parent;
				//constructor
	node(int value){
		left=NULL;
		right=NULL;
		parent=NULL;
		data=value;
	}
	};
				//creating class of the tree
	class BiST{
	public:
				//ptr to root
		node * root;
				//constructor
	BiST(){
		root=NULL;
		
	}
				
				//inserting recursively
				//first creating the main function so that it can be called recursively
	void insertH(node * curr,int value){
				//base casee
				//inserting when tree is empty
	if(curr==NULL){
		curr=new node(value);
				//updating the root
	if(root==NULL)
		root=curr;
	}
				//if value is less than the data of curr
	else if(value<curr->data){
				//linking the curr left
		if(curr->left==NULL){curr->left=new node(value);
		curr->left->parent=curr;}
				//if curr is not null the go left recursively
		else{
			insertH(curr->left,value);
		}
	}
				//if value is more than data of curr
	else{
				//linking the edge of curr right
		if(curr->right==NULL){curr->right=new node(value);
		curr->right->parent=curr;}
				//if curr right is not null then go right recursively
		else{
			insertH(curr->right,value);
		}
	}
	}
				//now writing the main insert fucnction using the insertH() recursively
	void insert(int value){
		insertH(root,value);
	}
				//finding the min within the node keeping the inserted value as node
	node* findmin(node * curr){
				//exit condition 
		if(curr->left==NULL){
			
			return curr;
				
		}
				//else keep going to left
		else findmin(curr->left);
		
				
		
	}
				//main minimum finding position and storing it to an int 
	
	int find(int dat){
		node*m=searchH(dat);
		
		node *x=findmin(m);
		int y=x->data;
		return y;
	}
			
				//displaying the linked list in 2d
	void display2dH(node * curr,int space){
		
				//base condition
		if(curr==NULL){return;}
				//increase the space,we intend to print each node with 5 spaces apart
		space=space+5;
				//process the right child first
		display2dH(curr->right,space);
		cout<<endl;
				//loop for increasing the space for each levels 
		for(int i=5;i<space;i++){
			cout<<" ";
		}
				//printing the node value
		cout<<curr->data<<endl;
		
				//process left child
		display2dH(curr->left,space);
	}
				//main display2d function using previous function
	void display2d(){
		cout<<"\n************************************"<<endl;
				//calling the display2dH function
		display2dH(root,0);
		cout<<"************************************"<<endl;
	}
							
	
				//finding an element within the binary tree
				//main searchH function usinf the search function recursively

		
	node* searchH (int value){
		search(root,value);
		}
				//fucntion that will be called recursively
	node* search(node * curr,int value){
				//exit condition
		if(curr==NULL || curr->data==value)return curr;
		
				//if value is less than root search left
		else if(value<curr->data) return search(curr->left,value);
				//else search right
		else return search(curr->right,value);
		}

	
				//finding the height of tree by edge counting method
	int findheight(node * curr){
				//exit condition
				//as height of the leaf is 0
		if(curr==NULL)return -1;
		return max(findheight(curr->right),findheight(curr->left))+1;
	}
				//implementing only using the value parameter
	int findlul(int value){
		node*temp=searchH(value);
		findheight(temp);
	}
				//counting number of nodes in bst
	int count(node * curr){
		
	
		
		if(curr==NULL)return 0;
		
		else{
				//storing the number of nodes in two integers
			
			int a=count(curr->left);
			int b=count(curr->right);
				//total number =a+b+root
		
		return a+b+1;}
	}
				//using another function to call the count function using only a value parameter
	int countH(int val){
		node*temp=searchH(val);
		count(temp);
	} 
				//rangecounting in BST
	int rancou(node * root,node*h,node*l){
				//exit condition
		if(!root) return 0;	
				//if there is only one node
		if(root->data==l->data && root->data==h->data)
			return 1;
		
				//if the curreent root falls inside the root
				//recurring the left and right childs
		if(root->data>=l->data && root->data<=h->data)
			return 1+rancou(root->left,l,h)+rancou(root->right,l,h);
		
				//if current root's data is less than the low
				//then recur at right
		else if(root->data<l->data)
			return rancou(root->right,l,h);
				//else recur left
		else return rancou(root->left,l,h);
	}
	int ranc(int low,int high){
		node*temp1=searchH(low);
		node*temp2=searchH(high);
		rancou(root,temp1,temp2);
	}
			
	
		
				
		
			
			
	};
	int main(){
	
	BiST b;
	node*root=NULL;
	b.insert(4);
	b.insert(2);
	
	b.insert(1);
	b.insert(3);
	b.insert(5);
	b.insert(7);
	b.insert(9);
	
	b.display2d();
	//int high=7;
	//int low=2;
	cout<<"the number of nodes between 2 and 7 is "<<b.ranc(1,9)<<endl;
	
				
	
	cout<<"the height of the tree is "<<b.findlul(4)<<endl;
	
	cout<<"The number of nodes are "<<b.countH(4)<<endl;
	



}
		
		
	
		
