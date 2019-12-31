#pragma once
class Shape {
public:
	virtual ~Shape() = default;
	virtual void Scale(float scalar) = 0;
	virtual void Display() const = 0;
};

class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	virtual void ShowArea() const = 0;
	bool operator>(const Shape2D &rhs) const;
	bool operator<(const Shape2D &rhs) const;
	bool operator==(const Shape2D &rhs) const;
};

class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	virtual void ShowVolume() const = 0;
	bool operator>(const Shape3D &rhs) const;
	bool operator<(const Shape3D &rhs) const;
	bool operator==(const Shape3D & rhs) const;
};

class Square : public Shape2D {
public:
	//Default constructor
	Square() = default;
	//Explicit constructor
	Square(float p_face);
	//Copy
	Square(const Square &d);
	//Operator Overloading
	Square &operator=(const Square &d);
	//Destructor
	virtual ~Square() noexcept = default;
	//Member functions
	void Scale(float scalar) override; //Override tells compiler to check that we are not altering methods that we may mistakenly override
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	float face = 0.0f;
};

class Rectangle : public Shape2D {
public:
	//Default constructor
	Rectangle() = default;
	//Explicit Constructor
	Rectangle(float p_l, float p_w);\
	//Copy
	Rectangle(const Rectangle &d);
	//Operator Overloading
	Rectangle &operator=(const Rectangle &d);
	//Destructor
	virtual ~Rectangle() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	//Length and Width
	float l = 0.0f;
	float w = 0.0f;
};

class Triangle : public Shape2D {
public:
	//Default constructor
	Triangle() = default;
	//Explicit constructor
	Triangle(float p_b, float p_h);
	//Copy constructors
	Triangle(const Triangle &d);
	//Opertor overloading
	Triangle &operator=(const Triangle &d);
	//Destructor
	virtual ~Triangle() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	//Base and Height
	float h = 0.0f;
	float b = 0.0f;
};

class Circle : public Shape2D {
public:
	//Default constructor
	Circle() = default;
	//Explicit constructor
	Circle(float p_r);
	//Copy constructors
	Circle(const Circle &d);
	//Operator overloading
	Circle &operator=(const Circle &d);
	//Destructor
	virtual ~Circle() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	//Radius
	float r = 0.0f;
};

class Ellipse : public Shape2D {
public:
	//Default constructor
	Ellipse() = default;
	//Explicit constructor
	Ellipse(float p_l, float p_w);
	//Copy constructors
	Ellipse(const Ellipse &d);
	//Operator overloading
	Ellipse &operator=(const Ellipse &d);
	//Destructor
	virtual ~Ellipse() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	//Length and Width
	float l = 0.0f;
	float w = 0.0f;
};

class Trapezoid : public Shape2D {
public:
	//Default constructor
	Trapezoid() = default;
	//Explicit constructor
	Trapezoid(float p_top, float p_bottom, float p_h);
	//Copy constructors
	Trapezoid(const Trapezoid &d);
	//Operator overloading
	Trapezoid &operator=(const Trapezoid &d);
	//Destructor
	virtual ~Trapezoid() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	//Top, bottom, and height
	float top = 0.0f;
	float bottom = 0.0f;
	float h = 0.0f;
};

class Sector : public Shape2D {
public:
	//Default constructor
	Sector() = default;
	//Explicit constructor
	Sector(float p_r, float p_theta);
	//Copy constructors
	Sector(const Sector &d);
	//Operator overloading
	Sector &operator=(const Sector &d);
	//Destructor
	virtual ~Sector() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Area() const override;
	virtual void ShowArea() const override;
private:
	float r = 0.0f;
	float theta = 0.0f;
};

class TriangularPyramid : public Shape3D {
public:
	//Default constructor
	TriangularPyramid() = default;
	//Explicit constructor
	TriangularPyramid(float p_h, float p_bw, double p_bl);
	//Copy constructor
	TriangularPyramid(const TriangularPyramid &d);
	//Operator overloading
	TriangularPyramid &operator=(const TriangularPyramid &d);
	//Destructor
	virtual ~TriangularPyramid() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Volume() const override;
	virtual void ShowVolume() const override;
private:
	//Height, base width, base length
	float h = 0.0f;
	float bw = 0.0f;
	double bl = 0.0;
};

class RectangularPyramid : public Shape3D {
public:
	//Default constructor
	RectangularPyramid() = default;
	//Explicit constructor
	RectangularPyramid(float p_l, float p_w, float p_h); //h,w,l
	//Copy constructor
	RectangularPyramid(const RectangularPyramid &d);
	//Operator overloading
	RectangularPyramid &operator=(const RectangularPyramid &d);
	//Destructor
	virtual ~RectangularPyramid() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Volume() const override;
	virtual void ShowVolume() const override;
private:
	//Height, width, length
	float l = 0.0f;
	float w = 0.0f;
	float h =  0.0f;
};

class Cylinder : public Shape3D {
public:
	//Default constructor
	Cylinder() = default;
	//Explicit constructor
	Cylinder(float p_h, float p_r);
	//Copy constructors
	Cylinder(const Cylinder &d);
	//Operator overloading
	Cylinder &operator=(const Cylinder &d);
	//Destructor
	virtual ~Cylinder() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Volume() const override;
	virtual void ShowVolume() const override;
private:
	//Height and radius
	float h = 0.0f;
	float r = 0.0f;
};

class Sphere : public Shape3D {
public:
	//Default constructor
	Sphere() = default;
	//Explicit constructor
	Sphere(float p_r);
	//Copy constructor
	Sphere(const Sphere &d);
	//Operator overloading
	Sphere &operator=(const Sphere &d);
	//Destructor
	virtual ~Sphere() noexcept = default;
	//Member functions
	void Scale(float scalar) override;
	void Display() const override;
	virtual float Volume() const override;
	virtual void ShowVolume() const override;
private:
	//Radius
	float r = 0.0f;
};