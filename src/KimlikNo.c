/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	KimlikNo.c
* </p>
*/


#include "KimlikNo.h"
#include "Rastgele.h"
#include <string.h>
KimlikNo KimlikNoOlustur()
{
	KimlikNo this;
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->rastgele_tc_uret = &rastgele_tc;
	this->isValidTC = &tc_validmi;
	this->tcyi_ata = &tc_ata;
	this->Yoket = &KimlikNoYoket;
}

long long rastgele_tc(KimlikNo this)
{
		long long tc = 0;
        int ilk_dokuz = 0;
        Rastgele rastgele = RastgeleOlustur();
        while(true)
        {
        ilk_dokuz = rastgele->randomPositiveInt(rastgele,999999999) + 1;
        char kontrol[10];
		sprintf(kontrol,"%d",ilk_dokuz);
        int len = strlen(kontrol);
        if(len == 9)
        {
            break;
        }
        }
        int intTab[9];
        int tmp = ilk_dokuz;
        for(int i = 8;i >= 0;i--)
        {
        	intTab[i] = ilk_dokuz % 10;
        	ilk_dokuz = ilk_dokuz / 10;
		}
        int onuncu_rakam = (((intTab[0]+intTab[2]+intTab[4]+intTab[6]+intTab[8]) * 7) - (intTab[1]+intTab[3]+intTab[5]+intTab[7])) % 10;
        int onbirinci_rakam = (intTab[0] + intTab[1] + intTab[2] + intTab[3] + intTab[4] + intTab[5] + intTab[6] + intTab[7] + intTab[8] + onuncu_rakam) % 10;
        for( int i=0; i < 9; i++){
        tc*=10;
        tc+=intTab[i];
        if(i == 8)
        {
            tc*=10;
            tc+=onuncu_rakam;
            tc*=10;
            tc+=onbirinci_rakam;
        }
        }
        rastgele->Yoket(rastgele);
        if(this->isValidTC(this,tc))
        	return tc;
        else
        	this->rastgele_tc_uret(this);
}

bool tc_validmi(KimlikNo this,long long TC)
{
		char basamaklar[12];
		sprintf(basamaklar,"%lld",TC);
		if(strlen(basamaklar) != 11)
        {
            return false;
        }
		int intTab[11];
		for(int i = 10;i >= 0;i--)
        {
        	intTab[i] = TC % 10;
        	TC = TC / 10;
		}
        int sum1 = 0;
        int sum2 = 0;
        if(intTab[0] == 0)
        {
            return false;
        }
        for (int i = 0; i < 9; i++) 
        { 
            if (i % 2 == 0) 
                sum1 += intTab[i]; 
            else
                sum2 += intTab[i];            
        } 
        int onuncu_hane = (sum1 * 7 - sum2) % 10;
        if(onuncu_hane != intTab[9])
        {
            return false;
        }
        int onbirinci_hane = (sum1 + sum2 + onuncu_hane) % 10;
        return onbirinci_hane == intTab[10];
}

void tc_ata(KimlikNo this)
{
	this->TC_No = this->rastgele_tc_uret(this);
}

void KimlikNoYoket(KimlikNo this){
if(this == NULL) return;
free(this);
}
