

#include "../graphic/graphic.h"

class Sphere
{
    public:
        Sphere(const Vector &center, const double radius): center_(center), radius_(radius){}

        
        ~Sphere(){}

        char RayIntersect (const Dot &origin, const Vector &dir) const;

     private:

        Vector center_;
        double radius_;
};


