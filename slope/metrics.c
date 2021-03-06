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

#include "slope/metrics_p.h"
#include "slope/data_p.h"
#include "slope/list.h"
#include <cairo.h>
#include <stdlib.h>


void slope_metrics_destroy (slope_metrics_t *metrics)
{
    if (metrics == NULL) {
        return;
    }
    if (metrics->klass->destroy_fn) {
        (*metrics->klass->destroy_fn)(metrics);
    }
    slope_list_destroy(metrics->data_list);
    free(metrics);
}


int slope_metrics_get_visible(slope_metrics_t *metrics)
{
    if (metrics == NULL) {
        return SLOPE_FALSE;
    }
    return metrics->visible;
}


void slope_metrics_set_visible (slope_metrics_t *metrics,
                                int visible)
{
    if (metrics == NULL) {
        return;
    }
    metrics->visible = visible;
}


void slope_metrics_update (slope_metrics_t *metrics)
{
    if (metrics == NULL) {
        return;
    }
    if (metrics->klass->update_fn) {
        (*metrics->klass->update_fn)(metrics);
    }
}


void __slope_metrics_draw (slope_metrics_t *metrics, cairo_t *cr,
                           const slope_rect_t *rect)
{
    (*metrics->klass->draw_fn)(metrics, cr, rect);
}


void slope_metrics_add_data (slope_metrics_t *metrics,
                             slope_data_t *data)
{
    if (metrics == NULL || data == NULL) {
        return;
    }
    data->metrics = metrics;
    metrics->data_list = slope_list_append(
        metrics->data_list, data);
    slope_metrics_update(metrics);
}


slope_list_t* slope_metrics_get_data_list (slope_metrics_t *metrics)
{
    if (metrics == NULL) {
        return NULL;
    }
    return metrics->data_list;
}


slope_scene_t* slope_metrics_get_scene (slope_metrics_t *metrics)
{
    if (metrics == NULL) {
        return NULL;
    }
    return metrics->scene;
}

/* slope/metrics.h */
