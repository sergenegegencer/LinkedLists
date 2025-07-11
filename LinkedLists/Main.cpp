#include <iostream>
#include <ctype.h>
#include "Singly.h"
#include "Doubly.h"

void singlyMenu(Singly& singlyList) {
	short secim;
	int eklenecekSayi;
	int konum;
	std::cout << "\nSINGLY LINKED LIST\n";
	std::cout << "1- Ba�a Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Ba�tan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSe� be�en al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secim;
		if (secim < 1 || secim > 9) std::cout << "L�tfen 1-9 aras�nda bir de�er giriniz: ";
	} while (secim < 1 || secim > 9);
	switch (secim) {
	case 1:
		std::cout << "SINGLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addHead(eklenecekSayi);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 2:
		std::cout << "SINGLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerle�ecek: ";
		std::cin >> konum;
		singlyList.addBetween(eklenecekSayi, konum);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 3:
		std::cout << "SINGLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addFoot(eklenecekSayi);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 4:
		std::cout << "SINGLY LIST: BA�TAN S�LME\n";
		singlyList.delFromHead();
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 5:
		std::cout << "SINGLY LIST: ARADAN S�LME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		singlyList.delFromBetween(konum);
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 6:
		std::cout << "SINGLY LIST: SONDAN S�LME\n";
		singlyList.delFromFoot();
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 7:
		std::cout << "SINGLY LIST: UZUNLUK BULMA\n";
		std::cout << "Listenin uzunlu�u = " << singlyList.findLength() << "\n\n";
		break;
	case 8: {
		std::cout << "SINGLY LIST: ARAMA\n";
		std::cout << "Aramak istedi�iniz say�y� girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlar� icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = singlyList.search(eklenecekSayi, &kactane);
		if (bulunanListe == nullptr) {
			std::cout << eklenecekSayi << " say�s�, listede bulunamam��t�r!\n\n";
			break;
		}
		std::cout << eklenecekSayi << " say�s�n�n bulundu�u indexler: ";
		for (int i = 0; i < kactane; i++) {
			if (i == kactane - 1) {
				std::cout << bulunanListe[i] << "\n";
				break;
			}
			std::cout << bulunanListe[i] << ", ";
		}
		std::cout << "�stedi�iniz arama i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	}
	case 9:
		std::cout << "SINGLY LIST: L�STELEME\n";
		std::cout << "Liste: ";
		singlyList.printList();
		std::cout << "\n\n";
	}
}

void doublyMenu(Doubly& doublyList) {
	short secim;
	int eklenecekSayi;
	int konum;
	std::cout << "\nDOUBLY LINKED LIST\n";
	std::cout << "1- Ba�a Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Ba�tan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSe� be�en al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secim;
		if (secim < 1 || secim > 9) std::cout << "L�tfen 1-9 aras�nda bir de�er giriniz: ";
	} while (secim < 1 || secim > 9);
	switch (secim) {
	case 1:
		std::cout << "DOUBLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addHead(eklenecekSayi);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 2:
		std::cout << "DOUBLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerle�ecek: ";
		std::cin >> konum;
		doublyList.addBetween(eklenecekSayi, konum);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 3:
		std::cout << "DOUBLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyece�iniz say�y� giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addFoot(eklenecekSayi);
		std::cout << "�stedi�iniz say� ba�ar�yla eklenmi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 4:
		std::cout << "DOUBLY LIST: BA�TAN S�LME\n";
		doublyList.delFromHead();
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 5:
		std::cout << "DOUBLY LIST: ARADAN S�LME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		doublyList.delFromBetween(konum);
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 6:
		std::cout << "DOUBLY LIST: SONDAN S�LME\n";
		doublyList.delFromFoot();
		std::cout << "�stedi�iniz silme i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 7:
		std::cout << "DOUBLY LIST: UZUNLUK BULMA\n";
		std::cout << "Liste uzunlu�u: " << doublyList.findLength() << "\n\n";
		break;
	case 8: {
		std::cout << "DOUBLY LIST: ARAMA\n";
		std::cout << "Aramak istedi�iniz say�y� girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlar� icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = doublyList.search(eklenecekSayi, &kactane);
		if (bulunanListe == nullptr) {
			std::cout << eklenecekSayi << " say�s�, listede bulunamam��t�r!\n\n";
			break;
		}
		std::cout << eklenecekSayi << " say�s�n�n bulundu�u indexler: ";
		for (int i = 0; i < kactane; i++) {
			if (i == kactane - 1) {
				std::cout << bulunanListe[i] << "\n";
				break;
			}
			std::cout << bulunanListe[i] << ", ";
		}
	}
		std::cout << "�stedi�iniz arama i�lemi ba�ar�yla ger�ekle�mi�tir! �sterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 9:
		std::cout << "DOUBLY LIST: L�STELEME\n";
		std::cout << "Liste: ";
		doublyList.printList();
		std::cout << "\n\n";
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Turkish");
	std::cout << "**********************************************************\n";
	std::cout << "*                                                        *\n";
	std::cout << "*                                                        *\n";
	std::cout << "*     **********************************************     *\n";
	std::cout << "*     *    LinkedList program�na ho�geldiniz.*     *\n";
	std::cout << "*     **********************************************     *\n";
	std::cout << "*                                                        *\n";
	std::cout << "*                                                        *\n";
	std::cout << "**********************************************************\n\n\n\n";

	bool tekrar = true; // bool degiskenlere deger atamayip islem yapmaya uygularsan error'u cakar sana
	short secim;
	char secimChar;
	Singly singlyList;
	Doubly doublyList;

	while (tekrar) {
		do { //kullanici hatali giris yaparsa donguye aldik
			std::cout << "1- Singly LinkedList\n";
			std::cout << "2- Doubly LinkedList\n";
			std::cout << "3- Circular LinkedList\n\n";
			std::cout << "Se� be�en al: ";
			std::cin >> secim;
		} while (secim < 1 || secim > 3);

		do { //kullanici tum bu islemleri tekrar yapmak isterse
			tekrar = false;
			switch (secim) {
			case 1:
				singlyMenu(singlyList);
				break;
			case 2:
				doublyMenu(doublyList);
				break;
			case 3: std::cout << "CIRCULAR LINKED LIST "; break;
			default: std::cout << "1, 2 veya 3 de�erlerinden birini gir\n";
			}

			std::cout << "Devam etmek ister misiniz? (E/H)";
			do {
				std::cin >> secimChar;
				secimChar = toupper(secimChar);
				if (secimChar != 'E' && secimChar != 'H') std::cout << "L�tfen klavyeye E ya da H harfini girin: ";
			} while (secimChar != 'E' && secimChar != 'H');
			if (secimChar == 'E') tekrar = true;
		} while (tekrar);
	}
	
	std::cout << "\n\nHO��AKALIN!";

	return 0;
}