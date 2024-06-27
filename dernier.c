/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dernier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:50:59 by macos             #+#    #+#             */
/*   Updated: 2024/06/26 19:25:33 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_the_cheapest_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *actuel;
    int smallestcost;

    actuel = *stack_a;
    smallestcost = actuel->cost;
    tmp = actuel;
    while(actuel)
    {
        if (actuel->cost < smallestcost)
        {
            smallestcost = actuel->cost;
            tmp = actuel;
        }
        actuel = actuel->next;
    }
    lets_sort_same(tmp, stack_a, stack_b);
}

void lets_sort_a(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // je trie la stack a par rapport a son indice et le place tout en haut
{
    int test;

    if (tmp->indice == 2)
		sa(stack_a);
    else if (tmp->indice == ft_size(*stack_a))
        rra(stack_a);
		else if (tmp->indice > ft_size(*stack_a) / 2 + 1) //VERSION CORRIGER
        {
            test = (ft_size(*stack_a) + 1) - tmp->indice;
			while(test > 0) // ou jinit les indice et jattend que lindice soit egal a 0 en sachant que apres il va rentrer dans les autres if peut etre
            {
                rra(stack_a);
                test--;
            }
        }
		else if (tmp->indice <= ft_size(*stack_a) / 2 + 1)
        {
                test = tmp->indice - 1;
			while(test > 0)
            {
                ra(stack_a);
                test--;
            }
        }
    lets_sort_b(tmp, stack_a, stack_b);
}

void lets_sort_b(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // je trie la stack b par rapport a son target_indice et le place tout en haut
{
    int test;

    (void)stack_a; // a changer 
    if (tmp->target_indice == 2)
			sb(stack_b);
   else if (tmp->target_indice == ft_size(*stack_b))
        rrb(stack_b);
		else if (tmp->target_indice > ft_size(*stack_b) / 2 + 1)
        {
            test = (ft_size(*stack_b) + 1) - tmp->target_indice;
			while(test > 0) // ou jinit les indice et jattend que lindice soit egal a 0 en sachant que apres il va rentrer dans les autres if peut etre
            {
                rrb(stack_b);
                test--;
            }
        }
		else if (tmp->target_indice <= ft_size(*stack_b) / 2 + 1)
        {
                test = tmp->target_indice - 1;
			while(test > 0)
            {
                rb(stack_b);
                test--;
            }
        }
    pb(stack_a, stack_b);
}

void lets_sort_same(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // pour le cas ou on veut ramener stack a dans stack b je trie si ya le meme mov
{
	if (tmp->indice == 2 && tmp->target_indice == 2)
		ss(stack_a, stack_b); // relance un target smallest normalement la case target de notre tmp va change par rapport au mouvement
	else if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		while((ft_size(*stack_a) + 1) - tmp->indice || (ft_size(*stack_b) + 1) - tmp->target_indice) // while((ft_size(*stack_b) + 1) - tmp->target_indice)
         {
            rrr(stack_a, stack_b);
         }   
	}
    else if (tmp->target_indice > 1 && tmp->indice > 1)
    {
	     if ((tmp->indice <= ft_size(*stack_a) / 2 + 1
	 	    && tmp->target_indice <= ft_size(*stack_b) / 2 + 1))
	    {
            while(--tmp->indice > 1 || --tmp->target_indice > 1)
                rr(stack_a, stack_b);
	    }
    }
    maj(stack_a, stack_b);
    lets_sort_a(tmp, stack_a, stack_b);
}

void lets_sort_same1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // pour le cas ou on veut ramener stack a dans stack b je trie si ya le meme mov
{
	if (tmp->indice == 2 && tmp->target_indice == 2)
		ss(stack_a, stack_b); // relance un target smallest normalement la case target de notre tmp va change par rapport au mouvement
	else if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		while((ft_size(*stack_a) + 1) - tmp->indice > 1 || (ft_size(*stack_b) + 1) - tmp->target_indice > 1) // while((ft_size(*stack_b) + 1) - tmp->target_indice)
         {
            rrr(stack_a, stack_b);
            maj1(stack_a, stack_b);
         }   
	}
    else if (tmp->target_indice > 1 && tmp->indice > 1)
    {
	     if ((tmp->indice <= ft_size(*stack_a) / 2 + 1
	 	    && tmp->target_indice <= ft_size(*stack_b) / 2 + 1))
	    {
            while(--tmp->indice > 1 || --tmp->target_indice > 1)
                rr(stack_a, stack_b);
	    }
    }
    maj1(stack_a, stack_b);
    lets_sort_a_1(tmp, stack_a, stack_b);
}

