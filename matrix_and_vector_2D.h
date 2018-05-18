#include <iostream>

using namespace std;

class Matrix2D;

class Vector2D
{
private:
    int x;
    int y;
public:
    Vector2D() = default;
    Vector2D(int x, int y);

    int getX() const { return this->x; }
    int getY() const { return this->y; }

    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }

    friend ostream& operator<<(ostream& os, const Vector2D& v);

    friend istream& operator >> (istream& is, Vector2D& v);

    bool operator== (const Vector2D& v2) const ;

    bool operator!= (const Vector2D& v2) const ;

    Vector2D operator+ (const Vector2D& v2);

    Vector2D operator- (const Vector2D& v2);

    int operator*(Vector2D& v1) const;

    Vector2D operator* (int a);
};

class Matrix2D {
private:
    int a;
    int b;
    int c;
    int d;
public:
    Matrix2D() = default;
    Matrix2D(int x1, int y1, int x2, int y2) {
        a = x1;
        b = y1;
        c = x2;
        d = y2;
    }
    int getA() const{
        return a;
    }
    int getB() const{
        return b;
    }
    int getC() const{
        return c;
    }
    int getD() const{
        return d;
    }
    void setA(int arg) {
        a = arg;
    }
    void setB(int arg) {
        b = arg;
    }
    void setC(int arg) {
        c = arg;
    }
    void setD(int arg) {
        d = arg;
    }
    Matrix2D operator* (int a) const;
    Vector2D operator* (Vector2D& v);
    Matrix2D operator* (Matrix2D& m) const ;
    Matrix2D operator+ (Matrix2D& m) const ;
    Matrix2D operator- (Matrix2D& m) const ;
    friend Matrix2D operator*(int a, Matrix2D& m);

    bool operator==(const Matrix2D &rhs) const;

    bool operator!=(const Matrix2D &rhs) const;

    int determinant() const ;

    friend ostream& operator<<(ostream& os, const Matrix2D& m);
    friend istream& operator >> (istream& is, Matrix2D& m);
};

Matrix2D Matrix2D::operator* (int arg) const {
    Matrix2D* matrix2D = new Matrix2D(a * arg, b * arg, c * arg, d * arg);
    return *matrix2D;
}
Matrix2D operator* (int arg, Matrix2D& m) {
    return m * arg;
}

Vector2D Matrix2D::operator*(Vector2D &v) {
    Vector2D* vector2D = new Vector2D(a * v.getX() + b * v.getY(), c * v.getX() + d * v.getY());
    return *vector2D;
}

int Matrix2D::determinant() const {
    return a * d - c * b;
}

Matrix2D Matrix2D::operator*(Matrix2D& m) const {
    int a3 = a * m.a + b * m.c;
    int b3 = a * m.b + b * m.d;
    int c3 = c * m.a + d * m.c;
    int d3 = c * m.b + d * m.d;
    return Matrix2D(a3, b3, c3, d3);
}

Matrix2D Matrix2D::operator+(Matrix2D &m) const {
    return Matrix2D(a + m.a, b + m.b, c + m.c, d + m.d);
}

Matrix2D Matrix2D::operator-(Matrix2D &m) const {
    return Matrix2D(a - m.a, b - m.b, c - m.c, d - m.d);
}

ostream& operator<<(ostream& os, const Matrix2D& m) {
    os << m.a << ' ' << m.b << '\n' << m.c << ' ' << m.d << endl;
    return os;
}

istream& operator >> (istream& is, Matrix2D& m) {
    int a, b, c, d;
    is >> a >> b >> c >> d;
    m.setA(a);
    m.setB(b);
    m.setC(c);
    m.setD(d);
    return is;
}

bool Matrix2D::operator==(const Matrix2D &rhs) const {
    return a == rhs.a &&
           b == rhs.b &&
           c == rhs.c &&
           d == rhs.d;
}

bool Matrix2D::operator!=(const Matrix2D &rhs) const {
    return !(rhs == *this);
}

//----------------------------------------------

Vector2D::Vector2D(int x, int y) {
    this->x = x;
    this->y = y;
}

ostream& operator<<(ostream &os, const Vector2D &v) {
    os << '(' << v.getX() << "; " << v.getY() << ')';
    return  os;
}

bool Vector2D::operator==(const Vector2D &v2) const {
    return this->x == v2.x && this->y == v2.y;
}

bool Vector2D::operator!=(const Vector2D &v2) const {
    return !(*this == v2);
}

Vector2D Vector2D::operator+(const Vector2D &v2) {
    Vector2D res;
    res.setX(this->x + v2.x);
    res.setY(this->y + v2.y);
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

istream& operator >> (std::istream &is, Vector2D &v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

Vector2D Vector2D::operator-(const Vector2D &v2) {
    Vector2D res;
    res.setX(this->x - v2.x);
    res.setY(this->y - v2.y);
    return res;
}

int Vector2D::operator*(Vector2D &v1) const{
    return v1.x * x + v1.y * y;
}
