/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_without_padding.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 10:01:39 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 15:21:55 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_without_padding(char *str, char padding)
{
	int	len;

	len = 0;
	if (*str == '+' || *str == '-')
	{
		str++;
		len++;
	}
	while (*str == padding)
		str++;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
