
#include <stdio.h>

char *x_convert( int val, char flag);

int main(int argc, char **argv)
{
	char *res = "A";
	void *adr;
	int i;

	adr = (unsigned char*)res;
	argc++;
	argv++;
	i =	15;
	//BASIC INPUT FOR HEX CONVERTER
	while (i < 16)
	{
		res = x_convert(12345, 'A');
		printf("%s -- %d\n",res, i);
		printf("%x !!", 12345);
		i++;
	}

	//ADRESS CONVERTERl
	res = x_convert(*((unsigned long int *)res), 'a');
	printf("%s\n",res);
	printf("printf %p\n",adr);
	/////////////////
	return (0);
}
