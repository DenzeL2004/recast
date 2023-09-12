#include "color.h"


//================================================================================

char MyColor::operator == (MyColor &other) const
{
    if (this->IsErrColor() || other.IsErrColor())
        return FALSE;

    char res = EqualityDouble(red_, other.red_)   && EqualityDouble(green_, other.green_) &&
               EqualityDouble(blue_, other.blue_) && EqualityDouble(alpha_, other.alpha_);

    return res;
 
}

//================================================================================      

void MyColor::operator *= (const double scale)
{
    double scale_ = scale / SFML_color_limit;

    red_   = std::min(red_   * scale_, Color_limit);
    green_ = std::min(green_ * scale_, Color_limit);
    blue_  = std::min(blue_  * scale_, Color_limit);
    alpha_ = std::min(alpha_ * scale_, Color_limit);

    return;
}

//================================================================================

void MyColor::operator += (const double scale)
{
    double scale_ = scale / SFML_color_limit;

    red_   = std::min(red_   + scale_, Color_limit);
    green_ = std::min(green_ + scale_, Color_limit);
    blue_  = std::min(blue_  + scale_, Color_limit);
    alpha_ = std::min(alpha_ + scale_, Color_limit);

    return;
}

//================================================================================

char MyColor::IsErrColor() const
{
    char res = isnan(red_)  || isnan(green_) ||
               isnan(blue_) || isnan(alpha_);

    return res;
}

//================================================================================

sf::Color MyColor::GetSFMLColor() const
{
    sf::Color color((sf::Uint8)(red_ * SFML_color_limit),  
                    (sf::Uint8)(green_ * SFML_color_limit),
                    (sf::Uint8)(blue_ * SFML_color_limit),
                    (sf::Uint8)(alpha_ * SFML_color_limit));

    return color;
}

//================================================================================