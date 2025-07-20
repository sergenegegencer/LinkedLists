#pragma once
#include <iostream>
#include "EmptyListException.h"
#include "IndexOverflowException.h"

class Circular {
private:
	struct SinglyNode {
		int data;
		SinglyNode* next;
		SinglyNode(int value) {
			this->data = value;
			this->next = nullptr;
		}
		~SinglyNode() {};
	};
	SinglyNode* singlyHead = nullptr;
	SinglyNode* singlyTemp = nullptr;
	int singlyLength = 0;

	struct DoublyNode {
		int data;
		DoublyNode* next;
		DoublyNode* prev;
		DoublyNode(int value) {
			this->data = value;
			this->next = nullptr;
			this->prev = nullptr;
		}
		~DoublyNode() {};
	};
	DoublyNode* doublyHead = nullptr;
	DoublyNode* doublyTemp = nullptr;
	int doublyLength = 0;

public:
	void printListSingly();
	int findLengthSingly();
	int* searchSingly(int key, int* count);
	void addHeadSingly(int key);
	void addFootSingly(int key);
	void addBetweenSingly(int key, int loc);
	void delFromHeadSingly();
	void delFromFootSingly();
	void delFromBetweenSingly(int loc);
	void printListDoubly();
	int findLengthDoubly();
	int* searchDoubly(int key, int* count);
	void addHeadDoubly(int key);
	void addFootDoubly(int key);
	void addBetweenDoubly(int key, int loc);
	void delFromHeadDoubly();
	void delFromFootDoubly();
	void delFromBetweenDoubly(int loc);
};