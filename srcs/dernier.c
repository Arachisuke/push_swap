/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dernier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:50:59 by macos             #+#    #+#             */
/*   Updated: 2024/06/30 20:54:55 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void lets_sort_a(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
    int test;

    if (tmp->indice == ft_size(*stack_a))
        rra(stack_a);
		else if (tmp->indice > ft_size(*stack_a) / 2 + 1) 
        {
            test = (ft_size(*stack_a) + 1) - tmp->indice;
			while(test > 0) 
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

void lets_sort_b(t_stack *tmp, t_stack **stack_a, t_stack **stack_b)
{
    int test;

    (void)stack_a;
    if (tmp->target_indice == ft_size(*stack_b))
        rrb(stack_b);
		else if (tmp->target_indice > ft_size(*stack_b) / 2 + 1)
        {
            test = (ft_size(*stack_b) + 1) - tmp->target_indice;
			while(test > 0)
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

void lets_sort_same(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) 
{
	if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		while((tmp->indice > 1) && (tmp->target_indice > 1)) 
         {
            rrr(stack_a, stack_b);
            maj(stack_a, stack_b);
         }   
	}
    else if (tmp->target_indice > 1 && tmp->indice > 1)
    {
	     if ((tmp->indice <= ft_size(*stack_a) / 2 + 1
	 	    && tmp->target_indice <= ft_size(*stack_b) / 2 + 1))
	    {
            while(tmp->indice > 1 && tmp->target_indice > 1) 
            {
                rr(stack_a, stack_b);
                maj(stack_a, stack_b);
            }
	    }
    }
    maj(stack_a, stack_b);
    lets_sort_a(tmp, stack_a, stack_b);
}

void lets_sort_same1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) 
{
	if ((tmp->indice > ft_size(*stack_a) / 2 + 1
			&& tmp->target_indice > ft_size(*stack_b) / 2 + 1))
	{
		while(tmp->indice > 1 && tmp->target_indice > 1) 
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
            while(tmp->indice > 1 && tmp->target_indice > 1) 
            {
                rr(stack_a, stack_b);
                maj1(stack_a, stack_b);
            }
	    }
    }
    maj1(stack_a, stack_b);
    lets_sort_a_1(tmp, stack_a, stack_b);
}


