/// @file Matrix.cpp
/// @brief Defines functions of a Matrix class

#include "Matrix.h"

#define M_PI 3.14159265359f

// Module Contents

// Matrix class constructor initialises its entries
Matrix::Matrix ( float _matrixArray [ 16 ] )
{
	for ( int i = 0; i < 16; ++i )
	{
		if ( _matrixArray == 0 )
		{
			matrix [ i ] = 0;
		}
		else
		{
			matrix [ i ] = _matrixArray [ i ];
		}
	}
}

// Matrix class destructor
Matrix::~Matrix ()
{

}

//operator+ overloaded function
Matrix Matrix::operator+ ( const Matrix _matrix2 )
{
	Matrix AdditionResult;

	for ( int i = 0; i < 16; ++i )
	{
		AdditionResult.matrix [ i ] = matrix [ i ] + _matrix2.matrix [ i ];
	}

	return AdditionResult;
}

//operator- overloaded function
Matrix Matrix::operator- ( const Matrix _matrix2 )
{
	Matrix SubtractionResult;

	for ( int i = 0; i < 16; ++i )
	{
		SubtractionResult.matrix [ i ] = matrix [ i ] - _matrix2.matrix [ i ];
	}

	return SubtractionResult;
}

//operator* overloaded function
Matrix Matrix::operator* ( const float _coefficient )
{
	Matrix MultiplicationResult;

	for ( int i = 0; i < 16; ++i )
	{
		MultiplicationResult.matrix [ i ] = matrix [ i ] * _coefficient;
	}

	return MultiplicationResult;
}

//operator/ overloaded function
Matrix Matrix::operator/ ( const float _coefficient )
{
	Matrix DivisionResult;

	for ( int i = 0; i < 16; ++i )
	{
		DivisionResult.matrix [ i ] = matrix [ i ] / _coefficient;
	}

	return DivisionResult;
}

//operator* overloaded function
Vector Matrix::operator* ( const Vector _vector2 )
{
	Vector MultiplicationResult;

	MultiplicationResult.x = matrix [ 0 ] * _vector2.x + matrix [ 4 ] * _vector2.y 
						   + matrix [ 8 ] * _vector2.z + matrix [ 12 ] * _vector2.w;
	
	MultiplicationResult.y = matrix [ 1 ] * _vector2.x + matrix [ 5 ] * _vector2.y 
		                   + matrix [ 9 ] * _vector2.z + matrix [ 13 ] * _vector2.w;
	
	MultiplicationResult.z = matrix [ 2 ] * _vector2.x + matrix [ 6 ] * _vector2.y 
		                   + matrix [ 10 ] * _vector2.z + matrix [ 14 ] * _vector2.w;
	
	MultiplicationResult.w = matrix [ 3 ] * _vector2.x + matrix [ 7 ] * _vector2.y 
		                   + matrix [ 11 ] * _vector2.z + matrix [ 15 ] * _vector2.w;

	return MultiplicationResult;
}

