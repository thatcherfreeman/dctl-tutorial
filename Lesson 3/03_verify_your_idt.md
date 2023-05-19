# Verification of your IDT

Easy test:
1. Most camera color spaces tell you the black/mid-gray/90% or 100% white points and what code value they correspond to. Make sure those check out.

Advanced test:
1. Get the camera and shoot multiple exposures with it at known distances apart.
2. Use your color management to convert to Linear, then apply the gain associated with those different exposures
3. Make sure the resulting images match what you'd expect.
