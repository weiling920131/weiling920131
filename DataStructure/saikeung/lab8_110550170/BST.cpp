#include "BST.h"
#include<iostream>
#include<queue>
using namespace std;

void BST::insert(Node* insertNode) {
	//TODO: insert a node to BST
	if (!root) {
		root = insertNode;
		return;
	}

	int num = insertNode->getValue();
	Node* tmp = root;
	while (tmp) {
		if (num < tmp->getValue()) {
			if (!(tmp->getLchild())) tmp->setLchild(insertNode);
			else tmp = tmp->getLchild();
		}
		else if (num > tmp->getValue()) {
			if (!(tmp->getRchild())) tmp->setRchild(insertNode);
			else tmp = tmp->getRchild();
		}
		else break;
	}
	
}

void BST::InOrder_traversal(Node* root)
{
	//TODO: Inorder traversal
	if (root) {
		InOrder_traversal(root->getLchild());
		cout << root->getValue() << ' ';
		InOrder_traversal(root->getRchild());
	}
}

void BST::LevelOrder_traversal(Node* root)
{
	//TODO: Level order traversal
	queue <Node*> num;
	num.push(root);
	while (!num.empty()) {
		Node* node = num.front();
		cout << node->getValue() << ' ';
		num.pop();
		if (node->getLchild()) num.push(node->getLchild());
		if (node->getRchild()) num.push(node->getRchild());
	}
	cout << endl;
}


Node* BST::getRoot() {
	//TODO: return root of BST
	return this->root;
}