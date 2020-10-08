/**
* @file b171210040_1A_Odev2
* @description Test
* @course 1-A
* @assignment 2
* @date 5.12.2018
* @author Yasin Güllü yasin.gullu@ogr.sakarya.edu.tr
*/
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

#include "Dlist.hpp"
int main()
{

	int  numara;
	int numaraSayisi = 0;
	string oku;
	fstream dosyaOku;
	dosyaOku.open("Sayi.txt", ios::in);

	dlist dll;

	while (!dosyaOku.eof())
	{
		oku = "";
		stringstream ss(oku);
		dosyaOku >> numara;
		numaraSayisi++;
		dll.push_back(numara);
	}
	dosyaOku.close();

	int d;
	int sec = 0;
	do {

		cout << "1-sola hareket" << endl;
		cout << "2-saga hareket" << endl;
		cout << "3-Enbuyukelemanicikar" << endl;
		cout << "4-Tum durumlari yazdir." << endl;
		cout << "5-cikis." << endl;
		cin >> sec;
		switch (sec)
		{
		case 1:

			system("cls");
			dll.sola_hareket();
			dll.display(numaraSayisi);

			break;

		case 2:
			system("cls");
			dll.saga_hareket();
			dll.display(numaraSayisi);
			break;


		case 3:
			//cout << "gormek istediginiz dugumu secin."; cin >> d;
			//dll.konumdan_goster(d);
			dll.EnBuyukElemanCikar();

			cout<<endl;
			break;

		case 4:
			system("cls");
			dll.display(numaraSayisi);
			

			break;

		case 5:
			break;

		default:
			cout << endl << "Yanlis tercih!" << endl;
			cin.ignore();
			cin.get();
			break;
		}


	} while (sec != 5);


}