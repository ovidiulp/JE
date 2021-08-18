#include <stdio.h>


#define EX 5
#define MAX_BITS 8
#define MAX_ULONG_BITS sizeof(uint32_t) * MAX_BITS

typedef unsigned long uint32_t;
// DONE 1, 2, 3, 4,
#if EX == 1
#define PASS_NUMBER 1552455155


uint32_t reg[32] = { 0 };

int count_1 = 0;

void convToBinary(uint32_t number)
{
    
    for (int i = 0; i < MAX_ULONG_BITS; i++)
    {
        reg[i] = (number >> i) & 1;

        count_1 += (reg[i] & 1);

    }



}

void main()
{
    
    convToBinary(PASS_NUMBER);
    
    for(int i = MAX_ULONG_BITS-1; i >= 0; i--)
    {
        printf("%d\n", reg[i]);
    }
    printf("\n");
    printf("Nr de biti de 0 = %d\n", (MAX_ULONG_BITS-count_1));
    printf("Nr de biti de 1 = %d\n", count_1);

}

#endif

#if EX == 2

#define setBit(posBit, var) (var |= (1 << posBit))
#define clearBit(posBit, var) (var &= ~(1 << posBit))

void main()
{
    uint32_t myNumber = 12445;

    uint32_t bitSetPos = 6;
    uint32_t bitClrPos = 4;

    setBit(bitSetPos, myNumber);   // setam cel de-al saselea bit, bitii ii numaram de la 0 la 31
    printf("%d\n", myNumber);      // afisare

    clearBit(bitClrPos, myNumber); // setam pe valoare zero bitul numarul 4
    printf("%d\n", myNumber);      // afisare



}

#endif

#if EX == 3
/*
Scrieti o functie care inverseaza ordinea bitilor dintr-un numar primit prin argumentul functiei;
argumentul fiind de tip unsigned long. 
Afisati pe biti numarul inainte si dupa modificare. */


void reverseBits(uint32_t passNumb)
{
    uint32_t revBitNumb[32] = { 0 };
    int i = 31;

    while (i >= 0)
    {
        revBitNumb[i] = (passNumb >> i) & 1;
        printf("%d", revBitNumb[i]);    
        i--;
        
    }
    printf("\n");

  
}
void convToBinary(uint32_t number)
{
    uint32_t reg[32] = { 0 };
    for (int i = 0; i < MAX_ULONG_BITS; i++)
    {
         reg[i] = (number >> i) & 1;
         printf("%d", reg[i]);
    }

    printf("\n");

}
void main()
{
    uint32_t numbToPass = 2837889586;
    uint32_t revNumb[32] = { 0 };

    convToBinary(numbToPass);
    
    reverseBits(numbToPass);
  


}

#endif // EX == 3

#if EX == 4
/*
#define LUNGIME_TABLOU	7
unsigned long	tablouIntervale[LUNGIME_TABLOU] = {5,20,50,90,100,130,139};

Scrieti o functie (intr-un fisier main.c) care primeste printr-un argument de tip unsigned long o valoare (ex: valViteza)
si printr-un alt argument - tabloul de intervale. Functia retureaza pozitia valori valViteza in cadrul tabloului,
ca in urmatorul exemplu:

valViteza < 5 – functia returneaza 0
valViteza in intervalul [5,20) – functia returneaza 1
valViteza in intervalul [20,50) – functia returneaza 2
...
valViteza >= 139 – functia returneaza 7

Nota 1: Functia trebuie sa ruleze corect daca se modifica LUNGIME_TABLOU si
             tablouIntervale. Folositi directive de preprocesare pentru a alege din mai multe variante
             de tablouri.

Nota 2: tablouIntervale contine valori strict crescatoare.

*/

#define LUNGIME_TABLOU	7
unsigned long	tablouIntervale[LUNGIME_TABLOU] = { 5,20,50,90,100,130,139 };

unsigned int SpeedValue(unsigned long valViteza, unsigned long ptablouIntervale[])
{
    unsigned int i = 0;
    unsigned int rez = 0;
    if (valViteza < ptablouIntervale[i])
    {
        rez = i;
    }
    else if (valViteza >= ptablouIntervale[LUNGIME_TABLOU - 1])
    {
        rez = LUNGIME_TABLOU;
    }

    for (i = 1; i < LUNGIME_TABLOU-1; i++)
    {
        if ((valViteza >= ptablouIntervale[i]) && (valViteza < ptablouIntervale[i + 1]))
        {
            rez = i+1;
        }

    }
    return rez;
}

void main(void)
{
    unsigned int valSpeed = 190;
    unsigned int retVal = SpeedValue(valSpeed, tablouIntervale);
    printf("%d\n", retVal);


}


#endif


//Problema 5
#if EX == 5
typedef long lint8;
#define LUNGIME_PP 7
#define LUNGIME_NPP 5
#define LUNGIME_NN 4
#define LUNGIME_N 20
#define tsize(x) (sizeof(x)/sizeof(x[0]))
long tab_nrPrimePozitive[LUNGIME_PP];
long tab_nrNonPrimePozitive[LUNGIME_NPP];
long tab_nrNegative[LUNGIME_NN];
long tab_numere[LUNGIME_N] = { 3,2,14,-64,32,12,4,56,21,32,-12,42,45,124,-56,32,12,34,56,23 };


