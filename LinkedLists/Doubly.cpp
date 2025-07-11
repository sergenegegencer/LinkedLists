#include "Doubly.h"

void Doubly::printList() {
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	else {
		temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

int Doubly::findLength() {
	if (head == nullptr) return 0;
	int length = 0;
	temp = head;
	while (temp != nullptr) {
		length++;
		temp = temp->next;
	}
	return length;
}

int Doubly::traversal(int loc) {
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	else {
		temp = head;
		while (temp != nullptr) {
			if (temp->data == loc) return temp->data;
			temp = temp->next;
		}
		std::cout << "Arad���n�z de�er bulunamad�!\n";
		return -1;
	}
}

int* Doubly::search(int key, int* count){ //nullptr d�nd�rme ihtimali oldu�undan mutlaka bu metodu kullan�rken bir ko�ula koy
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	int* tempArr = new int[length]; //arad���m�z de�er var m� yok mu bilmedi�imizden ge�ici bir dizi olu�turduk
	temp = head;
	*count = 0;
	int index = 0; // say�y� arad���m�z, linkedlistteki indexler
	while (temp != nullptr) {
		if (temp->data == key) {
			tempArr[*count] = index; //anahtar say�n�n oldu�u indexi ge�ici diziye ata
			(*count)++;
		}
		temp = temp->next;
		index++; //bir sonraki node'a ge�tik
	}
	if (!(*count)) { //count 0 ise yani arad���m�z de�er yoksa
		std::cout << "Arad���n�z de�er bulunamad�!\n";
		return nullptr;
	}
	int* foundIndices = new int[*count]; //buldu�umuz indexleri tutmak i�in yeni bir dizi olu�turduk
	for (index = 0; index < *count; index++) {
		foundIndices[index] = tempArr[index]; //ge�ici dizideki indexleri yeni dizimize at�yoruz
	}
	delete[] tempArr; //ge�ici diziyi sil
	return foundIndices; //�NEML�: i�in bitti�inde bunu atad���n pointer� sil
}

void Doubly::addHead(int key) {
	Node* newNode = new Node(key);
	if (head == nullptr) {
		head = newNode;
		length++;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	length++;
}

void Doubly::addFoot(int key) {
	Node* newNode = new Node(key);
	if (head == nullptr) { //e�er list bo�sa
		head = newNode;
		length++;
		return;
	}
	temp = head;
	while (temp->next != nullptr) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	length++;
}

void Doubly::addBetween(int key, int loc) {
	if (head == nullptr) throw EmptyListException("Liste bo�!\n");
	if (loc < 0 || loc > length) throw IndexOverflowException("Belirtti�iniz index bulunmamakta!");
	Node* newNode = new Node(key);
	temp = head;
	for (int i = 0; i < loc - 1; i++) temp = temp->next; //temp loc'tan bir �nceki node
	Node* temp2 = temp->next; //loc
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = temp2;
	temp2->prev = newNode;
	length++;
}

void Doubly::delFromHead() {
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	if (head->next == nullptr) {
		delete head;
		length--;
		return;
	}
	Node* temp2 = head;
	temp = head->next;
	delete temp2;
	head = temp;
	length--;
}

void Doubly::delFromFoot() {
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	if (head->next == nullptr) {
		delete head;
		length--;
		return;
	}
	Node* temp2 = head;
	while (temp2->next != nullptr) {
		temp2 = temp2->next;
	}
	temp = temp2->prev;
	delete temp2;
	temp->next = nullptr;
	length--;
}

void Doubly::delFromBetween(int loc) {
	if (head == nullptr) throw EmptyListException("Liste bo�!");
	if (loc < 0 || loc >= length) throw IndexOverflowException("Belirttti�iniz index bulunmamakta!");
	if (loc == 0) {
		delFromHead();
		return;
	}
	if (loc == length - 1) {
		delFromFoot();
		return;
	}
	Node* temp2 = head;
	while (loc > 0) { //temp2, loc'a gelene kadar
		temp2 = temp2->next;
		loc--;
	}
	temp = temp2->prev;
	temp->next = temp2->next;
	temp2->next->prev = temp;
	delete temp2;
	length--;
}

int Doubly::getLength() {
	return length;
}