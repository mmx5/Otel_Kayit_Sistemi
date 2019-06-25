#include "Odaislem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void Odaislem::OdaEkle()
{
    ofstream dosya;
	ifstream dosyaOku;
	string girdi, veri1, veri2;
	bool girdiKontrol = false;



	cout << "Oda Ekleme Islemi";
	cout << "\n----------------";
	cout << "\nEklemek istediginiz Oda Ismini giriniz: ";
	cin >> girdi;

	dosyaOku.open("OdaListe.txt");
	if (dosyaOku.is_open())
	{
		while (!dosyaOku.eof())
		{
			dosyaOku >> veri1 >> veri2;
			if (veri1 == girdi)
				girdiKontrol = true;
		}

		dosyaOku.close();

		if (girdiKontrol == true)
			cout << "Eklemek Istediginiz Oda Zaten Mevcut!..\n";
		else if (girdi == "")
			cout << "Girdiginiz Oda Ismi Gecerli Degil!..\n";
		else
		{

			dosya.open("OdaListe.txt", ios::app);

			dosya << endl << left << setw(16) << girdi << "BOS";

			dosya.close();
			cout << "Ekleme Islemi Basarili..\n";
		}

	}
	else
		cout << "OdaListe.txt bulunamadi\n";

}

void Odaislem::OdaSil()
{
    string girdi, veri1, veri2;
	
	bool girdiKontrol = false;
	bool hataKontrol = false;
	bool doluOdaKontrol = false;

	cout << "Oda Silme Islemi";
	cout << "\n-----------------";
	cout << "\nSilmek Istediginiz Oda Ismini Giriniz: ";
	cin >> girdi;
	
	ofstream yeniDosya;
	ifstream dosyaOku;
	dosyaOku.open("OdaListe.txt");
	yeniDosya.open("new.txt");
	if (dosyaOku.is_open())
	{
		dosyaOku >> veri1 >> veri2;
		if (veri1 == girdi && veri2 != "BOS")
		{
			cout << "Odayi Silmeden Once LUtfen Odadaki Musteri Kaydini Siliniz!\n";
			doluOdaKontrol = true;
		}
		if (veri1 == girdi && veri2 == "BOS")
		{
			girdiKontrol = true;
			hataKontrol = true;
		}
		else
			yeniDosya << left << setw(16) << veri1 << veri2;

		
		while (!dosyaOku.eof())
		{
			dosyaOku >> veri1 >> veri2;
			if (veri1 == girdi && veri2 != "BOS")
			{
				cout << "Odayi Silmeden Once Lutfen Odadaki Musteri Kaydini Siliniz!\n";
				doluOdaKontrol = true;
			}
			if (veri1 == girdi && veri2 == "BOS")
			{
				girdiKontrol = true;
				hataKontrol = true;
			}
			else if (veri1 != girdi && girdiKontrol)
			{
				yeniDosya << left << setw(16) << veri1 << veri2;
				girdiKontrol = false;
			}
			else
				yeniDosya << endl << left << setw(16) << veri1 << veri2;

		}

	}
	else
		cout << "OdaListe.txt bulunamadi\n";


	
	yeniDosya.close();
	dosyaOku.close();

	remove("OdaListe.txt");
	rename("new.txt", "OdaListe.txt");


	if (hataKontrol)
		cout << "\nSilme islemi basarili..\n";
	else if (!hataKontrol && !doluOdaKontrol)
		cout << "Girdiginiz Oda Ismine Ait Veri Bulunamadi..\n\n";
	
}

void Odaislem::OdaListele()
{
	string veri1, veri2;
	int secim;

	ifstream dosya;
	dosya.open("OdaListe.txt",ios::in);
	if (dosya.is_open()) {

		while (!dosya.eof())
		{
			dosya >> veri1 >> veri2;
			cout << left << setw(14) << veri1 << veri2 << endl;
		}

		dosya.close();
		do
		{
			cout << "99-Ust Menu\n";
			cout << "Seciminiz: ";
			cin >> secim;
			if (secim != 99)
			{
				system("cls");
				cout << ">>Hatali Secim!!\n";
			}
			else
				system("cls");
		} while (secim != 99);
	}
	else
		cout << "OdaListe.txt bulunamadı\n";
	
	
	
}


