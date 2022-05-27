/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:58:29 by vfiszbin          #+#    #+#             */
/*   Updated: 2022/05/27 17:20:48 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *t, int i, int j)
{
	int	tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

int	quicksort_separation(int *t, int begin, int end)
{
	int	i;
	int	sep;

	sep = begin + 1;
	i = begin + 1;
	while (i <= end)
	{
		if (t[i] < t[begin])
		{
			if (i != sep)
				swap(t, i, sep);
			sep++;
		}
		i++;
	}
	if (sep != begin + 1)
		swap(t, begin, sep - 1);
	return (sep - 1);
}

/*Sort an int array using the Quicksort Algorithm*/
int	quicksort(int *t, int begin, int end)
{
	int	milieu;

	if (begin < end)
	{
		milieu = quicksort_separation (t, begin, end);
		quicksort(t, begin, milieu);
		quicksort(t, milieu + 1, end);
	}
	return (0);
}

// #include <stdio.h>

// void print_tab(int *tab, int len)
// {
// 	for (int i = 0; i < len; i++)
// 		printf("%d ", tab[i]);
// 	printf("\n");
// }

// int main(){
// 	int tab[5] = {4,2,5,3,7};
// 	print_tab(tab, 5);
// 	quicksort(tab, 0, 4);
// 	print_tab(tab, 5);
// }