//operator* overloaded function
Matrix Matrix::operator* ( const Matrix _matrix2 )
{
	Matrix MultiplicationResult;
	
	//First column entries of the resultant matrix
	MultiplicationResult.matrix [ 0 ] = matrix [ 0 ] * _matrix2.matrix [ 0 ] + matrix [ 4 ] * _matrix2.matrix [ 1 ] 
								      + matrix [ 8 ] * _matrix2.matrix [ 2 ] + matrix [ 12 ] * _matrix2.matrix [ 3 ];
	
	MultiplicationResult.matrix [ 1 ] = matrix [ 1 ] * _matrix2.matrix [ 0 ] + matrix [ 5 ] * _matrix2.matrix [ 1 ] 
							          + matrix [ 9 ] * _matrix2.matrix [ 2 ] + matrix [ 13 ] * _matrix2.matrix [ 3 ];
	
	MultiplicationResult.matrix [ 2 ] = matrix [ 2 ] * _matrix2.matrix [ 0 ] + matrix [ 6 ] * _matrix2.matrix [ 1 ] 
								      + matrix [ 10 ] * _matrix2.matrix [ 2 ] + matrix [ 14 ] * _matrix2.matrix [ 3 ];
	
	MultiplicationResult.matrix [ 3 ] = matrix [ 3 ] * _matrix2.matrix [ 0 ] + matrix [ 7 ] * _matrix2.matrix [ 1 ] 
									  + matrix [ 11 ] * _matrix2.matrix [ 2 ] + matrix [ 15 ] * _matrix2.matrix [ 3 ];


	//Second column entries of the resultant matrix
	MultiplicationResult.matrix [ 4 ] = matrix [ 0 ] * _matrix2.matrix [ 4 ] + matrix [ 4 ] * _matrix2.matrix [ 5 ] 
								      + matrix [ 8 ] * _matrix2.matrix [ 6 ] + matrix [ 12 ] * _matrix2.matrix [ 7 ];
	
	MultiplicationResult.matrix [ 5 ] = matrix [ 1 ] * _matrix2.matrix [ 4 ] + matrix [ 5 ] * _matrix2.matrix [ 5 ] 
									  + matrix [ 9 ] * _matrix2.matrix [ 6 ] + matrix [ 13 ] * _matrix2.matrix [ 7 ];
	
	MultiplicationResult.matrix [ 6 ] = matrix [ 2 ] * _matrix2.matrix [ 4 ] + matrix [ 6 ] * _matrix2.matrix [ 5 ] 
								      + matrix [ 10 ] * _matrix2.matrix [ 6 ] + matrix [ 14 ] * _matrix2.matrix [ 7 ];
	
	MultiplicationResult.matrix [ 7 ] = matrix [ 3 ] * _matrix2.matrix [ 4 ] + matrix [ 7 ] * _matrix2.matrix [ 5 ] 
									  + matrix [ 11 ] * _matrix2.matrix [ 6 ] + matrix [ 15 ] * _matrix2.matrix [ 7 ];

	//Third column entries of the resultant matrix
	MultiplicationResult.matrix [ 8 ] = matrix [ 0 ] * _matrix2.matrix [ 8 ] + matrix [ 4 ] * _matrix2.matrix [ 9 ] 
									  + matrix [ 8 ] * _matrix2.matrix [ 10 ] + matrix [ 12 ] * _matrix2.matrix [ 11 ];
	
	MultiplicationResult.matrix [ 9 ] = matrix [ 1 ] * _matrix2.matrix [ 8 ] + matrix [ 5 ] * _matrix2.matrix [ 9 ] 
									  + matrix [ 9 ] * _matrix2.matrix [ 10 ] + matrix [ 13 ] * _matrix2.matrix [ 11 ];
	
	MultiplicationResult.matrix [ 10 ] = matrix [ 2 ] * _matrix2.matrix [ 8 ] + matrix [ 6 ] * _matrix2.matrix [ 9 ] 
									   + matrix [ 10 ] * _matrix2.matrix [ 10 ] + matrix [ 14 ] * _matrix2.matrix [ 11 ];
	
	MultiplicationResult.matrix [ 11 ] = matrix [ 3 ] * _matrix2.matrix [ 8 ] + matrix [ 7 ] * _matrix2.matrix [ 9 ] 
									   + matrix [ 11 ] * _matrix2.matrix [ 10 ] + matrix [ 15 ] * _matrix2.matrix [ 11 ];

	//Fourth column entries of the resultant matrix
	MultiplicationResult.matrix [ 12 ] = matrix [ 0 ] * _matrix2.matrix [ 12 ] + matrix [ 4 ] * _matrix2.matrix [ 13 ] 
									   + matrix [ 8 ] * _matrix2.matrix [ 14 ] + matrix [ 12 ] * _matrix2.matrix [ 15 ];
	
	MultiplicationResult.matrix [ 13 ] = matrix [ 1 ] * _matrix2.matrix [ 12 ] + matrix [ 5 ] * _matrix2.matrix [ 13 ] 
									   + matrix [ 9 ] * _matrix2.matrix [ 14 ] + matrix [ 13 ] * _matrix2.matrix [ 15 ];
	
	MultiplicationResult.matrix [ 14 ] = matrix [ 2 ] * _matrix2.matrix [ 12 ] + matrix [ 6 ] * _matrix2.matrix [ 13 ] 
									   + matrix [ 10 ] * _matrix2.matrix [ 14 ] + matrix [ 14 ] * _matrix2.matrix [ 15 ];
	
	MultiplicationResult.matrix [ 15 ] = matrix [ 3 ] * _matrix2.matrix [ 12 ] + matrix [ 7 ] * _matrix2.matrix [ 13 ] 
									   + matrix [ 11 ] * _matrix2.matrix [ 14 ] + matrix [ 15 ] * _matrix2.matrix [ 15 ];

	return MultiplicationResult;
}

