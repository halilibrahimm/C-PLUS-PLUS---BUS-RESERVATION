//Halil �brahim YILMAZ 110757001
#ifndef OTOBUS_H
#define OTOBUS_H

class otobus
{
	char kapasiteEkle[10];
	char kalkisSaatEkle[4];
	char varisSaatiEkle[4];
	char baslangicSehirEkle[10];
	char varisSehriEkle[10];
	char otoNoEkle[20];
	char hasilatEkle[5];
	char otoModelEkle[7];
	char otoNo2[5];
	char string[6];
	char a[2];
public:
	otobus();
	void KapasiteEkle();
	void OtoModelEkle();
	void PersonelSayiEkle();
	//SeferBilgisiEkle
	void SeferNoEkle();
	void OtoNoSecEkle();
	void SeferSaatEkle();
	void VarisSaatiEkle();
	void SehirEkleBaslangic();
	void SehirEkleBitis();
	void HasilatEkle();
	void UcretGoster();

	//Sefer Bilgisi G�ster
	void SeferKoltukBilgisiGoster();
	char seferNoGir[6];
	//M��teri Giri�i
	void SeferNoListele();
	void RezervasyonYap();
	void RezervasyonGoster();
	char personelEkle[1];
	void Pozisyon(int k);
	//Dizi ��ini Doldur
	char koltuk[8][4][10];
	void BosKoltuk();
private:
};
#endif

