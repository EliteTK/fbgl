About
=====

This is a "crappy" (depends on your definition) frame buffer graphics library.

We will see how far it goes but at the moment it allows for filling the screen with a variety of colours. It allows for circles of different colours, squares and rectangles (of different colours) and triangles which barycentrically interpolate across a set of colours.

Working Features:
-----------------
The currently working feature list is rather small but still relatively useful. It includes:
 * Drawing triangles with colours barycentrically interpolated between vertices.
 * Drawing coloured axis aligned boxes.
 * Drawing coloured circles.

Planned Short Term:
-------------------
There are currently certain planned short term goals for the project, to get it ready for use in some simple 2D game. They are as follows:
 * Fix the cursor input and output to the screen while drawing causing problems.
 * Using a callback to fill the objects with colours, including a basic solid fill and a separated version of the current barycentric interpolation algorithm for triangles.
 * Simple 2D texture mapping onto triangles and AABs.

Planned Long Term:
------------------
There are also certain planned long term features which will eventually be implemented but are not currently a must.
 * Allowing for all kinds of colour arrangements in memory, aka wider support for framebuffers.
 * Text drawing functions, including a reader for bitmap fonts.
 * Alpha blending for colours.
 * 3D library (Java canvas-esque).
