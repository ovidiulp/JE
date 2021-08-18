#include <stdio.h>

#define EX 1
#define MAX_BITS 8
#define MAX_CHAR_BITS (sizeof(unsigned char)*MAX_BITS)
typedef unsigned char uint8_t;



#if EX == 1

/*
o functie setez registrul // pointer
o functie setez fiecare camp din reg // pointer
o functie de afisare
*/
typedef enum fieldNames
{
	WPS,
	WPE,
	res = 3,
	HYS,
	ODE,
	DSC
}field;


typedef union _SIU_PCR_u
{
	struct _SIU_PCR_s
	{
	uint8_t WPS : 1;
	uint8_t WPE : 1;
	uint8_t res : 2;
	uint8_t HYS : 1;
	uint8_t ODE : 1;
	uint8_t DSC : 2;
	}SIU_PCR_s;

	unsigned int SIU_PCR;
}SIU_PCR_u;

void SetField(uint8_t *SIU_PCR_p, field position, uint8_t value)
{
	if (SIU_PCR_p != NULL)
	{
		SIU_PCR_u* SIU_PCR = (SIU_PCR_u*)SIU_PCR_p;
		switch (position)
		{
		case 0:
			SIU_PCR->SIU_PCR_s.WPS = value;
			break;
		case 1: 
			SIU_PCR->SIU_PCR_s.WPE = value;
		case 2:
			SIU_PCR->SIU_PCR_s.res = value;
		case 3:
			SIU_PCR->SIU_PCR_s.HYS = value;
		case 4:
			SIU_PCR->SIU_PCR_s.ODE = value;
		case 5:
			SIU_PCR->SIU_PCR_s.DSC = value;

		default:
			printf("Position %u not supported.\n", position);
			break;
		}
	}

}

void SetReg(uint8_t *SIU_PCR, uint8_t value)
{
	if (SIU_PCR != NULL)
	{
		SIU_PCR_u* SIU_PCR_p = (SIU_PCR_u*)&SIU_PCR;

		SIU_PCR_p->SIU_PCR = value;
	}
}

void PrintField(uint8_t SIU_PCR)
{
	int i = MAX_CHAR_BITS;

	SIU_PCR_u* SIU_PCR_p = (SIU_PCR_u*)&SIU_PCR;
	printf("\n");

	printf("\n%u\n", SIU_PCR_p->SIU_PCR);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.DSC);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.ODE);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.HYS);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.res);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.res);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.WPE);

	printf("\n%u\n", SIU_PCR_p->SIU_PCR_s.WPS);

	printf("\n");

}

void main()
{
	field position = WPE;
	uint8_t value = 1;
	uint8_t regVal = 0;
	SIU_PCR_u SIU_PCR;
   
	SetField(&regVal, position, value);
	position = WPS;
	regVal = 2;
	SetField(&regVal, position, value);
	position = HYS;
	regVal = 0;
	SetField(&regVal, position, value);
	position = DSC;
	regVal = 1;
	SetField(&regVal, position, value);
	position = ODE;
	regVal = 3;
	PrintField(&regVal);


}
#endif

#if EX == 2

#include <stdlib.h>
#define NMB_OF_PORTS 15

typedef enum _StarePort
{
	Normal,                // 0
	ScurtCircuitLaMasa,    // 1
	ScurtCircuitLaBaterie// 2

}starePort;

typedef struct _paramPort
{
	starePort currentState;
	uint8_t In;
	uint8_t Out;
	

}paramPort;

void NormalState(uint8_t In, uint8_t Out, starePort *nextState)
{
	if ((In == 0 && Out == 0) || (In == 1 && Out == 1))
	{
		*nextState = Normal;
	}
	else if(In == 0 && Out == 1)
	{
		*nextState = ScurtCircuitLaMasa;
	}
	else
	{
		*nextState = ScurtCircuitLaBaterie;
	}

}

void SCLM(uint8_t In, uint8_t Out, starePort *nextState)
{

	if ((In == 0 && Out == 0) || (In == 0 && Out == 1))
	{
		*nextState = ScurtCircuitLaMasa;
	}
	else if (In == 1 && Out == 1)
	{
		*nextState = Normal;
	}
	else
	{
		*nextState = ScurtCircuitLaBaterie;
	}

}

void SCLB(uint8_t In, uint8_t Out, starePort *nextState)
{

	if ((In == 1 && Out == 0) || (In == 1 && Out == 1))
	{
		*nextState = ScurtCircuitLaBaterie;
	}
	else if (In == 0 && Out == 0)
	{
		*nextState = Normal;
	}
	else
	{
		*nextState = ScurtCircuitLaMasa;
	}

}

void SetPortState(paramPort* pPort)
{
	if (pPort != NULL)
	{

		switch (pPort->currentState)
		{
		case (Normal):
			NormalState(pPort->In, pPort->Out, &pPort->currentState);
			break;

		case (ScurtCircuitLaMasa):
			SCLM(pPort->In, pPort->Out, &pPort->currentState);
			break;

		case (ScurtCircuitLaBaterie):
			SCLB(pPort->In, pPort->Out, &pPort->currentState);
			break;

		default:
			printf("Unknown state %d !", pPort->currentState);
			break;
		}

	}

}


void main()
{
	
	paramPort initialState = { 0, 0, Normal};
	uint8_t i = 0;
	


	for (; i < NMB_OF_PORTS; ++i )
	{
		initialState.In = rand() % 2;
		initialState.Out = rand() % 2;
		SetPortState(&initialState);
		printf("\nIn = %d\tOut = %d\nState :\t%d",initialState.In, initialState.Out, initialState.currentState);

	}



}

#endif

#if EX == 3
#if 0
#define TRUE 1
#define FALSE 0

#endif



#include <stdbool.h>

typedef enum 
{
	uint8,
	uint16,
	uint32,
	boolean,
	float32,

};

#if 0
typedef strcut _Bool
{
	uint8_t;
	uint8_t
}Bool;
#endif

typedef struct 
{
	

};

typedef union _Val
{
	uint8_t uint8;
	unsigned short uint16;
	unsigned int uint32;
	uint8_t boolean;
	float float32
};

void InitDataBase()
{

}

void PrintDataBase()
{

}

void SortByType()
{

}

void SortByValue()
{

}

void main()
{



}

#endif