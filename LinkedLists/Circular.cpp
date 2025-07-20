#include "Circular.h"

void Circular::printListSingly() {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	singlyTemp = singlyHead;
	do {
		if (singlyTemp->next != singlyHead) std::cout << singlyTemp->data << ", ";
		else std::cout << singlyTemp->data;
		singlyTemp = singlyTemp->next;
	} while (singlyTemp != singlyHead);
}

int Circular::findLengthSingly() {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	singlyTemp = singlyHead;
	int length = 1;
	singlyTemp = singlyTemp->next;
	while (singlyTemp != singlyHead) {
		length++;
		singlyTemp = singlyTemp->next;
	}
	return length;
}


int* Circular::searchSingly(int key, int* count) {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	singlyTemp = singlyHead;
	int loop = 0;
	for (int i = 0; loop != 1; i++) {
		if (singlyTemp->data == key) (*count)++;
		singlyTemp = singlyTemp->next;
		if (singlyTemp == singlyHead) loop++;
	}
	if ((*count) == 0) return nullptr;
	int* foundedIndex = new int[*count];
	int idx = 0;
	for (int i = 0; i < singlyLength; i++) {
		if (singlyTemp->data == key) foundedIndex[idx++] = i;
		singlyTemp = singlyTemp->next;
	}
	return foundedIndex;
}


void Circular::addHeadSingly(int key) {
	SinglyNode* newNode = new SinglyNode(key);
	if (singlyHead == nullptr) {
		singlyHead = newNode;
		singlyHead->next = singlyHead;
		singlyLength++;
		return;
	}
	singlyTemp = singlyHead;
	singlyTemp = singlyTemp->next;
	while (singlyTemp->next != singlyHead) singlyTemp = singlyTemp->next;
	singlyTemp->next = newNode;
	newNode->next = singlyHead;
	singlyHead = newNode;
	singlyLength++;
}

void Circular::addFootSingly(int key) {
	SinglyNode* newNode = new SinglyNode(key);
	if (singlyHead == nullptr) {
		singlyHead = newNode;
		singlyHead->next = singlyHead;
		singlyLength++;
		return;
	}
	singlyTemp = singlyHead;
	singlyTemp = singlyTemp->next;
	while (singlyTemp->next != singlyHead) singlyTemp = singlyTemp->next;
	singlyTemp->next = newNode;
	newNode->next = singlyHead;
	singlyLength++;
}

void Circular::addBetweenSingly(int key, int loc) {
	if (loc < 0 || loc >= singlyLength) throw EmptyListException("Liste boþ!");
	if (loc == 0) {
		addHeadSingly(key);
		return;
	}
	if (loc == singlyLength) {
		addFootSingly(key);
		return;
	}
	SinglyNode* newNode = new SinglyNode(key);
	int tempLoc = 0;
	singlyTemp = singlyHead;
	while (tempLoc + 1 != loc) {
		singlyTemp = singlyTemp->next;
		tempLoc++;
	}
	newNode->next = singlyTemp->next;
	singlyTemp->next = newNode;
	singlyLength++;
}

void Circular::delFromHeadSingly() {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (singlyHead->next == singlyHead) {
		delete singlyHead;
		singlyHead = nullptr;
		singlyLength--;
		return;
	}
	singlyTemp = singlyHead->next;
	while (singlyTemp->next != singlyHead) singlyTemp = singlyTemp->next;
	singlyTemp->next = singlyHead->next;
	SinglyNode* temp2 = singlyHead;
	delete singlyHead;
	singlyHead = singlyTemp;
	singlyLength--;
}

void Circular::delFromFootSingly() {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (singlyHead->next == singlyHead) {
		delete singlyHead;
		singlyHead = nullptr;
		singlyLength--;
		return;
	}
	singlyTemp = singlyHead->next;
	while (singlyTemp->next->next != singlyHead) singlyTemp = singlyTemp->next;
	SinglyNode* singlyTemp2 = singlyTemp->next;
	singlyTemp->next = singlyHead;
	delete singlyTemp2;
	singlyTemp2 = nullptr;
	singlyLength--;
}

