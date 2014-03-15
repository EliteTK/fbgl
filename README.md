About
=====

This is a "crappy" (depends on your definition) frame buffer graphics library.

We will see how far it goes but at the moment it allows for filling the screen with a variety of colours. It allows for circles of different colours, squares and rectangles (of different colours) and triangles which barycentrically interpolate across a set of colours.

For the future:
---------------
I hope to make the drawing process multi-threaded to see if I can speed up the ridiculous 100 clock cycles required to send a single piece of data to the framebuffer. I also hope to add 3D functionality.

Right now:
----------
Right now I am working on rewriting the current code to look less terrible and work slightly better. This also includes redoing the folder structure and making a good looking make file which allows for quite a few more things.
