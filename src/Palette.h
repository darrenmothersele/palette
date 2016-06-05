#ifndef PALETTE_PALETTE_H
#define PALETTE_PALETTE_H

#include <Eigen/Core>

typedef Eigen::Vector3f vec3f;

class Palette {
public:
    Palette()
            : a{0.5, 0.5, 0.5},
              b{0.5, 0.5, 0.5},
              c{1.0, 1.0, 1.0},
              d{0.0, 0.33, 0.67}
    {}

    Palette(vec3f _a, vec3f _b, vec3f _c, vec3f _d)
            : a(_a), b(_b), c(_c), d(_d)
    {}

    vec3f operator()(float t) const
    {
        return a.array() + b.array() * (6.28318 * (c.array() * t + d.array())).array().cos();
    }

private:
    vec3f a,b,c,d;
};

#endif //PALETTE_PALETTE_H
