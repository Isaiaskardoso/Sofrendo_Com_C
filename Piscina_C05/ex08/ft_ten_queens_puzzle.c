/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IsaiasKardoso <isaiaskardososilva@gmail    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:30:45 by IsaiasKardo       #+#    #+#             */
/*   Updated: 2026/07/29 21:35:42 by IsaiasKardo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char c;
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);	
}

int	ft_is_safe(int board[10], int col, int row)
{
	int	i;
	
	i = 0;
	while (i < col)
	{
		if (board[i] == row)
		{
			return (0);
		}
		if (board[i] - row == i - col || board[i] - row == col - i)
		{
			return (0);
		}
		i++;		
	}
	return (1);
}

void	ft_solve(int board[10], int col, int *count)
{
	int row;

	if (col == 10)
	{
		row = 0;
		while (row < 10)
		{
			ft_putchar(board[row] + '0');
			row++;
		}
		ft_putchar('\n');
		(*count)++;
		return ;	
	}
	
	row = 0;
	while (row < 10)
	{
		if (ft_is_safe(board, col, row))
		{
			board[col] = row;
			ft_solve(board, col + 1, count);
		}
		row++;	
	}
}

int	ft_ten_queens_puzzle(void)
{
	int board[10];	
	int count;
	
	count = 0;
	ft_solve(board, 0, &count);
	return (count);
}

int	main(int argc, char *argv[])
{
	int	count;

	(void)argv;
	if (argc == 1)
	{
		count = ft_ten_queens_puzzle();
		ft_putnbr(count);
		ft_putchar('\n');
	}
	return (0);
}