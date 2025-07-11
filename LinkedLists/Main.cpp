#include <iostream>
#include <ctype.h>
#include "Singly.h"
#include "Doubly.h"

void singlyMenu(Singly& singlyList) {
	short secim;
	int eklenecekSayi;
	int konum;
	std::cout << "\nSINGLY LINKED LIST\n";
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secim;
		if (secim < 1 || secim > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secim < 1 || secim > 9);
	switch (secim) {
	case 1:
		std::cout << "SINGLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addHead(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 2:
		std::cout << "SINGLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		singlyList.addBetween(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 3:
		std::cout << "SINGLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addFoot(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 4:
		std::cout << "SINGLY LIST: BAÞTAN SÝLME\n";
		singlyList.delFromHead();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 5:
		std::cout << "SINGLY LIST: ARADAN SÝLME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		singlyList.delFromBetween(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 6:
		std::cout << "SINGLY LIST: SONDAN SÝLME\n";
		singlyList.delFromFoot();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 7:
		std::cout << "SINGLY LIST: UZUNLUK BULMA\n";
		std::cout << "Listenin uzunluðu = " << singlyList.findLength() << "\n\n";
		break;
	case 8: {
		std::cout << "SINGLY LIST: ARAMA\n";
		std::cout << "Aramak istediðiniz sayýyý girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlarý icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = singlyList.search(eklenecekSayi, &kactane);
		if (bulunanListe == nullptr) {
			std::cout << eklenecekSayi << " sayýsý, listede bulunamamýþtýr!\n\n";
			break;
		}
		std::cout << eklenecekSayi << " sayýsýnýn bulunduðu indexler: ";
		for (int i = 0; i < kactane; i++) {
			if (i == kactane - 1) {
				std::cout << bulunanListe[i] << "\n";
				break;
			}
			std::cout << bulunanListe[i] << ", ";
		}
		std::cout << "Ýstediðiniz arama iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	}
	case 9:
		std::cout << "SINGLY LIST: LÝSTELEME\n";
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
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secim;
		if (secim < 1 || secim > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secim < 1 || secim > 9);
	switch (secim) {
	case 1:
		std::cout << "DOUBLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addHead(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 2:
		std::cout << "DOUBLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		doublyList.addBetween(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 3:
		std::cout << "DOUBLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addFoot(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 4:
		std::cout << "DOUBLY LIST: BAÞTAN SÝLME\n";
		doublyList.delFromHead();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 5:
		std::cout << "DOUBLY LIST: ARADAN SÝLME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		doublyList.delFromBetween(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 6:
		std::cout << "DOUBLY LIST: SONDAN SÝLME\n";
		doublyList.delFromFoot();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 7:
		std::cout << "DOUBLY LIST: UZUNLUK BULMA\n";
		std::cout << "Liste uzunluðu: " << doublyList.findLength() << "\n\n";
		break;
	case 8: {
		std::cout << "DOUBLY LIST: ARAMA\n";
		std::cout << "Aramak istediðiniz sayýyý girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlarý icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = doublyList.search(eklenecekSayi, &kactane);
		if (bulunanListe == nullptr) {
			std::cout << eklenecekSayi << " sayýsý, listede bulunamamýþtýr!\n\n";
			break;
		}
		std::cout << eklenecekSayi << " sayýsýnýn bulunduðu indexler: ";
		for (int i = 0; i < kactane; i++) {
			if (i == kactane - 1) {
				std::cout << bulunanListe[i] << "\n";
				break;
			}
			std::cout << bulunanListe[i] << ", ";
		}
	}
		std::cout << "Ýstediðiniz arama iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case 9:
		std::cout << "DOUBLY LIST: LÝSTELEME\n";
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
	std::cout << "*     *    LinkedList programýna hoþgeldiniz.*     *\n";
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
			std::cout << "Seç beðen al: ";
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
			default: std::cout << "1, 2 veya 3 deðerlerinden birini gir\n";
			}

			std::cout << "Devam etmek ister misiniz? (E/H)";
			do {
				std::cin >> secimChar;
				secimChar = toupper(secimChar);
				if (secimChar != 'E' && secimChar != 'H') std::cout << "Lütfen klavyeye E ya da H harfini girin: ";
			} while (secimChar != 'E' && secimChar != 'H');
			if (secimChar == 'E') tekrar = true;
		} while (tekrar);
	}
	
	std::cout << "\n\nHOÞÇAKALIN!";

	return 0;
}