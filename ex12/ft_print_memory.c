/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:50:01 by alnoukan          #+#    #+#             */
/*   Updated: 2026/06/25 11:11:46 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printhex(unsigned char c)
{
	char	base[16] = "0123456789abcdef";

	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_printable(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 16)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	ft_puthex(unsigned char *str, unsigned int size, unsigned int start)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (j < 16 && start + j < size)
			ft_printhex(str[start + j]);
		else
			ft_putchar(' ');
		if (j % 2 == 1)
			ft_putchar(' ');
		j++;
	}
}

void	ft_putnbr_base(unsigned long long nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	if (size < 0)
		return (addr);
	i = 0;
	ptr = (unsigned char *)addr;
	while(i < size)
	{
		ft_putnbr_base((unsigned long)(addr + i), "0123456789abcdef");
		ft_puthex((addr + i), size, i);
		ft_printable(addr + i);
		i += 16;
	}
	return (addr);
}

int main()
{
	char	str[48] = "hello world!hello world!hello world!hello world!";
	ft_print_memory((void *)str, 24);
	return (0);
}
