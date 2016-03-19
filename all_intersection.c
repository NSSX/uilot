#include "my_h.h"

void cone_inter(t_main *main)
{
  double a;
  double b;
  double c;
  double det;
  double myv;

  a = mypow(main->cone->x, 2) + mypow(main->cone->y, 2) - (mypow(main->cone->z, 2) * 0.1);
  b = (2 * main->cone->x * main->eye->xeye) + (2 * main->cone->y * main->eye->yeye) - ((2 * main->cone->z * main->eye->zeye) * 0.1);
  c = (mypow(main->eye->xeye, 2) + mypow(main->eye->yeye, 2) - (mypow(main->eye->zeye, 2) * 0.1));
  det = (b * b) - (4 * a * c);
  main->cone->v = (-b - sqrt(det)) / (2 * a);
  myv = (-b + sqrt(det)) / (2 * a);
  if(det < 0)
    main->cone->v = -1;
  else if (main->cone->v > myv && myv > 0)
    main->cone->v = myv;
}

void cyl_inter(t_main *main)
{
  double a;
  double b;
  double c;
  double det;
  double myv;

  a = mypow(main->cyl->x, 2) + mypow(main->cyl->y, 2);
  b = (2 * main->cyl->x * main->eye->xeye + 2 * main->cyl->y * main->eye->yeye);
  c = (mypow(main->eye->xeye, 2) + mypow(main->eye->yeye, 2) - mypow(main->cyl->rayon, 2));
  det = (b * b) - (4 * a * c);
  main->cyl->v = (-b - sqrt(det)) / (2 * a);
  myv = (-b + sqrt(det)) / (2 * a);
  if(det < 0)
    main->cyl->v = -1;
  else if (main->cyl->v > myv && myv > 0)
    main->cyl->v = myv;
}

int plan_inter(t_main *main)
{
  main->plan->v = (-main->eye->zeye) / main->eye->vz;
  if(main->eye->vz == 0)
    return (0);
  main->lum->nx = 0;
  main->lum->ny = 0;
  main->lum->nz = 100;
  if(main->plan->v > 0)
    return (2);
  else
    return (1);
}

void sphere_inter(t_main *main)
{
  double a;
  double b;
  double c;
  double det;
  double myv;

  a = (main->sphere->x * main->sphere->x + main->sphere->y * main->sphere->y + main->sphere->z * main->sphere->z);
  b = (2 * main->sphere->x * main->eye->xeye + 2 * main->sphere->y * main->eye->yeye + 2 * main->sphere->z * main->eye->zeye);
  c = (main->eye->xeye * main->eye->xeye + main->eye->yeye * main->eye->yeye + main->eye->zeye * main->eye->zeye - main->sphere->rayon * main->sphere->rayon);
  det = (b * b) - (4 * a * c);
  main->sphere->v = (-b - sqrt(det)) / (2 * a);
  myv = (-b + sqrt(det)) / (2 * a);
  if(det < 0)
    main->sphere->v = -1;
  else if (main->sphere->v > myv && myv > 0)
    main->sphere->v = myv;
}
