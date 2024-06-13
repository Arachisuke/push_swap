/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:23:50 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/13 19:44:37 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// on prend la chaine a alors celle quon va push
// je parcours la liste a,
// dabord le target_indice avec la range de if on recupere son mouvement ainsi que son cost ensuite indice on recupere son movement on le compare et la on calcul le full cost
// je calcule le cost ainsi que l'indice, if (1) if (2) ect
// ensuite je dois verifier si ya pas double movement des deux cotes donc faire un if (2) movement = swap,
// et verifier si le target indice = a swap if true alors il vaut que un le movement et on met que cest ss

void	calcul_cost_same_a(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	test = 0;
	if (tmp->indice == 2 && tmp->target_indice == 2)
		tmp->cost = 1;
	else if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		test = ft_size(*stack_a) - tmp->indice + 1;
		tmp->cost = ft_size(*stack_b) - tmp->target_indice + 1;
	}
	else if ((tmp->indice <= ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice <= ft_size(*stack_b) / 2 + 1))
	{
		test = tmp->indice - 1;
		tmp->cost = tmp->target_indice - 1;
	}
	else if ((tmp->indice == ft_size(*stack_a)
			&& tmp->target_indice == ft_size(*stack_b)))
		tmp->cost = 1;
	if (test > tmp->cost)
		tmp->cost = test;
}

void	calcul_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->indice == 2)
			tmp->cost = 1;
		else if (tmp->indice > ft_size(*stack_a) / 2 + 1)
			tmp->cost = ft_size(*stack_a) - tmp->indice + 1;
		else if (tmp->indice <= ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->indice - 1;
		// la jai calcule pour indice maintenant pour target
		if (tmp->target_indice == 2)
			tmp->cost = tmp->cost + 1;
		else if (tmp->indice > ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->cost + ft_size(*stack_a) - tmp->indice + 1;
		else if (tmp->indice <= ft_size(*stack_a) / 2 + 1)
			tmp->cost = tmp->cost + tmp->indice - 1;
		calcul_cost_same_a(tmp, stack_a, stack_b);
		// a voir si je dois pas lui envoyer un pointeur de pointeur pour change les valeurs
		tmp = tmp->next;
	}
}
void	calcul_cost_same_b(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
	int	test;

	test = 0;
	if (tmp->indice == 2 && tmp->target_indice == 2)
		tmp->cost = 1;
	if ((tmp->indice > ft_size(*stack_b) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_a) / 2 + 1))
	{
		test = ft_size(*stack_b) - tmp->indice + 1;
		tmp->cost = ft_size(*stack_a) - tmp->target_indice + 1;
	}
	if ((tmp->indice <= ft_size(*stack_b) / 2 + 1
			&& tmp->target_indice <= ft_size(*stack_a) / 2 + 1))
	{
		test = tmp->indice - 1;
		tmp->cost = tmp->target_indice - 1;
	}
	if (test > tmp->cost)
		tmp->cost = test;
}

void	calcul_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->indice == 2)
			tmp->cost = 1;
		else if (tmp->indice > ft_size(*stack_b) / 2 + 1)
			tmp->cost = ft_size(*stack_b) - tmp->indice + 1;
		else if (tmp->indice <= ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->indice - 1;
		// la jai calcule pour indice maintenant pour target
		if (tmp->target_indice == 2)
			tmp->cost = tmp->cost + 1;
		else if (tmp->indice > ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->cost + ft_size(*stack_b) - tmp->indice + 1;
		else if (tmp->indice <= ft_size(*stack_b) / 2 + 1)
			tmp->cost = tmp->cost + tmp->indice - 1;
		calcul_cost_same_b(tmp, stack_a, stack_b);
		// a voir si je dois pas lui envoyer un pointeur de pointeur pour change les valeurs
		tmp = tmp->next;
	}
}