//operator= overloaded function
Matrix Matrix::operator= ( const float _matrixArray [ 16 ] )
{
	Matrix NewMatrix;

	for ( int i = 0; i < 16; ++i )
	{
		matrix [ i ] = _matrixArray [ i ];
	}

	return NewMatrix;
}

//Transposes a Matrix
void Matrix::Transpose ()
{
	float temp = 0;

	//Entry 1 and Entry 4
	temp = matrix [ 1 ];

	matrix [ 1 ] = matrix [ 4 ];

	matrix [ 4 ] = temp;

	//Entry 2 and Entry 8
	temp = matrix [ 2 ];

	matrix [ 2 ] = matrix [ 8 ];

	matrix [ 8 ] = temp;

	//Entry 3 and Entry 12
	temp = matrix [ 3 ];

	matrix [ 3 ] = matrix [ 12 ];

	matrix [ 12 ] = temp;

	//Entry 6 and Entry 9
	temp = matrix [ 6 ];

	matrix [ 6 ] = matrix [ 9 ];

	matrix [ 9 ] = temp;

	//Entry 7 and Entry 13
	temp = matrix [ 7 ];

	matrix [ 7 ] = matrix [ 13 ];

	matrix [ 13 ] = temp;

	//Entry 11 and Entry 14
	temp = matrix [ 11 ];

	matrix [ 11 ] = matrix [ 14 ];

	matrix [ 14 ] = temp;
}

//Returns a Determinant
float Matrix::getDeterminant()
{
	return (matrix[0] * (matrix[5] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[13] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]))) 
		- (matrix[4] * (matrix[1] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]))) 
		+ (matrix[8] * (matrix[1] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[5] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]))) 
		- (matrix[12] * (matrix[1] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[5] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[9] * (matrix[2] * matrix[7] - matrix[6] * matrix[3])));
	/*
	
	4x4 matrix
	|0	4	8	12|
	|1	5	9	13|
	|2	6	10	14|
	|3	7	11	15|


		|5	9	13|		  |1	9	13|		  |1	5	13|		   |1	5	 9|
	0 *	|6	10	14| - 4 * |2	10	14| + 8 * |2	6	14| - 12 * |2	6	10|
		|7	11	15|		  |3	11	15|		  |3	7	15|		   |3	7	11|

	1) First 3x3 matrix (0*)
		|10	14|		  |6	14|		   |6 10|
	5 * |11 15| - 9 * |7	15| + 13 * |7 11|

	5 * (10 * 15 - 14 * 11) - 9 * (6 * 15 - 14 * 7) + 13 * (6 * 11 - 10 * 7) = 0;

	2) Second 3x3 matrix (4*)
	    |10	14|		  |2	14|		   |2	10|
	1 *	|11	15| - 9 * |3	15| + 13 * |3	11|

	1 * (10 * 15 - 14 * 11) - 9 * (2 * 15 - 14 * 3) + 13 * (2 * 11 - 10 * 3) = 0;

	3) Third 3x3 matrix (8*)
		|6	14|		  |2	14|		   |2	6|
	1 * |7	15| - 5 * |3	15| + 13 * |3	7|

	1 * (6 * 15 - 14 * 7) - 5 * (2 * 15 - 14 * 3) + 13 * (2 * 7 - 6 * 3) = 0;

	4) Fourth 3x3 matrix (12*)
		|6	10|		  |2	10|		  |2	6|
	1 * |7	11| - 5 * |3	11| + 9 * |3	7|

	1 * (6 * 11 - 10 * 7) - 5 * (2 * 11 - 10 * 3) + 9 * (2 * 7 - 6 * 3) = 0;

	Multiplying determinants of 3x3 matrix by 0, 4, 8 and 12:

	0 * 0 - 4 * 0 + 8 * 0 - 12 * 0 = 0;

	(matrix[0] * (matrix[5] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[13] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]))) - (matrix[4] * (matrix[1] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]))) + (matrix[8] * (matrix[1] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[5] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]))) - (matrix[12] * (matrix[1] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[5] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[9] * (matrix[2] * matrix[7] - matrix[6] * matrix[3])));

	*/
}

