#pragma once
#include <iostream>
#include "IndexOverflowException.h"
#include "EmptyListException.h"

class Singly {
private:
	struct Node {
		int data;
		Node* next;
		Node(int value) {
			this->data = value;
			this->next = nullptr;
		}
		~Node() {};
	};
	int length = 0;
	Node* head = nullptr;
	Node* temp = nullptr;
public:
	void printList();
	int findLength();
	int traversal(int loc);
	int* search(int key, int* count);
	void addHead(int key);
	void addFoot(int key);
	void addBetween(int key, int loc);
	void delFromHead();
	void delFromBetween(int loc);
	void delFromFoot();
	int getLength();
};