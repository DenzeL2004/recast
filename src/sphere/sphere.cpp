#include "sphere.h"
#include "../square_solve/square_solve.h"


char Sphere::RayIntersect (const Dot &origin, const Vector &dir) const
{
    Vector tmp = origin - center_;

    double cf_a = dir.ScalarProduct(dir);

    double cf_b = 2.0 * dir.ScalarProduct(tmp);

    double cf_c = tmp.ScalarProduct(tmp) - radius_ * radius_;

    double t1 = NAN, t2 = NAN;
    char cnt = SolveSquare(cf_a, cf_b, cf_c, &t1, &t2);

    if (t1 >= 0.0) return TRUE;

    return FALSE;
}

//================================================================================

sf::Color Sphere::RayCast (const Vector &orig, const Vector &dir, const sf::Color background_color) const
{
    
    if (!this->RayIntersect(orig, dir)) {
        return background_color;
    }

    return this->color_;
}


