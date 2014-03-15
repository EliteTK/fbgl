#include<stdio.h>
#include<stdlib.h>
#include"lib/fbio.h"
#include"lib/colours.h"
#include"lib/shapes.h"

void pincr( Point2D * );

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
    /*fbgl_fillscreen( fb, fbgl_colour( 13, 123, 55, 0 ) );*/
//    fbgl_fillrect( fb, 0, 0, 200, 200, C_RED );
//    fbgl_fillrect( fb, 0, 0, 100, 100, C_GREEN );
//    fbgl_fillrect( fb, 100, 100, 200, 200, C_BLUE );

//    Point2D ap0 = { 10, 10 }, ap1 = { 510, 10 }, ap2 = { 510, 510 };
//    Point2D bp0 = { 10, 10 }, bp1 = { 510, 510 }, bp2 = { 10, 510 };
//    Point2D ccentr = { 260, 260 };
//    int acolours[] = { C_RED, C_GREEN, C_BLUE };
//    int bcolours[] = { C_RED, C_BLUE, C_GREEN };

//    fbgl_drawtri( fb, &ap0, &ap1, &ap2, acolours );
//    fbgl_drawtri( fb, &bp0, &bp1, &bp2, bcolours );
//    fbgl_drawcir( fb, &ccentr, 150, C_BLACK );

    /*Point2D acp = { 60, 60 }, bcp = { 160, 60 };*/
    /*Point2D atp = { 60-44, 60+24 }, btp = { 110, 60 }, ctp = { 110, 260 }, dtp = { 160+44, 60+24 };*/
    /*int colours[] = { C_RED, C_RED, C_RED };*/

    /*fbgl_drawtri( fb, &atp, &btp, &ctp, colours );*/
    /*fbgl_drawtri( fb, &btp, &dtp, &ctp, colours );*/

    /*fbgl_drawcir( fb, &acp, 50, C_RED );*/
    /*fbgl_drawcir( fb, &bcp, 50, C_RED );*/

    Point2D atp = { 10, 10 }, btp = { 210, 10 }, ctp = { 110, 110 };
    unsigned int colours[] = { C_BLUE, C_BLUE, C_BLUE };

    int i;
    for( i = 0; i < 600; i++ ) {
        pincr( &atp );
        pincr( &btp );
        pincr( &ctp );
        int del;
        for(del = 0; del < 1; del++) {
            fbgl_fillscreen( fb, fbgl_colour( 13, 123, 55, 0 ) );
        }
        fbgl_drawtri( fb, &atp, &btp, &ctp, colours );
        fbgl_draw( fb );
    }
    fbgl_close( fb );
    return 0;
}

void pincr( Point2D *p ) {
    p->x += 1;
    p->y += 1;
}
