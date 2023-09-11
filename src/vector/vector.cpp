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

double Vector::Len () const
{
    double len = this->ScalarProduct(*this);
    
    len = sqrt(len);

    return len;
}

//=======================================================================


Vector Vector::Normalization () const
{
    double len = this->Len();

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
