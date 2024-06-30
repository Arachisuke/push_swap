/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:25:40 by macos             #+#    #+#             */
/*   Updated: 2024/06/30 20:25:43 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_last(*lst);
		last->next = new;
	}
}

t_stack	*ft_last(t_stack *lst)
{
	t_stack	*actuel;

	if (!lst)
		return (NULL);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}

int	l_close(char *str, t_stack **stack)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	if (stack)
		free_stack(stack);
	exit(0);
}
void	compare(t_stack **stack, int nbr)
{
	t_stack	*actuel;

	actuel = *stack;
	while (actuel)
	{
		if (nbr == actuel->content)
			l_close("ERROR1", stack);
		actuel = actuel->next;
	}
}
long	ft_atoii(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10);
		res = res + (str[i] - 48);
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (2147483648);
		i++;
	}
	return (res * sign);
}
