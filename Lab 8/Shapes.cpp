#include "Shapes.h"
#include <iostream>
using namespace std;
const float PI = 3.14159f;
//Operator overloading
bool Shape2D::operator>(const Shape2D &rhs) const {
	return Area() > rhs.Area();
}

bool Shape2D::operator<(const Shape2D &rhs) const {
	return Area() < rhs.Area();
}

bool Shape2D::operator==(const Shape2D &rhs) const {
	return Area() == rhs.Area();
}
//Operator overloading 3D
bool Shape3D::operator>(const Shape3D &rhs) const {
	return Volume() > rhs.Volume();
}

bool Shape3D::operator<(const Shape3D &rhs) const {
	return Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D &rhs) const {
	return Volume() == rhs.Volume();
}

Square::Square(float p_face) {
	face = p_face;
}

Square::Square(const Square &d) {
	face = d.face;
}

Square &Square::operator=(const Square &d) {
	Square holder(d);
	*this = move(holder);
	return *this;
}

void Square::Scale(float scalar) {
	face = face * scalar;
}

void Square::Display() const {
	ShowArea();
	cout << "Length of side: " << face << endl;
}

float Square::Area() const {
	float area = face * face;
	return area;
}

void Square::ShowArea() const {
	cout << "The area of the Square is : " << Area() << endl;
}

Rectangle::Rectangle(float p_l, float p_w) {
	l = p_l;
	w = p_w;
}

Rectangle::Rectangle(const Rectangle &d) {
	l = d.l;
	w = d.w;
}

Rectangle &Rectangle::operator=(const Rectangle &d) {
	Rectangle holder(d);
	*this = move(holder);
	return *this;
}

void Rectangle::Scale(float scalar) {
	l = l * scalar;
	w = w * scalar;
}

void Rectangle::Display() const {
	ShowArea();
	cout << "Length: " << l << endl;
	cout << "Width: " << w << endl;
}

float Rectangle::Area() const {
	float area = l * w;
	return area;
}

void Rectangle::ShowArea() const
{
	cout << "The area of the Rectangle is : " << Area() << endl;
}

Triangle::Triangle(float p_b, float p_h) {
	h = p_h;
	b = p_b;
}

Triangle::Triangle(const Triangle &d) {
	h = d.h;
	b = d.b;
}

Triangle &Triangle::operator=(const Triangle &d) {
	Triangle holder(d);
	*this = move(holder);
	return *this;
}

void Triangle::Scale(float scalar) {
	h = h * scalar;
	b = b * scalar;
}

void Triangle::Display() const {
	ShowArea();
	cout << "Base: " << b << endl;
	cout << "Height: " << h << endl;
}

float Triangle::Area() const {
	float area = h * b * 0.5f;
	return area;
}

void Triangle::ShowArea() const {
	cout << "The area of the Triangle is : " << Area() << endl;
}

Circle::Circle(float p_r) {
	r = p_r;
}

Circle::Circle(const Circle &d) {
	r = d.r;
}

Circle &Circle::operator=(const Circle &d) {
	Circle holder(d);
	*this = move(holder);
	return *this;
}

void Circle::Scale(float scalar) {
	r = r * scalar;
}

void Circle::Display() const {
	ShowArea();
	cout << "Radius: " << r << endl;
}

float Circle::Area() const {
	float area = (r * r * PI);
	return area;
}

void Circle::ShowArea() const {
	cout << "The area of the Circle is : " << Area() << endl;
}

Ellipse::Ellipse(float p_l, float p_w) {
	l = p_l;
	w = p_w;
}

Ellipse::Ellipse(const Ellipse &d) {
	l = d.l;
	w = d.w;
}

Ellipse &Ellipse::operator=(const Ellipse &d) {
	Ellipse holder(d);
	*this = move(holder);
	return *this;
}

void Ellipse::Scale(float scalar) {
	l = l * scalar;
	w = w * scalar;
}

void Ellipse::Display() const {
	ShowArea();
	cout << "Length of semi-major axis: " << l << endl;
	cout << "Length of semi-minor axis: " << w << endl;
}

float Ellipse::Area() const {
	float area = (l * w * PI);
	return area;
}

void Ellipse::ShowArea() const {
	cout << "The area of the Ellipse is : " << Area() << endl;
}

Trapezoid::Trapezoid(float p_top, float p_bottom, float p_h) {
	top = p_top;
	bottom = p_bottom;
	h = p_h;
}

Trapezoid::Trapezoid(const Trapezoid &d) {
	top = d.top;
	bottom = d.bottom;
	h = d.h;
}

Trapezoid &Trapezoid::operator=(const Trapezoid &d) {
	Trapezoid holder(d);
	*this = move(holder);
	return *this;
}

void Trapezoid::Scale(float scalar) {
	top = top * scalar;
	bottom = bottom * scalar;
	h = h * scalar;
}

void Trapezoid::Display() const {
	ShowArea();
	cout << "Length of side A: " << top << endl;
	cout << "Length of side B: " << bottom << endl;
	cout << "Height: " << h << endl;
}

