/// @file Transformation.cpp
/// @brief Defines functions of a Transformation namespace

#include "Transformation.h"

// Module Contents


//Returns a Scale Matrix
Matrix Transformation::Scaling ( float _XPoint, float _YPoint, float _ZPoint )
{
	Matrix ScaleMatrix;

	//Calls the function written in Matrix class
	ScaleMatrix.Scale ( _XPoint, _YPoint, _ZPoint );

	return ScaleMatrix;
}

Matrix Transformation::Scaling ( Vector _ScalingFactors )
{
	//Calls the function above
	return Scaling ( _ScalingFactors.x, _ScalingFactors.y, _ScalingFactors.z );
}

//Returns a Matrix storing Rotation about X
Matrix Transformation::RotationX ( float _RotFactor )
{
	Matrix RotationMatrix;

	//Calls the function written in Matrix class
	RotationMatrix.RotationX ( _RotFactor );

	return RotationMatrix;
}

//Returns a Matrix storing Rotation about Y
Matrix Transformation::RotationY ( float _RotFactor )
{
	Matrix RotationMatrix;

	//Calls the function written in Matrix class
	RotationMatrix.RotationY ( _RotFactor );

	return RotationMatrix;
}

//Returns a Matrix storing Rotation about Z
Matrix Transformation::RotationZ ( float _RotFactor )
{
	Matrix RotationMatrix;

	//Calls the function written in Matrix class
	RotationMatrix.RotationZ ( _RotFactor );

	return RotationMatrix;
}

//Returns a Translation Matrix
Matrix Transformation::Translation ( float _XPoint, float _YPoint, float _ZPoint )
{
	Matrix TranslationMatrix;

	//Calls the function written in Matrix class
	TranslationMatrix.Translate ( _XPoint, _YPoint, _ZPoint );

	return TranslationMatrix;
}

Matrix Transformation::Translation ( Vector _TranslatingFactors )
{
	//Calls the function above
	return Translation ( _TranslatingFactors.x, _TranslatingFactors.y, _TranslatingFactors.z );
}