/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kardoso <kardoso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:16:30 by kardoso           #+#    #+#             */
/*   Updated: 2026/11/11 12:09:48 by kardoso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <unistd.h>

void set_point(t_point *point, int x, int y)
{
point->x = x;
point->y = y;
}

int ft_atoi(char *str)
{
int i;
int sign;
int result;

i = 0;
sign = 1;
result = 0;
if (str[i] == '-' || str[i] == '+')
{
if (str[i] == '-')
sign = -1;
i++;
}
while (str[i] >= '0' && str[i] <= '9')
{
result = result * 10 + (str[i] - '0');
i++;
}
return (result * sign);
}

void ft_putnbr(int n)
{
char c;

if (n == -2147483648)
{
write(1, "-2147483648", 11);
return ;
}
if (n < 0)
{
write(1, "-", 1);
n = -n;
}
if (n > 9)
ft_putnbr(n / 10);
c = (n % 10) + '0';
write(1, &c, 1);
}

int main(int argc, char **argv)
{
t_point point;

if (argc != 3)
{
write(2, "Uso: ./a.out x y\n", 17);
return (1);
}
set_point(&point, ft_atoi(argv[1]), ft_atoi(argv[2]));
ft_putnbr(point.x);
write(1, "\n", 1);
ft_putnbr(point.y);
write(1, "\n", 1);
return (0);
}