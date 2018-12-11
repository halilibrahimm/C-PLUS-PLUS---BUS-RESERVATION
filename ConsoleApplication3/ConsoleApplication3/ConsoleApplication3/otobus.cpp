
//Halil Ýbrahim YILMAZ 110757001
#include "otobus.h"
#include <iostream>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
otobus::otobus()
{}

otobus otoBus[50];
static int sira = 0;
void otobus::KapasiteEkle()
{
	cout << "Lutfen kapasiteyi giriniz: \n";
	cin >> otoBus[sira].kapasiteEkle;
}
void otobus::OtoModelEkle()
{
	cout << "Lutfen otobusun modelini giriniz: \n";
	cin>>otoBus[sira].otoModelEkle;
}
void otobus::PersonelSayiEkle()
{
	if (kapasiteEkle[sira]>30)
	{ 
		cout << "Otobus kapasitesi 30 kisi uzeri oldugu icin mevcut personel sayisi 3 kisidir\n";
		personelEkle[sira]= 3;
		otoBus[sira].personelEkle;
	}
	else
	{
		cout << "Otobus kapasitesi 30 kisi alti oldugu icin mevcut personel sayisi 2 kisidir\n";
		personelEkle[sira] = 2;
		otoBus[sira].personelEkle;
	}
}

//SeferBigisi
void otobus::SeferNoEkle()
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
		if (c>57)
			c = c + 7;

		string[i] = c;  
		cout << string[i];
	}
	
}
void otobus::SehirEkleBaslangic()//Hocam sefer numarsýnýn yanýnda baþka ifadeler geldiði için sefer numarasýndan otobüsü bulmuyor yani girilen deðerle eþleþmiyor
//Onun için þehir isminden bulduruyorum
{
	cout << "Sefer no:";
	otoBus[sira].SeferNoEkle();
	cout << "Lutfen kapasiteyi giriniz: \n";
	cin >> otoBus[sira].kapasiteEkle;
	cout << "Lutfen sefer gereken hasilati giriniz \n";
	cin >> otoBus[sira].hasilatEkle;
	cout << "Lutfen gidilecek sehri giriniz \n";
	cin >> otoBus[sira].varisSehriEkle;
	cout << "Lutfen sefer baslangic sehrini giriniz \n";
	cin >> otoBus[sira].baslangicSehirEkle;
	cout << "Lutfen tahmini gidis  saatini giriniz \n";
	cin >> otoBus[sira].varisSaatiEkle;
	;
	for (int i = 0; i < 2; i++)
	{
		a[i]= varisSaatiEkle[i] % 10;
	}
	if (a[0, 1] == 01)
	{
		otoBus[sira].varisSaatiEkle;

	}
	else
		varisSaatiEkle[4] = varisSaatiEkle[4] + 1;
	otoBus[sira].varisSaatiEkle;
	cout << "Lutfen sefer baslangic saatini giriniz \n";
	cin >> otoBus[sira].kalkisSaatEkle;
	cout << "Lutfen kullanmak istediginiz otobusun nosunu giriniz: \n";
	cin >> otoBus[sira].otoNo2[6];
	otoBus[sira].BosKoltuk();
	sira++;
}
void otobus::UcretGoster()
{
	int a;
	for (int i = 0; i < sira; i++)
	{
		a=hasilatEkle[i]/ kapasiteEkle[i];
	}
	cout << a;
}
void otobus::SeferKoltukBilgisiGoster()
{
	int n;
	cout << "Lutfen bir sefer no seciniz: ";
	cin >> seferNoGir;
	for (n = 0; n <= sira; n++)
	{
		if (strcmp(otoBus[n].baslangicSehirEkle, seferNoGir) == 0)
		{
			break;
		}
	}
	while (n <= sira)
	{

		cout << "Sefer no:";
		otoBus[sira].SeferNoEkle();
		cout << endl;
		cout << "Otobus no: " << otoBus[n].otoNoEkle << endl;
		cout << "Otobus model no: " << otoBus[n].otoModelEkle;
		cout << "Varis saati: " << otoBus[n].varisSaatiEkle << endl;
		cout << "Kalkis saati: " << otoBus[n].kalkisSaatEkle << endl;
		cout << "Basangicsehri:" << otoBus[n].baslangicSehirEkle << endl;
		cout << "Varis saati: " << otoBus[n].varisSehriEkle << endl;
		cout << "Toplam hasilat: " << otoBus[n].hasilatEkle << endl;
		cout << "Kapasite: " << otoBus[n].kapasiteEkle << endl;
		otoBus[sira].PersonelSayiEkle();
		
		break;
	}

}
void otobus::Pozisyon(int k)
{
	
	int f = 0;
	int t = 0;
	
	for (int i = 0; i<9; i++)

	{

		cout << "\n";

		for (int j = 0; j<5; j++)

		{
			f++;

			if (strcmp(otoBus[k].koltuk[i][j], "Bos") == 0)

			{

				cout.width(5);

				cout.fill(' ');

				cout << f<< ".";

				cout.width(10);

				cout.fill(' ');

				cout << otoBus[k].koltuk[i][j];

				t++;

			}

			else

			{

				cout.width(5);

				cout.fill(' ');

				cout << f << ".";

				cout.width(10);

				cout.fill(' ');

				cout << otoBus[k].koltuk[i][j];

			}

		}

	}

	cout << "burada " << t << " Sefer no ";
		otoBus[k].SeferNoEkle();

}

