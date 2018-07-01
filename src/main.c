
#include "project.h"
/*****************************/
int arr[100] = {1,26,28,82,6,44,30,53,50,99,91,63,40,74,36,92,50,69,36,82,68,99,74,16,73,15,80,5,54,79,51,30,84,50
	,86,81,18,3,60,99,41,25,93,93,1,36,52,57,91,63,69,42,53,43,87,16,69,33,82,16,31,23,66,29,5,38,17,51,86,39
	,71,19,32,36,28,13,52,98,65,55,29,32,44,59,13,77,94,84,31,94,22,61,3,83,48,32,24,35,59 ,69 };
/*****************************/
void delay(unsigned int timeout)
{
   unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

/*Sap xep chen*/
void Chen(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = x;
	}
}

/*Sap xep lua chon*/
#define swap (a, b)  {int t; t = a; a = b; b = t};

void Luachon(int a[], int n)
{
	for (int i = 0; i < n -1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[iMin] > a[j])
			iMin = j;
		}
		if (i != iMin) swap (a[i], a[iMin]);
	}
}

/*Sap xep sui bot*/
void Suibot(int a[], int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 1; j < (n - i); j++)
	{
		if (a[j - 1] > a[j]) SWAP (a[j - 1], a[j]);
	}
}
/*******************************/
void main(void)
{
	/*Init_clock*/
	Enable_clk();
	/*Init_gpio_c*/
	Init_gpio();
	/*Init_interrupt*/
	Init_interrupt();
  while(1)
  {
	Turn_on(LD4_PIN);
	delay(0x0f);
	Turn_off(LD4_PIN);
	delay(0x0f);
  }
}



