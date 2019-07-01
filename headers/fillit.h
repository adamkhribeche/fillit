/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <fokrober@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:20:03 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/30 23:07:35 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "valid_file.h"
# include <stdio.h>

void	print_board(char *board, int size);
void	printab(int *tab, int n);
size_t	ft_strlenx(const char *s);
int		save_tetris(int *tab, int **all_tetris);
void	del_all(int **all);
char	*create_board(size_t size);
void	put_tetris(int *tab, char *board, char c);
int		available(int *tab, char *board);
void	remove_tetris(int *tab, char *board);
void	set_shift(int *tab, int val[][4], int size);
void	shift_tetris_top(int *tab, int size);
void	shift_tetris_right(int *tab, int j, int val);
void	shift_tetris_down(int *tab, int size, int n);
void	shift_all_tetris_to(int **all_tetris, int size);
int		place_on_board(int *tab, char *board, int size, int p);
int		fillit(int **all_tetris, char *board, int size, int p);
void	fill(int **all_tetris, int size, int nbtetris);
int		sort(int *tab, int n);
int		better_size(int start_size, int nbtetris);
#endif
