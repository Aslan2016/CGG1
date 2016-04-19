/// \file Calculator.h
/// \brief creates a namespace and defines its functions for a calculator demo
/// \author Aslan Saparov

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

//File Includes
#include "Transformation.h"

namespace Calculator
{
	int Choice = 0;
	Vector CalcVector1, CalcVector2;
	Matrix CalcMatrix1, CalcMatrix2;

	//Vector Calculator
	Vector SetVector ()
	{
		Vector CalcVector;

		std::cout << "\nType in x, y, z and w components of a vector as floats:" << std::endl;
		std::cin >> CalcVector.x >> CalcVector.y >> CalcVector.z >> CalcVector.w;
		std::cin.ignore();

		return CalcVector;
	}

	void VectorScalar ()
	{
		float Scalar;
		CalcVector1 = SetVector ();

		Vector MultiplicationResult;
		Vector DivisionResult;

		std::cout << "Type in a scalar value: ";
		std::cin >> Scalar;
		std::cin.ignore ();

		CalcVector1.PrintVector ();

		std::cout << "Multiplied and Divided by " << Scalar << "\nMultiplication Result:";

		MultiplicationResult = CalcVector1 * Scalar;

		MultiplicationResult.PrintVector ();

		std::cout << "Division Result:";

		DivisionResult = CalcVector1 / Scalar;

		DivisionResult.PrintVector();

		std::cin.get ();
	}

	void VectorVector ()
	{
		CalcVector1 = SetVector ();
		CalcVector2 = SetVector ();

		Vector AdditionResult;
		Vector SubtractionResult;

		std::cout << "Vector 1" << std::endl;

		CalcVector1.PrintVector ();

		std::cout << "Vector 2" << std::endl;

		CalcVector2.PrintVector ();

		std::cout << "Addition Result:" << std::endl;

		AdditionResult = CalcVector1 + CalcVector2;

		AdditionResult.PrintVector ();

		std::cout << "SubtractionResult:" << std::endl;

		SubtractionResult = CalcVector1 - CalcVector2;

		SubtractionResult.PrintVector ();

		std::cin.get ();
	}

	void DotCrossProduct ()
	{
		CalcVector1 = SetVector ();
		CalcVector2 = SetVector ();

		std::cout << "Vector1" << std::endl;

		CalcVector1.PrintVector ();

		std::cout << "Vector2" << std::endl;

		CalcVector2.PrintVector ();

		std::cout << "Dot Product: " << CalcVector1.DotProduct ( CalcVector2 ) << std::endl;

		std::cout << "\nCross Product:" << std::endl;

		CalcVector1.CrossProduct ( CalcVector2 );

		CalcVector1.PrintVector ();

		std::cin.get ();
	}

	void MagnitudeNormal ()
	{
		CalcVector1 = SetVector ();

		std::cout << "\nVector's Magnitude: " << CalcVector1.getMagnitude () << std::endl;

		std::cout << "\nNormalised Vector: ";
		CalcVector1.NormaliseVector ();
		CalcVector1.PrintVector ();

		std::cout << "\nNormalised Vector's magnitude: " << CalcVector1.getMagnitude () << std::endl;


		std::cin.get ();
	}

	void VectorMenu ()
	{
		bool Run = true;
		while ( Run == true )
		{
			system ( "CLS" );
			std::cout << "Type in a number and press Enter" << std::endl;
			std::cout << "1. Vector-Scalar arithmetic (Multiplication, division)" << std::endl;
			std::cout << "2. Vector-Vector arithmetic (Addition, subtraction)" << std::endl;
			std::cout << "3. Dot and Cross Product" << std::endl;
			std::cout << "4. Magnitude and Normalisation" << std::endl;
			std::cout << "5. Main Menu" << std::endl;
			std::cout << "Option: ";
			std::cin >> Choice;
			std::cin.ignore ();
			switch ( Choice )
			{
				case 1: { VectorScalar ();	break; }
				
				case 2: { VectorVector ();	break; }
				
				case 3: { DotCrossProduct ();	break; }
				
				case 4: { MagnitudeNormal ();	break; }
				
				case 5: { Run = false;	break; }
				
				default:
				{
					std::cin.clear ();
					std::cin.ignore ();
					break;
				}
			}
		}
	}

	//Matrix Calculator
	Matrix SetMatrix ()
	{
		Matrix CalcMatrix;

		std::cout << "\n\nType in matrix entries" << std::endl;
		for ( int i = 0; i < 16; ++i )
		{
			std::cout << "Matrix Entry " << i << ": ";
			std::cin >> CalcMatrix.matrix [ i ];
			std::cin.ignore ();
		}

		system ( "CLS" );
		
		return CalcMatrix;
	}

	void MatrixScalar ()
	{
		float Scalar;
		Matrix MultiplicationResult;

		CalcMatrix1 = SetMatrix ();

		std::cout << "Matrix";

		CalcMatrix1.PrintMatrix ();

		std::cout << "Scalar: ";
		std::cin >> Scalar;
		std::cin.ignore ();

		std::cout << "\nMultiplication Result: " << std::endl;

		MultiplicationResult = CalcMatrix1 * Scalar;

		MultiplicationResult.PrintMatrix();

		std::cout << "Division Result: " << std::endl;

		CalcMatrix1 = CalcMatrix1 / Scalar;

		CalcMatrix1.PrintMatrix ();

		std::cin.get ();
	}

