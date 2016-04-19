/// @file Vector.cpp
/// @brief Defines functions of a Vector class

#include "Vector.h"

// Module Contents

// Vector constructor initialises its components ( x, y, z, w )
Vector::Vector ( float _X, float _Y, float _Z, float _W )
{
	x = _X;
	y = _Y;
	z = _Z;
	w = _W;
}

// Vector destructor
Vector::~Vector ()
{

}

//operator+ overloaded function
Vector Vector::operator+ ( const Vector _Vector2 )
{
	Vector vector1;

	vector1.x = x + _Vector2.x;
	vector1.y = y + _Vector2.y;
	vector1.z = z + _Vector2.z;
	vector1.w = w + _Vector2.w;

	return vector1;
}

//operator- overloaded function
Vector Vector::operator- ( const Vector _Vector2 )
{
	Vector vector1;

	vector1.x = x - _Vector2.x;
	vector1.y = y - _Vector2.y;
	vector1.z = z - _Vector2.z;
	vector1.w = w - _Vector2.w;

	return vector1;
}

//operator* overloaded function
Vector Vector::operator* ( const float _Value )
{
	Vector vector1;

	vector1.x = x * _Value;
	vector1.y = y * _Value;
	vector1.z = z * _Value;
	vector1.w = w * _Value;

	return vector1;
}

//operator/ overloaded function
Vector Vector::operator/ ( const float _Value )
{
	Vector vector1;

	vector1.x = x / _Value;
	vector1.y = y / _Value;
	vector1.z = z / _Value;
	vector1.w = w / _Value;

	return vector1;
}

//Returns a Dot Product as a float
float Vector::DotProduct ( Vector _Vector2 )
{
	float DotProductResult = 0.0f;

	DotProductResult = ( x * _Vector2.x ) + ( y * _Vector2.y ) + ( z * _Vector2.z ) + ( w * _Vector2.w );

	return DotProductResult;
}

//Calculates a Cross Product Vector
void Vector::CrossProduct ( Vector _Vector2 )
{
	float TempX = x;
	float TempY = y;
	float TempZ = z;

	x = ( TempY * _Vector2.z - TempZ * _Vector2.y );
	y = -( TempX * _Vector2.z - TempZ * _Vector2.x );
	z = ( TempX * _Vector2.y - TempY * _Vector2.x );
	w = 1;
}

//Normalises Vector components
void Vector::NormaliseVector ()
{
	float magnitude = sqrt ( pow ( x, 2 ) + pow ( y, 2 ) + pow ( z, 2 ) );

	x = x/magnitude;
	y = y/magnitude;
	z = z/magnitude;
}

//Returns a magnitude of a Vector
float Vector::getMagnitude ()
{
	return sqrt ( pow ( x, 2 ) + pow ( y, 2 ) + pow ( z, 2 ) );
}

//Prints out all Vector components
void Vector::PrintVector ()
{
	std::cout << "\nVector.x = " << x << std::endl;
	std::cout << "Vector.y = " << y << std::endl;
	std::cout << "Vector.z = " << z << std::endl;
	std::cout << "Vector.w = " << w << "\n" << std::endl;
}