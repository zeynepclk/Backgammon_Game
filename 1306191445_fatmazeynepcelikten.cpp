#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <cmath>
#include <conio.h>
#include <stdio.h>

using namespace std;
vector <char> tahta;
vector <int> tahta2;
int kirik_y = 0, giremedim = 0, kirik_x = 0, toplama_x = 0, toplama_y = 0;
ofstream zar_kayit, ekran_kayit;
ifstream ekran_okuma;
void aciklama(char a, int satir, int zar, char sira_kimde);
void oynatma(int sütun, int zar, char sira_kimde, int satir)
{
	
	int indis = 0;
	char hamle1_1;
	if (sira_kimde == 'X')
		indis = sütun - zar;
	else if (sira_kimde == 'Y')
		indis = sütun + zar;
	if (sira_kimde == tahta[sütun] && tahta2[sütun] != 0)
	{
		if (tahta.size() >= indis) {
			if (tahta[(indis)] == sira_kimde || tahta[(indis)] == ' ') {
				tahta2[sütun]--;
				if (tahta2[sütun] == 0)
					tahta[sütun] = ' ';
				tahta2[(indis)]++;
				tahta[(indis)] = sira_kimde;
			}
			else if (tahta[(indis)] != sira_kimde) //gideceği sütunda karşıkinin elemanı varsa
			{
				if (tahta2[indis] == 1) //gideceği sütunda 1 taş varsa
				{
					tahta2[sütun]--;
					if (tahta2[sütun] == 0)
						tahta[sütun] = ' ';
					tahta[(indis)] = sira_kimde;
					if (sira_kimde == 'X')
						kirik_y++;
					else if (sira_kimde == 'Y')
						kirik_x++;
				}
				else {
					cout << "Invalid move." << endl;
					cout << "Player " << sira_kimde << " in which column and row do you want to apply the '" << zar << "' dice" << endl;
					cin >> satir;
					cin >> hamle1_1;
					aciklama(hamle1_1, satir, zar, sira_kimde);
				}
			}
		}
		else {
			cout << "Invalid move." << endl;
			cout << "Player " << sira_kimde << " in which column and row do you want to apply the '" << zar << "' dice" << endl;
			cin >> satir;
			cin >> hamle1_1;
			aciklama(hamle1_1, satir, zar, sira_kimde);
		}
	}
	
	else {
		cout << "Invalid move." << endl;
		cout << "Player " << sira_kimde << " in which column and row do you want to apply the '" << zar << "' dice" << endl;
		cin >> satir;
		cin >> hamle1_1;
		aciklama(hamle1_1, satir, zar, sira_kimde);
	}
}
void aciklama(char a, int satir, int zar, char sira_kimde)
{
	char hamle1_1;
	int yeter = 0;
	if (satir == 2)
	{
		cout << "Invalid move." << endl;
		cout << "Player " << sira_kimde << " in which column and row do you want to apply the '" << zar << "' dice" << endl;
		cin >> satir;
		cin >> hamle1_1;
		aciklama(hamle1_1, satir, zar, sira_kimde);
	}
	switch (a)
	{
	case 'A':
			if (satir == 1 && tahta2[11] != 0)  oynatma(11, zar, sira_kimde, satir);
			else if (satir == 3 && tahta2[12] != 0) oynatma(12, zar, sira_kimde, satir);
			else if (tahta2[11] == 0 || tahta2[12] == 0) yeter = 1;
		break;
	case 'B':
		if (satir == 1 && tahta2[10] != 0) oynatma(10, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[13] != 0) oynatma(13, zar, sira_kimde, satir);
		else if (tahta2[10] == 0 || tahta2[13] == 0) yeter = 1;
		break;
	case 'C':
			if (satir == 1 && tahta2[9] != 0) oynatma(9, zar, sira_kimde, satir);
			else if (satir == 3 && tahta2[14] != 0) oynatma(14, zar, sira_kimde, satir);
			else if (tahta2[9] == 0 || tahta2[14] == 0) yeter = 1;
		break;
	case 'D':
			if (satir == 1 && tahta2[8] != 0) oynatma(8, zar, sira_kimde, satir);
			else if (satir == 3 && tahta2[15] != 0) oynatma(15, zar, sira_kimde, satir);
			else if (tahta2[8] == 0 || tahta2[15] == 0) yeter = 1;
		break;
	case 'E':
			if (satir == 1 && tahta2[7] != 0) oynatma(7, zar, sira_kimde, satir);
			else if (satir == 3 && tahta2[16] != 0) oynatma(16, zar, sira_kimde, satir);
			else if (tahta2[7] == 0 || tahta2[16] == 0) yeter = 1;
		break;
	case 'F':
		if (satir == 1 && tahta2[6] != 0) oynatma(6, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[17] != 0) oynatma(17, zar, sira_kimde, satir);
		else if (tahta2[6]== 0 || tahta2[17] == 0) yeter = 1;
		break;
	case 'G':
		if (satir == 1 && tahta2[5] != 0) oynatma(5, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[18] != 0) oynatma(18, zar, sira_kimde, satir);
		else if (tahta2[5] == 0 || tahta2[18] == 0) yeter = 1;
		break;
	case 'H':
		if (satir == 1 && tahta2[4] != 0) oynatma(4, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[19] != 0) oynatma(19, zar, sira_kimde, satir);
		else if (tahta2[4] == 0 || tahta2[19] == 0) yeter = 1;
		break;
	case 'I':
		if (satir == 1 && tahta2[3] != 0) oynatma(3, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[20] != 0) oynatma(20, zar, sira_kimde, satir);
		else if (tahta2[3] == 0 || tahta2[20]== 0) yeter = 1;
		break;
	case 'J':
		if (satir == 1 && tahta2[2] != 0) oynatma(2, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[21] != 0) oynatma(21, zar, sira_kimde, satir);
		else if (tahta2[2] == 0 || tahta2[21]== 0) yeter = 1;
		break;
	case 'K':
		if (satir == 1 && tahta2[1] != 0) oynatma(1, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[22] != 0) oynatma(22, zar, sira_kimde, satir);
		else if (tahta2[1] == 0 || tahta2[22] == 0) yeter = 1;
		break;
	case 'L':
		cout << "satir: " << satir << "tahta2 " << tahta2[0] << "tahta2 " << tahta2[23]<< endl;
		if (satir == 1 && tahta2[0] != 0)  oynatma(0, zar, sira_kimde, satir);
		else if (satir == 3 && tahta2[23] != 0) oynatma(23, zar, sira_kimde, satir);
		else if (tahta2[0] == 0 || tahta2[23] == 0) yeter = 1;
		break;
	}
	if (yeter == 1)
	{
		yeter = 0;
		cout << "Invalid move." << endl;
		cout << "Player " << sira_kimde << " in which column and row do you want to apply the '" << zar << "' dice" << endl;
		cin >> satir;
		cin >> hamle1_1;
		aciklama(hamle1_1, satir, zar, sira_kimde);
	}

}
void ekran_yaz(char sira, int zar1, int zar2, int kirik_x, int kirik_y)
{
	string bas = "\tA\tB\tC\tD\tE\tF    |    G\tH\tI\tJ\tK\tL  \n\t";
	string sira1 = "\n\n1\t";
	string sira2 = "\n\n\n2\t\tBroken Flake of X:";
	string sira3 = "       \n\n\n3\t";
	ekran_kayit << bas << sira1;
	cout << bas << sira1;
	for (int i = 11; i >= 0; i--)
	{
		cout << tahta2[i] << tahta[i] << "\t";
		ekran_kayit << tahta2[i] << tahta[i] << "\t";
	}
	cout << sira2 << kirik_x << "\t\t" << zar1 << "\t" << zar2 << "\t\tBroken Flake of Y:" << kirik_y << sira3;
	ekran_kayit << sira2 << kirik_x << "\t\t" << zar1 << "\t" << zar2 << "\t\tBroken Flake of Y:" << kirik_y << sira3;
	for (int i = 12; i < tahta.size(); i++)
	{
		cout << tahta2[i] << tahta[i] << "\t";
		ekran_kayit << tahta2[i] << tahta[i] << "\t";
	}
	cout << endl << endl;
	ekran_kayit << endl << endl;

}
void kiriktas(int zar, char sira)
{
	giremedim = 0;
	int indis = 0;
	char karsit;
	if (sira == 'X') karsit = 'Y';
	else if (sira == 'Y') karsit = 'X';

	if (sira == 'X') indis = 24 - zar;
	else if (sira == 'Y') indis = zar - 1;
	if (tahta[(indis)] == sira || tahta[(indis)] == ' ')
	{
		tahta2[(indis)]++; //yerleştir
		tahta[(indis)] = sira;
		if (sira == 'X')
			kirik_x--;
		else if (sira == 'Y')
			kirik_y--;
	}
	else if (tahta[indis] == karsit) // karşı eleman varsa
	{
		if (tahta2[(indis)] == 1)
		{
			tahta[indis] = sira;
			if (sira == 'X') {
				kirik_y++;
				kirik_x--;
			}
			else if (sira == 'Y') {
				kirik_x++;
				kirik_y--;
			}
		}
		else giremedim = 1;
	}
}
void toplama_aktif(int sira)
{
	int a = 0;
	if (sira == 'X')
	{
		for (int i = 0; i < 6; i++)
		{
			if (tahta[i] == 'X')
				a += tahta2[i];
		}
		if (a == 15)
			toplama_x = 1;
	}
	else
	{
		for (int i = 18; i < 24; i++)
		{
			if (tahta[i] == 'Y')
				a += tahta2[i];
		}
		if (a == 15)
			toplama_y = 1;
	}
}
void toplama(int sira, int zar)
{
	if (sira == 'X')
	{
		if (tahta[(zar - 1)] == 'X')
		{
			tahta2[(zar - 1)] --;
			if (tahta2[(zar - 1)] == 0) tahta[(zar - 1)] = ' ';
		}
	}
	else
	{
		if (tahta[(24 - zar)] == 'Y')
		{
			tahta2[(24 - zar)] --;
			if (tahta2[(24 - zar)] == 0) tahta[(24 - zar)] = ' ';
		}
	}
}
int kontrol(int sira)
{
	int bayrak = 0;
	if (sira == 'X')
	{
		for (int i = 0; i < 6; i++)
		{
			if (tahta2[i] != 0)
				bayrak = 1;
		}
	}
	else
	{
		for (int i = 18; i < 24; i++)
		{
			if (tahta2[i] != 0)
				bayrak = 1;
		}
	}
	return bayrak;

}
int main()
{
	string s;
	int zar1, zar2, satir = 0, say = 0, sayac = 0;
	char hamle1_1, hamle1_2, sira, sat = ' ', devammi;
	bool baslangic = 0, zar_bay = 0, eski = 0, yeni = 0;
	ekran_okuma.open("table.txt");
	while (getline(ekran_okuma, s))
	{
		if (sayac == 1) sayac = 2;
		if (s == "??")
		{
			cout << "There is an unfinished game. Would you like to continue? (Y / N)" << endl;
			devammi = _getch();
			if (devammi == 'N')
				yeni = 1;
			else if (devammi == 'Y')
			{
				zar_kayit.open("zar_kayit.txt", ios::app);
				ekran_kayit.open("table.txt", ios::app);
				sayac++;
				eski = 1;
			}
		}
		if (sayac == 4)
		{
			sira = s[0];
			break;
		}

		else if (sayac == 3)
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == '0')
					tahta.push_back(' ');
				else if (s[i] != 0)
					tahta.push_back(s[i]);
			}
			sayac++;
			this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		else if (sayac == 2)
		{
			string ten;
			vector <string> mytimeiscome;
			vector <string> sourcandy = { "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15" };
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] != ' ')
					ten += s[i];
				else if (s[i] == ' ')
				{
					mytimeiscome.push_back(ten); ten.clear();
				}
			}
			for (int i = 0; i < mytimeiscome.size(); i++)
			{
				for (int j = 0; j < 15; j++)
				{
					if (mytimeiscome[i] == sourcandy[j])
						tahta2.push_back(j);
				}
			}
			sayac++;
		}
	}
	srand(time(0));
	if (eski == 0 || yeni == 1)
	{
		zar_kayit.open("zar_kayit.txt");
		ekran_kayit.open("table.txt"); //yeni dosya olarak aç canım
		tahta2 = { 2,0,0,0,0,5,0,3,0,0,0,5,5,0,0,0,3,0,5,0,0,0,0,2 };
		tahta = { 'Y',' ',' ',' ',' ','X',' ','X',' ',' ',' ','Y','X',' ',' ',' ','Y',' ','Y',' ',' ',' ',' ','X' };
		cout << ("Welcome to the backgammon game. The rules of the game:\nMake your moves with capital letters.\nPlayer X's direction of play is clockwise\nPlayer Y's direction of play is counterclockwise.\nIf you want to exit the game, you must type 777 before entering your move.\nIf you don't have a piece to play with that dice, type 700 to skip the dice row.\nHave fun!");
		this_thread::sleep_for(std::chrono::milliseconds(7000));
		system("cls");

		while (baslangic == 0)
		{
			zar1 = 1 + rand() % 6;
			zar2 = 1 + rand() % 6;
			cout << "X:" << zar1 << "\nY:" << zar2 << endl;
			zar_kayit << "X:" << zar1 << "\nY:" << zar2 << endl;
			if (zar1 > zar2)
			{
				cout << "First player:X\n";
				zar_kayit << "First player:X" << endl;
				baslangic = 1;
				sira = 'X'; //x başlıyo
			}
			else if (zar1 < zar2)
			{
				cout << "First player:Y";
				zar_kayit << "First player:Y";
				baslangic = 1;
				sira = 'Y'; //y başlıyo
			}
			else
			{
				cout << "There is a draw, the dice are thrown again...\n";
				zar_kayit << "There is a draw, the dice are thrown again...\n";
			}
		}
		this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
	for (int i = 3; i > 0; i--)
	{
		system("cls");
		cout << "Our game will start after " << i << ". seconds. Player: " << sira;
		this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
	system("cls");
	while (true)
	{
		int bayrak = 0;
		if (say == 0)
		{
			zar1 = 1 + rand() % 6;
			zar2 = 1 + rand() % 6;
		}
		zar_kayit << sira << "->" << zar1 << "," << zar2 << endl;
		if (zar1 == zar2) { say++; }
		ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
		if (kirik_x > 0 && sira == 'X') {
			kiriktas(zar1, sira);
			if (giremedim == 1)//ilk zarda giremediyse
			{
				kiriktas(zar2, sira); //ikinci zarda tekrar girmeyi dene
				if (giremedim == 1) { //gene giremediysen hamle yok
					cout << "You have no moves to play." << endl;
					this_thread::sleep_for(std::chrono::milliseconds(2500));
					system("cls");
					if (say == 2) { say = 0; }
					if (say == 0)	sira = 'Y';
					continue;
				}
				else //ikinci zarda girdiysen 1.zar için hamleni gerçekleştirebilirsin
				{
					system("cls");
					ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
					cout << "Your broken stone has been placed with the second dice " << endl;
					cout << "Player " << sira << " in which column and row do you want to apply the '" << zar1 << "' dice" << endl;
					cin >> satir;
					if (satir == 777) break;
					cin >> hamle1_1;
					aciklama(hamle1_1, satir, zar1, sira);
					system("cls");
					ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
					if (say == 2) { say = 0; }
					if (say == 0)	sira = 'Y';
					continue;
				}
			}
			else if ((kirik_x > 0 || kirik_y > 0)) //ilk zarda girdiyse ve hala kırık taşı varsa 
			{
				cout << "Your broken stone has been placed with the first dice " << endl;
				kiriktas(zar2, sira); //ikinci zar için de dene
				if (giremedim == 1) { // giremediysen hamle yok
					cout << "You have no moves to play." << endl;
					this_thread::sleep_for(std::chrono::milliseconds(2500));
					system("cls");
				}
				sira = 'Y';
				continue;
			}
			else //ilk zarda girdiyse, kırık taşı da yoksa ikinci zar için hamle yap
			{
				system("cls");
				ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
				cout << "Your broken stone has been placed with the first dice " << endl;
				cout << "Player " << sira << " in which column and row do you want to apply the " << zar2 << " dice" << endl;
				cin >> satir;
				if (satir == 777) break;
				cin >> hamle1_2;
				aciklama(hamle1_2, satir, zar2, sira);
				system("cls");
				if (say == 2) { say = 0; }
				if (say == 0)	sira = 'Y';
				continue;
			}
		} // x'in kirik tas varsa //X'in kırık taşı varsa ve sıra X'teyse
		if (kirik_y > 0 && sira == 'Y') {
			kiriktas(zar1, sira);
			if (giremedim == 1)//ilk zarda giremediyse
			{
				kiriktas(zar2, sira); //ikinci zarda tekrar girmeyi dene
				if (giremedim == 1) { //gene giremediysen hamle yok
					this_thread::sleep_for(std::chrono::milliseconds(2500));
					system("cls");
					if (say == 2) { say = 0; }
					if (say == 0)	sira = 'X';
					continue;
				}
				else //ikinci zarda girdiysen 1.zar için hamleni gerçekleştirebilirsin
				{
					system("cls");
					ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
					cout << "Your broken stone has been placed with the second dice " << endl;
					cout << "Player " << sira << " in which column and row do you want to apply the '" << zar1 << "' dice" << endl;
					cin >> satir;
					if (satir == 777) break;
					cin >> hamle1_1;
					aciklama(hamle1_1, satir, zar1, sira);
					system("cls");
					ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
					if (say == 2) { say = 0; }
					if (say == 0)	sira = 'X';
					continue;
				}
			}
			else if (kirik_y > 0 && sira == 'Y') //ilk zarda girdiyse ve hala kırık taşı varsa 
			{
				cout << "Your broken stone has been placed with the first dice " << endl;
				kiriktas(zar2, sira); //ikinci zar için de dene
				if (giremedim == 1) { // giremediysen hamle yok
					cout << "You have no moves to play." << endl;
					this_thread::sleep_for(std::chrono::milliseconds(2500));
					system("cls");
				}
				if (say == 2) { say = 0; }
				if (say == 0)	sira = 'X';
				continue;
			}
			else //ilk zarda girdiyse, kırık taşı da yoksa ikinci zar için hamle yap
			{
				system("cls");
				ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
				cout << "Your broken stone has been placed with the first dice " << endl;
				cout << "Player " << sira << " in which column and row do you want to apply the " << zar2 << " dice" << endl;
				cin >> satir;
				if (satir == 777) break;
				cin >> hamle1_2;
				aciklama(hamle1_2, satir, zar2, sira);
				ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
				system("cls");
				if (say == 2) { say = 0; }
				if (say == 0) sira = 'X';
				continue;
			}
		}

		if (toplama_x == 0 && sira == 'X')toplama_aktif(sira); //toplama hiç aktif olmadıysa ve sıra x'teyse sorgula
		if (toplama_y == 0 && sira == 'Y')toplama_aktif(sira); //toplama hiç aktif olmadıysa ve sıra y'teyse sorgula
		if (toplama_x > 0 && sira == 'X') //sıra x'te ve toplaması aktifse
		{
			cout << "Player X:" << endl;
			toplama(sira, zar1);
			toplama(sira, zar2);
			bayrak = kontrol(sira);
			if (bayrak == 0) {
				cout << "Winner:" << sira << endl;
				ekran_kayit << "Winner:" << sira << endl << "***"; break;
			}
			else {
				this_thread::sleep_for(std::chrono::milliseconds(500));
				ekran_kayit << "---------------------------------------------------------------------------------------------------" << endl;
				system("cls");
				if (say == 2) { say = 0; }
				if (say == 0) sira = 'Y';
			}
			continue;
		}
		else if (toplama_y > 0 && sira == 'Y') //sıra Y'te ve toplaması aktifse
		{
			cout << "Player Y:" << endl;
			toplama(sira, zar1);
			toplama(sira, zar2);
			bayrak = kontrol(sira);
			if (bayrak == 0) {
				cout << "Winner:" << sira << endl;
				ekran_kayit << "Winner:" << sira << endl << "***"; break;
			}
			else {
				this_thread::sleep_for(std::chrono::milliseconds(500));
				ekran_kayit << "---------------------------------------------------------------------------------------------------" << endl;
				system("cls");
				if (say == 2) say = 0;
				if (say == 0) sira = 'X';
			}
			continue;
		}
		system("cls");
		ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
		cout << "Player " << sira << " in which column and row do you want to apply the '" << zar1 << "' dice" << endl;
		cin >> satir;
		if (satir == 777) break;
		if (satir != 700)
		{
			cin >> hamle1_1;
			aciklama(hamle1_1, satir, zar1, sira);
			system("cls");
			ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
			ekran_kayit << "---------------------------------------------------------------------------------------------------" << endl;
		}
		if (toplama_x == 0 && sira == 'X')toplama_aktif(sira); //toplama hiç aktif olmadıysa ve sıra x'teyse sorgula
		if (toplama_y == 0 && sira == 'Y')toplama_aktif(sira); //toplama hiç aktif olmadıysa ve sıra y'teyse sorgula
		if (toplama_x > 0 && sira == 'X') //sıra x'te ve toplaması aktifse
		{
			toplama(sira, zar1);
			toplama(sira, zar2);
			bayrak = kontrol(sira);
			if (bayrak == 0) { cout << "Winner:" << sira << endl; break; }
			else {
				this_thread::sleep_for(std::chrono::milliseconds(2000));
				system("cls");
				if (say == 2) { say = 0; }
				if (say == 0) sira = 'Y';
			}
			continue;
		}
		else if (toplama_y > 0 && sira == 'Y') //sıra Y'te ve toplaması aktifse
		{
			toplama(sira, zar1);
			toplama(sira, zar2);
			bayrak = kontrol(sira);
			if (bayrak == 0) { cout << "Winner:" << sira << endl; break; }
			else {
				this_thread::sleep_for(std::chrono::milliseconds(2000));
				system("cls");
				if (say == 2) { say = 0; }
				if (say == 0) sira = 'Y';
			}
			continue;
		}
		cout << "Player " << sira << " in which column and row do you want to apply the " << zar2 << " dice" << endl;
		cin >> satir;
		if (satir == 777) break;
		if (satir != 700)
		{
			cin >> hamle1_2;
			aciklama(hamle1_2, satir, zar2, sira);
			ekran_yaz(sira, zar1, zar2, kirik_x, kirik_y);
			ekran_kayit << "---------------------------------------------------------------------------------------------------" << endl;
		}
		else continue;
		if (say == 2) { say = 0; }
		if (say == 0)
		{
			if (sira == 'X') sira = 'Y';
			else sira = 'X';
		}
		system("cls");
	}
	if (satir == 777)
	{
		ekran_kayit << "??" << endl;
		for (int i = 0; i < tahta2.size(); i++)
			ekran_kayit << tahta2[i] << " ";
		ekran_kayit << endl;
		for (int i = 0; i < tahta.size(); i++)
		{
			if (tahta[i] == ' ')
				ekran_kayit << 0;
			else
				ekran_kayit << tahta[i];
		}
		ekran_kayit << endl;
		ekran_kayit << sira << endl;
	}
	ekran_okuma.close();
	zar_kayit.close();
	ekran_kayit.close();
	return 0;
}