	void MatrixVector ()
	{
		CalcMatrix1 = SetMatrix ();

		std::cout << "Matrix";

		CalcMatrix1.PrintMatrix ();

		CalcVector1 = SetVector ();

		std::cout << "\nVector" << std::endl;

		CalcVector1.PrintVector();

		std::cout << "MultiplicationResult:" << std::endl;

		CalcVector1 = CalcMatrix1 * CalcVector1;

		CalcVector1.PrintVector();

		std::cin.get ();
	}

	void MatrixMatrix ()
	{
		Matrix AdditionResult;

		Matrix SubtractionResult;

		CalcMatrix1 = SetMatrix ();

		CalcMatrix1.PrintMatrix ();

		CalcMatrix2 = SetMatrix ();

		std::cout << "Matrix 1";

		CalcMatrix1.PrintMatrix ();

		std::cout << "Matrix 2";

		CalcMatrix2.PrintMatrix ();

		std::cout << "Addition Result:";

		AdditionResult = CalcMatrix1 + CalcMatrix2;

		AdditionResult.PrintMatrix ();

		std::cout << "Subtraction Result:";

		SubtractionResult = CalcMatrix1 - CalcMatrix2;

		SubtractionResult.PrintMatrix ();

		std::cout << "Multiplication Result:";

		CalcMatrix1 = CalcMatrix1 * CalcMatrix2;

		CalcMatrix1.PrintMatrix ();

		std::cin.get ();
	}

	void MatrixMore ()
	{
		CalcMatrix1 = SetMatrix ();
		CalcMatrix2 = CalcMatrix1;

		std::cout << "Matrix" << std::endl;

		CalcMatrix1.PrintMatrix ();

		std::cout << "Determinant: " << CalcMatrix1.getDeterminant () << std::endl;

		std::cout << "Transposed Matrix:" << std::endl;

		CalcMatrix1.Transpose ();

		CalcMatrix1.PrintMatrix ();

		std::cout << "Inversed Matrix:" << std::endl;

		if ( CalcMatrix2.Inverse () == false )
		{
			std::cout << "\nMatrix can not be inversed as the it's determinant is " << CalcMatrix2.getDeterminant () << std::endl;
		}
		else
		{
			CalcMatrix2.PrintMatrix ();

			std::cout << "Inversed Matrix Determinant: " << CalcMatrix2.getDeterminant () << std::endl;
		}

		std::cin.get ();
	}

	void MatrixMenu ()
	{
		bool Run = true;

		while ( Run == true )
		{
			system ("CLS");
			std::cout << "Type in a number and press Enter" << std::endl;
			std::cout << "1. Matrix-Scalar arithmetic" << std::endl;
			std::cout << "2. Matrix-Vector arithmetic" << std::endl;
			std::cout << "3. Matrix-Matrix arithmetic" << std::endl;
			std::cout << "4. Transposition, Determinant and Inverse" << std::endl;
			std::cout << "5. Main Menu" << std::endl;
			std::cout << "Option: " << std::endl;
			std::cin >> Choice;
			std::cin.ignore ();
			switch ( Choice )
			{
				case 1: { MatrixScalar ();	break; }
				
				case 2: { MatrixVector ();	break; }
				
				case 3: { MatrixMatrix ();	break; }
				
				case 4: { MatrixMore ();	break; }
				
				case 5: { Run = false;	break; }
				
				default:
				{
					std::cin.clear ();
					std::cin.ignore ();
					break;
				}
			}
		}
	}

	void TransformMenu ()
	{
		bool Run = true;

		while ( Run == true )
		{
			system ( "CLS" );
			std::cin >> Choice;
			std::cin.ignore ();

			switch ( Choice )
			{
				case 1: { break; }
			
				case 2: { break; }
			
				default:
				{
					std::cin.clear ();
					std::cin.ignore ();
					break;
				}
			}
		}
	}

	void MainMenu ()
	{
		bool Run = true;

		while ( Run == true )
		{
			system ( "CLS" );
			std::cout << "Type in a number and press Enter" << std::endl;
			std::cout << "1. Vector" << std::endl;
			std::cout << "2. Matrix" << std::endl;
			std::cout << "3. Transform matrix calculations" << std::endl;
			std::cout << "4. Exit" << std::endl;
			std::cout << "Option: ";
			std::cin >> Choice;
			std::cin.ignore ();

			switch ( Choice )
			{
				case 1: { VectorMenu ();	break; }
				
				case 2: { MatrixMenu ();	break; }
				
				case 3: { break; }
				
				case 4: { Run = false; break; }
				
				default:
				{
					std::cin.clear ();
					std::cin.ignore ();
					break;
				}
			}
		}
	}
}

#endif // _CALCULATOR_H_