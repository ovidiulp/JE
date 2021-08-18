
#include <stdio.h>

#define SET 3
#define EX 20
#define arr_size(x) (sizeof(x) / sizeof(x[0]))
#define MAX_BITS 8
#define MAX_SHORT_BITS sizeof(short)*MAX_BITS
typedef unsigned long uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

//DONE 1, 2, 3, 4, 5

#if  (SET == 3 && EX == 1)
#include <stdio.h>


void byte_print(uint32_t* pNumber)
{
	int i = 0;
	uint32_t a[32] = { 0 };
	uint32_t rez = *pNumber;
	while (rez > 0) {
		((rez % 2) == 0) ? a[i] = 0 : (a[i] = 1);
		rez = rez / 2;
		i++;


	}
	for (int j = 31; j >= 0; j--)
	{
		printf("%ld", a[j]);
		if ((j % 8) == 0)
			printf("\n");
	}
	printf("\n");
}



int main()
{
	uint32_t* pNumber;
	uint32_t number = 454020;
	pNumber = &number;
	byte_print(pNumber);

	return 0;
}

#endif 

#if (SET == 3 && EX == 2)
#include "myErr.h"

void printReg(unsigned short* puRegister)
{

	ex_ret eret = ex_ret_ok;

	if (puRegister != NULL)
	{
		int i = MAX_SHORT_BITS - 1;
		for (; i >= 0; --i)
		{
			printf("%d", (*puRegister >> i) & 1);
		}
		printf("\n");
	}
	else
	{
		eret = ex_ret_invalid_param;
	}
	return eret;



}



ex_ret SetRegister(uint16_t* puRegister, uint16_t uFieldStart, uint8_t uFieldSize, uint16_t uFieldValue) //ex_ret enumeratie  // uint16_t <- unsigned short
{
	uint8_t i = 0;
	uint16_t uReg = *puRegister;
	ex_ret eret = ex_ret_ok;

	if (puRegister != NULL)
	{

		for (; i < uFieldSize; ++i)
		{
			uReg = uReg & (~(1 << (uFieldStart - 1)));

		}
		uReg = uReg | (uFieldValue << (uFieldStart - uFieldSize + 1));
		*puRegister = uReg;
	}
	else
	{
		eret = ex_ret_invalid_param;
	}
	return eret;
}


//PROBLEMA 2
//Scrieti o functie care primeste ca argument un pointer la o variabila FLASH_BIUCR pe 16 biti (unsigned short)
//care impacheteaza urmatoarele campuri (valori pozitive): APC, WWSC, RWSC, DPFEN, IPFEN, PFLIM si BFEN. 
//Functia initializeaza aceste campuri cu valori furnizate de voi tot prin intermediul argumentelor.Folositi operatii pe biti si masti.
//Afisati valoarea lui FLASH_BIUCR(folosind argument de tip pointer) intr - o alta functie.

void main()
{
	ex_ret eret = last;
	uint16_t FLASH_BIUCR = 0;
	uint8_t value = 3;
	uint8_t size = 2;
	uint8_t position = 12;

	printf("Before :\n");
	
	printReg(&FLASH_BIUCR);

	eret = SetRegister(&FLASH_BIUCR, position, size, value);
	
	value = 5;
	position = 3;
	size = 3;

	eret = SetRegister(&FLASH_BIUCR, position, size, value);

	printf("After :\n");

	printReg(&FLASH_BIUCR);

	printf("eret = %d\n", eret);




}


#endif

#if (SET == 3 && EX == 3)
//trebuie verificati pointerii
	
void calcul(char*, long*, long*, long*);

	void main()
	{
		char tablou[10] = {9, 5, 4, 32, -31, 25, 24, 2, 14, 55 };
		long min = tablou[1];
		long max = 0;
		long sum = 0;
		
		

		calcul(tablou, &min, &max, &sum);

		printf("Elementul minim -> %d\nElemenetul maxim ->%d\nSuma elementelor -> %d\n", min, max, sum);
	}

	void calcul(char* ptablou, long* min, long* max, long* sum)
	{
		if (ptablou != NULL && min != NULL && max != NULL && sum != NULL)
		{
			int  i = 1;

			for (; i < ptablou[0]; ++i)
			{
				if (ptablou[i] < *min)
				{
					*min = ptablou[i];
				}
				if (ptablou[i] > *max)
				{
					*max = ptablou[i];
				}

				*sum += ptablou[i];
			}
		}

}


