#include<bits/stdc++.h>
#include<queue>
using namespace std;

template<typename T>
//Node 
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	BinaryTreeNode(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}

};

class BST
{
public:
	BinaryTreeNode<int>* root;
	//Constructor
	BST()
	{
		root=NULL;
	}
	//Destructor
	~BST()
	{
		delete root;
	}
	//Hasdata
private:
	bool Hasdata(int element,BinaryTreeNode<int>* root)
	{
		if(root==NULL)
		{
			return false;
		}
		if(root->data==element)
		{
			return true;
		}
		else if(root->data>element)
		{
			return Hasdata(element,root->left);
		}
		else
		{
			return Hasdata(element,root->right);
		}
	}
public:
	bool Hasdata(int element)
	{
		return Hasdata(element,this->root);
	}

	//insert element(new data) in the BST
private:
	BinaryTreeNode<int>* insert(int element,BinaryTreeNode<int>* root)
	{
		if(root==NULL)
		{
			BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(element);
			return newnode;
		}
		if(root->data>element)
		{
			root->left=insert(element,root->left);
		}
		else
		{
			root->right=insert(element,root->right);
		}
		return root;
		
	}
public:
	void insert(int element)
	{
		this->root=insert(element,this->root);
	}
	//delete elemnt in BST
private:
	BinaryTreeNode<int>* deleted(int element,BinaryTreeNode<int>* root)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(root->data>element)
		{
			root->left=deleted(element,root->left);
			return root;
		}
		if(element>root->data)
		{
			root->right=deleted(element,root->right);
			return root;
		}
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->left==NULL)
		{
			BinaryTreeNode<int>* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			BinaryTreeNode<int>* temp=root->left;
			delete root;
			return temp;
		}
		else
		{
			BinaryTreeNode<int>* minNODE=root->right;
			while(minNODE->left!=NULL)
			{
				minNODE=minNODE->right;
			}
			int right_min_element=minNODE->data;
			root->data=right_min_element;
			root->right=deleted(right_min_element,root->right);
			return root;
		}
	}
public:
	void deleted(int element)
	{
		this->root=deleted(element,this->root);
	}
	//print BST
private:
	void print(BinaryTreeNode<int>* root)
	{
		if(root==NULL)
	    {
	    	return;
	    }
	
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	
	while(pendingNode.size()!=0)
	{
		BinaryTreeNode<int>* ele=pendingNode.front();
		pendingNode.pop();
		cout<<ele->data<<" : ";
		if(ele->left!=NULL)
		{
			cout<<" L-> "<<ele->left->data;
			pendingNode.push(ele->left);
		}
		if(ele->right!=NULL)
		{
			cout<<" R-> "<<ele->right->data;
			pendingNode.push(ele->right);
		}
		cout<<endl;

	}
	}

public:
	void  print()
	{
		print(this->root);
	}
	
};
int main()
{
	BST* tree=new BST();
	int choice;
	int input;
	cout<<"choice : 1 ->Inserting Data"<<endl;
	cout<<"choice : 2 ->Deleting  Data"<<endl;
	cout<<"choice : 3 ->Searching Data"<<endl;
	cout<<"choice :   ->Print     Data"<<endl;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter The Data ,For Inserting In The BST"<<endl;   

                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cout<<"Enter The Data ,For Deleting In The BST"<<endl;
                cin >> input;
                tree->deleted(input);
                break;
            case 3:
                cout<<"Enter The Data ,For Searching In The BST"<<endl;
                cin >> input;
                if(tree->Hasdata(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->print();
                return 0;
                break;
        }
    }
}