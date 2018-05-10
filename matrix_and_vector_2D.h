#include <iostream>

using namespace std;

class Matrix2D;

class Vector2D
{
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

	friend ostream& operator<<(ostream& os, Vector2D& v);

	friend istream& operator >> (istream& is, Vector2D& v);

	bool operator== (const Vector2D& v2);

	bool operator!= (const Vector2D& v2);

	Vector2D operator+ (const Vector2D& v2);

	Vector2D operator- (const Vector2D& v2);

	friend int scal_mult(Vector2D& v1, Vector2D& v2);

	Vector2D operator* (int a);

	Vector2D operator* (Matrix2D& m);
};

class Matrix2D {
public:
	int a;
	int b;
	int c;
	int d;
	Matrix2D() = default;
	Matrix2D(int x1, int y1, int x2, int y2) {
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
	friend istream& operator >> (istream& is, Matrix2D& m);
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

istream& operator >> (istream& is, Matrix2D& m) {
	int a, b, c, d;
	is >> a >> b >> c >> d;
	m.a = a;
	m.b = b;
	m.c = c;
	m.d = d;
	return is;
}

//----------------------------------------------

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

int scal_mult(Vector2D &v1, Vector2D &v2) {
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}
