typedef char uint8;
uint8 nr = 213;
//Functie de setare a bitului de pe o pozitie data
void setBit(uint8 bitPos, uint8 bitValue)
{
	uint8 i = nr;

	bitValue == 1 ? (nr |= 1 << bitPos) : (nr &= ~(1 << bitPos));


}


//functie de citire a unui bit de pe o anumita pozitie
uint8 getBit(uint8 bitPos)
{
	uint8 value = 0;

	value = (nr >> bitPos) & 1;

	return value;




}
//functie ce afiseaza valoarea binara a unui numar
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