//Inverses a Matrix. Returns false if the Determinant of a Matrix equals 0
bool Matrix::Inverse()
{
	bool Passed = false;

	//Checks if the Determinant of a Matrix equals 0
	if ( getDeterminant() != 0 )
	{
		Passed = true;
		Matrix CofactorMatrix;
		float Determinant = getDeterminant ();

		// First Row
		CofactorMatrix.matrix[0] = matrix[5] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[13] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]);

		CofactorMatrix.matrix[4] = -1 * (matrix[1] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]));

		CofactorMatrix.matrix[8] = matrix[1] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[5] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]);

		CofactorMatrix.matrix[12] = -1 * (matrix[1] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[5] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[9] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		// Second Row
		CofactorMatrix.matrix[1] = -1 * (matrix[4] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[8] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[12] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]));

		CofactorMatrix.matrix[5] = matrix[0] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[8] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[12] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]);

		CofactorMatrix.matrix[9] = -1 * (matrix[0] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[4] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[12] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		CofactorMatrix.matrix[13] = matrix[0] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[4] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[8] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]);

		// Third Row
		CofactorMatrix.matrix[2] = matrix[4] * (matrix[9] * matrix[15] - matrix[13] * matrix[11]) - matrix[8] * (matrix[5] * matrix[15] - matrix[13] * matrix[7]) + matrix[12] * (matrix[5] * matrix[11] - matrix[9] * matrix[7]);

		CofactorMatrix.matrix[6] = -1 * (matrix[0] * (matrix[9] * matrix[15] - matrix[13] * matrix[11]) - matrix[8] * (matrix[1] * matrix[15] - matrix[13] * matrix[3]) + matrix[12] * (matrix[1] * matrix[11] - matrix[9] * matrix[3]));

		CofactorMatrix.matrix[10] = matrix[0] * (matrix[5] * matrix[15] - matrix[13] * matrix[7]) - matrix[4] * (matrix[1] * matrix[15] - matrix[13] * matrix[3]) + matrix[12] * (matrix[1] * matrix[7] - matrix[5] * matrix[3]);

		CofactorMatrix.matrix[14] = -1 * (matrix[0] * (matrix[5] * matrix[11] - matrix[9] * matrix[7]) - matrix[4] * (matrix[1] * matrix[11] - matrix[9] * matrix[3]) + matrix[8] * (matrix[1] * matrix[7] - matrix[5] * matrix[3]));

		// Fourth Row
		CofactorMatrix.matrix[3] = -1 * (matrix[4] * (matrix[9] * matrix[14] - matrix[13] * matrix[10]) - matrix[8] * (matrix[5] * matrix[14] - matrix[13] * matrix[6]) + matrix[12] * (matrix[5] * matrix[10] - matrix[9] * matrix[6]));

		CofactorMatrix.matrix[7] = matrix[0] * (matrix[9] * matrix[14] - matrix[13] * matrix[10]) - matrix[8] * (matrix[1] * matrix[14] - matrix[13] * matrix[2]) + matrix[12] * (matrix[1] * matrix[10] - matrix[9] * matrix[2]);

		CofactorMatrix.matrix[11] = -1 * (matrix[0] * (matrix[5] * matrix[14] - matrix[13] * matrix[6]) - matrix[4] * (matrix[1] * matrix[14] - matrix[13] * matrix[2]) + matrix[12] * (matrix[1] * matrix[6] - matrix[5] * matrix[2]));

		CofactorMatrix.matrix[15] = matrix[0] * (matrix[5] * matrix[10] - matrix[9] * matrix[6]) - matrix[4] * (matrix[1] * matrix[10] - matrix[2] * matrix[9]) + matrix[8] * (matrix[1] * matrix[6] - matrix[5] * matrix[2]);

		CofactorMatrix.Transpose();

		for (int i = 0; i < 16; ++i)
		{
			matrix[i] = CofactorMatrix.matrix[i] * 1/Determinant;
		}

		/*
		4x4 matrix
		|0	4	8	12|
		|1	5	9	13|
		|2	6	10	14|
		|3	7	11	15|

		matrix of minors
		| |5	9	13|	|1	9	13| |1	5	13| |1	5	 9| |
		| |6	10	14|	|2	10	14| |2	6	14| |2	6	10| |
		| |7	11	15|	|3	11	15| |3	7	15| |3	7	11| |
		|													|
		| |4	8	12| |0	8	12| |0	4	12| |0	4	 8| |
		| |6	10	14|	|2	10	14| |2	6	14| |2	6	10| |
		| |7	11	15|	|3	11	15| |3	7	15| |3	7	11| |
		|													|
		| |4	8	12| |0	8	12| |0	4	12| |0	4	 8| | 
		| |5	9	13| |1	9	13| |1	5	13| |1	5	 9| |
		| |7	11	15| |3	11	15| |3	7	15| |3	7	11| |
		|													|
		| |4	8	12| |0	8	12| |0	4	12| |0	4	 8| |
		| |5	9	13| |1	9	13| |1	5	13| |1	5	 9| |
		| |6	10	14| |2	10	14| |2	6	14| |2	6	10| |

		// First Row
		0) 5 * (10 * 15 - 14 * 11) - 9 * (6 * 15 - 14 * 7) + 13 * (6 * 11 - 10 * 7) = 0 * positiveOne;
		CofactorMatrix.matrix[0] = 1 * (matrix[5] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[13] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]));

		4) 1 * (10 * 15 - 14 * 11) - 9 * (2 * 15 - 14 * 3) + 13 * (2 * 11 - 10 * 3) = 0 * negativeOne;
		CofactorMatrix.matrix[4] = -1 * (matrix[1] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[9] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]));

		8) 1 * (6 * 15 - 14 * 7) - 5 * (2 * 15 - 14 * 3) + 13 * (2 * 7 - 6 * 3) = 0 * positiveOne;
		CofactorMatrix.matrix[8] = 1 * (matrix[1] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[5] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[13] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		12) 1 * (6 * 11 - 10 * 7) - 5 * (2 * 11 - 10 * 3) + 9 * (2 * 7 - 6 * 3) = 0 * negativeOne;
		CofactorMatrix.matrix[12] = -1 * (matrix[1] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[5] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[9] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		// Second Row
		1) 4 * (10 * 15 - 14 * 11) - 8 * (6 * 15 - 14 * 7) + 12 * (6 * 11 - 10 * 7) = 0 * negativeOne;
		CofactorMatrix.matrix[1] = -1 * (matrix[4] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[8] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) + matrix[12] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]));

		5) 0 * (10 * 15 - 14 * 11) - 8 * (2 * 15 - 14 * 3) + 12 * (2 * 11 - 10 * 3) = 0 * positiveOne;
		CofactorMatrix.matrix[5] = 1 * (matrix[0] * (matrix[10] * matrix[15] - matrix[14] * matrix[11]) - matrix[8] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[12] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]));

		9) 0 * (6 * 15 - 14 * 7) - 4 * (2 * 15 - 14 * 3) + 12 * (2 * 7 - 6 * 3) = 0 * negativeOne;
		CofactorMatrix.matrix[9] = -1 * (matrix[0] * (matrix[6] * matrix[15] - matrix[14] * matrix[7]) - matrix[4] * (matrix[2] * matrix[15] - matrix[14] * matrix[3]) + matrix[12] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		13) 0 * (6 * 11 - 10 * 7) - 4 * (2 * 11 - 10 * 3) + 8 * (2 * 7 - 6 * 3) = 0 * positiveOne;
		CofactorMatrix.matrix[13] = 1 * (matrix[0] * (matrix[6] * matrix[11] - matrix[10] * matrix[7]) - matrix[4] * (matrix[2] * matrix[11] - matrix[10] * matrix[3]) + matrix[8] * (matrix[2] * matrix[7] - matrix[6] * matrix[3]));

		// Third Row
		2) 4 * (9 * 15 - 13 * 11) - 8 * (5 * 15 - 13 * 7) + 12 * (5 * 11 - 9 * 7) = 0 * positiveOne;
		CofactorMatrix.matrix[2] = 1 * (matrix[4] * (matrix[9] * matrix[15] - matrix[13] * matrix[11]) - matrix[8] * (matrix[5] * matrix[15] - matrix[13] * matrix[7]) + matrix[12] * (matrix[5] * matrix[11] - matrix[9] * matrix[7]));

		6) 0 * (9 * 15 - 13 * 11) - 8 * (1 * 15 - 13 * 3) + 12 * (1 * 11 - 9 * 3) = 0 * negativeOne;
		CofactorMatrix.matrix[6] = -1 * (matrix[0] * (matrix[9] * matrix[15] - matrix[13] * matrix[11]) - matrix[8] * (matrix[1] * matrix[15] - matrix[13] * matrix[3]) + matrix[12] * (matrix[1] * matrix[11] - matrix[9] * matrix[3]));

		10) 0 * (5 * 15 - 13 * 7) - 4 * (1 * 15 - 13 * 3) + 12 * (1 * 7 - 5 * 3) = 0 * positiveOne;
		CofactorMatrix.matrix[10] = 1 * (matrix[0] * (matrix[5] * matrix[15] - matrix[13] * matrix[7]) - matrix[4] * (matrix[1] * matrix[15] - matrix[13] * matrix[3]) + matrix[12] * (matrix[1] * matrix[7] - matrix[5] * matrix[3]));

		14) 0 * (5 * 11 - 9 * 7) - 4 * (1 * 11 - 9 * 3) + 8 * (1 * 7 - 5 * 3) = 0 * negativeOne;
		CofactorMatrix.matrix[14] = -1 * (matrix[0] * (matrix[5] * matrix[11] - matrix[9] * matrix[7]) - matrix[4] * (matrix[1] * matrix[11] - matrix[9] * matrix[3]) + matrix[8] * (matrix[1] * matrix[7] - matrix[5] * matrix[3]));

		// Fourth Row
		3) 4 * (9 * 14 - 13 * 10) - 8 * (5 * 14 - 13 * 6) + 12 * (5 * 10 - 9 * 6) = 0 * negativeOne;
		CofactorMatrix.matrix[3] = -1 * (matrix[4] * (matrix[9] * matrix[14] - matrix[13] * matrix[10]) - matrix[8] * (matrix[5] * matrix[14] - matrix[13] * matrix[6]) + matrix[12] * (matrix[5] * matrix[10] - matrix[9] * matrix[6]));

		7) 0 * (9 * 14 - 13 * 10) - 8 * (1 * 14 - 13 * 2) + 12 * (1 * 10 - 9 * 2) = 0 * positiveOne;
		CofactorMatrix.matrix[7] = 1 * (matrix[0] * (matrix[9] * matrix[14] - matrix[13] * matrix[10]) - matrix[8] * (matrix[1] * matrix[14] - matrix[13] * matrix[2]) + matrix[12] * (matrix[1] * matrix[10] - matrix[9] * matrix[2]));

		11) 0 * (5 * 14 - 13 * 6) - 4 * (1 * 14 - 13 * 2) + 12 * (5 * 2 - 1 * 6) = 0 * negativeOne;
		CofactorMatrix.matrix[11] = -1 * (matrix[0] * (matrix[5] * matrix[14] - matrix[13] * matrix[6]) - matrix[4] * (matrix[1] * matrix[14] - matrix[13] * matrix[2]) + matrix[12] * (matrix[5] * matrix[2] - matrix[1] * matrix[6]));

		15) 0 * (5 * 10 - 9 * 6) - 4 * (1 * 10 - 2 * 9) + 8 * (1 * 6 - 5 * 2) = 0 * positiveOne;
		CofactorMatrix.matrix[15] = 1 * (matrix[0] * (matrix[5] * matrix[10] - matrix[9] * matrix[6]) - matrix[4] * (matrix[1] * matrix[10] - matrix[2] * matrix[9]) + matrix[8] * (matrix[1] * matrix[6] - matrix[5] * matrix[2]));


		// Cofactor
		|+0	-4	+8	-12|
		|-1	+5	-9	+13|
		|+2	-6	+10	-14|
		|-3	+7	-11	+15|

		CofactorMatrix.Transpose();

		|0	1	2	 3|
		|4	5	6	 7|
		|8	9	10	11|
		|12	13	14	15|

		for (int i = 0; i < 16; ++i)
		{
			matrix[i] = CofactorMatrix.matrix[i] * 1/getDeterminant();
		}

		*/

	}

	return Passed;
}

