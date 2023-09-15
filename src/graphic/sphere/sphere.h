#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "../../vector/vector.h"
#include "../material/material.h"

struct RayHit
{
    Vector  hit_pos_;
    Vector  hit_normal_;

    Material material_;

    double   hit_dist_;

    char     hit_flag_;


    public:
        RayHit ():
            hit_pos_(Err_vector), hit_normal_(Err_vector),
            material_(Material(Err_vector, Err_vector, Err_vector, 0.0, 0.0)), 
            hit_dist_(NAN), hit_flag_(FALSE){}


        RayHit(const Vector &hit_pos, const Vector &hit_normal_, const Material &material, 
               const double hit_dist, const char flag):
            hit_pos_(hit_pos), hit_normal_(hit_normal_),
            material_(material), hit_dist_(hit_dist), hit_flag_(flag){}

        ~RayHit(){}
};

class Sphere
{
    public:
        Sphere(const Vector &center, const double radius, 
               const double specular, const Material material): 
               center_(center), radius_(radius), material_(material){}
        
        ~Sphere(){}

        Vector   GetCenter()    const {return center_; }
        double   GetRadius()    const {return radius_; }
        Material GetMaterial()  const {return material_; }

        RayHit  RayIntersect (const Dot &origin, const Vector &dir) const;

     private:

        Vector center_;
        double radius_;

        Material material_;
};

const double Shines_cf = 4.0;

#endif //_SPHERE_H_
