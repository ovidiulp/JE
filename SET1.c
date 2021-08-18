#include <stdio.h>

#define EX	6
#define MAX_BITS 8


typedef char uint8;
typedef unsigned int uint32;
typedef unsigned long ulint32;

#if EX == 1
uint8 binVal(uint8 num)
{
	uint8 rez[8] = { 0 };
	
	for (int i = 7; i >= 0; i--)
	{
		rez[i] = (num >> i) & 1;
		printf("%d", rez[i]);
	}
	printf("\n");

	


}

void main()
{
	uint8 number = 245;

	binVal(number);

  
}
#endif

#if EX == 2
//2.	
//Scrieti o functie care returneaza 0 sau 1, valoarea difera la fiecare apel a functiei(daca la apelul precedent a returnat 0,
//la apelul curent va returna 1, iar la urmatorul apel va returna 0, s.a.m.d.).
//Nu folositi instructiuni de testare.Folositi doar operatii pe biti.
uint8 val = 0;

uint8 apelFunc();

void main()
{
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();
	apelFunc();

}
uint8 apelFunc()
{
	uint8 rez = val;
	val = !val;
	printf("%d\n", rez);

	return rez;


}




#endif

#if EX == 3
 /*3.	Avand o variabila pe 8 biti (unsigned char), 
 scrieti o functie “get” care citeste valoarea unui bit de la o anumita pozitie
 si o functie “set” care scrie un bit de la o anumita pozitie cu o anumita valoare data:
get (pozitie)
set (pozitie, valoare)
*/

uint8 nr = 123; // 0111 1011  
// setBit(5, 0)
// 


void setBit(uint8 , uint8);
uint8 getBit(uint8);
uint8 binVal(uint8);

void main()
{
	binVal(nr);
	setBit(6, 0);
	binVal(nr);


}


void setBit(uint8 bitPos, uint8 bitValue)
{
	uint8 i = nr;
	
	bitValue == 1 ?( nr |= 1 << bitPos) : (nr &= ~(1 << bitPos));
	

}

uint8 getBit(uint8 bitPos)
{
	uint8 value = 0;

	value = (nr >> bitPos) & 1;

	return value;
	
	
	

}

uint8 binVal(uint8 num)
{
	uint8 rez[8] = { 0 };

	for (int i = 7; i >= 0; i--)
	{
		rez[i] = (num >> i) & 1;
		printf("%d", rez[i]);
	}
	printf("\n");
}
#endif

#if EX == 4
/*
4.	Definiti o functie rightrot(a, n) care roteste circular (bitii care "ies" in dreapta "intra" in stanga) 
pe a cu n pozitii la dreapta. Incercati fara instructiuni de ciclare.
a – variabila pe 32 biti fara semn
n – variabila pe 8 biti fara semn
Ex.  a = 0x300C00FF, n = 2
*/

void rightrot(uint32 number, uint8 posNumber) // nu merge 
{
	uint32 temp = number; // temp = 0x300c00ff
	uint32 rez;
	number = number >> posNumber; // number == 0x00300c00;

	temp = temp << (MAX_BITS - posNumber); // temp == 0xff000000
	rez = number | temp;

	printf("0x%x", rez);


}

void main()
{
	uint32 a = 0x300C00FF;
	uint8 n = 2;
	rightrot(a, 2);
}




#endif

#if EX == 5

/*5.	Fie o variabila EBI_MCR pe 32 biti (unsigned long) care impacheteaza urmatoarele campuri (valori pozitive):
SIZEN, SIZE, ACGE, EXTM, EARB, MDIS si DBM. Initializati aceste campuri cu valori furnizate de voi.
Afisati valoarea lui EBI_MCR in urma initializarii. Afisati valorile campurilor.
Modificati valoarea lui EBI_MCR si afisati din nou valorile campurilor. Folositi operatii pe biti si masti.
Inainte de afisare, stocati valoarea intr-o variabila.
*/

void setField(ulint32 *puEBI_MCR_set, uint8 fieldPosition, uint8 fieldSize ,ulint32 setValue)
{
	ulint32 regVal = *puEBI_MCR_set;

	int i = 0;

	for (; i < fieldSize; ++i)
	{
		regVal &= ~(1 << (fieldPosition - i));
		regVal |= (setValue << (fieldPosition - i - fieldSize + 1)) & (1 << (fieldPosition - i));
	}

	*puEBI_MCR_set = regVal;
	printf("0x%x\n", *puEBI_MCR_set);
	

}

void getField(ulint32 *puEBI_MCR_get, ulint32 fieldPos, ulint32 fieldSize, ulint32 *fieldVal)
{
	ulint32 regValue = *puEBI_MCR_get;
	ulint32 fVal = *fieldVal;

	fVal = (regValue >> (fieldPos - fieldSize + 1)) & (~(1 << fieldSize));



	

	*fieldVal = fVal;
	printf("0x%x\n", *fieldVal);


}

void main()
{

	ulint32 EBI_MCR = 0x8000;

	uint8 fldSize = 1;
	uint8 fldPos  =10;
	uint32 fldVal = 2;

	uint32* val;
	ulint32* pEBI;

	pEBI = &EBI_MCR;
	val = &fldVal;
	getField(pEBI, fldPos, fldSize, val);
	printf("0x%x\n", *pEBI);

	setField(pEBI, fldPos, fldSize, fldVal);
	printf("0x%x\n", *pEBI);

	getField(pEBI, fldPos, fldSize, val);
	printf("0x%x\n", *pEBI);



}
 // neterminata
#endif

#if EX == 6

#endif