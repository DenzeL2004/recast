#include "sphere.h"
#include "../../square_solve/square_solve.h"


double Sphere::RayIntersect (const Dot &origin, const Vector &dir) const
{
    Vector tmp = origin - center_;

    double cf_a = dir.ScalarProduct(dir);

    double cf_b = 2.0 * dir.ScalarProduct(tmp);

    double cf_c = tmp.ScalarProduct(tmp) - radius_ * radius_;

    double t1 = NAN, t2 = NAN;
    SolveSquare(cf_a, cf_b, cf_c, &t1, &t2);

    if (isnan(t1)) return NAN;

    if (t1 > t2) t1 = t2;
    
    return t1;
}

//================================================================================

MyColor Sphere::RayCast (const Vector &orig, const Vector &dir, std::vector<Light> lights) const
{

    double intersection_point = this->RayIntersect(orig, dir);   
    if (isnan(intersection_point)) {
        return Err_color;
    }

    Vector norm    = Dot((orig + dir * intersection_point) - center_).Normalization();

    MyColor color_out = color_;

    double alpha = 0.0, reflection = 1.0;
    for (size_t i = 0; i < lights.size(); ++i)
    {
        double scale = lights[i].dir_.ScalarProduct(norm);

        Vector vec_mir = norm * scale * 2.0 - lights[i].dir_;

        if (scale > 0.0) 
            alpha += lights[i].intensity_ * scale / lights[i].dir_.Len();   

        if (specular_ > 0)
        {
            double scale_cf = vec_mir.ScalarProduct(dir * -1.0);
            if (scale_cf > 0)
                reflection += lights[i].intensity_ * std::pow(scale_cf / (vec_mir.Len() * dir.Len()), specular_);
        }
    }

    color_out *= (alpha);
    color_out += reflection;
    
    return color_out;
}


