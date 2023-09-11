#include "sphere.h"
#include "../square_solve/square_solve.h"


char Sphere::RayIntersect (const Dot &origin, const Vector &dir) const
{
    Vector tmp = dir - center_;

    double cf_a = dir.GetX() * dir.GetX() + 
                  dir.GetY() * dir.GetY() + 
                  dir.GetZ() * dir.GetZ();

    double cf_b = 2.0 * (dir.GetX() * tmp.GetX() + 
                         dir.GetY() * tmp.GetY() +
                         dir.GetZ() * tmp.GetZ());

    double cf_c = tmp.GetX() * tmp.GetX() +
                  tmp.GetY() * tmp.GetY() - radius_;

    double t1 = NAN, t2 = NAN;
    char cnt = SolveSquare(cf_a, cf_b, cf_c, &t1, &t2);

    if (t1 > 0 || IsZero(t1) ||
        t2 > 0 || IsZero(t2)) return TRUE;

    return FALSE;
}