#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<linux/fb.h>
#include<sys/mman.h>
#include"fbio.h"

// Open framebuffer located at path and set fb to the information needed to reference it
// later when writing to it.
int fbgl_open( struct framebuffer *fb, char *path ) {
    fb->filedesc = open( path, O_RDWR );
    if( !fb->filedesc )
        return 1;

    if( ioctl( fb->filedesc, FBIOGET_VSCREENINFO, &fb->vinfo ) )
        return 2;
    if( ioctl( fb->filedesc, FBIOGET_FSCREENINFO, &fb->finfo ) )
        return 3;

    if( fb->vinfo.bits_per_pixel != 32 )
        return 4;

    fb->size = fb->vinfo.xres * fb->vinfo.yres * 4;
    fb->ptr = (unsigned int *)mmap(NULL, fb->size, PROT_READ | PROT_WRITE, MAP_SHARED, fb->filedesc, 0);
    if ( fb->ptr == MAP_FAILED )
        return 5;

    return 0;
}

// Close the framebuffer fb.
void fbgl_close( struct framebuffer *fb ) {
    close( fb->filedesc );
    munmap( fb->ptr, fb->size );
}

// Set pixel (x, y) in framebuffer fb to colour value RGBA.
void fbgl_pxlset( struct framebuffer *fb, unsigned int x, unsigned int y, unsigned int RGBA ) {
    if ( x < fb->vinfo.xres && y < fb->vinfo.yres )
        *(fb->ptr + y * fb->vinfo.xres + x) = RGBA;
}

// Get the integer value located at memory address fb->ptr + y * fb->vinfo.xres + x.
unsigned int fbgl_pxlget( struct framebuffer *fb, unsigned int x, unsigned int y ) {
    if ( x < fb->vinfo.xres && y < fb->vinfo.yres )
        return *((int *)(fb->ptr + y * fb->vinfo.xres + x));
    return 0;
}

// Fill the framebuffer fb with colour value RGBA.
void fbgl_fillscreen( struct framebuffer *fb, unsigned int RGBA) {
    int i;
    for( i = 0; i < fb->size / 4; i++)
        *(fb->ptr + i) = RGBA;
}
