#include "my_h.h"

int my_light_plan(t_main *main)
{
  double v1;
  double n1;
  double n2;
  double tempx;
  double tempy;
  double tempz;

  tempx = main->eye->xeye + main->eye->vx * main->plan->v;
  tempy = main->eye->yeye + main->eye->vy * main->plan->v;
  tempz = main->eye->zeye + main->eye->vz * main->plan->v;
  main->lum->vx = main->lum->x - tempx;
  main->lum->vy = main->lum->y - tempy;
  main->lum->vz = main->lum->z - tempz;
  v1 = (main->lum->nx * main->lum->vx + main->lum->ny * main->lum->vy + main->lum->nz * main->\
        lum->vz);
  n1 = (pow(main->lum->nx,2) + pow(main->lum->ny,2) + pow(main->lum->nz, 2));
  n2 = (pow(main->lum->vx,2) + pow(main->lum->vy,2) + pow(main->lum->vz, 2));
  main->img->cos = v1 / (sqrt(n1) * sqrt(n2));
  if (my_shadow_sphere(main, main->plan->v) == 2 ||
      my_shadow_cylinder(main, main->plan->v) == 2 ||
      my_shadow_conee(main, main->plan->v) == 2 )
    return (0x000000);
  return (0x00FFFF);
}

int             my_light_cylinder(t_main *main)
{
  double v1;
  double n1;
  double n2;
  double tempx;
  double tempy;
  double tempz;

  tempx = main->eye->xeye + (main->cyl->x * main->cyl->v);
  tempy = main->eye->yeye + (main->cyl->y * main->cyl->v);
  tempz = main->eye->zeye + (main->cyl->z * main->cyl->v);
  main->lum->nx = tempx;
  main->lum->ny = tempy;
  main->lum->nz = 0;
  main->lum->vx = main->lum->x - tempx;
  main->lum->vy = main->lum->y - tempy;
  main->lum->vz = main->lum->z - tempz;
  v1 = (main->lum->nx * main->lum->vx + main->lum->ny
        * main->lum->vy + main->lum->nz * main->lum->vz);
  n1 = (pow(main->lum->nx, 2) + pow(main->lum->ny, 2)
	+ pow(main->lum->nz, 2));
  n2 = (pow(main->lum->vx, 2) + pow(main->lum->vy, 2)
	+ pow(main->lum->vz, 2));
  main->img->cos = v1 / (sqrt(n1) * sqrt(n2));
  if (my_shadow_sphere(main, main->cyl->v) == 2 ||
      my_shadow_conee(main, main->cyl->v) == 2)
    return (0x000000);
  return (0xFFFF00);
}

int             my_light_conee(t_main *main)
{
  float         v1;
  float         n1;
  float         n2;
  double tempx;
  double tempy;
  double tempz;

  tempx = main->eye->xeye + (main->cone->x * main->cone->v);
  tempy = main->eye->yeye + (main->cone->y * main->cone->v);
  tempz = main->eye->zeye + (main->cone->z * main->cone->v);
  main->lum->nx = tempx;
  main->lum->ny = tempy;
  main->lum->nz = 0.05 * tempz;
  main->lum->vx = main->lum->x - tempx;
  main->lum->vy = main->lum->y - tempy;
  main->lum->vz = main->lum->z - tempz;
  v1 = (main->lum->nx * main->lum->vx + main->lum->ny
        * main->lum->vy + main->lum->nz * main->lum->vz);
  n1 = (pow(main->lum->nx, 2) + pow(main->lum->ny, 2)
	+ pow(main->lum->nz, 2));
  n2 = (pow(main->lum->vx, 2) + pow(main->lum->vy, 2)
	+ pow(main->lum->vz, 2));
  main->img->cos = v1 / (sqrt(n1) * sqrt(n2));
  if (my_shadow_sphere(main, main->cone->v) == 2 ||
      my_shadow_cylinder(main, main->cone->v) == 2)
    return (0x000000);
  return (0x0000FF);
}

int             my_light_sphere(t_main *main)
{
  float         v1;
  float         n1;
  float         n2;
  double tempx;
  double tempy;
  double tempz;

  tempx = main->eye->xeye + (main->sphere->x * main->sphere->v);
  tempy = main->eye->yeye + (main->sphere->y * main->sphere->v);
  tempz = main->eye->zeye + (main->sphere->z * main->sphere->v);
  main->lum->nx = tempx;
  main->lum->ny = tempy;
  main->lum->nz = tempz;
  main->lum->vx = main->lum->x - tempx;
  main->lum->vy = main->lum->y - tempy;
  main->lum->vz = main->lum->z - tempz;
  v1 = (main->lum->nx * main->lum->vx + main->lum->ny
        * main->lum->vy + main->lum->nz * main->lum->vz);
  n1 = (pow(main->lum->nx, 2) + pow(main->lum->ny, 2)
	+ pow(main->lum->nz, 2));
  n2 = (pow(main->lum->vx, 2) + pow(main->lum->vy, 2)
	+ pow(main->lum->vz, 2));
  main->img->cos = v1 / (sqrt(n1) * sqrt(n2));
  if (my_shadow_cylinder(main, main->sphere->v) == 2 ||
      my_shadow_conee(main, main->sphere->v) == 2)
    return (0x000000);
  return (0xFF0000);
}
