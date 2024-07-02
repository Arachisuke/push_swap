/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:15:48 by wzeraig           #+#    #+#             */
/*   Updated: 2024/07/01 19:49:07 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checkarg(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++j <= argc - 1)
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				if (argv[j][i] != '-' && argv[j][i] != '+' && argv[j][i] != ' ')
					l_close("ERROR", NULL);
			if (argv[j][i] == '-' || argv[j][i] == '+')
			{
				if (i != 0)
					if (argv[j][i - 1] != ' ')
						l_close("ERROR", NULL);
				if (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')
					l_close("ERROR", NULL);
			}
			i++;
		}
		i = 0;
	}
	return (0);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && i != 0 && str[i + 1] != '\0')
			if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '-'
				|| str[i + 1] == '+')
				return (1);
		i++;
	}
	return (0);
}

t_stack	*handle_one_input(t_stack **stack_a, char **argv, int j)
{
	char	**arg;
	int		i;
	long	num;

	i = 0;
	arg = ft_split(argv[j], ' ');
	if (arg == NULL)
		return (NULL);
	while (arg[i])
	{
		num = ft_atoii(arg[i]);
		if (num == 2147483648)
		{
			ft_free(arg);
			l_close("ERROR", stack_a);
		}
		compare(stack_a, num);
		if (i == 0 && !*stack_a)
			*stack_a = ft_new(num);
		else
			ft_back(stack_a, ft_new(num));
		i++;
	}
	ft_free(arg);
	return (*stack_a);
}

t_stack	*handle_input(t_stack **stack_a, char **argv)
{
	int		j;
	long	num;
	char	**arg;

	j = 0;
	arg = NULL;
	while (argv[++j])
	{
		num = ft_atoii(argv[j]);
		if (num == 2147483648)
			l_close("ERROR", stack_a);
		compare(stack_a, num);
		if (is_space(argv[j]))
		{
			if (arg)
				return (NULL);
			handle_one_input(stack_a, argv, j);
		}
		else
		{
			ft_back(stack_a, ft_new(num));
		}
	}
	return (*stack_a);
}

t_stack	*ft_new(long value)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->content = value;
	elem->next = NULL;
	return (elem);
}

// void	print_stack(t_stack **stack)
// {
// 	t_stack	*actuel;

// 	actuel = *stack;
// 	while (actuel)
// 	{
// 		printf("[%d]->", actuel->content);
// 		// printf("[%d]->", actuel->indice);
// 		// printf("[%d]->", actuel->target_indice);
// 		// printf("[%d]->", actuel->previousnbr);
// 		actuel = actuel->next;
// 	}
// 	printf("NULL");
// 	printf("\n");
// }
// void	print_target_indice(t_stack **stack)
// {
// 	t_stack	*actuel;

// 	actuel = *stack;
// 	printf("voici la target : \n");
// 	while (actuel)
// 	{
// 		//printf("[%d]->", actuel->content);
// 		//printf("[%d]->", actuel->indice);
// 		printf("[%d]->", actuel->target_indice);
// 		//printf("[%d]->", actuel->cost);
// 		//printf("[%d]->", actuel->previousnbr);
// 		actuel = actuel->next;
// 	}
// 	printf("NULL");
// 	printf("\n");
// }
// void	print_indice(t_stack **stack)
// {
// 	t_stack	*actuel;

// 	actuel = *stack;
// 	printf("voici l'indice : \n");
// 	while (actuel)
// 	{
// 		//printf("[%d]->", actuel->content);
// 		printf("[%d]->", actuel->indice);
// 		//printf("[%d]->", actuel->target_indice);
// 		//printf("[%d]->", actuel->previousnbr);
// 		actuel = actuel->next;
// 	}
// 	printf("NULL");
// 	printf("\n");
// }

// void swap(t_stack **stack)
// {
// 	t_stack *tmp;

// 	tmp = st
// }

// void	print_cost(t_stack **stack)
// {
// 	t_stack	*actuel;

// 	actuel = *stack;
// 	printf("voici le cost : \n");

// 	while (actuel)
// 	{
// 		//printf("[%d]->", actuel->content);
// 		//printf("[%d]->", actuel->indice);
// 		//printf("[%d]->", actuel->target_indice);
// 		printf("[%d]->", actuel->cost);
// 		//printf("[%d]->", actuel->previousnbr);
// 		actuel = actuel->next;
// 	}
// 	printf("NULL");
// 	printf("\n");
// }
