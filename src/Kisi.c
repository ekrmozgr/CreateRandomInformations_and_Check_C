/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	Kisi.c
* </p>
*/

#include "Kisi.h"
#include "RastgeleKisi.h"
#include <stdlib.h>
#include "KimlikNo.h"
#include "IMEINo.h"
#include <string.h>
#include <stdio.h>
Kisi KisiOlustur(){
Kisi this;
this = (Kisi)malloc(sizeof(struct KISI));
rastgelekisi = RastgeleKisiOlustur();
this->isim_soyisim = rastgelekisi->isim_soyisim_sec(rastgelekisi);
this->yas=rastgelekisi->yas_sec(rastgelekisi);
this->tc = KimlikNoOlustur();
this->telefon = TelefonOlustur();
this->kisiyi_tamamla = &kisi_tamamla;
this->txt_yazdir = &Yazdir;
this->Yoket = &KisiYoket;
return this;
}

void kisi_tamamla(Kisi this)
{
	this->tc->tcyi_ata(this->tc);
	this->telefon->telOlustur(this->telefon);
}
void Yazdir(const Kisi k)
{
	FILE *f = fopen("Kisiler.txt", "a");
	fprintf(f,"%lld %s %d %s (%s)\n",k->tc->TC_No,k->isim_soyisim,k->yas,k->telefon->telNo,k->telefon->imeiNo);	
	fclose(f);
}

void Oku()
{
	int gecerli_tc = 0;
    int gecersiz_tc = 0;
    int gecerli_imei = 0;
    int gecersiz_imei = 0;
    KimlikNo kimlik = KimlikNoOlustur();
    IMEINo imei = IMEINoOlustur();
    FILE *f = fopen("Kisiler.txt", "r");
    if (f == NULL)
	{
    	printf("Dosya bulunamadi\n");
	}
	else
	{
		char x[25];
		int i = 0;
    	while (fscanf(f,"%s", x) == 1)
		{
        if(i == 0)
		{
        	char*eptr;
        	long long tc = strtoll(x,&eptr,10);
        	if(kimlik->isValidTC(kimlik,tc))
        		gecerli_tc++;
			else			
			{
				gecersiz_tc++;
			}
		}
		if(i == 5)
		{			
			if(strlen(x) != 17)
			{			
				gecersiz_imei++;
				i=0;
				continue;
			}
			char* asd;
			char tmp[15];
			strncpy(tmp,x+1,strlen(x)-2);
			tmp[15]='\0';
			if(imei->isValidIMEI(imei,tmp))
				gecerli_imei++;
			else
				gecersiz_imei++;
			i = -1;
		}
    	i++;
		}
	printf("\nT.C. Kimlik Kontrol\n");
	printf("%d Gecerli\n",gecerli_tc);
	printf("%d Gecersiz\n\n",gecersiz_tc);
	printf("IMEI Kontrol\n");
	printf("%d Gecerli\n",gecerli_imei);
	printf("%d Gecersiz\n\n",gecersiz_imei);
	kimlik->Yoket(kimlik);
	imei->Yoket(imei);
	fclose(f);
	}
}

void KisiYoket(Kisi this)
{
	if(this == NULL) return;
	this->tc->Yoket(this->tc);
	this->telefon->Yoket(this->telefon);
	free(this->isim_soyisim);
	rastgelekisi->Yoket(rastgelekisi);
	free(this);
}
