#include "scene.h"


int Scene::FindNearestSphere(const Vector &origin, const Vector &dir, RayHit &ray_hit) const
{
    int ind_res = Not_intersect;
    double min_dist = (double)UINT64_MAX;

    for (int i = 0; i < this->spheres_.size(); ++i)
    {
        RayHit cur_hit = this->spheres_[i].RayIntersect(origin, dir);
        if(cur_hit.hit_flag_ && cur_hit.hit_dist_ < min_dist)
        {
            ind_res = i;
            min_dist = cur_hit.hit_dist_;
            ray_hit = cur_hit;
        }
    }

    return ind_res;
}

void Scene::Render (sf::RenderWindow &window) const
{
    const double aspect = (double)width_/(double)height_;

    for (size_t i = 0; i < width_; ++i) 
    {
        for (size_t j = 0; j < height_; ++j) 
        {
            double x = (double) i / (double) width_  * 2.0 - 1.0;
            double y = (double) j / (double) height_ * 2.0 - 1.0;

            x *= aspect;

            Vector dir = Vector((double)x, (double)y, 0).Normalization();

            Vector color = this->Tracing(camera_, dir);
           
            DrawPixel(window, Dot((double)i, (double)j, 0), GetSFMLColor(color));
        }
    }
    
    return;
}

Vector Scene::Tracing (Vector origin, Vector dir) const
{
    Vector res_color(0.0, 0.0, 0.0);
    double reflection = 1.0;

    for (size_t depth = 0; depth < Max_depth; ++depth)
    {
        RayHit sphere_hit;

        int nearest_sphere = FindNearestSphere(origin, dir, sphere_hit);

        if (nearest_sphere == Not_intersect) break;

        Vector shift_pos = sphere_hit.hit_pos_ + sphere_hit.hit_normal_ * Eps;

        Vector illumination(0.0, 0.0, 0.0);

        for (size_t id = 0; id < lights_.size(); ++id)
        {
            Dot light_pos = lights_[id].GetPos();

            Vector light_dir  = (light_pos - shift_pos).Normalization();

            RayHit light_hit;
            int nearest = FindNearestSphere(shift_pos, light_dir, light_hit);

            double light_hit_len = (light_pos - sphere_hit.hit_pos_).Len();

            if (light_hit.hit_dist_ < light_hit_len)
                continue;

            illumination += GetIllumination(sphere_hit, lights_[id], light_dir);
        }

        res_color   += reflection * illumination;
        reflection  *= spheres_[nearest_sphere].GetMaterial().GetReflection();
        
        origin      = shift_pos;
        dir = (dir - 2 * dir.ScalarProduct(sphere_hit.hit_normal_) * sphere_hit.hit_normal_).Normalization();

    }

    return res_color;
}

Vector Scene::GetIllumination(const RayHit &sphere_hit, const Light &light, const Vector &light_dir) const
{
    Vector illumination(0.0, 0.0, 0.0);

    illumination += sphere_hit.material_.GetAmbient() * light.GetAmbient();

    illumination += sphere_hit.material_.GetDiffuse() * light.GetDiffuse() * light_dir.ScalarProduct(sphere_hit.hit_normal_);

    Vector camera_dir = (camera_ - sphere_hit.hit_pos_).Normalization();
    Vector camera_light_dir = (light_dir + camera_dir).Normalization();
    illumination += sphere_hit.material_.GetSpecular() * light.GetSpecular() * 
                    pow(camera_light_dir.ScalarProduct(sphere_hit.hit_normal_), sphere_hit.material_.GetShines() / Shines_cf);

    return illumination;
}