/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_give.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:48:12 by avella            #+#    #+#             */
/*   Updated: 2016/03/17 15:48:33 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

void define_main(int x, int y, t_main *main)
{
  main->lum->nx = 0;
  main->lum->ny = 0;
  main->lum->nz = 100;
  main->lum->x = -3000;
  main->lum->y = 0;
  main->lum->z = 2000;
  main->eye->vx = 0;
  main->eye->vy = (WIDTH / 2) - x;
  main->eye->vz = (HEIGHT / 2) - y;
  main->eye->xeye = -3000;
  main->eye->yeye = 300;
  main->eye->zeye = 500;
  main->sphere->x = main->eye->vx + 1000- 400;
  main->sphere->y = main->eye->vy + 0;
  main->sphere->z = main->eye->vz + -300;
  main->sphere->rayon = 800;
  main->cyl->x = main->eye->vx + 1000;
  main->cyl->y = main->eye->vy + 0 - 100;
  main->cyl->z = main->eye->vz + -300;
  main->cyl->rayon = 150;
  main->cone->x = main->eye->vx + 1000;
  main->cone->y = main->eye->vy + 100;
  main->cone->z = main->eye->vz + -300;
}

void    my_give_v(double *v_value, t_main *main)
{
  v_value[0] = main->plan->v;
  v_value[1] = main->cone->v;
  v_value[2] = main->cyl->v;
  v_value[3] = main->sphere->v;
}

void            give_shadow_sphere(t_main *main, double v)
{
  main->sphere->xp = main->eye->xeye + (main->sphere->x * v);
  main->sphere->yp = main->eye->yeye + (main->sphere->y * v);
  main->sphere->zp = main->eye->zeye + (main->sphere->z * v);
  main->lum->vx = main->lum->x - main->sphere->xp;
  main->lum->vy = main->lum->y - main->sphere->yp;
  main->lum->vz = main->lum->z - main->sphere->zp;
}

void            give_shadow_cyl(t_main *main, double v)
{
  main->cyl->xp = main->eye->xeye + (main->cyl->x * v);
  main->cyl->yp = main->eye->yeye + (main->cyl->y * v);
  main->lum->vx = main->lum->x - main->cyl->xp;
  main->lum->vy = main->lum->y - main->cyl->yp;
}

void            give_shadow_cone(t_main *main, double v)
{
  main->cone->xp = main->eye->xeye + (main->cone->x * v);
  main->cone->yp = main->eye->yeye + (main->cone->y * v);
  main->cone->zp = main->eye->zeye + (main->cone->z * v);
  main->lum->vx = main->lum->x - main->cone->xp;
  main->lum->vy = main->lum->y - main->cone->yp;
  main->lum->vz = main->lum->z - main->cone->zp;
}
