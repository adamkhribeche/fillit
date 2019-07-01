/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:47:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/06/26 12:23:14 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_FILE_H
# define VALID_FILE_H
# include "error.h"
# define BUF_SIZE 546

int		isfull(int *tab, int n);
int		valid_tetrimino(int *tab);
int		valid_line(char *line, int *tab, int *nblines);
int		valid_file(int fd, int **all_tetris);
#endif