//Sets all matrix entries to be zero
void Matrix::ZeroMatrix ()
{
	for (int i = 0; i < 16; ++i)
	{
		matrix [ i ] = 0;
	}
}

//Sets a matrix to be an Identity Matrix
void Matrix::Identity ()
{
	ZeroMatrix ();

	matrix [ 0 ] = 1;
	matrix [ 5 ] = 1;
	matrix [ 10 ] = 1;
	matrix [ 15 ] = 1;
}

//Sets a matrix to be a Perspective Matrix
///The following section is from: https://github.com/datenwolf/linmath.h/blob/master/linmath.h
///datenwolf (2016). linmath.h [online]. [Accessed 18 April 2016].
void Matrix::Perspective ( float _FOV_deg, float _AspectRatio, float _ZNear, float _ZFar )
{
	//Changing degrees into radians
	float RadianFOV = _FOV_deg * M_PI / 180.0f;

	float a = 1.f / tan ( RadianFOV / 2.f );

	ZeroMatrix ();

	matrix [ 0 ] = a / _AspectRatio;
	matrix [ 5 ] = a;
	matrix [ 10 ] = -( ( _ZFar + _ZNear) / ( _ZFar - _ZNear ) );
	matrix [ 11 ] = -1.f;
	matrix [ 14 ] = -( (2.f * _ZFar * _ZNear) / ( _ZFar - _ZNear ) );
}
///end of Citation

