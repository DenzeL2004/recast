#ifndef _MYCOLOR_H_
#define _MYCOLOR_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../../generals_func/generals.h"
#include "../../log_info/log_errors.h"


const double Color_limit = 1.0;
const double SFML_color_limit = 255.0;

class MyColor
{
    public:

        MyColor(double red, double green, double blue, double alpha):
                red_(  (double)red   / SFML_color_limit),
                green_((double)green / SFML_color_limit),
                blue_( (double)blue  / SFML_color_limit),
                alpha_((double)alpha / SFML_color_limit){}

        ~MyColor(){}

        char operator == (MyColor &other) const;

        void operator *= (const double scale);
        void operator += (const double scale);

        char IsErrColor() const;

        sf::Color GetSFMLColor() const;



    private:
        double red_, green_, blue_;
        double alpha_;

};



const MyColor Err_color = MyColor(NAN, NAN, NAN, NAN);

#endif