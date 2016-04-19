/// \file Matrix.h
/// \brief creates a class for a 4x4 Matrix
/// \author Aslan Saparov

#ifndef _MATRIX_H_
#define _MATRIX_H_

//File Includes
#include "Vector.h"

//Header Contents

//Matrix Class
class Matrix
{
public:
	
	float matrix [ 16 ];///<Matrix array

	Matrix ( float _matrixArray [ 16 ] = 0 );///<Matrix class constructor

	~Matrix ();///<Matrix class destructor
	
	///
	/// 
	/// \param Matrix
	/// \return Matrix
	///
	Matrix operator+ ( Matrix _matrix2 ); ///<operator+ overloaded function

	///
	/// \brief minus a matrix from a matrix
	/// \param Matrix
	/// \return Matrix
	///
	/// Subtracting each entry of one matrix from each matrix from another
	///
	Matrix operator- ( Matrix _matrix2 );

	///operator* overloaded function
	Matrix operator* ( const float _coefficient );

	///operator/ overloaded function
	Matrix operator/ ( const float _coefficient );

	///operator* overloaded function
	Vector operator* ( const Vector _vector2 );

	///operator* overloaded function
	Matrix operator* ( const Matrix _matrix2 );

	///operator= overloaded function
	Matrix operator= ( const float _matrixArray [ 16 ] );

	///Transposes a Matrix
	void Transpose ();

	///Returns a Determinant
	/// \return Determinant
	float getDeterminant ();

	///Inverses a Matrix. Returns false if the Determinant of a Matrix equals 0
	bool Inverse ();

	///Sets all matrix entries to be zero
	void ZeroMatrix ();

	///Sets a matrix to be an Identity Matrix
	void Identity ();

	///Sets a matrix to be a Perspective Matrix
	void Perspective ( float _FOV, float _AspectRatio, float _ZNear, float _ZFar );

	///Sets a matrix to be a Scale Matrix
	void Scale ( float _XPoint, float _YPoint, float _ZPoint );

	void Scale ( Vector _ScalingFactors );

	///Sets a matrix to store rotation about X
	void RotationX ( float _RotFactor );

	///Sets a matrix to store rotation about Y
	void RotationY ( float _RotFactor );

	///Sets a matrix to store rotation about Z
	void RotationZ ( float _RotFactor );

	///Sets a matrix to be Translate Matrix
	void Translate ( float _XPoint, float _YPoint, float _ZPoint );

	void Translate ( Vector _TranslatingFactors );

	///Prints out a matrix
	void PrintMatrix ();
};

#endif // _MATRIX_H_