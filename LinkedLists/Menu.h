#pragma once
#include <iostream>
#include "Singly.h"
#include "Doubly.h"
#include "Circular.h"
#include "LinkedListOperationEnums.h"

class Menu {
private:
	bool tekrar, singlyCircularLoop, doublyCircularLoop;
	short secim, secimFonk;
	char secimChar;
	int eklenecekSayi;
	int konum;
	Singly singlyList;
	Doubly doublyList;
	Circular circularList;

public:
	void showMenu();
	void singlyMenu();
	void doublyMenu();
	void circularMenu();
	void singlyCircularMenu();
	void doublyCircularMenu();
};