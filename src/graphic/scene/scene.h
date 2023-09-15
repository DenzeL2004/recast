#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "../graphic.h"

#include "../../vector/vector.h"
#include "../material/material.h"

#include "../sphere/sphere.h"

struct Light
{
    public:
        Light(const Vector &pos, 
              const Vector &ambient, const Vector &diffuse, const Vector &specular): 
              pos_(pos), 
              ambient_(ambient), diffuse_(diffuse), specular_(specular){}

        ~Light(){}

        Vector  GetPos()       const {return pos_;}

        Vector GetAmbient()    const {return ambient_;}
        Vector GetDiffuse()    const {return diffuse_;}
        Vector GetSpecular()   const {return specular_;}

    
    private:

        Vector pos_;

        Vector ambient_;
        Vector diffuse_;
        Vector specular_;



};


class Scene
{ 

    public:
        Scene(const Vector camera, const size_t height, const size_t width, 
              std::vector<Light> lights = {}, std::vector<Sphere> spheres = {}):
            camera_(camera),
            height_(height), width_(width), 
            lights_(lights), spheres_(spheres){}

        ~Scene(){}


        void Render (sf::RenderWindow &window) const;

        void AddLight (const Light &light) 
        {
            lights_.push_back(light); 
            return;
        }

        void AddSphere (const Sphere &sphere) 
        {
            spheres_.push_back(sphere); 
            return;
        }
        
    private:

        static const size_t Max_depth = 4;

        int FindNearestSphere (const Vector &origin, const Vector &dir, RayHit &ray_hit) const;

        Vector Tracing (Vector origin, Vector dir) const;

        Vector GetIllumination(const RayHit &sphere_hit, const Light &light, const Vector &light_dir) const;

        Vector camera_;

        size_t height_, width_;

        std::vector<Sphere> spheres_;
        std::vector<Light>  lights_; 
              
};


int const Not_intersect = -1; 

#endif //#endif _SCENE_H_