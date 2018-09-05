/* EtkinBot Akilli Bocek 4-8 yas Kodlama Programi ******************************

-----------Degiskenler--------------------------
startButton	: Etkinbot Akilli Bocek Dahili Kullanici Buttonu.
buzzer		: Etkinbot Akilli Bocek Dahili Buzzer.
buttonVal[]	: Senaryonun bulunacagi dizi.
val 		: readButton() metodunun cikti verisi.
counter		: dizi indis sayicisi.
goDist		: ileri ve Geri yonde olan hareketler icin gerekli olan mesafe.
turnDist	: Saga ve sola donusler icin gerekli olan mesafe.
runSpeed	: Motor hizi.


-	Etkin Teknolojiler
-	Cagatay YILMAZ
-	arge@etkinteknolojiler.com
*******************************************************************************/


#include "etkinbot.h"

EtkinClass etkinbot;

uint8_t startButton = 7;
uint8_t buzzer = 8;
uint8_t buttonVal[100];
int val = 0;
int count = 0;
int goDist = 150;
int turnDist = 65;
uint8_t runSpeed = 255;

void setup()
{
	pinMode(startButton, INPUT);
	pinMode(buzzer, OUTPUT);
	Serial.begin(9600);
}
void loop()
{
	while(1)
	{
		val = readButton();
		if(val != 0)
		{
			buttonVal[count] = val;
			count++;
			etkinbot.ledcolor(120, 255, 120);
			tone(buzzer,262,1000);
			delay(1000);
			Serial.print("deger: ");
			Serial.println(val);
			etkinbot.ledcolor(0, 0, 0);
		}

		if(digitalRead(startButton) == 1)
		{
			count = 0;
			etkinbot.ledcolor(0, 255, 0);
			tone(buzzer,440,500);
			delay(2000);
			break;
		}
	}
	//if(run(buttonVal) == 0) playMusic();
	run(buttonVal);
}

/* run()********************************************************************
-yapilan senoryoyu gercekler
1 --> ileri
2 --> geri
3 --> sol
4 --> sag
***************************************************************************/
int run(uint8_t array[])
{
	int _dist = 0;
	for(int i = 0; array[i] != NULL; i++)
	{
		if(array[i] == 1 || array[i] == 2) _dist = goDist;
		else if(array[i] == 3 || array[i] == 4) _dist = turnDist;
		Serial.print("deger: ");
		Serial.println(array[i]);
		etkinbot.movePid(array[i], runSpeed, _dist);
		tone(buzzer,330, 500);
		delay(1000);
	}

	return 0;
}

/* readButton()*****************************************************************
-A0 pinine baglanmis olan buttonlarin analog degerini okuyup yon bilgisine
cevirir.
*******************************************************************************/
int readButton()
{
	int _readVal = analogRead(A4);
	if (_readVal == 0) return 1;
	else if (_readVal > 0 && _readVal <  520) return 2;
	else if (_readVal > 520 && _readVal <  700) return 3;
	else if (_readVal > 700 && _readVal <  1020) return 4;
	else if (_readVal > 1020 ) return 0;
}

/* playMusic()************************************************************
-Senayo tamalandigini belirten "Tebrikler" muzigi calar.
***************************************************************************/
void playMusic()
{
	tone(buzzer,262,500);
	tone(buzzer,262,500);
	tone(buzzer,262,500);
	tone(buzzer,262,500);
	tone(buzzer,262,500);
	tone(buzzer,262,500);
}
