/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:44 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/26 20:30:54 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*stack || !(*stack)->next) // bien comprendre la syntax
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	// print_stack(stack);
	return (*stack);
}
t_stack	*sa(t_stack **stack_a)
{
	if (!*stack_a)
		return (NULL);
	*stack_a = swap(stack_a);
	ft_printf("sa\n");
	if (!stack_a)
		return (NULL);
	return (*stack_a);
}
t_stack	*sb(t_stack **stack)
{
	if (!*stack)
		return (NULL);
	*stack = swap(stack);
	if (!stack)
		return (NULL);
	ft_printf("sb\n");
	return (*stack);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	*stack_a = swap(stack_a);
	if (!*stack_a)
		return ;
	*stack_b = swap(stack_b);
	// protection ou pas ?
	ft_printf("ss\n");
}
t_stack	*push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!stack_1)
		return (NULL);
	tmp = (*stack_1);
	*stack_1 = (*stack_1)->next;
	tmp->next = *stack_2;
	*stack_2 = tmp;
	// print_stack(stack_2);
	// printf("\n");
	// print_stack(stack_1);
	return (*stack_2);
}
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	if (stack_a == NULL)
		return ;
	//print_stack(stack_a);
	ft_printf("pa\n");
}
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	//print_stack(stack_b);
	ft_printf("pb\n");
}
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	// tmp = *stack;
	// *stack = (*stack)->next;
	// tmp->next = NULL;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_back(stack, tmp);
	// print_stack(stack);
}
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	ft_front(stack, tmp->next);
	tmp->next = NULL;
	// print_stack(stack);
}
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
void	ft_front(t_stack **list, t_stack *new)
{
	new->next = *list;
	*list = new;
}
void	sort_three(t_stack **stack) // made by me =)
{
	if ((*stack)->content > (*stack)->next->content
		&& ((*stack)->content > (*stack)->next->next->content))
		ra(stack);
	if ((*stack)->content < (*stack)->next->content
		&& ((*stack)->content > (*stack)->next->next->content))
		rra(stack);
	// seul cas qui fais 3 coup jai envie de le mettre en un coup
	if (if_sorted(stack))
		sa(stack);
	if (if_sorted(stack))
		ra(stack);
	if (if_sorted(stack))
		sa(stack);
	//print_stack(stack);
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
