#include<stdio.h>
#include<stdlib.h>
#include"lib/fbio.h"
#include"lib/colours.h"
#include"lib/shapes.h"

int main( int argc, char *argv[] ) {
    struct framebuffer *fb = malloc(sizeof(struct framebuffer));
    if( fbgl_open( fb, "/dev/fb0" ) ) {
        perror( "Couldn't open framebuffer." );
        exit(1);
    }

    fbgl_fillscreen( fb, fbgl_colour( 13, 123, 55, 0 ) );

    Point2D acp = { 60, 60 }, bcp = { 160, 60 };
    Point2D atp = { 60-44, 60+24 }, btp = { 110, 60 }, ctp = { 110, 260 }, dtp = { 160+44, 60+24 };
    int colours[] = { C_RED, C_RED, C_RED };

    fbgl_drawtri( fb, &atp, &btp, &ctp, colours );
    fbgl_drawtri( fb, &btp, &dtp, &ctp, colours );

    fbgl_drawcir( fb, &acp, 50, C_RED );
    fbgl_drawcir( fb, &bcp, 50, C_RED );

    sleep(10);
    fbgl_close( fb );
}

