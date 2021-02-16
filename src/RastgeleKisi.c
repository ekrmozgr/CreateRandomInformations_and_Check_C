/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	RastgeleKisi.c
* </p>
*/

#include "RastgeleKisi.h"
#include "Rastgele.h"
#include <stdio.h>
#include <string.h>
RastgeleKisi RastgeleKisiOlustur(){
RastgeleKisi this;
this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
this->isim_soyisim_sec = &isim_sec;
this->yas_sec = &yas;
this->Yoket = &RastgeleKisiYoket;
return this;
}

char*isim_sec(RastgeleKisi this)
{
	const int size = 30;
	char* tmp = NULL;
	int count = 0;
	FILE *f = fopen("random_isimler.txt", "r");
    if (f == NULL)
	{
    	printf("Dosya bulunamadi\n");
	}
	else
	{
		tmp = malloc(size);
		Rastgele rastgele = RastgeleOlustur();
		int kacinci_kisi = rastgele->randomPositiveInt(rastgele,3000)+1;
    	while (fgets(tmp, 30, f) != NULL)
    	{
    		count++;
        	if (count == kacinci_kisi)
        	{
			break;
        	}
    	}
    	rastgele->Yoket(rastgele);
    	fclose(f);
	}
	tmp[strcspn(tmp,"\n")] = 0;
	return tmp;
}

int yas(RastgeleKisi this)
{
	Rastgele rastgele = RastgeleOlustur();
	int yass = rastgele->randomPositiveInt(rastgele,99)+1;
	rastgele->Yoket(rastgele);
	return yass;
}

void RastgeleKisiYoket(RastgeleKisi this){
if(this == NULL) return;
free(this);
}
