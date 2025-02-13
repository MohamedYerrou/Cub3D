#include "../medpart.h"

int	message_val(int detail, char *str, int code)
{
	ft_putstr_fd(BRED "cub3D: Error: ", 2);
	ft_putnbr_fd(detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" BRED, 2);
	return (code);
}

int	message(char *detail, char *str, int code)
{
	ft_putstr_fd(BRED "Error", 2);
	if (detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(detail, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("!\n", 2);
	}
	return (code);
}
