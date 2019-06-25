derlecalistir:program calistir

program:Kaynak.o Odaislem.o Musteriislem.o OdaKayitIslem.o Menu.o
	g++ ./lib/Kaynak.o ./lib/Odaislem.o ./lib/Musteriislem.o ./lib/OdaKayitIslem.o ./lib/Menu.o -o ./bin/program
Kaynak.o:
	g++ -I "./include" -c ./src/Kaynak.cpp -o ./lib/Kaynak.o
Odaislem.o:
	g++ -I "./include" -c ./src/Odaislem.cpp -o ./lib/Odaislem.o
Musteriislem.o:
	g++ -I "./include" -c ./src/Musteriislem.cpp -o ./lib/Musteriislem.o
OdaKayitIslem.o:
	g++ -I "./include" -c ./src/OdaKayitIslem.cpp -o ./lib/OdaKayitIslem.o
Menu.o:
	g++ -I "./include" -c ./src/Menu.cpp -o ./lib/Menu.o
calistir:
	./bin/program