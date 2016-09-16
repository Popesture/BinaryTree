#include "stdafx.h"
#include <string>
#include <queue>

using namespace std;

struct ListNode //Linked List Struct
{
	int data;
	ListNode* next;
};

struct BTreeNode //Binary Tree Struct
{
	int data;
	BTreeNode *left;
	BTreeNode	*right;
};

BTreeNode* newTreeNode(int data) //Creates a new node from the passed data
{
	BTreeNode *tempNode = new BTreeNode;
	tempNode->data = data;
	tempNode->left = tempNode->right = NULL;
	return tempNode; 
}

class BinaryTree
{
private:
	
public:
	BinaryTree();//Begins the process from main()
	void insertNode(struct ListNode** startRef, int newData);//This func will insert a node at beginning of the linked-list
	void convertList2Binary(ListNode *head, BTreeNode* &root);//Converts the linked list of into linked binary tree
	void printLeftTraversal(BTreeNode* root);//Print the tree root and left-left-nodes

	~BinaryTree()
	{
		//if(... = NULL)
		//{

		//}
	}
};