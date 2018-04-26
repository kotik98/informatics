#include <iostream>
#include <math.h>
#include "Matrix2D.h"

using namespace std;

class Vector2D
{
    int x;
    int y;
public:
    Vector2D() = default;
    Vector2D(int x, int y);

    int getX() const { return this->x; }
    int getY() const { return this->y; }

    void setX(int x){
        this->x = x;
        return;
    }
    void setY(int y){
        this->y = y;
        return;
    }

    friend ostream& operator<<(ostream& os, Vector2D& v);

    friend istream& operator>>(istream& is, Vector2D& v);

    bool operator== (const Vector2D& v2);

    bool operator!= (const Vector2D& v2);

    Vector2D operator+ (const Vector2D& v2);

    Vector2D operator- (const Vector2D& v2);

    friend int scal_mult (Vector2D& v1, Vector2D& v2);

    Vector2D operator* (const int a);

    Vector2D operator* (Matrix2D& m);
};

Vector2D Vector2D::operator*(Matrix2D& m) {
    Vector2D* vector2D = new Vector2D(m.a * x + m.c * y, m.b * x + m.d * y);
    return *vector2D;
}

Vector2D::Vector2D(int x, int y) {
    this->x = x;
    this->y = y;
}

ostream& operator<<(ostream &os, Vector2D &v) {
    os << '(' << v.getX() << "; " << v.getY() << ')';
    return  os;
}

bool Vector2D::operator==(const Vector2D &v2) {
    if (this->getX() == v2.getX() && this->getY() == v2.getY()){
        return true;
    }else{
        return false;
    }
}

bool Vector2D::operator!=(const Vector2D &v2) {
    if (*this == v2){
        return false;
    } else{
        return true;
    }
}

Vector2D Vector2D::operator+(const Vector2D &v2) {
    Vector2D res;
    res.setX(this->getX() + v2.getX());
    res.setY(this->getX() + v2.getY());
    return res;
}

Vector2D Vector2D::operator*(const int a) {
    Vector2D res;
    res.setX(x * a);
    res.setY(y * a);
    return  res;
}

Vector2D operator* (int a, const Vector2D& v) {
    Vector2D res;
    res.setX(v.getX() * a);
    res.setY(v.getY() * a);
    return res;
}

istream& operator>>(std::istream &is, Vector2D &v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

Vector2D Vector2D::operator-(const Vector2D &v2) {
    Vector2D res;
    res.setX(this->getX() - v2.getX());
    res.setY(this->getX() - v2.getY());
    return res;
}

int scal_mult(Vector2D &v1, Vector2D &v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}