//Sets a matrix to be a Scale Matrix
void Matrix::Scale ( float _XPoint, float _YPoint, float _ZPoint )
{
	Identity ();

	matrix [ 0 ] = _XPoint;
	matrix [ 5 ] = _YPoint;
	matrix [ 10 ] = _ZPoint;
}

void Matrix::Scale ( Vector _ScalingFactors )
{
	Scale ( _ScalingFactors.x, _ScalingFactors.y, _ScalingFactors.z );
}

//Sets a matrix to store rotation about X
void Matrix::RotationX ( float _RotFactor )
{
	Identity ();

	//Changing degrees into radians
	float Radian = _RotFactor * M_PI / 180.0f;

	matrix [ 5 ] = cos ( Radian );
	matrix [ 6 ] = sin ( Radian );
	matrix [ 9 ] = -sin ( Radian );
	matrix [ 10 ] = cos ( Radian );
}

//Sets a matrix to store rotation about Y
void Matrix::RotationY ( float _RotFactor )
{
	Identity ();

	//Changing degrees into radians
	float Radian = _RotFactor * M_PI / 180.0f;

	matrix [ 0 ] = cos ( Radian );
	matrix [ 2 ] = -sin ( Radian );
	matrix [ 8 ] = sin ( Radian );
	matrix [ 10 ] = cos ( Radian );
}

