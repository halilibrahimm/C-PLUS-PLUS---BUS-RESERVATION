#include<stdio.h>

#include <conio.h>

#include<stdlib.h>

#include<math.h>

void veriYarat();

void sirala();

void yeniEkle();

void sil();

void araSiradan();

void araIkili();

int i, j, k, enkucuk, sayi[200] = { 0 }, yeni, pozisyon, n = 50, ara, alt = 0, ust = 50, orta, acikmi;

int main()

{

	int sec;

	do{

		printf("\n\n  *********ANA MENU**********\n\n");

		printf("  1.Dizinkli degiskeni Random ile yaratma\n");

		printf("  2.Siralama\n");

		printf("  3.Yeni Ekleme\n");

		printf("  4.Silme\n");

		printf("  5.Arama siradan\n");

		printf("  6.Arama Ikili\n");

		printf("  7.Cikis\n");

		scanf("%d", &sec);

		switch (sec)

		{

		case 1:veriYarat(); break;

		case 2:sirala(); break;

		case 3:yeniEkle(); break;

		case 4:sil(); break;

		case 5:araSiradan(); break;

		case 6:araIkili(); break;

		}

	} while (sec <= 6);

	return 0;

}

void veriYarat(void)

{

	for (i = 0; i<50; i += 1)

	{
		srand(i);

		k = rand() % 500;

		sayi[i] = k;

	}

	acikmi = 1;

	printf("Veri Yaratildi\n");

};

void sirala(void)

{

	for (i = 0; i <= n - 1; i++)

	{

		enkucuk = sayi[i];

		pozisyon = i;

		for (j = i + 1; j<n - 1; j++)
		if (sayi[j]<enkucuk){
			enkucuk = sayi[i];
			pozisyon = j;
		}

		sayi[pozisyon] = sayi[i];

		sayi[i] = enkucuk;

	};

	printf("Sayilar siralandi\n");

	for (i = 0; i<n; i++)

	{

		printf("%d\n", sayi[i]);

	};

}

//* Ekleme Baþlangýç *//

void yeniEkle(void)

{

	if (acikmi != 1)

	{

		printf("Veri yaratilmadi ekleme yapamazsiniz");

	}

	else {

		printf("Eklenecek Tam Sayiyi Giriniz \n");

		scanf("%d", &yeni);

		for (i = 0; i<n; i++)

		if (sayi[i]>yeni) break;

		for (int j = n; j>i; j--)

			sayi[j] = sayi[j - 1];

		sayi[i] = yeni;

		n += 1;

		printf("Sayi Eklendi");

		for (i = 0; i<n; i++) //listeleme baþlangýç

		{

			printf("%d\n", sayi[i]);

		};

	} // listeleme sonuç

}

//* Bitiþ *//

//* Silme Baþlangýç *//

void sil(void){
	if (acikmi != 1)

	{

		printf("Veri yaratilmadi silme yapamazsiniz");

	}

	else {

		printf("Silinecek Sayiyi Giriniz \n");

		scanf("%d", &ara);

		for (i = 0; i<n; i++) {

			if (sayi[i] == ara) break;

		}

		for (j = i; j<n; j++) {

			sayi[j] = sayi[j + 1];

		}

		n = n - 1;

		printf("Sayi Silindi \n");

		for (i = 0; i<n; i++)  // listeleme baþlangýç

		{
			printf("%d\n", sayi[i]);
		};

	} //listeleme sonuç

}

/* Bitiþ */

//* Sýradan Arama Baþlangýç *//

void araSiradan(void){

	printf("Aranacak Degeri Giriniz ? \n");

	scanf("%d", &ara);

	for (k = 0; k <= 49; k++)

	if (sayi[k] == ara) { printf("%d degeri %d.Sirada bulundu", ara, k + 1); break; }

	if (k>49) printf("Sayi Bulunamadi\n");

}

/*Bitiþ*/

//* Ýkili Arama Baþlangýç *//

void araIkili(void){

	printf("Aranacak Degeri Giriniz ? \n");

	scanf("%d", &ara);

	while (alt <= ust){

		orta = (alt + ust) / 2;

		if (ara == sayi[orta]) { printf("%d degeri %d.Sirada bulundu", ara, orta + 1); break; }

		else if (ara<sayi[orta])

			ust = orta - 1;

		else

			alt = orta + 1;

	}

}

/*Bitiþ*/


