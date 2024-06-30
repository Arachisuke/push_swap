/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:16:25 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/30 20:57:36 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack_b = NULL;
	stack = NULL;
	if (argc == 1) 
		return (0);
	if (!argv[1])
		return (0); 
	checkarg(argc, argv);
	if (argc == 2 && !is_space(argv[1]))
		return (0); 
	if (argc == 2)
		stack = handle_one_input(&stack, argv, 1);
	else
		stack = handle_input(&stack, argv);
	if (stack == NULL)
		return (1);
	if (!if_sorted(&stack))
		l_close("ERRORTRI", &stack);
	
	choose_sort(&stack, &stack_b);
	free_stack(&stack);
}

