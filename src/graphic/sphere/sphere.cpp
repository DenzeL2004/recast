#include "sphere.h"


RayHit Sphere::RayIntersect (const Dot &origin, const Vector &dir) const
{
    Vector tmp = origin - center_;


    double cf_b = 2.0 * dir.ScalarProduct(tmp);

    double cf_c = tmp.ScalarProduct(tmp) - radius_ * radius_;

    double discriminant = cf_b * cf_b - 4 * cf_c;

    if (discriminant < 0.0 || IsZero(discriminant))
        return RayHit(Err_vector, Err_vector, material_, 0.0, FALSE);
    
    double discriminant_ = sqrt(discriminant);

    double t1 = (-cf_b + discriminant_) / 2.0;
    double t2 = (-cf_b - discriminant_) / 2.0;

    double distance = std::min(t1, t2);

    Vector hit_pos = origin + dir * distance;
    Vector hit_normal = (hit_pos - center_).Normalization();

    return RayHit(hit_pos, hit_normal, material_, distance, TRUE);
}

//================================================================================
