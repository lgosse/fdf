/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:03:02 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/15 15:49:11 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>

# define WIN_HEIGHT		1315
# define WIN_WIDTH		2560
# define HUD			0x01

# ifndef FT_KEYCODES
#  define FT_KEYCODES
#  define FT_ESC		53
#  define FT_PLUS		69
#  define FT_MINUS		78
#  define FT_WILDCARD	67
#  define FT_DIVIDE		75
#  define FT_LEFT		123
#  define FT_RIGHT		124
#  define FT_DOWN		125
#  define FT_UP			126
#  define FT_H			4
# endif

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_seg
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_seg;

typedef	struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sline;
	int				endian;
}					t_img;

typedef struct		s_win
{
	void			*win;
	int				width;
	int				height;
}					t_win;

typedef struct		s_fdf
{
	void			*mlx;
	t_win			*win;
	t_win			*hud;
	t_img			*img;
	t_parse			*parse;
	t_list			*map;
	int				tile_width;
	int				tile_height;
	int				alt_quota;
	int				begin_x;
	int				begin_y;
	int				color;
	t_pos			*size;
	t_pos			*extremes;
}					t_fdf;

/*
** init
*/

t_list				*ft_getmap(char *filename);
void				ft_testprint(t_list *map);
int					ft_map_to_coords(t_fdf *fdf);
t_win				*ft_init_win(t_fdf *fdf, int width, int height);
void				ft_reinit_fdf(t_fdf *fdf);
t_img				*ft_init_img(t_fdf *fdf);
t_fdf				*ft_init_fdf(int ac, char **av);
void				ft_init_hud(t_fdf *fdf, int width, int height);
void				ft_delinfos(char **infos);
void				ft_destroy_hud(t_fdf *fdf);
t_pos				*ft_init_extremes(t_list *map);
t_pos				*ft_init_size(t_list *map);

/*
** draw
*/

void				ft_pixel_put_to_image(t_img *img, int x, int y, int color);
void				ft_draw(t_fdf *fdf);
void				ft_draw_line(t_fdf *fdf,
									t_seg *seg, int alt_begin, int alt_end);
void				ft_color_square(t_fdf *fdf, int x1, int y1, int color);
void				ft_draw_infos(t_fdf *fdf);
void				ft_draw_text(t_fdf *fdf);
void				ft_draw_colors(t_fdf *fdf);
void				ft_draw_buttons(t_fdf *fdf);
void				ft_draw_hud(t_fdf *fdf);
void				ft_clear_text(t_fdf *fdf);

/*
** hooks
*/

int					ft_handle_hud_win(int button, int x, int y, t_fdf *fdf);
int					ft_handle_graph_win(int button, int x, int y, t_fdf *fdf);
int					ft_handle_keys(int keycode, t_fdf *fdf);
void				ft_exit_fdf(t_fdf *fdf);

/*
** modify_fdf
*/

void				ft_modify_color(t_fdf *fdf, int color);
void				ft_modify_alt_quota(t_fdf *fdf, int value);
void				ft_modify_tiles_length(t_fdf *fdf, int value);
void				ft_move_horizontal(t_fdf *fdf, int value);
void				ft_move_vertical(t_fdf *fdf, int value);

#endif
