*This project has been created as part of the 42 curriculum by lrouchon*

### Description:

The goal of this project was to provide a 3D wireframe representation of a given height map.
It's an important introduction to the world of computer graphics, and requires the use of *minilibx*, a custom-made graphic library for the C language.
The biggest challenge was figuring out how to translate a set of 3D coordinates to an isometric projection on a flat screen, which was made possible by using the *math.h* library.
It also required the use of *Bresenham's line algorithm*, in order to properly draw lines using the optimal amount of pixels, no matter the angle.

### Instructions:

-	Build *fdf* using `make`
-	Launch the program using the following command in your terminal: `./fdf <valid_map_name.fdf>`.

The following controls are available in the program:
**ESC:** exit
**UP/RIGHT/DOWN/LEFT:** move around
**NUMPAD 1:** isometric projection (default)
**NUMPAD 2:** parallel projection
**SCROLLWHEEL:** adjust z-scale
**+/-:** adjust zoom level

### Resources:

Resources on math.h:
-	https://www.w3schools.com/c/c_ref_math.php
Resources on Bresenham's line algorithm:
-	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
-	https://youtu.be/CceepU1vIKo?si=AckokeQiqQ5a0xow

