#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <SFML/Graphics.hpp>

#include "../vector/vector.h"

class Sphere
{
    public:
        Sphere(const Vector &center, const double radius, const sf::Color color): 
               center_(center), radius_(radius), color_ (color){}
        
        ~Sphere(){}

        Vector      GetCenter() const {return center_; }
        double      GetRadius() const {return radius_; }
        sf::Color   GetColor()  const {return color_; }

        char RayIntersect (const Dot &origin, const Vector &dir) const;

        sf::Color RayCast (const Vector &orig, const Vector &dir, const sf::Color background_color) const;

     private:

        Vector center_;
        double radius_;

        sf::Color color_;

};

#endif //_SPHERE_H_
