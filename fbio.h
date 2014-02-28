#ifndef FBGL_FBIO
#define FBGL_FBIO
#include<linux/fb.h>

struct framebuffer {
    int filedesc;
    int *ptr;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long size;
};

int fbgl_open( struct framebuffer *, char * );
void fbgl_close( struct framebuffer * );

void fbgl_pxlset( struct framebuffer *, unsigned int, unsigned int, unsigned int);
unsigned int fbgl_pxlget( struct framebuffer *, unsigned int, unsigned int );

void fbgl_fillscreen( struct framebuffer *, unsigned int);
#endif
