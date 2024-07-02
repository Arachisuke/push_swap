/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:48:05 by macos             #+#    #+#             */
/*   Updated: 2024/07/01 18:57:09 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;
	char	*cmd;

	cmd = NULL;
	stack_b = NULL;
	stack = NULL;
	if (argc == 1 || !argv[1])
		return (0);
	checkarg(argc, argv);
	if (argc == 2 && !is_space(argv[1]))
		return (0);
	if (argc == 2)
		stack = handle_one_input(&stack, argv, 1);
	else
		stack = handle_input(&stack, argv);
	if (stack == NULL)
		return (0);
	command(&stack, &stack_b, cmd);
	if (!if_sorted(&stack) && stack_b == NULL)
		l_close("OK", &stack);
	else
		l_close("KO", &stack);
}

int	ft_size1(t_stack *lst)
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

void	command2(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "ra", 2) && ft_strlen(cmd) == 3)
		ra(stack_a);
	else if (!ft_strncmp(cmd, "rb", 2) && ft_strlen(cmd) == 3)
		rb(stack_b);
	else if (!ft_strncmp(cmd, "rr", 2) && ft_strlen(cmd) == 3)
		rr(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "rra", 3) && ft_strlen(cmd) == 4)
		rra(stack_a);
	else if (!ft_strncmp(cmd, "rrb", 3) && ft_strlen(cmd) == 4)
		rrb(stack_b);
	else if (!ft_strncmp(cmd, "rrr", 3) && ft_strlen(cmd) == 4)
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "sa", 2) && ft_strlen(cmd) == 3)
		sa(stack_a);
	else if (!ft_strncmp(cmd, "pb", 2) && ft_strlen(cmd) == 3)
		pb(stack_a, stack_b);
	else if (!ft_strncmp(cmd, "pa", 2) && ft_strlen(cmd) == 3)
		pa(stack_a, stack_b);
	else
	{
		free(cmd);
		l_close("ERROR", stack_a);
	}
}

void	command(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	while (1)
	{
		if (if_sorted(stack_a) == 0)
		{
			if (ft_size1(*stack_b) == 0)
			{
				free(cmd);
				break ;
			}
		}
		if (cmd)
			free(cmd);
		cmd = get_next_line(0);
		if (!ft_strncmp(cmd, "\n", 2))
		{
			free(cmd);
			break ;
		}
		command2(stack_a, stack_b, cmd);
	}
}
