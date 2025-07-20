#include "Menu.h"

void Menu::showMenu() {
	setlocale(LC_ALL, "Turkish");
	tekrar = true;
	singlyCircularLoop = false;
	doublyCircularLoop = false;
	while (tekrar) {
		std::cout << "**********************************************************\n";
		std::cout << "*                                                        *\n";
		std::cout << "*                                                        *\n";
		std::cout << "*     **********************************************     *\n";
		std::cout << "*     *    LinkedList programýna hoþgeldiniz.*     *\n";
		std::cout << "*     **********************************************     *\n";
		std::cout << "*                                                        *\n";
		std::cout << "*                                                        *\n";
		std::cout << "**********************************************************\n\n\n\n";

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
			case 1: singlyMenu(); break;
			case 2: doublyMenu(); break;
			case 3: circularMenu(); break;
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
}

void Menu::singlyMenu() {
	std::cout << "\nSINGLY LINKED LIST\n";
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secimFonk;
		if (secimFonk < 1 || secimFonk > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secimFonk < 1 || secimFonk > 9);
	switch (secimFonk) {
	case ADDTOHEAD:
		std::cout << "SINGLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addHead(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDBETWEEN:
		std::cout << "SINGLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		singlyList.addBetween(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDTOFOOT:
		std::cout << "SINGLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		singlyList.addFoot(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMHEAD:
		std::cout << "SINGLY LIST: BAÞTAN SÝLME\n";
		singlyList.delFromHead();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEBETWEEN:
		std::cout << "SINGLY LIST: ARADAN SÝLME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		singlyList.delFromBetween(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMFOOT:
		std::cout << "SINGLY LIST: SONDAN SÝLME\n";
		singlyList.delFromFoot();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case FINDLENGTH:
		std::cout << "SINGLY LIST: UZUNLUK BULMA\n";
		std::cout << "Listenin uzunluðu = " << singlyList.findLength() << "\n\n";
		break;
	case SEARCH: {
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
	case PRINTLIST:
		std::cout << "SINGLY LIST: LÝSTELEME\n";
		std::cout << "Liste: ";
		singlyList.printList();
		std::cout << "\n\n";
		break;
	}
}

void Menu::doublyMenu() {
	std::cout << "\nDOUBLY LINKED LIST\n";
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secimFonk;
		if (secimFonk < 1 || secimFonk > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secimFonk < 1 || secimFonk > 9);
	switch (secimFonk) {
	case ADDTOHEAD:
		std::cout << "DOUBLY LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addHead(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDBETWEEN:
		std::cout << "DOUBLY LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		doublyList.addBetween(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDTOFOOT:
		std::cout << "DOUBLY LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		doublyList.addFoot(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMHEAD:
		std::cout << "DOUBLY LIST: BAÞTAN SÝLME\n";
		doublyList.delFromHead();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEBETWEEN:
		std::cout << "DOUBLY LIST: ARADAN SÝLME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		doublyList.delFromBetween(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMFOOT:
		std::cout << "DOUBLY LIST: SONDAN SÝLME\n";
		doublyList.delFromFoot();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case FINDLENGTH:
		std::cout << "DOUBLY LIST: UZUNLUK BULMA\n";
		std::cout << "Liste uzunluðu: " << doublyList.findLength() << "\n\n";
		break;
	case SEARCH: {
		std::cout << "DOUBLY LIST: ARAMA\n";
		std::cout << "Aramak istediðiniz sayýyý girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlarý icin onceden olusturdugumuz degisken kullanildi.
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
	case PRINTLIST:
		std::cout << "DOUBLY LIST: LÝSTELEME\n";
		std::cout << "Liste: ";
		doublyList.printList();
		std::cout << "\n\n";
		break;
	}
}

void Menu::singlyCircularMenu() {
	std::cout << "\nSINGLY CIRCULAR LINKED LIST\n";
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secimFonk;
		if (secimFonk < 1 || secimFonk > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secimFonk < 1 || secimFonk > 9);
	switch (secimFonk) {
	case ADDTOHEAD: 
		std::cout << "SINGLY CIRCULAR LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		circularList.addHeadSingly(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDBETWEEN: 
		std::cout << "SINGLY CIRCULAR LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		circularList.addBetweenSingly(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDTOFOOT: 
		std::cout << "SINGLY CIRCULAR LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		circularList.addFootSingly(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMHEAD: 
		std::cout << "SINGLY CIRCULAR LIST: BASTAN SÝLME\n";
		circularList.delFromHeadSingly();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEBETWEEN: 
		std::cout << "SINGLY CIRCULAR LIST: ORTAYA EKLEME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		circularList.delFromBetweenSingly(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMFOOT: 
		std::cout << "SINGLY CIRCULAR LIST: SONDAN SÝLME\n";
		circularList.delFromFootSingly();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case FINDLENGTH: 
		std::cout << "SINGLY CIRCULAR LIST: UZUNLUK BULMA\n";
		std::cout << "Liste uzunluðu: " << circularList.findLengthSingly() << "\n\n";
		break;
	case SEARCH: {
		std::cout << "SINGLY CIRCULAR LIST: ARAMA\n";
		std::cout << "Aramak istediðiniz sayýyý girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlarý icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = circularList.searchSingly(eklenecekSayi, &kactane);
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
	case PRINTLIST: 
		std::cout << "DOUBLY LIST: LÝSTELEME\n";
		std::cout << "Liste: ";
		doublyList.printList();
		std::cout << "\n\n";
		break;
	}
}

void Menu::doublyCircularMenu() {
	std::cout << "\nDOUBLY CIRCULAR LINKED LIST\n";
	std::cout << "1- Baþa Ekleme\n2- Araya Ekleme\n3- Sona Ekleme\n4- Baþtan Silme\n5- Aradan Silme\n6- Sondan Silme\n7- Uzunluk Bulma\n";
	std::cout << "8- Arama\n9- Listeleme\nSeç beðen al: ";
	do { // kullanci hatali giris yaparsa donguye aldik
		std::cin >> secimFonk;
		if (secimFonk < 1 || secimFonk > 9) std::cout << "Lütfen 1-9 arasýnda bir deðer giriniz: ";
	} while (secimFonk < 1 || secimFonk > 9);
	switch (secimFonk) {
	case ADDTOHEAD:
		std::cout << "DOUBLY CIRCULAR LIST: BASA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		circularList.addHeadDoubly(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDBETWEEN:
		std::cout << "DOUBLY CIRCULAR LIST: ORTAYA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		std::cout << "Hangi index'e yerleþecek: ";
		std::cin >> konum;
		circularList.addBetweenDoubly(eklenecekSayi, konum);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case ADDTOFOOT:
		std::cout << "DOUBLY CIRCULAR LIST: SONA EKLEME\n";
		std::cout << "Ekleyeceðiniz sayýyý giriniz: ";
		std::cin >> eklenecekSayi;
		circularList.addFootDoubly(eklenecekSayi);
		std::cout << "Ýstediðiniz sayý baþarýyla eklenmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMHEAD:
		std::cout << "DOUBLY CIRCULAR LIST: BASTAN SÝLME\n";
		circularList.delFromHeadDoubly();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEBETWEEN:
		std::cout << "DOUBLY CIRCULAR LIST: ORTAYA EKLEME\n";
		std::cout << "Hangi index'teki silinecek: ";
		std::cin >> konum;
		circularList.delFromBetweenDoubly(konum);
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case DELETEFROMFOOT:
		std::cout << "DOUBLY CIRCULAR LIST: SONDAN SÝLME\n";
		circularList.delFromFootDoubly();
		std::cout << "Ýstediðiniz silme iþlemi baþarýyla gerçekleþmiþtir! Ýsterseniz listeleyerek kontrol edebilirsiniz.\n\n";
		break;
	case FINDLENGTH:
		std::cout << "DOUBLY CIRCULAR LIST: UZUNLUK BULMA\n";
		std::cout << "Liste uzunluðu: " << circularList.findLengthDoubly() << "\n\n";
		break;
	case SEARCH: {
		std::cout << "DOUBLY CIRCULAR LIST: ARAMA\n";
		std::cout << "Aramak istediðiniz sayýyý girin: ";
		std::cin >> eklenecekSayi; //bellekte ek yer kullanmamak icin add metotlarý icin oncecen olusturdugumuz degisken kullanildi.
		int kactane = 0; // aranan sayidan kac tane oldugu
		int* bulunanListe = circularList.searchDoubly(eklenecekSayi, &kactane);
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
	case PRINTLIST:
		std::cout << "DOUBLY CIRCULAR LIST: LÝSTELEME\n";
		std::cout << "Liste: ";
		circularList.printListDoubly();
		std::cout << "\n\n";
		break;
	}
}

void Menu::circularMenu() {
	std::cout << "\nCIRCULAR LINKED LIST\n";
	if (singlyCircularLoop) singlyCircularMenu();
	else if (doublyCircularLoop) doublyCircularMenu();
	else if (!singlyCircularLoop && !doublyCircularLoop) {
		do { //Loop if the user enters wrong input
			std::cout << "1- Singly Circular Linked List\n2- Doubly Circular Linked List\nSeç beðen al: ";
			std::cin >> secimFonk;
		} while (secimFonk != 1 && secimFonk != 2);
		if (secimFonk == 1) {
			singlyCircularLoop = true;
			singlyCircularMenu();
		}
		else {
			doublyCircularLoop = true;
			doublyCircularMenu();
		}
	}
}