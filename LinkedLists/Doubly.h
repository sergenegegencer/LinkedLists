#pragma once
#include <iostream>
#include "IndexOverflowException.h"
#include "EmptyListException.h"

class Doubly {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;
		Node(int value) {
			this->data = value;
			this->next = nullptr;
			this->prev = nullptr;
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
	void delFromFoot();
	void delFromBetween(int loc);
	int getLength();
};