/// \file Vector.h
/// \brief creates a class for a 4D Vector
/// \author Aslan Saparov

#ifndef _VECTOR_H_
#define _VECTOR_H_

//File Includes
#include "math.h"
#include "iostream"
#include "iomanip"

//Header Contents

//Vector Class
class Vector
{
public:
	//Vector x, y, z, w components
	float x;
	float y;
	float z;
	float w;

	//Vector class constructor
	Vector ( float _X = 0.0f, float _Y = 0.0f, float _Z = 0.0f, float _W = 0.0f );

	//Vector class destructor
	~Vector ();

	//operator+ overloaded function
	Vector operator+ ( const Vector _Vector2 );

	//operator- overloaded function
	Vector operator- ( const Vector _Vector2 );

	//operator* overloaded function
	Vector operator* ( const float _Value );

	//operator/ overloaded function
	Vector operator/ ( const float _Value );

	//Calculates a Dot Product of two Vectors
	float DotProduct ( Vector _Vector2 );

	//Calculates a Cross Product of two Vectors
	void CrossProduct ( Vector _Vector2 );

	//Calculates magnitude
	float getMagnitude ();

	//Normalises a vector
	void NormaliseVector ();

	//Prints out all vector components
	void PrintVector ();
};

#endif // _VECTOR_H_