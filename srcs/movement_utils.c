/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:31:58 by macos             #+#    #+#             */
/*   Updated: 2024/07/01 19:22:00 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_front(t_stack **list, t_stack *new)
{
	new->next = *list;
	*list = new;
}

void	sort_three(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& ((*stack)->content > (*stack)->next->next->content))
		ra(stack);
	if ((*stack)->content < (*stack)->next->content
		&& ((*stack)->content > (*stack)->next->next->content))
		rra(stack);
	if (if_sorted(stack))
		sa(stack);
	if (if_sorted(stack))
		ra(stack);
	if (if_sorted(stack))
		sa(stack);
}

int	if_sorted(t_stack **stack)
{
	t_stack	*actuel;

	actuel = *stack;
	while (actuel->next)
	{
		if (actuel->next->content < actuel->content)
			return (1);
		actuel = actuel->next;
	}
	return (0);
}

void	ft_free(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
	{
		free(strs[j]);
		j++;
	}
	free(strs);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	while (tmp)
	{
		free(*stack);
		*stack = tmp;
		tmp = tmp->next;
	}
	free(*stack);
}
