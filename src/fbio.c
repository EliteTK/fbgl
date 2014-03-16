#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<linux/fb.h>
#include<sys/mman.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include"fbio.h"

// Open framebuffer located at path and set fb to the information needed to reference it
// later when writing to it.
int fbgl_open( struct framebuffer *fb, const char *path ) {
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
    fb->buffer = (unsigned int *)malloc( fb->size );
    if ( fb->ptr == MAP_FAILED )
        return 5;

    return 0;
}

// Close the framebuffer fb.
void fbgl_close( const struct framebuffer *fb ) {
    close( fb->filedesc );
    munmap( fb->ptr, fb->size );
    free( fb->buffer );
}

// Set pixel (x, y) in framebuffer fb to colour value RGBA.
void fbgl_pxlset( const struct framebuffer *fb, const unsigned int x,
                  const unsigned int y, const unsigned int RGBA ) {
    if ( x < fb->vinfo.xres && y < fb->vinfo.yres )
        *(fb->buffer + y * fb->vinfo.xres + x) = RGBA;
}

// Draw the contents of the buffer to the framebuffer.
void fbgl_draw( const struct framebuffer *fb ) {
    unsigned int i;
    for ( i = 0; i < fb->size / 8; i++)
        *((size_t *)fb->ptr + i) = *((size_t *)fb->buffer + i);
}

// Get the integer value located at memory address fb->ptr + y * fb->vinfo.xres + x.
unsigned int fbgl_pxlget( const struct framebuffer *fb, const unsigned int x,
                          const unsigned int y ) {
    if ( x < fb->vinfo.xres && y < fb->vinfo.yres )
        return *((int *)(fb->ptr + y * fb->vinfo.xres + x));
    return 0;
}

// Fill the framebuffer fb with colour value RGBA.
void fbgl_fillscreen( const struct framebuffer *fb, const unsigned int RGBA) {
    unsigned int i;
    for( i = 0; i < fb->size / 4; i++)
        *(fb->buffer + i) = RGBA;
}
