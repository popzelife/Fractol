/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:01:47 by qfremeau          #+#    #+#             */
/*   Updated: 2016/11/09 19:44:56 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void print_help()
{
	ft_printf("Fractol list:\n\t1 - Mandelbrot\n\t2 - Julia\n\t3 - Glynn\n");
	//ft_printf("\t-4 Burning Ship\t\n4 - Pythagor Tree\n\t5 - Buddhabrot\n");
	ft_printf("\nUsage: fractol [-gIlh] [Fractol number]\n");
	ft_printf("\t-g : colored representation\n");
	ft_printf("\t-I : 3D representation\n");
	ft_printf("\t-l : display fractol list\n");
	ft_printf("\t-h : show this help\n");
}

static void	mlx_free(t_mlx *fdf)
{
	t_img		*img_curs;
	t_img		*img_temp;
	if (fdf->mlx_ptr && fdf->win_ptr)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	img_curs = fdf->img;
	while (img_curs != NULL)
	{
		mlx_destroy_image(fdf->mlx_ptr, img_curs->img_ptr);
		img_temp = img_curs->next;
		free(img_curs);
		img_curs = img_temp;
	}
}

void		mlx_exit(int ret, t_mlx *fdf, char *error)
{
	if (ret == HELP)
	{
		if (error[0] != 0)
			ft_dprintf(2, "Fractol error - %s\n\n", error);
		print_help();
	}
	else if (ret == -1)
		ft_dprintf(2, "Fractol error - %s\n", error);
	else if (ret == 1)
	{
		mlx_free(fdf);
	}
	exit(ret);
}
