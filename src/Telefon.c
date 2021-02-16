/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	Telefon.c
* </p>
*/

#include "Telefon.h"
#include "Rastgele.h"
#include <string.h>
#include "IMEINo.h"
Telefon TelefonOlustur()
{
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->telNoBaslangic = &baslangic;
	this->telNoDevami = &devam;
	this->telOlustur = &olustur;
	this->Yoket = &TelefonYoket;
}



char* baslangic(Telefon this)
{
	Rastgele rastgele = RastgeleOlustur();
	char *kodlar[] = {"0501","0505","0506","0507","0551","0552","0553","0554","0555","0559","0530","0531","0532","0533","0534","0535","0536","0537","0538","0539","0561","0540","0541","0542","0543","0544","0545","0546","0547","0548","0549",NULL};
	int random_sayi = rastgele->randomPositiveInt(rastgele,31);
	rastgele->Yoket(rastgele);
	return kodlar[random_sayi];
}


char* devam(Telefon this)
{
	Rastgele rastgele = RastgeleOlustur();
	int random_tel = 0;
	char* devam = malloc(7);
	while(true)
	{
		random_tel = rastgele->randomPositiveInt(rastgele,9999999)+1;
		char kontrol[8];
		sprintf(kontrol,"%d",random_tel);
		int len = strlen(kontrol);
		if(len == 7)
		{
			break;
		}
	}
	sprintf(devam,"%d",random_tel);
	rastgele->Yoket(rastgele);
	return devam;
}

void olustur(Telefon this)
{
	IMEINo imei = IMEINoOlustur();
	this->imeiNo=imei->imei_olustur(imei);
	imei->Yoket(imei);
	snprintf(this->telNo, sizeof(this->telNo) ,"%s%s",this->telNoBaslangic(this), this->telNoDevami(this));
}

void TelefonYoket(Telefon this)
{
	if(this == NULL) return;
	free(this->imeiNo);
	free(this->telNo);
	free(this);
}
