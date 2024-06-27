/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dernier2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:45:26 by macos             #+#    #+#             */
/*   Updated: 2024/06/27 13:27:15 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_the_cheapest_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *actuel;
    int smallestcost;

    actuel = *stack_b;
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
    lets_sort_same1(tmp, stack_a, stack_b);
}

void lets_sort_a_1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // je trie la stack a par rapport a son indice et le place tout en haut
{
    int test;

    // if (tmp->target_indice == 2)
	// 	sa(stack_a);
    if (tmp->target_indice == ft_size(*stack_a))
        rra(stack_a);
		else if (tmp->target_indice > ft_size(*stack_a) / 2 + 1)
        {
            test = (ft_size(*stack_a) + 1) - tmp->target_indice;
			while(test > 0) // ou jinit les indice et jattend que lindice soit egal a 0 en sachant que apres il va rentrer dans les autres if peut etre
            {
                rra(stack_a);
                test--;
            }
        }
		else if (tmp->target_indice <= ft_size(*stack_a) / 2 + 1)
        {
                test = tmp->target_indice - 1;
			while(test > 0)
            {
                ra(stack_a);
                test--;
            }
        }
        maj1(stack_a, stack_b);
    lets_sort_b_1(tmp, stack_a, stack_b);
}

void lets_sort_b_1(t_stack *tmp, t_stack **stack_a, t_stack **stack_b) // je trie la stack b par rapport a son target_indice et le place tout en haut
{
    int test;
    (void)stack_a; // a change 
    if (tmp->indice == 2)
		sb(stack_b);
    else if (tmp->indice == ft_size(*stack_b) && tmp->indice > 1)
        rrb(stack_b);
	else if (tmp->indice > ft_size(*stack_b) / 2 + 1)
    {
        test = (ft_size(*stack_b) + 1) - tmp->indice;
		while(test > 0) // ou jinit les indice et jattend que lindice soit egal a 0 en sachant que apres il va rentrer dans les autres if peut etre
        {
                rrb(stack_b);
                test--;
            }
        }
		else if (tmp->indice <= ft_size(*stack_b) / 2 + 1)
        {
                test = tmp->indice - 1;
			while(test > 0)
            {
                rb(stack_b);
                test--;
            }
        }
        pa(stack_a, stack_b);
}

void maj(t_stack **stack_a, t_stack **stack_b) //  change en stack1 stack2 comme ca la fonction marche dans les deux sens
{
    //init_indice(stack_b); // target utilise son propre indice lors de la boucle pas
    init_indice(stack_a);
    target_smallest(stack_a, stack_b); // je retarget en sachant que mon target a du bouge 
   // print_target_indice(stack_a);
    //print_indice(stack_a);
    // une fois arrive dans la fonction d'apres les modification ont ete operer et la ca rentre ou non dans le bon if
}
void maj1(t_stack **stack_a, t_stack **stack_b) //  change en stack1 stack2 comme ca la fonction marche dans les deux sens
{
    //init_indice(stack_b); // target utilise son propre indice lors de la boucle pas
    init_indice(stack_b);
    target_biggest(stack_a, stack_b); // je retarget en sachant que mon target a du bouge 
   // print_target_indice(stack_a);
    //print_indice(stack_a);
    // une fois arrive dans la fonction d'apres les modification ont ete operer et la ca rentre ou non dans le bon if
}

void find_the_min(t_stack **stack) // trouver le min dans la stack a et le remettre tout en haut
{
    t_stack *tmp;
    int indice;

    tmp = *stack;
    indice = target_the_smallest(tmp, stack);
    
    // if (indice == 2)
    //     sa(stack);
    while(indice != 1)
    {
        if (indice <= ft_size(*stack) / 2 + 1)
            ra(stack);
        if (indice > ft_size(*stack) / 2 + 1)
            rra(stack);
        indice = target_the_smallest(tmp, stack);
    }
    
}