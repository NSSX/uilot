#ifndef MY_H
#define MY_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define WIDTH 800
# define HEIGHT 600

typedef struct                                                                  s_img
{
  double cos;
  void                            *mlx;
  void                            *win;
  unsigned long           img_color;
  char                            *data;
  void                            *img_ptr;
  int                                     sizeline;
  int                                     bpp;
  int                                     x;
  int                                     y;
  int                                     endian;
  void                            *mlx_ptr;
}                                                                                               t_img;

typedef struct  s_pos
{
  float         k_plan;
  float         k_sph;
  float         k_cyl;
  float         k_cone;
  float         xp;
  float         yp;
  float         zp;
}               t_pos;



typedef struct  s_coord
{
  float         vx;
  float         vy;
  float         vz;
  float         rayon;
  float         xeye;
  float         yeye;
  float         zeye;
  float         angle;
}               t_coord;

typedef struct  s_lum
{
  float         x;
  float         y;
  float         z;
  float         vx;
  float         vy;
  float         vz;
  float         nx;
  float         ny;
  float         nz;
}               t_lum;

typedef struct  s_struct_point
{
  t_coord       *coord;
  t_coord       *sph;
  t_coord       *cyl;
  t_coord       *cone;
  t_pos         *pos;
  t_lum         *lum;
  t_img 	*img;
  int count;
}               t_point;



typedef struct s_vec3d
{
  double x;
  double y;
  double z;
  double v;
  double rayon;
  double         xp;
  double         yp;
  double        zp;
}		t_vec3d;


typedef struct s_sphere
{
  t_vec3d *pos;
  double xt;
  double yt;
  double zt;
  double radius;
}		t_sphere;


typedef struct s_ray
{
  t_vec3d *o;
  t_vec3d *d;
  double vx;
  double vy;
  double vz;
  double xeye;
  double yeye;
  double zeye;
}		t_ray;


typedef struct s_light
{
  double x;
  double y;
  double z;
  double dx;
  double dy;
  double dz;
  double ox;
  double oy;
  double oz;
}		t_light;

typedef struct                                                                  s_struct
{
  int                                     fracnum;
  void                            *mlx;
  void                            *win;
  t_img                           *img;
  int color;
  double decx;
  double decy;
  double decz;
  t_sphere *spheres;
  t_sphere *cones;
  t_sphere *cyls;
  t_vec3d *plan;
  double xp;
  double yp;
  double zp;
  t_ray *rays;
  t_light *lights;
  t_point *point;
  int count;
}                                                                                               t_struct;

typedef struct s_main
{
  void                            *mlx;
  void                            *win;
  t_img                           *img;
  t_vec3d 	*sphere;
  t_vec3d 	*cyl;
  t_vec3d 	*cone;
  t_vec3d *plan;
  t_coord       *eye;
  t_lum         *lum;
  int color;
}	t_main;

void define_main(int x, int y, t_main *main);
void    my_give_v(double *v_value, t_main *main);
void            give_shadow_sphere(t_main *main, double v);
void            give_shadow_cyl(t_main *main, double v);
void            give_shadow_cone(t_main *main, double v);
void cone_inter(t_main *main);
void cyl_inter(t_main *main);
int plan_inter(t_main *main);
void sphere_inter(t_main *main);
int my_light_plan(t_main *main);
int             my_light_cylinder(t_main *main);
int             my_light_conee(t_main *main);
int             my_light_sphere(t_main *main);
int             my_shadow_cylinder(t_main *main, double v);
int             my_shadow_conee(t_main *main, double v);
int             my_shadow_sphere(t_main *main, double v);
double mypow(int a, int n);
int                     event_mlx(int keycode, t_main *main);
int definee_color(int x, int y, t_main *main);
int             my_pixel_put_to_image2(t_img *img, int x, int y, int color);
void parcour_all(t_main *main);

#endif