int nr_prim(long number)
{
    int i;
    int flag = 0;

    for (i = 2; i < number / 2; i++)
    {
        if (number % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return 0; // nr nu este prim
    }
    else
        return 1; // nr este prim

}

void printTab(long a[], int n)
{
        int i;
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);

        }
}


void main()
{
    int l_tab = sizeof(tab_numere) / sizeof(tab_numere[0]);
    int count = 0;
    int primPoz = 0;        // counter array nr PRIME POZITIVE
    int nonPrimPoz = 0;     // counter array nr NON PRIME POZITIVE
    int nrNeg = 0;          // counter array nr NEGATIVE
    while ((count < LUNGIME_N) && (nrNeg < LUNGIME_NN) && (nonPrimPoz < LUNGIME_NPP) && (primPoz < LUNGIME_PP))
    {
        
        for (int i = 0; i < LUNGIME_N; i++)
        {

            if (nr_prim(tab_numere[i]) == 1 && tab_numere[i] >= 0)            // verific daca nr este prim si pozitiv
            {
                tab_nrPrimePozitive[primPoz] = tab_numere[i];
                primPoz++;
                
            }
            else if (nr_prim(tab_numere[i]) == 0 && tab_numere[i] >= 0)     // verific daca numarul nu este prim dar este pozitiv
            {
                tab_nrNonPrimePozitive[nonPrimPoz] = tab_numere[i];
                nonPrimPoz++;
                
            }
            else if (tab_numere < 0)                                        // verific daca numarul este negativ
            {
                tab_nrNegative[nrNeg] = tab_numere[i];
                nrNeg++;
                
            }
            count++;

        }
    }

    printf("Tabloul de numere:\n");
    printTab(&tab_numere[0], LUNGIME_N);

    printf("\nTabloul cu numere prime pozitive:\n");
    printTab(&tab_nrPrimePozitive[0], LUNGIME_PP);

    printf("\nTabloul cu numere non prime pozitive:\n");
    printTab(&tab_nrNonPrimePozitive[0], LUNGIME_NPP);

    printf("\nTabloul cu numere negative:\n");
    printTab(&tab_nrNegative[0], LUNGIME_NN);



}

#endif

//SET 2 problema 6
#define mn	1                    /* man */
#define rt 	2                    /* renault  */ 
#define vt 	3                    /* volvo */
#define mt 	4                    /* mack */
#define highline 1
#define basicline 2
#define insbrand mt
#define insvar highline


#if( (insbrand == vt) || (insbrand == rt) || (insbrand == mn))
    static void ledc__vswitchtachoredleds(uint8 u8rangelow, uint8 u8rangehigh); 	/*1*/
    static void ledc__vswitchtachogreenleds(uint8 u8rangelow, uint8 u8rangehigh);    /*2*/
    #if ((insbrand == rt) || (insbrand == mn))
    static void ledc__vswitchtachoblueleds(uint8 u8rangelow, uint8 u8rangehigh);       /*3*/
    #endif	
    #if ( ((insbrand == vt) && (insvar == highline)) || (insbrand == mn))
    static void ledc__vswitchaccleds(uint8 u8rangelow, uint8 u8rangehigh);                 /*4*/    
    #endif	
#endif
    
   //a
   //nothing

    //b 
    //#define INSBrand RT
    //#define INSVar BasicLine

    //static void LEDC__vSwitchTachoRedLeds(uint8 u8RangeLow, uint8 u8RangeHigh); 	
    //static void LEDC__vSwitchTachoGreenLeds(uint8 u8RangeLow, uint8 u8RangeHigh);
    //static void LEDC__vSwitchTachoBlueLeds(uint8 u8RangeLow, uint8 u8RangeHigh);

    //c
    //static void LEDC__vSwitchTachoRedLeds(uint8 u8RangeLow, uint8 u8RangeHigh); 	
    //static void LEDC__vSwitchTachoGreenLeds(uint8 u8RangeLow, uint8 u8RangeHigh);

    //d
    //#define INSBrand VT
    //#define INSVar HighLine
    // 
    //static void LEDC__vSwitchTachoRedLeds(uint8 u8RangeLow, uint8 u8RangeHigh); 	
    //static void LEDC__vSwitchTachoGreenLeds(uint8 u8RangeLow, uint8 u8RangeHigh);
    //static void LEDC__vSwitchACCLeds(uint8 u8RangeLow, uint8 u8RangeHigh);


///SET 2 EX7
#if EX == 7



void func(uint32_t nr)
{
    char reg[10] = { 0 };
    int i = 0;


    
    
    while (nr > 0)
    {
        reg[i] = (nr % 10 ) + '0';
        nr /= 10;
        i++;
    }
    
    for (i = 9; i >= 0; i--)
    {
        printf("0x%x ", reg[i]);
    }

}
 


void main()
{
    
    uint32_t number1 = 1234567890;
    uint32_t number2 = 18;

    func(number1);
    
    printf("\n");

    func(number2);


}
#endif

#if EX == 8
//Scrieti o functie care permite obtinerea unui element din sirul Fibonacci.
//Se doreste o implementare nerecursiva fara a folosi tablouri

void fiboNumb(uint32_t);

void main()
{
    uint32_t element = 12;
    fiboNumb(element);

}

void fiboNumb(uint32_t nrElement)
{
    int last = 0;
    int actual = 1;
    int rez = 0;
    int i = 0;

    for (i = 2; i < nrElement; ++i)
    {
        rez = last + actual;
        last = actual;
        actual = rez;
    }
    printf("%d ", rez);

}
#endif