#include "graphic.h"


//===============================================================================

void Plane::DrawEmptyPlane(sf::RenderWindow &window) const
{
    sf::RectangleShape rect(sf::Vector2f((float)this->plane_width_, 
                                         (float)this->plane_height_));

    rect.setPosition((float)this->plane_origin_.GetX(), 
                     (float)this->plane_origin_.GetY());

    rect.setFillColor(this->color_);

    window.draw(rect);


    return;
}

void Plane::ShowAxis(sf::RenderWindow &window) const
{
    
    Vector vec_tmp = this->axis_x_;
    this->DrawAxis(window, vec_tmp);

    vec_tmp *= -1.f;
    this->DrawAxis(window, vec_tmp);

    vec_tmp = this->axis_y_;
    this->DrawAxis(window, vec_tmp);

    vec_tmp *= -1.f;
    this->DrawAxis(window, vec_tmp);

    return;
}

void Plane::DrawAxis(sf::RenderWindow &window, const Vector &dir) const
{
    Dot dot_prev = this->axis_shift_;
    Dot dot_next = dot_prev + dir;

    while (this->CheckDotOnPlane(dot_next))
    {
        DrawCircle(window, dot_prev, Stroke_radius, Default_axis_color);

        dot_prev  = dot_next;   
        dot_next += dir;      
    }


    DrawLine(window, this->axis_shift_, dot_prev, Default_axis_color);    

    return;
}

//===============================================================================

int Plane::CheckDotOnPlane(const Dot &dot) const
{

    double left_border  = this->plane_origin_.GetX();
    double right_border = this->plane_origin_.GetX() + (double)this->plane_width_;
    
    double up_border   = this->plane_origin_.GetY();
    double down_border = this->plane_origin_.GetY() + (double)this->plane_height_;

    double dot_x = dot.GetX();
    double dot_y = dot.GetY();

    return  (dot_x < right_border) && (dot_x > left_border) &&
            (dot_y < down_border)  && (dot_y > up_border);  
}


//===============================================================================

void Plane::DrawVector(sf::RenderWindow &window, 
                        const Dot &dot_start, const Vector &dir, const sf::Color color_line) const
{

    Vector norm_res =   dir.Normalization();
    Vector norm_ort =   norm_res.Orthogonality2xy().Normalization(); 
    
    Vector tendril1 = (norm_ort + norm_res) * Len_tendril;
    Vector tendril2 = (norm_res - norm_ort) * Len_tendril;

    tendril1 = tendril1.Normalization();
    tendril2 = tendril2.Normalization();

    Dot coord1 = dir - tendril1;
    Dot coord2 = dir - tendril2;

    Dot dot_begin = this->ZoomDot(dot_start) + this->axis_shift_;
    Dot dot_end   = this->ZoomDot(dir)       + dot_begin;

    if (!this->CheckDotOnPlane(dot_begin) || !this->CheckDotOnPlane(dot_end))
    {
        printf("line cannot be drawn because one of the coordinates is out of plane's bounds.\n");
        return;
    }

    DrawLine(window, dot_begin, dot_end, color_line);

    Dot zoom_coord1 = this->ZoomDot(coord1) + dot_begin;
    Dot zoom_coord2 = this->ZoomDot(coord2) + dot_begin;

    DrawLine(window, dot_end, zoom_coord1, color_line);
    DrawLine(window, dot_end, zoom_coord2, color_line);

    return;
   
}

//===============================================================================

Dot Plane::ZoomDot(const Dot &dot) const
{
    Vector vec1 = this->axis_x_ * dot.GetX();
    Vector vec2 = this->axis_y_ * dot.GetY();

    Dot new_dot = vec1 + vec2;

    return new_dot;
}


//================================================================================

void DrawLine(sf::RenderWindow &window, 
              const Dot &dot_begin, const Dot &dot_end, const sf::Color color_line)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f((float)dot_begin.GetX(), (float)dot_begin.GetY()), color_line),
        sf::Vertex(sf::Vector2f((float)dot_end.GetX(), (float)dot_end.GetY()), color_line)
    };

    window.draw(line, 2, sf::Lines);

    return;
   
}

void DrawCircle(sf::RenderWindow &window, const Dot &pos, 
                const float radius, const sf::Color color)
{

    sf::CircleShape circle(radius);
    circle.setFillColor(color);

    circle.setPosition((float)pos.GetX(), (float)pos.GetY());

    window.draw(circle);

    return;
   
}

void DrawPixel(sf::RenderWindow &window, const Dot &pos, const sf::Color color)
{

    sf::RectangleShape pixel;
    pixel.setSize({ 1.f, 1.f });
    pixel.setFillColor(color);


    pixel.setPosition((float)pos.GetX(), (float)pos.GetY());

    window.draw(pixel);
    
    return;
   
}

//================================================================================

sf::Color GetSFMLColor(const Vector &color)
{

    double red   = std::min(color.GetX(), 1.0);
    double green = std::min(color.GetY(), 1.0);
    double blue  = std::min(color.GetZ(), 1.0);
    
    return sf::Color((uint8_t) (red * 255.0), (uint8_t) (green * 255.0), (uint8_t) (blue * 255.0));
}