#endif

#if (SET == 3 && EX == 4)


void strncpy(char* sursa, char* destinatie, unsigned int n)
{
	unsigned int i;
	
	if ((sursa != NULL) && ( destinatie != NULL))
	{
		for (i = 0; i < n; ++i)
		{

			*(destinatie + i) = *(sursa + i);

		}
		*(destinatie + i) = '\0';
		
	}
}

void main()
{
	int n = 15;
	char sursa[17] = "sir de caractere";
	
	char destinatie[17] = { 0 };

	

	strncpy(sursa, destinatie, n);

	printf("%s\n", sursa);
	printf("%s\n", destinatie);


}


#endif

#if (SET == 3 && EX == 5)


int minElement(int v[], int n)
{
	int i, min;
	min = v[0];
	for (i = 0; i < n; ++i)
	{
		if (min > v[i])
			min = v[i];
	}
	return min;
}



int maxElement(int v[], int n)
{
	int i, max = v[0];
	for (i = 0; i < n; ++i)
	{
		if (max < v[i])
			max = v[i];
	}
	return max;
}



int suma(int v[], int n)
{
	int i, sum;
	sum = 0;
	for (i = 0; i < n; ++i)
	{
		sum += v[i];
	}
	return sum;
}



void handler(int(*pf)(int, int), int tablou[])
{
	int result;
	result = pf(tablou, 6);
	printf("rezultatul este %d\n", result);
}



void main()
{
	int v[6] = { -11, 2, 3, 7, 5, 6 };
	int(*pmin)(int*, int);
	int(*pmax)(int*, int);
	int(*psum)(int*, int);
	psum = suma;
	pmin = minElement;
	pmax = maxElement;



	handler(pmin, v);
	handler(pmax, v);
	handler(psum, v);


	
}

#endif

#if (SET == 3 && EX == 6)

#include<stdio.h>
#define N 3 // linii
#define M 3 // coloane

void swap(int *a, int *b)
{

	if (a != NULL && b != NULL) 
	{
		int temp;
		
		temp = *x;
		*x = *y;
		*y = temp;

	}
}

void sortMatrix(int (*a)[N][M])
{



}


void main()
{
	int matrix[N][M];



}




#endif


#if (SET == 3 && EX == 7)


#define N 3
 

int print_array(int *pmat)
    //int *pmat=&matrix;
{ // matrice de dimensiune = 3x3 = 9
    int i;
    for(i = 0; i < 9; i++){
        if (i%3 == 0)
        {
            printf("\n");
        }
        printf("%d ", *pmat);

        pmat++;// afisarea fiecarui element 

    }
 
}
 
int incrementare(int *pmat)
{ // matrice de dimensiune = 3x3 = 9
    int j;
    int i;
        for(j = 0; j < 3; j++){
            *pmat = *(pmat) + 1;
             pmat = pmat + (N+1); // doar daca e matrice cu N==M
        }

    // 00   01   02
    // 10   11   12
    // 20   21   22   
        //for(i = 0; i < 9; i++){
        //    printf("Matricea este = %d\n", *pmat);
        //    pmat++;// afisarea fiecarui element 
        //}
}
 

void main()
{
    int matrix[N][N] = { {2,1,4}, 
                         {3,7,5}, 
                         {11,9,10}
                                 };
    //int *pmat;
    //pmat = &matrix;
 
    print_array(matrix);
    incrementare(matrix);
    print_array(matrix);
 
  
}


#endif




#if EX == 21


void main()
{

	uint8_t sir1[3] = "abc";
	uint8_t sir2[3] = "243";
	uint8_t size = sizeof(sir1) / sizeof(sir1[0]);

	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t sir3[9] = { 0 }; // dimensiunea sa fie ca parametru 
	

	for (; i < size; ++i)
	{
		for (j = 0; j < (sir2[i] - '0'); ++j)
		{
			sir3[j+i] = sir1[i];
			printf("%c", sir3[j+i]);
			
		}
		

	}
}

#endif