#include <stdio.h>
#include "../includes/ft_printf.h"

int		main(void)
{
	char	*str = "Hello";

	printf("%15c|\n", 'c');
	ft_printf("%15c|\n", 'c');
	printf("%15s|\n", str);
	ft_printf("%15s|\n", str);
	printf("%15c|\n", 'c');
	ft_printf("%15c|\n", 'c');
	printf("%-15s|\n", str);
	ft_printf("%-15s|\n", str);
	printf("%-15.3s|\n", str);
	ft_printf("%-15.3s|\n", str);
	printf("------------------------------------------------------\n");
	printf("%p|\n", str);
	ft_printf("%p|\n", str);
	printf("%30p|\n", str);
	ft_printf("%30p|\n", str);
	printf("%-30p|\n", str);
	ft_printf("%-30p|\n", str);
	printf("------------------------------------------------------\n");
	printf("%d|\n", 5);
	ft_printf("%d|\n", 5);
	printf("%.20d|\n", 5);
	ft_printf("%.20d|\n", 5);
	printf("% d|\n", 5);
	ft_printf("% d|\n", 5);
	printf("%+d|\n", 5);
	ft_printf("%+d|\n", 5);
	printf("%d|\n", -5);
	ft_printf("%d|\n", -5);
	printf("%+15.10d|\n", -5);
	ft_printf("%+15.10d|\n", -5);
}
