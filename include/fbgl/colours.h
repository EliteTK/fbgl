#ifndef __FBGL_COLOURS

#define C_RED 16711680
#define C_GREEN 65280
#define C_BLUE 255
#define C_WHITE 16777215
#define C_BLACK 0
#define C_GRAY 8355711
#define C_CYAN 16776960
#define C_MAGENTA 16711935
#define C_YELLOW 16776960

#define fbgl_colour( R, G, B, A ) ((unsigned int)((unsigned char)(A) << 24 | (unsigned char)(R) << 16 | (unsigned char)(G) << 8 | (unsigned char)(B)))

#define fbgl_getR(C) ((C) >> 16 & 255)
#define fbgl_getG(C) ((C) >> 8 & 255)
#define fbgl_getB(C) ((C) & 255)
#define fbgl_getA(C) ((C) >> 24 & 255)

#define __FBGL_COLOURS
#endif
