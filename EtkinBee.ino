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
********************************************************************************/


#include <etkinbot.h>

Etkinclass etkinbot;

uint8_t startButton = 7;
uint8_t buzzer = 8;
uint8_t buttonVal[100];
int val = 0;
int counter = 0;
int goDist = 150;
int turnDist = 55;
uint8_t runSpeed = 255;

void setup()
{
	pinMode(button, INPUT);
	pinMode(button, OUTPUT);
}
void loop()
{
	while(1)
	{
		val = readButton();
		if(val != 0)
		{
			buttonVal[counter] = val;
			counter++;
		}

		if(digitalRead(startButton) == 1)
		{
			counter = 0;
			etkinbot.ledcolor(0, 255, 0);
			tone(buzzer,262,500);
			delay(200);
			break;
		}
	}
	if(run(buttonVal) == 0) playMusic();
}

/* run()********************************************************************
-yapilan senoryoyu gercekler
1 --> ileri
2 --> geri
3 --> sol
4 --> sag
****************************************************************************/
int run(int array[])
{
	int _dist = 0;
	for(int i = 0; array[i] != NULL; i++)
	{
		if(array[i] == 1 || array[i] == 2) _dist = goDist;
		else if(array[i] == 3 || array[i] == 4) _dist = tunDist;
		etkinbot.movePID(array[i], runSpeed, _dist);
	}

	return 0;
}

/* readButton()************************************************************
-A0 pinine baglanmis olan buttonlarin analog degerini okuyup yon bilgisine
cevirir.
***************************************************************************/
int readButton()
{
	int _readVal = analogRead(A0);

	if (_readVal > 600) return 1;
	else if (_readVal > 500 && _readVal <  600) return 2;
	else if (_readVal > 300 && _readVal <  500) return 3;
	else if (_readVal > 30 && _readVal <  300) return 4;
	else if (_readVal < 30) return 0;
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
