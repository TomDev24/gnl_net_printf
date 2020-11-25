
#include <stdio.h>

char *x_convert(unsigned long int val, char flag);

int main(int argc, char **argv)
{
	char *res = "A";
	void *adr;
	int i;

	adr = (unsigned char*)res;
	argc++;
	argv++;
	i =	0;
	//BASIC INPUT FOR HEX CONVERTER
	/*while (i < 100)
	{
		res = x_convert(i, 'a');
		printf("%s -- %d\n",res, i);
		i++;
	}*/

	//ADRESS CONVERTERl
	res = x_convert(*((unsigned long int *)res), 'a');
	printf("%s\n",res);
	printf("printf %p\n",adr);
	return (0);
}
