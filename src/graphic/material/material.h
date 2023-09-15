#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../../generals_func/generals.h"
#include "../../log_info/log_errors.h"

#include "../../vector/vector.h"




class Material
{
    public:

        Material(const Vector ambient_color, const Vector diffuse_color, const Vector specular_color, 
                double shines = 0, double reflection = 0) :
                ambient_color_  (ambient_color), diffuse_color_ (diffuse_color), specular_color_ (specular_color),
                shines_ (shines), reflection_  (reflection){}


        ~Material() {}

        Vector GetAmbient()    const {return ambient_color_;}
        Vector GetDiffuse()    const {return diffuse_color_;}
        Vector GetSpecular()   const {return specular_color_;}

        double GetShines()     const {return shines_;}

        double GetReflection() const {return reflection_;}

    private:

        Vector ambient_color_;
        Vector diffuse_color_;
        Vector specular_color_;

        double  shines_;
        double  reflection_;
};

#endif