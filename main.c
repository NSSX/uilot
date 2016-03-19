#include "my_h.h"

int color_choice(t_main *main)
{
  double v;
  double v_value[4];
  int i;
  double temp;


  v = 0;
  i = -1;
  my_give_v(v_value, main);
  while(i < 2)
    {
      i++;
      if(v_value[i] > v_value[i + 1])
        {
          temp = v_value[i];
          v_value[i] = v_value[i + 1];
          v_value[i + 1] = temp;
          i = -1;
        }
    }
  i = 0;
  while(i < 4 && v_value[i] <= 0)
    {
      i++;
      if(i == 4)
        break;
    }
  if(v > 3)
    v = v_value[3];
  else
    v = v_value[i];
  my_give_v(v_value, main);
  if(v == v_value[0])
    return (my_light_plan(main));
   else if(v == v_value[1])
    return(my_light_conee(main));
  else if(v == v_value[2])
    return(my_light_cylinder(main));
  else if(v == v_value[3])
    return(my_light_sphere(main));
  return (0x000000);
}



int definee_color(int x, int y, t_main *main)
{
   int color;
   
   main->sphere = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
  main->cyl = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
  main->cone = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
  main->lum = (t_lum *)malloc(sizeof(t_lum) * 1);
  main->eye = (t_coord *)malloc(sizeof(t_coord) * 1);
  main->plan = (t_vec3d *)malloc(sizeof(t_vec3d) * 1);
  define_main(x, y, main);
  plan_inter(main);
  sphere_inter(main);
  cone_inter(main);
  cyl_inter(main);
  color = color_choice(main);//start the lets choice func;
  return (color);
}

int                     main(int argc, char **argv)
{
  t_main *main;

  main = (t_main *)malloc(sizeof(t_main));
  main->img = (t_img *)malloc(sizeof(t_img) * 1);
  main->mlx = mlx_init();
  main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "RayTracer V1");
  main->img->img_ptr = mlx_new_image(main->mlx, WIDTH, HEIGHT);
  parcour_all(main);
  mlx_put_image_to_window(main->mlx, main->win, main->img->img_ptr, 0, 0);
  mlx_key_hook(main->win, event_mlx, main);
  mlx_loop(main->mlx);
  return (0);
}
