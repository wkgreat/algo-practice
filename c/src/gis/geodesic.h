//
// Created by wkgreat on 2020/1/14.
// from source code of postGIS lwgeodetic.h
//

#ifndef ALGO_PRACTICE_GEODESIC_H
#define ALGO_PRACTICE_GEODESIC_H

/**
* Point in spherical coordinates on the world. Units of radians.
*/
typedef struct
{
    double lon;
    double lat;
} GEOGRAPHIC_POINT;

/**
* Two-point great circle segment from a to b.
*/
typedef struct
{
    GEOGRAPHIC_POINT start;
    GEOGRAPHIC_POINT end;
} GEOGRAPHIC_EDGE;

/**
 * distance from edge to point
 * */
double edge_distance_to_point(const GEOGRAPHIC_EDGE *e, const GEOGRAPHIC_POINT *gp, GEOGRAPHIC_POINT *closest)
{
    double d1 = 1000000000.0, d2, d3, d_nearest;
    POINT3D n, p, k;
    GEOGRAPHIC_POINT gk, g_nearest;

    /* Zero length edge, */
    if ( geographic_point_equals(&(e->start), &(e->end)) )
    {
        *closest = e->start;
        return sphere_distance(&(e->start), gp);
    }

    /* wk: Cross Product e->start ** e->end => n */
    robust_cross_product(&(e->start), &(e->end), &n);
    normalize(&n); /*wk: n vector to unit vector*/
    geog2cart(gp, &p); /*wk: to cartesian on unit sphere*/
    vector_scale(&n, dot_product(&p, &n));
    vector_difference(&p, &n, &k);
    normalize(&k);
    cart2geog(&k, &gk);
    if ( edge_contains_point(e, &gk) )
    {
        d1 = sphere_distance(gp, &gk);
    }
    d2 = sphere_distance(gp, &(e->start));
    d3 = sphere_distance(gp, &(e->end));

    d_nearest = d1;
    g_nearest = gk;

    if ( d2 < d_nearest )
    {
        d_nearest = d2;
        g_nearest = e->start;
    }
    if ( d3 < d_nearest )
    {
        d_nearest = d3;
        g_nearest = e->end;
    }
    if (closest)
        *closest = g_nearest;

    return d_nearest;
}

int geographic_point_equals(const GEOGRAPHIC_POINT *g1, const GEOGRAPHIC_POINT *g2)
{
    return FP_EQUALS(g1->lat, g2->lat) && FP_EQUALS(g1->lon, g2->lon);
}

/**
* Normalize to a unit vector.
*/
void normalize(POINT3D *p)
{
    double d = sqrt(p->x*p->x + p->y*p->y + p->z*p->z);
    if (FP_IS_ZERO(d))
    {
        p->x = p->y = p->z = 0.0;
        return;
    }
    p->x = p->x / d;
    p->y = p->y / d;
    p->z = p->z / d;
    return;
}

/**
* Convert spherical coordinates to cartesian coordinates on unit sphere
*/
void geog2cart(const GEOGRAPHIC_POINT *g, POINT3D *p)
{
    p->x = cos(g->lat) * cos(g->lon);
    p->y = cos(g->lat) * sin(g->lon);
    p->z = sin(g->lat);
}

/**
* Convert cartesian coordinates on unit sphere to spherical coordinates
*/
void cart2geog(const POINT3D *p, GEOGRAPHIC_POINT *g)
{
    g->lon = atan2(p->y, p->x);
    g->lat = asin(p->z);
}

/**
* Scale a vector out by a factor
*/
static void vector_scale(POINT3D *n, double scale)
{
    n->x *= scale;
    n->y *= scale;
    n->z *= scale;
    return;
}

static void vector_difference(const POINT3D *a, const POINT3D *b, POINT3D *n)
{
    n->x = a->x - b->x;
    n->y = a->y - b->y;
    n->z = a->z - b->z;
    return;
}

/**
* Computes the cross product of two vectors using their lat, lng representations.
* Good even for small distances between p and q.
*/
void robust_cross_product(const GEOGRAPHIC_POINT *p, const GEOGRAPHIC_POINT *q, POINT3D *a)
{
    double lon_qpp = (q->lon + p->lon) / -2.0;
    double lon_qmp = (q->lon - p->lon) / 2.0;
    double sin_p_lat_minus_q_lat = sin(p->lat-q->lat);
    double sin_p_lat_plus_q_lat = sin(p->lat+q->lat);
    double sin_lon_qpp = sin(lon_qpp);
    double sin_lon_qmp = sin(lon_qmp);
    double cos_lon_qpp = cos(lon_qpp);
    double cos_lon_qmp = cos(lon_qmp);
    a->x = sin_p_lat_minus_q_lat * sin_lon_qpp * cos_lon_qmp -
           sin_p_lat_plus_q_lat * cos_lon_qpp * sin_lon_qmp;
    a->y = sin_p_lat_minus_q_lat * cos_lon_qpp * cos_lon_qmp +
           sin_p_lat_plus_q_lat * sin_lon_qpp * sin_lon_qmp;
    a->z = cos(p->lat) * cos(q->lat) * sin(q->lon-p->lon);
}


#endif //ALGO_PRACTICE_GEODESIC_H
