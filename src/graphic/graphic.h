#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

#include "../vector/vector.h"
#include "../sphere/sphere.h"

#include "../graphic/graphic_config.h"


void    DrawLine        (sf::RenderWindow &window, 
                         const Dot &dot_begin, const Dot &dot_end, const sf::Color color_line);

void    DrawCircle      (sf::RenderWindow &window, const Dot &pos, 
                         const float radius, const sf::Color color);

void    DrawPixel       (sf::RenderWindow &window, const Dot &pos, const sf::Color color);


class Plane
{
    public:

        Plane (const Dot plane_origin, uint32_t plane_height, const uint32_t plane_weight, 
               const Dot axis_shift, const Vector axis_x, const Vector axis_y, const sf::Color color = Default_plane_color):
        plane_origin_(plane_origin), plane_height_(plane_height), plane_width_(plane_weight),
        axis_shift_(axis_shift + plane_origin), axis_x_(axis_x), axis_y_(axis_y), color_(color){}

        ~Plane(){}

        void    DrawEmptyPlane  (sf::RenderWindow &window) const;
        
        void    ShowAxis        (sf::RenderWindow &window) const;

        int     CheckDotOnPlane (const Dot &dot) const;

        void    DrawVector      (sf::RenderWindow &window, 
                                 const Dot &dot_start, const Vector &dir, 
                                 const sf::Color color_line = Default_vec_color) const;

        void    RenderSphere    (sf::RenderWindow &window, const Sphere &spher);

    private:

        void DrawAxis(sf::RenderWindow &window, const Vector &dir) const;

        Dot ZoomDot(const Dot &dot) const;


        Dot      plane_origin_;
        uint32_t plane_height_;
        uint32_t plane_width_;
        
        Dot    axis_shift_;
        Vector axis_x_;
        Vector axis_y_;

        sf::Color color_; 
              
};


#endif //#endif _GRAPHIC_H_