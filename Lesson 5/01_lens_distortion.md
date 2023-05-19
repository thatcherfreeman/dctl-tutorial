# Lens Distortion Modelling - The Math

### Suppose we're trying to remove lens distortion.

**Overall goal**: Replace the current pixel with the color at the location in the image where this pixel would have been if the lens didn't have distortion.

1. Move the origin $(x_d, y_d) = (0, 0)$ to the middle of the screen, where $x_d, y_d$ are the $x$ and $y$ coordinates within the distorted image.
2. Scale the input coordinates uniformly so the height of the frame is $1.0$
3. Compute the distance of the current pixel from the center of the frame: $$r_d = \sqrt{x_d^2 + y_d^2}$$
4. Let's compute the coordinates of the undistorted pixel: $$x_u = x_d(1 + k_1 r_d^2 + k_2 r_d^4 + \dots)$$ $$y_u = y_d(1 + k_1r_d^2 + k_2 r_d^4 + \dots)$$
    * It turns out we don't need most of the terms in practice
5. Look up the color at $(x_u, y_u)$ and return that color.





## Source:
Frédéric Devernay, Olivier Faugeras. *Straight lines have to be straight: automatic calibration and re-moval of distortion from scenes of structured enviroments*. Machine Vision and Applications, Springer Verlag, 2001, 13 (1), pp.14-24. 10.1007/PL00013269. inria-00267247