float Trapezoid::Area() const {
	float area = (top + bottom) * h * 0.5f;
	return area;
}

void Trapezoid::ShowArea() const {
	cout << "The area of the Trapezoid is : " << Area() << endl;
}

Sector::Sector(float p_r, float p_theta) {
	r = p_r;
	theta = p_theta;
}

Sector::Sector(const Sector &d) {
	r = d.r;
	theta = d.theta;
}

Sector &Sector::operator=(const Sector &d) {
	Sector holder(d);
	*this = move(holder);
	return *this;
}

void Sector::Scale(float scalar) {
	r = r * scalar;
	theta = theta * scalar;
}

void Sector::Display() const {
	ShowArea();
	cout << "Radius: " << r << endl;
	cout << "Angle in radians: " << theta * PI / 180 << endl;
	cout << "Angle in degrees: " << theta << endl;
}

float Sector::Area() const {
	float area = (theta * PI / 180) * r * r * 0.5f;
	return area;
}

void Sector::ShowArea() const {
	cout << "The area of the Sector is : " << Area() << endl;
}

TriangularPyramid::TriangularPyramid(float p_h, float p_bw, double p_bl) {
	h = p_h;
	bw = p_bw;
	bl = p_bl;
}

TriangularPyramid::TriangularPyramid(const TriangularPyramid &d) {
	h = d.h;
	bw = d.bw;
	bl = d.bl;
}

TriangularPyramid &TriangularPyramid::operator=(const TriangularPyramid &d) {
	TriangularPyramid holder(d);
	*this = move(holder);
	return *this;
}

void TriangularPyramid::Scale(float scalar) {
	h = h *scalar;
	bw = bw * scalar;
	bl = bl * scalar;
}

void TriangularPyramid::Display() const {
	ShowVolume();
	cout << "The height is: " << h << endl;
	cout << "The area of the Triangle is : " << bw * static_cast<float>(bl) * 0.5f << endl;
	cout << "Base: " << bw << endl;
	cout << "Height: " << bl << endl;
}

float TriangularPyramid::Volume() const {
	const float areaOfBase = bw * static_cast<float>(bl) * 0.5f;
	const float volume = 0.33333333333f * (areaOfBase) * h;
	return volume;
}

void TriangularPyramid::ShowVolume() const {
	cout << "The volume of the Triangular Pyramid is : " << Volume() << endl;
}

RectangularPyramid::RectangularPyramid(float p_h, float p_w, float p_l) {
	l = p_l;
	w = p_w;
	h = p_h;
}

RectangularPyramid::RectangularPyramid(const RectangularPyramid &d) {
	l = d.l;
	w = d.w;
	h = d.h;
}

RectangularPyramid &RectangularPyramid::operator=(const RectangularPyramid &d) {
	RectangularPyramid holder(d);
	*this = move(holder);
	return *this;
}

void RectangularPyramid::Scale(float scalar) {
	l = l * scalar;
	w = w * scalar;
	h = h * scalar;
}

void RectangularPyramid::Display() const {
	ShowVolume();
	cout << "The height is: " << h << endl;
	cout << "The area of the Rectangle is : " << (w * l) << endl;
	cout << "Length: " << w << endl;
	cout << "Width: " << l << endl;
}

float RectangularPyramid::Volume() const {
	float volume = 0.3333333333f * l * w * h;
	return volume;
}

void RectangularPyramid::ShowVolume() const
{
	cout << "The volume of the Rectangular Pyramid is : " << Volume() << endl;
}

Cylinder::Cylinder(float p_h, float p_r) {
	h = p_h;
	r = p_r;
}

Cylinder::Cylinder(const Cylinder &d) {
	h = d.h;
	r = d.r;
}

Cylinder &Cylinder::operator=(const Cylinder &d) {
	Cylinder holder(d);
	*this = move(holder);
	return *this;
}

void Cylinder::Scale(float scalar) {
	h = h * scalar;
	r = r * scalar;
}

void Cylinder::Display() const {
	ShowVolume();
	cout << "The height is: " << h << endl;
	cout << "The area of the Circle is : " << PI * r * r << endl;
	cout << "Radius: " << r << endl;
}

float Cylinder::Volume() const {
	float volume = PI * r * r * h;
	return volume;
}

void Cylinder::ShowVolume() const {
	cout << "The volume of the Cylinder is : " << Volume() << endl;
}

Sphere::Sphere(float p_r) {
	r = p_r;
}

Sphere::Sphere(const Sphere &d) {
	r = d.r;
}

Sphere &Sphere::operator=(const Sphere &d) {
	Sphere holder(d);
	*this = move(holder);
	return *this;
}

void Sphere::Scale(float scalar) {
	r = r * scalar;
}

void Sphere::Display() const {
	ShowVolume();
	cout << "The area of the Circle is : " << r * PI * r << endl;
	cout << "Radius: " << r << endl;
}

float Sphere::Volume() const {
	return 1.333333333333f * PI * r * r * r;
}

void Sphere::ShowVolume() const {
	cout << "The volume of the Sphere is : " << Volume() << endl;
}