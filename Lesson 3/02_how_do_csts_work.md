# How do Color Space Transforms work?

Given:
* Source color space's Transfer Function and Primaries
* Destination color space's Transfer Function and Primaries

The Color Space Transform tool takes these three steps for an $(r, g, b)$ pixel in the source color space:
1. Linearize the pixel by applying the Source's linearization transfer function (log to linear) to each of $r, g, b$.
2. Compute a $3 \times 3$ matrix $A = BCD$, where:
    - $D$ is the Source Primaries to XYZ gamut transform matrix 
    - $C$ is a chromatic adaptation matrix from the source white point to the destination white point
    - $B$ is the XYZ to Destination Primaries gamut transform matrix
3. In linear space, compute $A \begin{bmatrix} r \\ g \\ b\end{bmatrix}$
4. Apply the Destination's inverse linearization transfer function (linear to log) to each of $r, g, b$.