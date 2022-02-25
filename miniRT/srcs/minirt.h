/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:23:15 by marvin            #+#    #+#             */
/*   Updated: 2022/02/25 16:01:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <X11/Xlib.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include "../lib/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define PI 3.14159265359
# define HEADER_SIZE 54
# define INF DBL_MAX
# define MIN 0.0000000001
# define KEYCODE_RIGHT 65363
# define KEYCODE_ESCAPE 65307

typedef	struct	s_objects
{
	int					type;
	int					num;
	double				pos[3];
	double				vert[3][3];
	double				rgb[3];
	double				vec[3];
	double				fov;
	double				ratio;
	double				size;
	double				r;
	struct s_objects	*next;
}				t_objects;

typedef struct	s_ray
{
	double		s[3];
	double		d[3];
	double		rgb[3];
	double		min_distance;
	t_objects	colli_obj;
	int			obj_num;
	int			inout_flag;
}				t_ray;

typedef struct	s_all
{
	double		rx;
	double		ry;
	t_ray		ray;
	t_objects	ambi_light;
	t_objects	camera_save;
	t_objects	camera;
	t_objects	light;
	t_objects	object[5];
	int			err_flag;
	int			obj_num;
	int			image_yx[2];
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
	int			r_flag;
	int			a_flag;
}				t_all;

void			destroy_liner_obj(t_objects *obj);
int				make_obj3_2(char **s, t_all *all, int *flag, t_objects **tail);
int				ft_exit0(int k, t_all *all);
void			make_screen_yx_vec(t_all *all, double *y, double *x);
void			make_n_vec(t_ray ray, t_ray new_ray, double *n);
double			screen_val_set(t_all *all, double *screen_yx_pos,
	double screen_yx_vec[2][3], double *t);
void			make_ray(t_all *all, double *screen_yx_pos,
	double screen_yx_vec[2][3], double t);
void			make_ray_to_light(t_all *all);
void			make_ambi_light(t_all *all);
void			make_screen(t_all *all);
void			ray_to_light(t_all *all, t_ray new_ray, t_objects light);
void			collision_triangle(t_objects obj, t_ray *ray_save);
void			collision_cylinder(t_objects obj, t_ray *ray_save);
void			collision_square(t_objects obj, t_ray *ray_save);
void			collision_plane(t_objects obj, t_ray *ray_save);
void			collision_sphere(t_objects obj, t_ray *ray_save);
int				collision_detect_main(t_all all, t_ray *ray);
void			copy_vec(double *dest, double *src);
void			reverse_vec(double *vec);
void			normalize_vec(double *vec);
void			vec_diff(double *dest, double *from1, double *from2);
void			cross_product(double ret[3], double a[3], double b[3]);
double			inner_product(double a[3], double b[3]);
double			dist_sq(double a[3], double *b);
double			ft_cos_sq(double *a, double *b);
double			ft_cosr_sq(double *n, t_ray ray, t_ray new_ray);
void			make_yx_vec(double *vec, double *y, double *x);
int				check_alpha(char *s);
double			ft_atoi(char **s, int *flag);
void			obj_input_3(double *i, char **s, int *flag);
void			ft_strlncat(char *dest, char *src, int n, int srcn);
char			*read_file(int fd);
int				make_obj(char *s, t_all *all);
int				make_obj1(char **s, t_all *all, int *flag, t_objects **tail);
int				make_obj4(char **s, t_all *all, int *flag, t_objects **tail);
void			make_triangle_vec(t_objects *obj);
void			make_square_vert(t_objects *obj);
void			ft_write(char *s);
void			ft_bzero(void	*s, int n);
int				ft_strcmp(char *s1, char *s2);
int				check_file_name(char *s);
int				handle_key(int k, t_all *all);
int				rgb_to_int(double *rgb);
void			err_exit3(int n);
void			make_images(t_all *all);
void			bpm_main(t_all all);
void			err_exit(int n, t_all all);
void			ft_exit(t_all all);
int				check_file(t_all *all);
int				check_obj0(t_all *all);
int				check_obj5(t_all *all);
int				zero(double x);

#endif
