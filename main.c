#include "ft_printf.h"

int main ()
{
//	char *str = "salut";
	char c = 'a';
	ft_printf("%p", &c);
	write(1, "\n", 1);
	printf("%p",&c);
	return(0);
}
