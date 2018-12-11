
//Halil Ýbrahim YILMAZ 110757001
#include "otobus.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main()
{
	static int sira = 0;
	int giris;
	otobus otoBus[50];
	char string[6];
	int k = 0;
    anaMenu:
	//Ana Menü
	cout << "\n";
	cout << "\n";
	cout << "\t\tAna Menu\n";
	cout << "\n";
	cout << "\t\t1.Firma Girisi\n";
	cout << "\t\t2.Musteri Girisi\n";
	cout << "\t\t3.Cikis\n";
	cout << "\n";
	cout << "\t\tLutfen bir giris yapiniz :-->\n";
	cin >> giris;
	//Firma Giriþi
	if (giris==1)
	{
		int giris2;
		cout << "1-Otobus Ekle\n";
		cout << "2 - Sefer Bilgisi Ekle\n";
		cout << "3 - Sefer / Koltuk Bilgisi\n";
		cout << "4 - Bir Ust Menuye Don\n";
		cin >> giris2;
		//Otobüs Ekle
		if (giris2 == 1)
		{	
			
			k++;
			cout << "Eklenecek otobus numarasi: " << k << endl;
			otoBus[sira].KapasiteEkle();
			otoBus[sira].OtoModelEkle();
			otoBus[sira].PersonelSayiEkle();
			goto anaMenu;
		}
		//SeferBilgisi Ekle
		else if (giris2 == 2)
		{
			otoBus[sira].SehirEkleBaslangic();
			goto anaMenu;
		}
		//Sefer Koltuk Bilgisi
		else if (giris2 == 3)
		{
			otoBus[sira].SeferKoltukBilgisiGoster();

		}
		//Bir Önceki Menü
		else if (giris2 == 4)
		{
			goto anaMenu;
		}
	}
	//Müþteri Giriþi
	else if (giris==2)
	{
		musteriMenu:
		cout << "1.Seferleri Listele\n";
		cout << "2.Sefer Rezervasyon Yap\n";
		cout << "3.Bir Ust Menuye Don\n";
		cout << "4.Rezervasyon Goster\n";
	
		int giris3;
		cin >> giris3;
		//Seferleri Listele
		if (giris3==1)
		{
			otoBus[sira].SeferNoListele();

		}
		//Rezervasyon Yap
		else if (giris3==2)
		{
			otoBus[sira].RezervasyonYap();
			cout << "Onaylýyor musunuz? E/H\n";
			char onay;
			cin >> onay;
			if (onay == 'E')
			{
				int i;
				char c;
				srand(time(0));
				for (i = 0; i < 6; i++)
				{
					if (i == 0)
					{
						c = 48;
					}
					else if (i == 1)
					{
						c = 49;
					}
					else{
						c = rand() % 16 + 48;
					}
					if (c > 57)
						c = c + 7;

					string[i] = c;    
					
				}
			}
			else if (onay == 'H')
			{
				for (int i = 0; i <sira; i++)
				{
					delete(otoBus[sira].koltuk[i]);
					cout << "Rezervasyon silindi"<<endl;
				}
				cout << "---------------------" << endl;
				goto musteriMenu;
			}
			goto anaMenu;
		}
		//Üst Menüye dön
		else if (giris3==3)
		{
			goto anaMenu;
		}
		else if (giris3==4)
		{
			otoBus[sira].RezervasyonGoster();
		}
	}
	//Çýkýþ
	else if (giris=3)
	{
		exit(0);
	}
	else
		cout << "Hatali giris yaptiniz !!\n";
	
	return 0;
}