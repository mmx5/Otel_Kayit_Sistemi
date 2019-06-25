#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Odaislem.h"
#include "Musteriislem.h"
#include "OdaKayitIslem.h"
#include "Menu.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Turkish");
	Menu menu;
	Odaislem islem1;
	Musteriislem islem2;
	OdaKayitIslem islem3;
	
	menu.Yonet(islem1, islem2, islem3);
	
	
	return 0;
}