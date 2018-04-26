#include <iostream>
#include "Vecror2D.h"

using namespace std;

class Matrix2D{
public:
    int a;
    int b;
    int c;
    int d;
    Matrix2D() = default;
    Matrix2D(int x1, int y1, int x2, int y2){
        a = x1;
        b = y1;
        c = x2;
        d = y2;
    }

    Matrix2D operator* (int a);
    Vector2D operator* (Vector2D& v);
    Matrix2D operator* (Matrix2D& m);
    Matrix2D operator+ (Matrix2D& m);
    Matrix2D operator- (Matrix2D& m);
    int determinant();

    friend ostream& operator<<(ostream& os, Matrix2D& m);
    friend istream& operator>>(istream& is, Matrix2D& m);
};

Matrix2D Matrix2D::operator* (int arg) {
    Matrix2D* matrix2D = new Matrix2D(a * arg, b * arg, c * arg, d * arg);
    return *matrix2D;
}

Vector2D Matrix2D::operator*(Vector2D &v) {
    Vector2D* vector2D = new Vector2D(a * v.getX() + b * v.getY(), c * v.getX() + d * v.getY());
    return *vector2D;
}

int Matrix2D::determinant() {
    return a * b - c * d;
}

Matrix2D Matrix2D::operator*(Matrix2D& m) {
    int a3 = a * m.a + b * m.c;
    int b3 = a * m.b + b * m.d;
    int c3 = c * m.a + d * m.c;
    int d3 = c * m.b + d * m.d;
    return Matrix2D(a3, b3, c3, d3);
}

Matrix2D Matrix2D::operator+(Matrix2D &m) {
    return Matrix2D(a + m.a, b + m.b, c + m.c, d + m.d);
}

Matrix2D Matrix2D::operator-(Matrix2D &m) {
    return Matrix2D(a - m.a, b - m.b, c - m.c, d - m.d);
}

ostream& operator<<(ostream& os, Matrix2D& m) {
    os << m.a << ' ' << m.b << '\n' << m.c << ' ' << m.d << endl;
    return os;
}

istream& operator>>(istream& is, Matrix2D& m){
    int a, b, c, d;
    is >> a >> b >> c >> d;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;
    return is;
}

