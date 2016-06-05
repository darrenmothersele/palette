# Palette.h

Procedural palette generation in CPP (C++11) using gradient technique
originally developed by [Íñigo Quílez](http://www.iquilezles.org/www/articles/palettes/palettes.htm).
A Clojure version developed by [Karsten Schmidt](https://github.com/thi-ng/color).
There's a [GLSL shadertoy](https://www.shadertoy.com/view/ll2GD3) version.
And, [an online generator tool](http://dev.thi.ng/gradients/).

![Gradient Example](https://raw.githubusercontent.com/darrenmothersele/palette/master/output.png "Gradient Example")

Example

Create your own values for a, b, c, and d, as described in the original
article. The [online generator] can be used to generate palettes.
The generator gives output like this:

    [[0.500 0.500 0.500] [0.500 0.500 0.500] [1.000 1.000 1.000] [0.000 0.333 0.667]]

Convert that to an initializer list for use C++...

    {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,1.0},{0.0,0.33,0.67}}

Use that to create a palette, call the palette with a value for `t` between 0 and 1:

    #include "Palette.h"

    Palette p{{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,1.0},{0.0,0.33,0.67}};

    vec3f colour = p(0.5);

