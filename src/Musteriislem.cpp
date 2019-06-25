#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Musteriislem.h"

using namespace std;

struct Musteri
{
    int MusteriNo;
	string Isim;
	string Soyisim;
	string TC;
};


void Musteriislem::MusteriEkle()
{
    Musteri musteri;
    bool idKontrol = false;
    bool tcKontrol = false;
    string veri;
    string girdi;

    cout << "Musteri Ekleme Islemi";
    cout << "\n---------------------\n";
    cout << "(Not: Turkce Karakter Desteklenmemektedir)\n";
    cout << "Musteri Numarasi: ";
    cin >> girdi;

    while (!(girdi.length() <= 7))
    {
        cout << "Musteri Numarasi En Fazla 7 Basamakli Bir Sayi Olmalidir: ";
        cin >> girdi;
    }
    try
    {
        musteri.MusteriNo = stoi(girdi);
    }
    catch (const std::exception &)
    {
        cout << "Musteri Numarasi Rakamlardan Olusmalidir!..\n";

        cout << "Musteri Numarasi: ";
        cin >> girdi;
        while (!(girdi.length() <= 7))
        {
            cout << "Musteri Numarasi En Fazla 7 Basamakli Bir Sayi Olmalidir: ";
            cin >> girdi;
        }
    }
    musteri.MusteriNo = stoi(girdi);

    cout << "Musteri Isim: ";
    cin >> musteri.Isim;
    cout << "Musteri Soyisim: ";
    cin >> musteri.Soyisim;
    cout << "Musteri TC Numarasi: ";
    cin >> girdi;
    while (girdi.length() != 11)
    {
        cout << "TC Kimlik Numarasi 11 Haneli Olmalidir: ";
        cin >> girdi;
    }
    musteri.TC = girdi;

    ifstream dosyaOku;
    ofstream dosyaYaz;

    dosyaOku.open("MusteriListe.txt", ios::in);
    if (dosyaOku.is_open())
    {
        int sayac = 0;
        while (!dosyaOku.eof())
        {
            dosyaOku >> veri;
            if (sayac % 4 == 0)
            {
                if (veri == to_string(musteri.MusteriNo))
                    idKontrol = true;
            }
            else if (sayac % 4 == 3)
            {
                if (veri == musteri.TC)
                    tcKontrol = true;
            }
            sayac++;
        }
        if (idKontrol)
            cout << "Bu Musteri Numarasina Sahip Musteri Zaten Var !..\n";
        else if (tcKontrol)
            cout << "Bu TC Kimlik Numarasina Sahip Musteri Zaten var !..\n";
        else if (idKontrol && tcKontrol)
            cout << "Bu TC Kimlik ve Musteri Numarasina Sahip Musteri Zaten var !..";
        else
        {
            dosyaYaz.open("MusteriListe.txt", ios::app);
            if (dosyaYaz.is_open())
                dosyaYaz << endl
                         << left << setw(8) << musteri.MusteriNo << setw(10) << musteri.Isim << setw(13) << musteri.Soyisim << setw(11) << musteri.TC;
            else
                cout << "MusteriListe.txt bulunamadi\n";
            dosyaYaz.close();
            cout << "Musteri basariyla eklendi ...\n";
        }
    }
    else
        cout << "MusteriListe.txt bulunamadi\n";

    dosyaOku.close();
}

void Musteriislem::MusteriSil()
{
    string girdi;
	
	bool hataKontrol = false;
	bool doluKontrol = false;
	
	cout << "Musteri Silme Islemi";
	cout << "\n--------------------\n";
	cout << "Silmek Istediginiz Musterinin Musteri Numarasini Giriniz: ";
	cin >> girdi;

	string veri1, veri2, veri3, veri4;
	string kVeri1, kVeri2;
	ifstream dosyaOku, kontrolDosya;
	ofstream dosyaYaz;
	
	kontrolDosya.open("OdaListe.txt");
	if (kontrolDosya.is_open())
	{
		while (!kontrolDosya.eof())
		{
			kontrolDosya >> kVeri1 >> kVeri2;
			if (kVeri2 == girdi)
				doluKontrol = true;
		}
	}
	else
		cout << "OdaListe.txt bulunamadi\n";


	kontrolDosya.close();


	if (!doluKontrol)
	{
        bool noKontrol = false;
		dosyaOku.open("MusteriListe.txt");
		dosyaYaz.open("new.txt");

		if (dosyaOku.is_open())
		{
			dosyaOku >> veri1 >> veri2 >> veri3 >> veri4;
			if (veri1 == girdi)
			{
				noKontrol= true;
				hataKontrol = true;
			}
			else
				dosyaYaz << left << setw(8) << veri1 << setw(10) << veri2 << setw(13) << veri3 << setw(11) << veri4;


			while (!dosyaOku.eof())
			{
				dosyaOku >> veri1 >> veri2 >> veri3 >> veri4;
				if (veri1 == girdi)
				{
					
					hataKontrol = true;
				}
				else if (veri1 != girdi && noKontrol)
				{
					noKontrol=false;
					dosyaYaz << left << setw(8) << veri1 << setw(10) << veri2 << setw(13) << veri3 << setw(11) << veri4;
				}
				else
					dosyaYaz << endl << left << setw(8) << veri1 << setw(10) << veri2 << setw(13) << veri3 << setw(11) << veri4;
			}

			if (!hataKontrol)
				cout << "Silmek istediginiz musteri numarasi bulunamadi..\n";
			else
				cout << "Musteri basariyla silindi..\n";


		}
		else
			cout << "MusteriListe.txt bulunamadi\n";


		dosyaYaz.close();
		dosyaOku.close();

		remove("MusteriListe.txt");
		rename("new.txt", "MusteriListe.txt");
	}
	else
		cout << "Musteriyi Silmeden Once Lutfen Kayitli Oldugu Odadan Kaydini Siliniz!...\n";
	
}

void Musteriislem::MusteriListele()
{
	string veri;
	int secim;

	ifstream dosya;
	dosya.open("MusteriListe.txt", ios::in);
	if (dosya.is_open())
	{
		while (!dosya.eof())
		{
			getline(dosya, veri);;
			cout << veri << endl;
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
		cout << "MusteriListe.txt bulunamadi\n";

}