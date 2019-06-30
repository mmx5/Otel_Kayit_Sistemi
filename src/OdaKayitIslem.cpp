#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "OdaKayitIslem.h"

using namespace std;

void OdaKayitIslem::OdayaMusteriEkle()
{
    cout << "Odaya Musteri Ekleme Islemi";
	cout << "\n---------------------------\n";

	cout << "\n------------ ODA LISTESI ------------\n";
	ifstream liste;
	liste.open("OdaListe.txt");
	string list;
	while (!liste.eof())
	{
		getline(liste,list);
		cout<<list<<endl;
	}

	liste.close();

	string girdi1, girdi2, veri1, veri2;

	bool girdiKontrol = false;
	bool odaKontrol = false;
	bool musteriKontrol = false;

	
	cout << "\nMusteriyi Eklemek Istediginiz Oda Ismini Giriniz: ";
	cin >> girdi1;
	cout << "\nEklemek Istediginiz Musterinin Musteri Numarasini Giriniz: ";
	cin >> girdi2;

	ofstream yeniDosya;
	ifstream dosyaOku, dosyaOku2;
	dosyaOku.open("OdaListe.txt");
	dosyaOku2.open("MusteriListe.txt");
	yeniDosya.open("new.txt");

	if (dosyaOku.is_open() && dosyaOku2.is_open())
	{

		/** BAŞ *********************   MÜŞTERİ KONTROL İŞLEMİ   **************************/
		int sayac = 0;
		while (!dosyaOku2.eof())
		{
			dosyaOku2 >> veri2;
			if (sayac % 4 == 0)
			{
				if (veri2 == girdi2)
					musteriKontrol = true;
			}
			sayac++;
		}
		/** SON *********************   MÜŞTERİ KONTROL İŞLEMİ   **************************/


		/** BAŞ *********************   ODAYA ATAMA İŞLEMİ   **************************/
		dosyaOku >> veri1 >> veri2;
		if (veri1 == girdi1)
		{
			if (veri2 == "BOS" || musteriKontrol)
				yeniDosya << left << setw(16) << veri1 << girdi2;
			else {
				yeniDosya << left << setw(16) << veri1 << veri2;
				odaKontrol = true;
			}
			girdiKontrol = true;
		}
		else
			yeniDosya << left << setw(16) << veri1 << veri2;



		while (!dosyaOku.eof())
		{
			dosyaOku >> veri1 >> veri2;
			if (veri1 == girdi1)
			{
				if (veri2 == "BOS" || musteriKontrol)
					yeniDosya << endl << left << setw(16) << veri1 << girdi2;
				else
				{
					yeniDosya << endl << left << setw(16) << veri1 << veri2;
					odaKontrol = true;
				}
				girdiKontrol = true;
			}
			else
				yeniDosya << endl << left << setw(16) << veri1 << veri2;

		}
		/** SON *********************   ODAYA ATAMA İŞLEMİ   **************************/
	}
	else
		cout << "MusterListe.txt veya OdaListe.txt bulunamadi\n";

	yeniDosya.close();
	dosyaOku2.close();
	dosyaOku.close();

	
	if (girdiKontrol && !odaKontrol && musteriKontrol)
	{
		remove("OdaListe.txt");
		rename("new.txt", "OdaListe.txt");
		cout << "\nAtama islemi basarili..\n";
	}
	else if (odaKontrol)
		cout << "Musteri Atanacak Oda Dolu, Lutfen Once Odadan Musteri Kaydini Siliniz..\n";
	else if (!musteriKontrol)
		cout << "Odaya Atamak Istediginiz Musteri Numarasi Kaydi Bulunmamaktadir!..\n";
	else
		cout << "Girdiginiz Oda Ismine Ait Veri Bulunamadi..\n\n";

	
}
void OdaKayitIslem::OdadanMusteriSil()
{
        cout << "Odadan Musteri Silme Islemi";
	cout << "\n---------------------------\n";

	string girdi, veri1, veri2;
	bool odaKontrol = false;
	cout << "Musteriyi Cikarmak Istediginiz Odanin Ismini Giriniz: ";
	cin >> girdi;

	ifstream dosyaOku;
	ofstream dosyaYaz;
	dosyaOku.open("OdaListe.txt");
	dosyaYaz.open("new.txt");

	dosyaOku >> veri1 >> veri2;
	if (veri1 == girdi)
	{
		dosyaYaz << left << setw(16) << veri1 << "BOS";
		odaKontrol = true;
	}
	
	while (!dosyaOku.eof())
	{
		dosyaOku >> veri1 >> veri2;
		if (veri1 == girdi)
		{
			dosyaYaz << endl << left << setw(16) << veri1 << "BOS";
			odaKontrol = true;
		}
		else
			dosyaYaz << endl << left << setw(16) << veri1 << veri2;
	}

	if (!odaKontrol)
		cout << "Aradiginiz Oda Bulunmamaktadir.\n";
	else
		cout << "Islem Basarili..\n";

	dosyaYaz.close();
	dosyaOku.close();


	remove("OdaListe.txt");
	rename("new.txt", "OdaListe.txt");
    
}
    