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

    bool operator== (const Vector2D& v2);

    bool operator!= (const Vector2D& v2);

    Vector2D operator+ (const Vector2D& v2);

    Vector2D operator- (const Vector2D& v2);

    friend int operator*(Vector2D& v1, Vector2D& v2);

    Vector2D operator* (int a);

    Vector2D operator* (Matrix2D& m);
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
    int get(string s) const{
        if (s == "a"){
            return a;
        }
        if (s == "b"){
            return b;
        }
        if (s == "c"){
            return c;
        }
        if (s == "d"){
            return d;
        }
    }
    int set(const string &s, int arg) {
        if (s == "a"){
             a = arg;
        }
        if (s == "b"){
            b = arg;
        }
        if (s == "c"){
            c = arg;
        }
        if (s == "d"){
            d = arg;
        }
    }
    Matrix2D operator* (int a);
    Vector2D operator* (Vector2D& v);
    Matrix2D operator* (Matrix2D& m);
    Matrix2D operator+ (Matrix2D& m);
    Matrix2D operator- (Matrix2D& m);
    friend Matrix2D operator*(int a, Matrix2D& m);

    bool operator==(const Matrix2D &rhs) const;

    bool operator!=(const Matrix2D &rhs) const;

    int determinant();

    friend ostream& operator<<(ostream& os, const Matrix2D& m);
    friend istream& operator >> (istream& is, Matrix2D& m);
};

Matrix2D Matrix2D::operator* (int arg) {
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

int Matrix2D::determinant() {
    return a * d - c * b;
}

Matrix2D Matrix2D::operator*(Matrix2D& m) {
    int a3 = a * m.get("a") + b * m.get("c");
    int b3 = a * m.get("b") + b * m.get("d");
    int c3 = c * m.get("a") + d * m.get("c");
    int d3 = c * m.get("b") + d * m.get("d");
    return Matrix2D(a3, b3, c3, d3);
}

Matrix2D Matrix2D::operator+(Matrix2D &m) {
    return Matrix2D(a + m.get("a"), b + m.get("b"), c + m.get("c"), d + m.get("d"));
}

Matrix2D Matrix2D::operator-(Matrix2D &m) {
    return Matrix2D(a - m.get("a"), b - m.get("b"), c - m.get("c"), d - m.get("d"));
}

ostream& operator<<(ostream& os, const Matrix2D& m) {
    os << m.get("a") << ' ' << m.get("b") << '\n' << m.get("c") << ' ' << m.get("d") << endl;
    return os;
}

istream& operator >> (istream& is, Matrix2D& m) {
    int a, b, c, d;
    is >> a >> b >> c >> d;
    m.set("a", a);
    m.set("b", b);
    m.set("c", c);
    m.set("d", d);
    return is;
}

bool Matrix2D::operator==(const Matrix2D &rhs) const {
    return a == rhs.get("a") &&
           b == rhs.get("b") &&
           c == rhs.get("c") &&
           d == rhs.get("d");
}

bool Matrix2D::operator!=(const Matrix2D &rhs) const {
    return !(rhs == *this);
}

//----------------------------------------------

Vector2D Vector2D::operator*(Matrix2D& m) {
    Vector2D* vector2D = new Vector2D(m.get("a") * x + m.get("c") * y, m.get("b") * x + m.get("d") * y);
    return *vector2D;
}

Vector2D::Vector2D(int x, int y) {
    this->x = x;
    this->y = y;
}

ostream& operator<<(ostream &os, const Vector2D &v) {
    os << '(' << v.getX() << "; " << v.getY() << ')';
    return  os;
}

bool Vector2D::operator==(const Vector2D &v2) {
    return this->getX() == v2.getX() && this->getY() == v2.getY();
}

bool Vector2D::operator!=(const Vector2D &v2) {
    return !(*this == v2);
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

istream& operator >> (std::istream &is, Vector2D &v) {
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

int operator*(Vector2D &v1, Vector2D &v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}
