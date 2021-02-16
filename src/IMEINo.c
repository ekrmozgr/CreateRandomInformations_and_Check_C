/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	IMEINo.c
* </p>
*/


#include "IMEINo.h"
#include "Rastgele.h"
#include <string.h>
IMEINo IMEINoOlustur(){
IMEINo this;
this = (IMEINo)malloc(sizeof(struct IMEINO));
this->imei_olustur = &imei;
this->sumDig = &sumDigits;
this->isValidIMEI = &validmi;
this->Yoket = &IMEINoYoket;
return this;
}


int sumDigits(IMEINo this,int n)
{	
	int a = 0; 
        while (n > 0) 
        { 
            a = a + n % 10; 
            n = n / 10; 
        } 
        return a; 
}

bool validmi(IMEINo this,char m[])
{		m[strcspn(m,"\n")] = 0;
        int len = strlen(m); 
        if (len != 15) 
            return false; 
            		
		char* ilk_iki[] ={"\0","01","10","30","33","35","44","45","49","50","51","52","53","54","86","91","98","99",NULL};  
		char tmp[2];
		strncpy(tmp,m,strlen(m)-13);
		tmp[2] = '\0';
		int cnt = 0;

		for(int i = 1;i < 18;i++)
		{
			if(strcmp(tmp, ilk_iki[i]) == 0)
			{
				cnt++;
				break;
			}
		}
		if(cnt==0)
		{
			return false;
		}
		if(tmp[0] != '0')
		{
			
			char*eptr;
			long long imei = strtoll(m,&eptr,10);
			int sum = 0; 
        	for (int i = len; i >= 1; i--) 
        	{ 
            int d = (int)(imei % 10); 

            if (i % 2 == 0) 
                d = 2 * d; 
  
            sum += sumDigits(this,d); 
            imei = imei / 10; 
        	}  
        return (sum % 10 == 0); 			
		}
		else
		{
			char*eptr;
			char tmp[14];
			strncpy(tmp,m+1,strlen(m)-1);
			long long imei = strtoll(tmp,&eptr,10);
			int sum = 0; 
        	for (int i = 14; i >= 1; i--) 
        	{ 
            int d = (int)(imei % 10); 

            if (i % 2 != 0) 
                d = 2 * d; 
  
            sum += sumDigits(this,d); 
            imei = imei / 10; 
        }	 
  
        return (sum % 10 == 0); 
			
		}
	return false;
}

char* imei(IMEINo this)
{	
	char *imei = malloc(15);
	Rastgele rastgele = RastgeleOlustur();
	char* ilk_iki[] ={"\0","01","10","30","33","35","44","45","49","50","51","52","53","54","86","91","98","99",NULL};  
	char ilk_ondort[14];
	char*tmp = ilk_iki[rastgele->randomPositiveInt(rastgele,16)+1];
	int len = 2;
	long long sayi_gecici = 0;
	char basamaklar[12];
		while(strlen(basamaklar) != 12)
		{
			sayi_gecici = rastgele->randomPositiveLong(rastgele,999999999999) + 1;
			sprintf(basamaklar,"%lld",sayi_gecici);
		}
		len = len + strlen(basamaklar);
	snprintf(ilk_ondort,sizeof(tmp)+sizeof(basamaklar)-1,"%s%s",tmp,basamaklar);	
	int sum = 0;
	if(ilk_ondort[0] != '0')
	{
		char* eptr;
		long long temp = strtoll(ilk_ondort,&eptr,10);
		for (int i = len; i >= 1; i--) 
        { 
            int d = (int)(temp % 10); 

            if (i % 2 == 0) 
			{			
                d = 2 * d; 
			}
            sum += sumDigits(this,d); 
            temp = temp / 10; 
        } 
    int onbesinci_rakam = 0;
    while(sum % 10 != 0)
    {
        sum++;
        onbesinci_rakam++;
    }
    char c = (char)(onbesinci_rakam+'0');
	snprintf(imei,16,"%s%c",ilk_ondort,c);
    rastgele->Yoket(rastgele);
    imei[strcspn(imei,"\n")] = 0;
    return imei;		
	}	
	
	else
	{
		char*eptr;
		long long temp = strtoll(ilk_ondort+1,&eptr,10);
		for (int i = strlen(ilk_ondort)-1; i >= 1; i--) 
        { 
            int d = (int)(temp % 10); 

            if (i % 2 != 0) 
			{			
                d = 2 * d; 
			}
            sum += sumDigits(this,d); 
            temp = temp / 10; 
        } 
    int onbesinci_rakam = 0;
    while(sum % 10 != 0)
    {
        sum++;
        onbesinci_rakam++;
    }
    rastgele->Yoket(rastgele);
	char c = (char)(onbesinci_rakam+'0');
	snprintf(imei,16,"%s%c",ilk_ondort,c);
	imei[strcspn(imei,"\n")] = 0;
    return imei;	
	}
}

void IMEINoYoket(IMEINo this)
{
	if(this == NULL) return;
	free(this);
}
