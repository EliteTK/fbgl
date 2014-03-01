#ifndef FBGL_SHAPES
#define FBGL_SHAPES

typedef struct point2d {
    int x;
    int y;
} Point2D;

void fbgl_fillrect(struct framebuffer *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int );
void fbgl_drawtri( struct framebuffer *, Point2D *, Point2D *, Point2D *, unsigned int * );
#endif