void Circular::delFromBetweenSingly(int loc) {
	if (singlyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (loc < 0 || loc >= singlyLength) throw IndexOverflowException("Ýstediðiniz index bu LinkedList'te bulunmamakta!");
	if (loc == 0) {
		delFromHeadSingly();
		return;
	}
	if (loc == singlyLength - 1) {
		delFromFootSingly();
		return;
	}
	singlyTemp = singlyHead;
	int tempLoc = 0;
	while (tempLoc != loc - 1) {
		singlyTemp = singlyTemp->next;
		tempLoc++;
	}
	SinglyNode* temp2 = singlyTemp->next;
	singlyTemp->next = temp2->next;
	delete temp2;
	temp2 = nullptr;
	singlyLength--;
}

void Circular::printListDoubly() {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	doublyTemp = doublyHead;
	do {
		if (doublyTemp->next != doublyHead) std::cout << doublyTemp->data << ", ";
		else std::cout << doublyTemp->data;
		doublyTemp = doublyTemp->next;
	} while (doublyTemp != doublyHead);
}

int Circular::findLengthDoubly() {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	doublyTemp = doublyHead;
	int length = 1;
	do {
		doublyTemp = doublyTemp->next;
		length++;
	} while (doublyTemp != doublyHead);
	return length;
}

int* Circular::searchDoubly(int key, int* count) {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	doublyTemp = doublyHead;
	int loop = 0;
	for (int i = 0; loop != 1; i++) {
		if (doublyTemp->data == key) (*count)++;
		doublyTemp = doublyTemp->next;
		if (doublyTemp == doublyHead) loop++;
	}
	if (*count == 0) return nullptr;
	int* foundedIndex = new int[*count];
	int idx = 0;
	for (int i = 0; i < doublyLength; i++) { //doublyTemp = doublyHead at this point
		if (doublyTemp->data == key) foundedIndex[idx++] = i;
		doublyTemp = doublyTemp->next;
	}
	return foundedIndex;
}

void Circular::addHeadDoubly(int key) {
	DoublyNode* newNode = new DoublyNode(key);
	if (doublyHead == nullptr) {
		doublyHead = newNode;
		doublyHead->next = doublyHead->prev = doublyHead;
		doublyLength++;
		return;
	}
	doublyTemp = doublyHead->prev;
	doublyTemp->next = newNode;
	newNode->prev = doublyTemp;
	newNode->next = doublyHead;
	doublyHead->prev = newNode;
	doublyHead = newNode;
	doublyLength++;
}

void Circular::addFootDoubly(int key) {
	DoublyNode* newNode = new DoublyNode(key);
	if (doublyHead == nullptr) {
		doublyHead = newNode;
		doublyHead->next = doublyHead->prev = doublyHead;
		doublyLength++;
		return;
	}
	doublyTemp = doublyHead->prev;
	doublyTemp->next = newNode;
	newNode->prev = doublyTemp;
	newNode->next = doublyHead;
	doublyHead->prev = newNode;
	doublyLength++;
}

void Circular::addBetweenDoubly(int key, int loc) {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (loc < 0 || loc > doublyLength) throw IndexOverflowException("Belirttiðiniz index bulunmamakta!");
	if (loc == 0) {
		addHeadDoubly(key);
		return;
	}
	if (loc == doublyLength) {
		addFootDoubly(key);
		return;
	}
	DoublyNode* newNode = new DoublyNode(key);
	doublyTemp = doublyHead;
	int tempLoc;
	if (doublyLength / 2 >= loc) { //to optimize the code, the iteration goes straight. 0 means the first index of the list.
		tempLoc = 0;
		while (tempLoc < loc - 1) {
			doublyTemp = doublyTemp->next;
			tempLoc++;
		}
		newNode->next = doublyTemp->next;
		doublyTemp->next->prev = newNode;
		doublyTemp->next = newNode;
		newNode->prev = doublyTemp;
	}
	else {
		doublyTemp = doublyTemp->prev;
		tempLoc = doublyLength - 1;
		while (tempLoc != loc) {
			doublyTemp = doublyTemp->prev;
			tempLoc--;
		}
		doublyTemp->prev->prev->next = newNode;
		newNode->prev = doublyTemp->prev->prev;
		newNode->next = doublyTemp;
		doublyTemp->prev = newNode;
	}
	doublyLength++;
}

void Circular::delFromHeadDoubly() {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (doublyHead->prev == doublyHead) {
		delete doublyHead;
		doublyHead = nullptr;
		doublyLength--;
		return;
	}
	doublyTemp = doublyHead->prev;
	DoublyNode* temp2 = doublyHead;
	doublyTemp->next = doublyHead->next;
	doublyHead = doublyHead->next;
	doublyHead->prev = doublyTemp;
	delete temp2;
	doublyLength--;
}

void Circular::delFromFootDoubly() {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (doublyHead->prev == doublyHead) {
		delFromHeadDoubly();
		return;
	}
	DoublyNode* temp2 = doublyHead->prev;
	doublyTemp = temp2->prev;
	doublyTemp->next = doublyHead;
	doublyHead->prev = doublyTemp;
	delete temp2;
	doublyLength--;
}

void Circular::delFromBetweenDoubly(int loc) {
	if (doublyHead == nullptr) throw EmptyListException("Liste boþ!");
	if (loc < 0 || loc >= doublyLength) throw IndexOverflowException("Belirttiðiniz index bulunmamakta!");
	if (loc == 0) {
		delFromHeadDoubly();
		return;
	}
	if (loc == doublyLength - 1) {
		delFromFootDoubly();
		return;
	}
	DoublyNode* temp2;
	int tempLoc;
	if (doublyLength / 2 >= loc) { //to optimize the code, the iteration goes straight. 0 means the first index of the list.
		doublyTemp = doublyHead;
		tempLoc = 0;
		while (tempLoc < loc - 1) {
			doublyTemp = doublyTemp->next;
			tempLoc++;
		}
		temp2 = doublyTemp->next;
		temp2->next->prev = doublyTemp;
		doublyTemp->next = temp2->next;
		delete temp2;
	}
	else {
		doublyTemp = doublyHead->prev;
		tempLoc = doublyLength - 1;
		while (tempLoc != loc + 1) {
			doublyTemp = doublyTemp->prev;
			tempLoc--;
		}
		temp2 = doublyTemp->prev;
		temp2->prev->next = doublyTemp;
		doublyTemp->prev = temp2->prev;
		delete temp2;
	}
	doublyLength--;
}