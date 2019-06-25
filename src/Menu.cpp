#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Odaislem.h"
#include "Musteriislem.h"
#include "OdaKayitIslem.h"
#include "Menu.h"

using namespace std;

void Menu::OdaIslemMenu(Odaislem islem)
{
    int secim;
    bool hataVarmi = false;
    do
    {

        cout << "Oda Islemleri";
        cout << "\n-------------";
        cout << "\n1-Oda Ekle";
        cout << "\n2-Oda Sil";
        cout << "\n3-Odalari Listele";
        cout << "\n99-Ust Menu";

        if (hataVarmi)
            cout << "\n>>Hatali Secim!!";

        cout << "\nSeciminiz: ";

        hataVarmi = false;

        cin >> secim;
        switch (secim)
        {
        case 1:
            system("cls");
            islem.OdaEkle();
            break;
        case 2:
            system("cls");
            islem.OdaSil();
            break;
        case 3:
            system("cls");
            islem.OdaListele();
            break;
        case 99:
            system("cls");
            break;
        default:
            system("cls");
            hataVarmi = true;
            break;
        }

    } while (secim != 99);
}

void Menu::MusteriIslemMenu(Musteriislem islem)
{
    int secim;
	bool hataVarmi = false;

	do
	{
		cout << "Musteri Islemleri";
		cout << "\n-----------------";
		cout << "\n1-Musteri Ekle";
		cout << "\n2-Musteri Sil";
		cout << "\n3-Musteri Listele";
		cout << "\n99-Ust Menu";

		if (hataVarmi)
			cout << "\n>>Hatali Secim!!";

		cout << "\nSeciminiz: ";

		hataVarmi = false;

		cin >> secim;
		switch (secim)
		{
		case 1:	system("cls");
			islem.MusteriEkle();
			break;
		case 2:	system("cls"); 
			islem.MusteriSil();
			break;
		case 3: system("cls");
			islem.MusteriListele();
			break;
		case 99:system("cls");
		default:
			system("cls");
			hataVarmi = true;
			break;
		}
		
	} while (secim!=99);
	
}

void Menu::OdaKayitIslemMenu(OdaKayitIslem islem)
{
	int secim;
	bool hataVarmi = false;

	do
	{
		cout << "Oda Kayit Islemleri";
		cout << "\n-------------------";
		cout << "\n1-Odaya Musteri Kaydi Ekle";
		cout << "\n2-Odadan Musteri Kaydi Sil";
		cout << "\n99-Ust Menu";

		if(hataVarmi)
			cout << "\n>>Hatali Secim!!";
		cout << "\nSeciminiz: ";

		cin >> secim;

		hataVarmi = false;

		switch (secim)
		{
		case 1:	system("cls");
			islem.OdayaMusteriEkle();
			break;
		case 2:	system("cls");
			islem.OdadanMusteriSil();
			break;
		case 99:system("cls");
			break;
		default:
			system("cls");
			hataVarmi = true;
			break;
		}
	} while (secim != 99);

}

void Menu::Yonet(Odaislem islem1, Musteriislem islem2, OdaKayitIslem islem3)
{
    int secim;
    bool hataVarmi = false;
    do
    {
        cout << "Otel Islemleri";
        cout << "\n--------------";
        cout << "\n1-Oda Islemleri";
        cout << "\n2-Musteri Islemleri";
        cout << "\n3-Oda Kayit Islemleri";
        cout << "\n99-Cikis";

        if (hataVarmi)
            cout << "\n>>Hatali Secimm!!";

        cout << "\nSeciminiz: ";

        hataVarmi = false;
        cin >> secim;
        switch (secim)
        {
        case 1:
            system("cls");

            OdaIslemMenu(islem1);
            break;
        case 2:
            system("cls");
            MusteriIslemMenu(islem2);
            break;
        case 3:
            system("cls");
            OdaKayitIslemMenu(islem3);
            break;
        case 99:
            break;
        default:
            system("cls");
            hataVarmi = true;
            break;
        }

    } while (secim != 99);
}