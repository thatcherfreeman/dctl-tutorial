# Rolloff Function, now with parameters!
Starting with:

$$f(x) = \frac{x}{x + 1}$$

Let's add as many parameters as we could possibly want.

$$g(x) = a * \frac{x}{x + b} + c$$

By tuning the parameters $a, b, c$, hopefully we can control the following constraints:

Let $M_i$ be Mid gray, let $M_o$ be the value mid gray should be reproduced at, let $W$ be the desired white point, let $B$ be the desired black point

1. Black point is hit. $g(0) = B$
2. White point is established. $\lim_{x \rightarrow \infty} g(x) = W$
3. Mid gray mapping. $g(M_i) = M_o$

This is hit with the following assignments:

Constraint 1:
$$g(0) = B = c$$

Constraint 2:
$$g(\infty) = W = a + c$$
$$a = W - c$$

Constraint 3:
$$g(M_i) = M_o = a * \frac{M_i}{M_i + b} + c$$
$$\frac{M_o - c}{a} (M_i + b) = M_i$$
$$\frac{M_o - c}{a} M_i + \frac{M_o - c}{a} b = M_i$$
$$\frac{M_o - c}{a} b = M_i - \frac{M_o - c}{a} M_i$$
$$b = \left(\frac{a}{M_o - c}\right) \left(1 - \frac{M_o - c}{a}  \right)M_i$$

