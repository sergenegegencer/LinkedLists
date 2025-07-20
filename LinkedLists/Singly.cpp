#include "Singly.h"

void Singly::printList() {
	temp = head;

	while (temp != nullptr) {
		if (temp->next == nullptr) {
			std::cout << temp->data;
			break;
		}
		std::cout << temp->data << ", ";
		temp = temp->next;
	}
}

int Singly::findLength() {
	int lengthfunc = 0;
	temp = head;

	while (temp != nullptr) {
		lengthfunc++;
		temp = temp->next;
	}

	return lengthfunc;
}

int Singly::traversal(int loc) {
	temp = head;
	for (int i = 0; i < loc; i++)
		temp = temp->next;
	return temp->data;
}

int* Singly::search(int key, int* count) {
	temp = head;
	for (int i = 0; temp != nullptr; i++) {
		if (temp->data == key)
			(*count)++;
		temp = temp->next;
	}
	if (*count == 0)
		return nullptr;

	int* foundedIndex = new int[*count];
	temp = head;
	int idx = 0;
	for (int i = 0; i < length; i++) {
		if(temp->data == key) foundedIndex[idx++] = i;
		temp = temp->next;
	}
	return foundedIndex;
}

void Singly::addHead(int key) {
	Node* newNode = new Node(key);
	newNode->next = head;
	head = newNode;
	length++;
}

void Singly::addFoot(int key) {
	if (head == nullptr) {
		addHead(key);
		return;
	}
	Node* newNode = new Node(key);
	temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	temp->next = newNode;
	length++;
}

void Singly::addBetween(int key, int loc) {
	if (loc < 0 || loc > length) throw IndexOverflowException("Ýstediðiniz index bu LinkedList'te bulunmamakta!");
	if (loc == 0) {
		addHead(key);
		return;
	}
	if (loc == length) {
		addFoot(key);
		return;
	}
	temp = head;
	Node* temp2 = new Node(key);
	while (loc - 1 > 0) { // temp, loc'un 1 altindaki indextedir. temp2, loc indexi yerine gecer
		loc--;
		temp = temp->next;
	}
	temp2->next = temp->next;
	temp->next = temp2;
	length++;
}

void Singly::delFromHead() {
	if (head == nullptr) {
		std::cout << "Herhangi bir düðüm bulunmamakta!";
		return;
	}
	Node* temp2 = head;
	head = head->next;
	delete(temp2);
	length--;
}

void Singly::delFromFoot() {
	if (head == nullptr) {
		std::cout << "Herhangi bir düðüm bulunmamakta!";
		return;
	}
	if (head->next == nullptr) {
		delFromHead();
		return;
	}
	Node* temp2 = head;
	temp = head;
	while (temp2->next != nullptr) {
		temp2 = temp2->next;
		if (temp2->next != nullptr) temp = temp->next;
	}
	delete(temp2);
	temp->next = nullptr;
	length--;
}

void Singly::delFromBetween(int loc) {
	if (loc < 0 || loc >= length) throw IndexOverflowException("Ýstediðiniz index bu LinkedList'te bulunmamakta!");
	if (loc == 0) {
		delFromHead();
		return;
	}
	if (loc == length - 1) {
		delFromFoot();
		return;
	}
	temp = head;
	Node* temp2;
	while (loc - 1 > 0) { // temp, silinecek indexten bir önceki indexe tekabul eder
		temp = temp->next;
		loc--;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	delete(temp2);
	length--;
}

int Singly::getLength() {
	return length;
}