#include "vector.h"

//=======================================================================

Vector& Vector::operator = (const Vector &other)
{
    this->x_ = other.x_;
    this->y_ = other.y_;
    this->z_ = other.z_;

    return *this;
}

//=======================================================================

Vector& Vector::operator += (const Vector &other)
{
    this->x_ += other.x_;
    this->y_ += other.y_;
    this->z_ += other.z_;

    return *this;
}

//=======================================================================

Vector& Vector::operator -= (const Vector &other)
{
    this->x_ -= other.x_;
    this->y_ -= other.y_;
    this->z_ -= other.z_;

    return *this;
}

//=======================================================================

Vector& Vector::operator *= (const double scale)
{
    this->x_ *= scale;
    this->y_ *= scale;
    this->z_ *= scale;

    return *this;
}

//=======================================================================

Vector& Vector::operator /= (const double scale)
{
    this->x_ /= scale;
    this->y_ /= scale;
    this->z_ /= scale;

    return *this;
}

//=======================================================================

Vector& Vector::operator *= (const Vector &other)
{
    x_ *= other.x_;
    y_ *= other.y_;
    z_ *= other.z_;

    return *this;
}

Vector operator * (const Vector &lhs, const Vector &rhs)
{
    Vector res = lhs;
    res *= rhs;

    return res;
}

//=======================================================================

double Vector::Len () const
{
    double len = this->ScalarProduct(*this);
    
    len = sqrt(len);

    return len;
}

//=======================================================================

void Vector::RotateZ (double const angle) 
{
    double radian = angle * M_PI / 180.0;

    double rotate_x = x_ * cos(radian) - y_ * sin(radian);
    double rotate_y = x_ * sin(radian) + y_ * cos(radian);

    x_ = rotate_x;
    y_ = rotate_y;

    return;
}

void Vector::RotateX (double const angle) 
{
    double radian = angle * M_PI / 180.0;

    double rotate_y = y_ * cos(radian) - z_ * sin(radian);
    double rotate_z = y_ * sin(radian) + z_ * cos(radian);

    y_ = rotate_y;
    z_ = rotate_z;

    return;
}

void Vector::RotateY (double const angle) 
{
    double radian = angle * M_PI / 180.0;

    double rotate_x =  x_ * cos(radian) + z_ * sin(radian);
    double rotate_z = -x_ * sin(radian) + z_ * cos(radian);
    
    x_ = rotate_x;
    z_ = rotate_z;

    return;
}

//=======================================================================


Vector Vector::Normalization () const
{
    Vector res(*this / this->Len());

    return res;
}


//=======================================================================

Vector Vector::Orthogonality2xy  () const
{
    Vector res(this->GetY() * -1.0, this->GetX(), this->GetZ());

    return res;
}

//=======================================================================

double Vector::ScalarProduct (const Vector &vec) const
{
    return  vec.x_ * this->x_ + 
            vec.y_ * this->y_ +
            vec.z_ * this->z_;
}

//=======================================================================

Vector operator + (const Vector &vec1, const Vector &vec2)
{
    Vector res = vec1;
    res += vec2;

    return res;
}

//=======================================================================

Vector operator - (const Vector &vec1, const Vector &vec2)
{
    Vector res = vec1;
    res -= vec2;
    
    return res;
}

//=======================================================================

Vector operator * (const Vector &vec, const double scale)
{
    Vector res = vec;
    res *= scale;

    return res;
}

Vector operator * (const double scale, const Vector &vec)
{
    Vector res = vec;
    res *= scale;

    return res;
}

//=======================================================================

Vector operator / (const Vector &vec, const double scale)
{
    Vector res = vec;
    res /= scale;

    return res;
}


//=======================================================================

double Vector::Corner (const Vector &vec) const
{ 
    return  acos(this->ScalarProduct(vec) / (vec.Len() * this->Len())); 
}

//=======================================================================
