#include<stdlib.h>
#include"fbio.h"
#include"colours.h"
#include"shapes.h"

#define min( A, B ) ( (A) < (B) ? (A) : (B) )
#define max( A, B ) ( (A) > (B) ? (A) : (B) )
#define min3( A, B, C ) ( min( A, min( B, C ) ) )
#define max3( A, B, C ) ( max( A, max( B, C ) ) )


void fbgl_fillrect(struct framebuffer *fb, unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey, unsigned int RGBA ) {
    int x, y;
    for ( x = min(sx, ex); x < max(sx, ex); x++ )
        for ( y = min(sy, ey); y < max(sy, ey); y++ )
            fbgl_pxlset( fb, x, y, RGBA );
}

void fbgl_drawtri( struct framebuffer *fb,  Point2D *v0,  Point2D *v1,  Point2D *v2, unsigned int *colours ) {
    // AABB
    int minX = min3(v0->x, v1->x, v2->x);
    int minY = min3(v0->y, v1->y, v2->y);
    int maxX = max3(v0->x, v1->x, v2->x);
    int maxY = max3(v0->y, v1->y, v2->y);

    // Iterate over all points in AABB
    Point2D p;
    for (p.y = minY; p.y <= maxY; p.y++)
        for (p.x = minX; p.x <= maxX; p.x++) {
            // Calculate barycentric coordinates.
            int w0 = orient2d(v1, v2, &p);
            int w1 = orient2d(v2, v0, &p);
            int w2 = orient2d(v0, v1, &p);

            // If all barys are positive then draw triangle.
            if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                int wT = w0 + w1 + w2;
                float fw0 = (float)w0 / (float)wT;
                float fw1 = (float)w1 / (float)wT;
                float fw2 = (float)w2 / (float)wT;
                int R = (float)fbgl_getR(colours[0]) * fw0
                    +   (float)fbgl_getR(colours[1]) * fw1
                    +   (float)fbgl_getR(colours[2]) * fw2;
                int G = (float)fbgl_getG(colours[0]) * fw0
                    +   (float)fbgl_getG(colours[1]) * fw1
                    +   (float)fbgl_getG(colours[2]) * fw2;
                int B = (float)fbgl_getB(colours[0]) * fw0
                    +   (float)fbgl_getB(colours[1]) * fw1
                    +   (float)fbgl_getB(colours[2]) * fw2;
                int A = (float)fbgl_getA(colours[0]) * fw0
                    +   (float)fbgl_getA(colours[1]) * fw1
                    +   (float)fbgl_getA(colours[2]) * fw2;

                fbgl_pxlset( fb, p.x, p.y, fbgl_colour( R, G, B, A ) );
            }
        }
}

int orient2d( const Point2D *a, const Point2D *b, const Point2D *c ) {
    return ( b->x - a->x ) * ( c->y - a->y ) - ( b->y - a->y ) * ( c->x - a->x );
}

