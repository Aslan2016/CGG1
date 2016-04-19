/// \file Transformation.h
/// \brief creates a namespace and defines its functions for matrix transformations
/// \author Aslan Saparov

#ifndef _TRANSFORMATIONS_H_
#define _TRANSFORMATIONS_H_

//File Includes
#include "Matrix.h"

//Header Contents
namespace Transformation
{
	//Returns a Scale Matrix
	Matrix Scaling ( float _XPoint, float _YPoint, float _ZPoint );

	Matrix Scaling ( Vector _ScalingFactors );

	//Returns a Matrix storing Rotation about X
	Matrix RotationX ( float _RotFactor );

	//Returns a Matrix storing Rotation about Y
	Matrix RotationY ( float _RotFactor );

	//Returns a Matrix storing Rotation about Z
	Matrix RotationZ ( float _RotFactor );

	//Returns a Translation Matrix
	Matrix Translation ( float _XPoint, float _YPoint, float _ZPoint );

	Matrix Translation ( Vector _TranslatingFactors );
}

#endif // _TRANSFORMATIONS_H_