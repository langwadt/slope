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

#ifndef __SLOPE_XYMETRICS_P_H
#define __SLOPE_XYMETRICS_P_H

#include "slope/xymetrics.h"
#include "slope/metrics_p.h"

__SLOPE_BEGIN_DECLS

/**
 */
typedef struct _slope_xymetrics slope_xymetrics_t;

/**
 */
struct _slope_xymetrics
{
    slope_metrics_t parent;
    /* axis list */
    slope_list_t *axis_list;
    /* boundary between data image and scene frontier */
    double x_low_bound, x_up_bound;
    double y_low_bound, y_up_bound;
    /* data space geometry attributes */
    double xmin, xmax;
    double ymin, ymax;
    double width, height;
    /* scene geometry attributes */
    double xmin_scene, xmax_scene;
    double ymin_scene, ymax_scene;
    double width_scene, height_scene;
};

/**
 */
slope_metrics_class_t* __slope_xymetrics_get_class();

/**
 */
void __slope_xymetrics_destroy (slope_metrics_t *metrics);

/**
 */
void __slope_xymetrics_draw (slope_metrics_t *metrics, cairo_t *cr,
                             const slope_rect_t *rect);

/**
 */
void __slope_xymetrics_update (slope_metrics_t *metrics);

__SLOPE_END_DECLS

#endif /*__SLOPE_XYMETRICS_P_H */
