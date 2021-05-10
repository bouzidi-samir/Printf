#include "ft_printf.h"
#include "limits.h"

int main ()
{
//	char *str = "salut";
//	char *s2 = "coucou";
//	char *s3 = "sam";
//	char *s4 = "ola";
	//int j = 3;
	int i = 0;
	//	int j = 1;
	i = ft_printf("%09.0d", -42);
	write(1, "\n", 1);
//	printf("%.d", 0);
	printf("%d" , i);
//	write(1, "\n", 1);
	return(0);
}
