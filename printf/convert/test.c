
#include <stdio.h>

char *x_convert(int val, char flag);

int main(int argc, char **argv)
{
	char *res = "A";
	int i;

	argc++;
	argv++;
	i = 100;
	while (i < 255)
	{
		res = x_convert(i, 'a');
		printf("%s -- %d\n",res, i);
		i++;
	}
	return (0);
}
