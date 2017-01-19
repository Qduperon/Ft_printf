#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int		main(void)
{
	printf("\ndis is mine : %d\n", ft_printf("%x", 17));
	printf("\nze original : %d", printf("%x", 17));
	// printf("\n%d", printf("%p, %#x", malloc(1), 154654));
	// printf("\n%d", printf("%16p", "hello"));
	//printf("\n%d", printf("%+20hhd", 90));
	return (0);
}