//Sets a matrix to store rotation about Z
void Matrix::RotationZ ( float _RotFactor )
{
	Identity ();

	//Changing degrees into radians
	float Radian = _RotFactor * M_PI / 180.0f;

	matrix [ 0 ] = cos ( Radian );
	matrix [ 1 ] = sin ( Radian );
	matrix [ 4 ] = -sin ( Radian );
	matrix [ 5 ] = cos ( Radian );
}

//Sets a matrix to be Translate Matrix
void Matrix::Translate ( float _XPoint, float _YPoint, float _ZPoint )
{
	Identity ();

	matrix [ 12 ] = _XPoint;
	matrix [ 13 ] = _YPoint;
	matrix [ 14 ] = _ZPoint;
}

void Matrix::Translate ( Vector _TranslatingFactors )
{
	Translate ( _TranslatingFactors.x, _TranslatingFactors.y, _TranslatingFactors.z );
}


//Prints out a matrix
void Matrix::PrintMatrix ()
{
	//Adds a new line before printing out a matrix
	std::cout << std::endl;

	//Moves through rows and add to i
	for ( int row = 0, i = 0; row < 4; ++row, ++i )
	{

		//Moves through columns and 4 to j
		for ( int column = 0, j = 0; column < 4; ++column, j+=4 )
		{
			std::cout << matrix [ j + i ] << "     ";
		}

		// 
		std::cout << "\n" << std::endl;
	}

	/*
	
	row 0
	print column 0 than 4 than 8 than 12

	row 1
	print column 1 than 5 than 9 than 13
	
	row 2
	print column 2 than 6 than 10 than 14
	
	row 3
	print column 3 than 7 than 11 than 15

	for (int row = 0, i = 0; row < 4; ++row, ++i)
	{
		for (int column = 0, j = 0; column < 4; ++column, j+=4)
		{
			std::cout << matrix[j + i] << "	";
		}
		std::cout << "\n" << std::endl;
	}
	*/
}