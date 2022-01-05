/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 11:53:23 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 15:21:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(char *str)
{
	long long	nbr;
	int			sign;

	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (*str == '0')
		str++;
	while (*str)
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (sign * nbr);
}
