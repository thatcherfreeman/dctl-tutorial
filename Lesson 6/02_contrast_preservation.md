# Contrast Preservation

$$g(x) = a * \frac{x}{x + b} + c$$


Let's modify the original function

$$h(x) = g\left(M_i * (\frac{1}{M_i} x)^\gamma\right) = a * \frac{M_i * (\frac{1}{M_i} x)^\gamma}{M_i * (\frac{1}{M_i} x)^\gamma + b} + c$$


Want to add one more constraint to the previous set:

1. Black point is hit. $g(0) = B$
2. White point is established. $\lim_{x \rightarrow \infty} g(x) = W$
3. Mid gray mapping. $g(M_i) = M_o$
4. **Slope at Mid Gray is $S$**, $\frac{d}{dx}\left. h(x) \right\rvert_{x=M_i} = S$

Here's our constraint:

$$h'(M_i) = S$$
$$h'(x) = g'(x) * \frac{d}{dx} \left( M_i * \left(\frac{1}{M_i} x\right)^\gamma \right)$$
$$h'(x) = g'(x) * \gamma * \left(\frac{x}{M_i}\right)^{\gamma - 1}$$
$$h'(M_i) = g'(M_i) * \gamma$$
$$\gamma = \frac{S}{g'(M_i)} =  S \frac{(M_i + b)^2}{a * b}$$
