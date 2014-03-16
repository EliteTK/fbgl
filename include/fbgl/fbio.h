#ifndef FBGL_FBIO
#define FBGL_FBIO
#include<linux/fb.h>

struct framebuffer {
    int filedesc;
    unsigned int *ptr;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long size;
};

int fbgl_open( struct framebuffer *, const char * );
void fbgl_close( const struct framebuffer * );

void fbgl_pxlset( const struct framebuffer *, const unsigned int, const unsigned int, const unsigned int);
unsigned int fbgl_pxlget( const struct framebuffer *, const unsigned int, const unsigned int );

void fbgl_fillscreen( const struct framebuffer *, const unsigned int);
#endif
