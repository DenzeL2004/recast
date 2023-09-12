#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "../../vector/vector.h"
#include "../color/color.h"


struct Light
{
    public:
        Light(const Vector &dir, const double intensity): dir_(dir), intensity_(intensity){}

        ~Light(){}

    Vector dir_;
    double intensity_;
};


class Sphere
{
    public:
        Sphere(const Vector &center, const double radius, 
               const double specular, const MyColor color): 
               center_(center), radius_(radius), specular_(specular), color_ (color){}
        
        ~Sphere(){}

        Vector      GetCenter() const {return center_; }
        double      GetRadius() const {return radius_; }
        MyColor     GetColor()  const {return color_; }

        double  RayIntersect (const Dot &origin, const Vector &dir) const;

        MyColor RayCast (const Vector &orig, const Vector &dir, std::vector<Light> lights) const;

     private:

        Vector center_;
        double radius_;

        double specular_;

        MyColor color_;

};

#endif //_SPHERE_H_
