// BinaryTree.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

void BinaryTree::insertNode(struct ListNode** startRef, int newData) 
{
	struct ListNode* newNode = new ListNode; //Assign memory for the data

	newNode->data = newData;//Assign passed data into the new_node 
	newNode->next = (*startRef); //Link the the list off the new node 
	(*startRef) = newNode; //Set the startRef to point at the new node
}

void BinaryTree::convertList2Binary(ListNode *startRef, BTreeNode* &root) 
{
	queue<BTreeNode*> que;//Store parent nodes in queue

	if (startRef == NULL) //If startRef is NULL set root to NULL and return
	{
		root = NULL;
		return;
	}

	root = newTreeNode(startRef->data);//Add first node as root to queue
	que.push(root); 
	startRef = startRef->next;//Move to next avaliable node space

	while (startRef)//Until final data from link list...
	{
		BTreeNode* parent = que.front();//Take parent node to front of queue
		que.pop();//Pop/Remove it from the queue

		BTreeNode *leftChild = NULL, *rightChild = NULL;//Initialises 2 children
		leftChild = newTreeNode(startRef->data);//Adds left child to its parent
		que.push(leftChild);//Put in queue read to be a parent as well if needed
		startRef = startRef->next;
		if (startRef)
		{
			rightChild = newTreeNode(startRef->data);
			que.push(rightChild);
			startRef = startRef->next;
		}
		parent->left = leftChild;//Assign left child of parent
		parent->right = rightChild;//Assign right child of parent
	}
}

void BinaryTree::printLeftTraversal(BTreeNode* root)
{
	if (root)
	{
		printLeftTraversal( root->left ); //Pass the root->left..->left node until there is no more
		cout << root->data << " "; //Print the data in the data
		//printLeftTraversal( root->right ); //To traverse right (Uneeded to show tree in action)
	}
}

BinaryTree::BinaryTree()
{
	struct ListNode* startRef = NULL; //Creates Linked list from following ints
	insertNode(&startRef, 7);//Whilst entered first, becomes last node in LL
	insertNode(&startRef, 9);
	insertNode(&startRef, 13);
	insertNode(&startRef, 18);
	insertNode(&startRef, 22);
	insertNode(&startRef, 30); 
	insertNode(&startRef, 45);//Whilst passed last, 45 becomes first node in LL

	BTreeNode *root;
	convertList2Binary(startRef, root);

	cout << "Root->Left->Left traversal of Tree: \n";
	printLeftTraversal(root);
}

int main()
{
	cout << "This program will create a binary tree for temporary hard coded data \n";
	cout << "Will be testing with numbers.. 7,9,13,18,22,30,45.. \n \n";

	BinaryTree();

	cout << "\n \n" << "Do you want to exit? (type anything to exit) \n";
	getchar(); //Waits for input to exit
	return 0;
}