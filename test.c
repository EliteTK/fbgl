#include<stdio.h>
#include<stdlib.h>
#include"fbio.h"
#include"colours.h"

int main( int argc, char *argv[] ) {
    struct framebuffer *fb = malloc(sizeof(struct framebuffer));
    if( fbgl_open( fb, "/dev/fb0" ) ) {
        perror( "Couldn't open framebuffer." );
        exit(1);
    }

//    int x, y;
//    struct vec2 *pos = malloc(sizeof(struct vec2));
//    int *col = malloc(sizeof(int));
//    for ( x = 0; x < 1000; x++ ) {
//        for ( y = 0; y < 700; y++ ) {
//            *col = 4294967295;
//            pos->x = x;
//            pos->y = y;
//            fbgl_pxlset( fb, pos, (char *)col );
//        }
//    }
    unsigned int col = fbgl_colour( 13, 123, 55, 0 );
    printf("Colourvalue %u\n", col);
    fbgl_fillscreen( fb, col );
    fbgl_fillrect( fb, 0, 0, 200, 200, C_RED );
    fbgl_fillrect( fb, 0, 0, 100, 100, C_GREEN );
    fbgl_fillrect( fb, 100, 100, 200, 200, C_BLUE );

    sleep(10);
    fbgl_close( fb );
}

