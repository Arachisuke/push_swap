/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:40:19 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/13 19:29:56 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(t_stack *lst)
{
	int		i;
	t_stack	*actuel;

	actuel = lst;
	i = 0;
	while (actuel)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}
void choose_sort(t_stack **stack)
{
	if (ft_size(*stack) == 2)
		two_arg(stack);
	if (ft_size(*stack) == 3)
		sort_three(stack);
	//if (ft_size(*stack) == 4)
		// trier les 4
	//else
		//main_sort(stack);
}
void two_arg(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}
void test1(t_stack **stack)
{
	while(*stack)
	{
		*stack = (*stack)->next; // ok donc si je deplace le pointeur a la fin il prend vraiment la valeur mdr quand je lecris je comprend que c logique c'etait pour savoir si je parcours la chaine avec stack que jenvoie et ce que apres il renvoie null comme a la fin de son voyage il vaut NULL
	}
}

void init_node(t_stack **stack) // donc jarrive a init sur la base d'actuel... a mediter
{
	t_stack *actuel;
	int i;

	actuel = *stack;
	i = 1;
	while(actuel)
	{
		actuel->indice = i;
		actuel->target_indice = 0;
		actuel->previousnbr = 0;
		i++;
		actuel = actuel->next;
	}
}

void init_node_b(t_stack **stack)
{
	t_stack *actuel;
	int i;

	actuel = *stack;
	i = 1;
	while(actuel)
	{
		actuel->indice = i;
		i++;
		actuel = actuel->next;
	}
}
