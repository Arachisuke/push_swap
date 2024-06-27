/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:16:25 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/26 20:19:31 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack_b = NULL;
	stack = NULL;
	// stack_b = NULL;
	if (argc == 1) // donc ya pas d'arg heiiiinn
		return (0);
	if (!argv[1])
		return (0); // l'arg est vide heiiin
	checkarg(argc, argv);
	if (argc == 2 && !is_space(argv[1]))
		return (0); // un arg donc trier heiiiins
	if (argc == 2)
		stack = handle_one_input(&stack, argv, 1);
	else
		stack = handle_input(&stack, argv);
	if (stack == NULL)
		return (1);
	// print_stack(&stack);
	if (!if_sorted(&stack))
		l_close("c'est deja trier mon reuuuuuf");
	
	choose_sort(&stack, &stack_b);
	// print_indice(&stack_b);
	// print_indice(&stack);
	// print_stack(&stack_b);
	// print_stack(&stack);
	// print_target_indice(&stack_b);
	// print_target_indice(&stack);
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
