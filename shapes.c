#include<stdlib.h>
#include"fbio.h"

#define min(A, B) ((A) < (B) ? (A) : (B))
#define max(A, B) ((A) > (B) ? (A) : (B))

typedef struct vec2 {
    int x, y;
} Vec2;

void fbgl_fillrect(struct framebuffer *fb, unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey, unsigned int RGBA ) {
    int x, y;
    for ( x = min(sx, ex); x < max(sx, ex); x++ )
        for ( y = min(sy, ey); y < max(sy, ey); y++ )
            fbgl_pxlset( fb, x, y, RGBA );
}

void fbgl_drawtriangle( unsigned int *xints, unsigned int *yints, unsigned int *colours ) {
    int xmin, xmax, ymin, ymax;
    xmin = min( *(xints), min( *(xints + 1), *(xints + 2) ) );
    ymin = min( *(yints), min( *(yints + 1), *(yints + 2) ) );
    xmax = max( *(xints), max( *(xints + 1), *(xints + 2) ) );
    ymax = max( *(yints), max( *(yints + 1), *(yints + 2) ) );

}
