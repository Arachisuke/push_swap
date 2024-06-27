/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macos <macos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:15:48 by wzeraig           #+#    #+#             */
/*   Updated: 2024/06/24 16:49:06 by macos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
					l_close("ni un chiffre ni un operateur ni un espace");
			// si cest autre chose quun chiffre / espace
			if (argv[j][i] == '-' || argv[j][i] == '+')
			{
				if (i != 0)
					if (argv[j][i - 1] != ' ')
						l_close("ya un chiffre avant l'operateur");
				if (argv[j][i + 1] < '0' || argv[j][i + 1] > '9')
					l_close("c'est pas un chiffre apres l'operateur");
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
			//  0 lespace vaut rien et espace de fin
			if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '-'
				|| str[i + 1] == '+') // si c un chiffre
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
			l_close("ton gros nombre la tshiiip");
		compare(stack_a, num);
		if (i == 0 && !*stack_a)
			*stack_a = ft_new(num);
		// je supprimerais apres pck jai pas besoin la stack a cca le fais dans addback
		else
			ft_back(stack_a, ft_new(num));
		i++;
	}
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
			l_close("ton gros nombre la tshiiip");
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

void	ft_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_last(*lst);
		last->next = new;
	}
}

t_stack	*ft_last(t_stack *lst)
{
	t_stack	*actuel;

	if (!lst)
		return (NULL);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}
void	print_stack(t_stack **stack)
{
	t_stack	*actuel;

	actuel = *stack;
	while (actuel)
	{
		printf("[%d]->", actuel->content);
		//printf("[%d]->", actuel->indice);
		//printf("[%d]->", actuel->target_indice);
		//printf("[%d]->", actuel->previousnbr);		
		actuel = actuel->next;
	}
	printf("NULL");
	printf("\n");
}
void	print_target_indice(t_stack **stack)
{
	t_stack	*actuel;

	actuel = *stack;
	printf("voici la target : \n");
	while (actuel)
	{
		//printf("[%d]->", actuel->content);
		//printf("[%d]->", actuel->indice);
		printf("[%d]->", actuel->target_indice);
		//printf("[%d]->", actuel->cost);
		//printf("[%d]->", actuel->previousnbr);		
		actuel = actuel->next;
	}
	printf("NULL");
	printf("\n");
}
void	print_indice(t_stack **stack)
{
	t_stack	*actuel;

	actuel = *stack;
	printf("voici l'indice : \n");
	while (actuel)
	{
		//printf("[%d]->", actuel->content);
		printf("[%d]->", actuel->indice);
		//printf("[%d]->", actuel->target_indice);
		//printf("[%d]->", actuel->previousnbr);		
		actuel = actuel->next;
	}
	printf("NULL");
	printf("\n");
}

// void swap(t_stack **stack)
// {
// 	t_stack *tmp;

// 	tmp = st
// }

int	l_close(char *str)
{
	printf("%s", str);
	exit(0);
}
void	compare(t_stack **stack, int nbr)
{
	t_stack	*actuel;

	actuel = *stack;
	while (actuel)
	{
		if (nbr == actuel->content)
			l_close("doublons brooo");
		actuel = actuel->next;
	}
}
void	print_cost(t_stack **stack)
{
	t_stack	*actuel;

	actuel = *stack;
	printf("voici le cost : \n");
	
	while (actuel)
	{
		//printf("[%d]->", actuel->content);
		//printf("[%d]->", actuel->indice);
		//printf("[%d]->", actuel->target_indice);
		printf("[%d]->", actuel->cost);
		//printf("[%d]->", actuel->previousnbr);		
		actuel = actuel->next;
	}
	printf("NULL");
	printf("\n");
}