#ifndef _GRAPHIC_CONFIG_H_
#define _GRAPHIC_CONFIG_H_

const uint32_t Default_window_hight  = 1200;
const uint32_t Default_window_weight = 1600;

const uint32_t Default_plane_hight  = (uint32_t)((double)Default_window_hight  / 1.1);
const uint32_t Default_plane_weight = (uint32_t)((double)Default_window_weight / 1.75);

const double X_plane_start = 10.0;
const double Y_plane_start = 10.0;

const Dot Left_corner  = Vector(X_plane_start, Y_plane_start, 0.0);
const Dot Right_corner = Vector(X_plane_start + Default_plane_weight + 50, Y_plane_start, 0.0);


//===============================================================================

const uint32_t Max_limit_vector_cnt = 100;

const float Stroke_radius = 1.5f;

const double Len_tendril = 1.0;

const sf::Color Default_vec_color = sf::Color::Red;
const sf::Color Default_axis_color = sf::Color::Black;

const useconds_t Mouse_press_delay = 50U;


#endif //#endif _GRAPHIC_CONFIG_H_