//Müþteri giriþi
void otobus::SeferNoListele()
{
	for (int i = 0; i < sira; i++)
	{
		cout << "- - - - - - - - - - - - - -  " << endl;
		cout << "Otobus no:" << otoBus[i].otoNoEkle << endl;
		cout << "Bulunulan yer:" << otoBus[i].baslangicSehirEkle << endl;
		cout << "Gidilecek yer:" << otoBus[i].varisSehriEkle << endl;
		cout << "Kalkis saati:" << otoBus[i].kalkisSaatEkle << endl;
		cout << "Varis saati:" << otoBus[i].varisSaatiEkle << endl;
	
	}
}

void otobus::RezervasyonYap()
{
	
	int koltuk;
	char koltukSec[6];
top:
	cout << "Rezervasyon yapmak istediginiz sefer nosunu giriniz: ";
	cin >> koltukSec;
	int k=0;
	for (k = 0; k <= sira; k++)

	{

		if (strcmp(otoBus[k].baslangicSehirEkle, koltukSec) == 0)

			break;

	}

	while (k<=sira)
	{
		cout << "Koltuk numarasini giriniz: ";
		cin >> koltuk;
		if (strcmp(otoBus[k].koltuk[koltuk / 4][(koltuk % 4) - 1], "Bos") == 0)
		{
			cout << "Adiniz ve soyadinizi giriniz: ";
			cin >> otoBus[k].koltuk[koltuk / 4][(koltuk % 4) - 1];
			break;
		}
		else
		{
			cout << "Koltuk dolu" << endl;
			goto top;
		}
	}
	if (k>sira)
	{
		cout << "Lutfen dogru bir sefer no giriniz: ";
		goto top;
	}
}
void otobus::BosKoltuk()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			strcpy_s(otoBus[sira].koltuk[i][j], "Bos");
		}
	}
}
void otobus::RezervasyonGoster()
{
	int n;
	cout << "Lutfen bir sefer no seciniz: ";
	cin >> seferNoGir;
	for (n = 0; n <= sira; n++)
	{
		if (strcmp(otoBus[n].baslangicSehirEkle, seferNoGir) == 0)
		{
			break;
		}
	}
	while (n<=sira)
	{
		otoBus[0].Pozisyon(n);
		int a = 1;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				a++;
				if (strcmp(otoBus[n].koltuk[i][j], "Bos") != 0)
					cout << "\nKoltuk no:" << (a - 1) << "Rezervasyon yeri " << otoBus[n].koltuk[i][j];
			}

		}
		break;
	}
}