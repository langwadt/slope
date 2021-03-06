/*
 * Copyright (C) 2015  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "slope/legend_p.h"
#include "slope/scene_p.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


slope_data_class_t* __slope_legend_get_class()
{
    static int first_call = SLOPE_TRUE;
    static slope_data_class_t klass;

    if (first_call) {
        klass.destroy_fn = NULL;
        klass.draw_fn = __slope_legend_draw;
        first_call = SLOPE_FALSE;
    }

    return &klass;
}


slope_data_t* slope_legend_create (slope_scene_t *scene)
{
    slope_legend_t *legend = malloc(sizeof(slope_legend_t));
    slope_data_t *parent = (slope_data_t*) legend;
    
    legend->scene = scene;
    parent->klass = __slope_legend_get_class();
    
    return parent;
}


void __slope_legend_draw (slope_data_t *legend, cairo_t *cr,
                          const slope_metrics_t *metrics)
{

}

/* slope/legend.c */

