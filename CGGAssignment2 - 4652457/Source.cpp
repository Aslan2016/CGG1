/// @file Source.cpp
/// @brief The main project file

#include "Transformation.h"
#include "include\SDL.h"
#include "Calculator.h"

// Module Contents

// Declares a function
void SDL ();

void QuitSDL ( SDL_Window* _Window, SDL_Renderer* _Renderer );

int main ( int args, char* argc[] )
{
	int Choice = 0;
	//Quit flag
	bool Run = true;

	//Menu Loop
	while (Run == true)
	{
		system("CLS");
		std::cout << "Type in a number of a presented option and press Enter:" << std::endl;
		std::cout << "1. Calculator" << "\n2. 3D Rendering Engine" << "\n3. Exit" << "\nOption: ";
		std::cin >> Choice;
		std::cin.ignore ();
		switch ( Choice )
		{
			case 1: { Calculator::MainMenu ();	break; }

			case 2: { SDL ();	break; }
			
			case 3: { Run = false; break; } //Breaks the Menu Loop

			default: 
			{
				std::cin.clear ();
				std::cin.ignore ();
				break;
			}
		}
	}

	return 0;
}

//3D Rendering Engine
void SDL ()
{
	//Initalises SDL, video subsystem
	SDL_Init ( SDL_INIT_VIDEO );

	//Creates a window
	SDL_Window* Window = SDL_CreateWindow ( "3D Rendering Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN );
	
	//Creates a renderer with SDL_RENDERER_PRESENTVSYNC to fix the refresh rate to that of the screen
	//to avoid the engine being excessively fast
	SDL_Renderer* Renderer = SDL_CreateRenderer ( Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	float Angle = 0.0f;

	float Move = 1.0f;

	//Matrices to move the object into the World Space
	Matrix ModelTranslate;

	Matrix ModelRotation;
	
	Matrix ModelScale;

	Matrix ModelMatrix;


	//Matrices to move the object into the View (Camera, Eye) Space
	Matrix CameraTranslate;

	Matrix CameraRotation;

	Matrix CameraScale;

	Matrix ViewMatrix;
	//Eye Space End


	//Matrices to change the View Space into Projection Space
	Matrix ProjectionPerspective;

	Matrix ProjectionMatrix;
	//Projection End

	Matrix MVPMatrix; //ModelViewProjection Matrix

	//Cube's Vertices position vectors
	Vector CubeVertexPosition1 ( -1.0f, 1.0f, 1.0f, 1.0f );

	Vector CubeVertexPosition2 ( 1.0f, 1.0f, 1.0f, 1.0f );

	Vector CubeVertexPosition3 ( -1.0f, -1.0f, 1.0f, 1.0f );

	Vector CubeVertexPosition4 ( -1.0f, -1.0f, -1.0f, 1.0f );

	Vector CubeVertexPosition5 ( -1.0f, 1.0f, -1.0f, 1.0f );

	Vector CubeVertexPosition6 ( 1.0f, 1.0f, -1.0f, 1.0f );

	Vector CubeVertexPosition7 ( 1.0f, -1.0f, 1.0f, 1.0f );

	Vector CubeVertexPosition8 ( 1.0f, -1.0f, -1.0f, 1.0f );

	//Visual representation of vertices
	SDL_Rect Vertex1 = { 0, 0, 2, 2 };

	SDL_Rect Vertex2 = { 0, 0, 2, 2 };

	SDL_Rect Vertex3 = { 0, 0, 2, 2 };

	SDL_Rect Vertex4 = { 0, 0, 2, 2 };

	SDL_Rect Vertex5 = { 0, 0, 2, 2 };

	SDL_Rect Vertex6 = { 0, 0, 2, 2 };

	SDL_Rect Vertex7 = { 0, 0, 2, 2 };

	SDL_Rect Vertex8 = { 0, 0, 2, 2 };
	//Cube End

	//Creates a game loop and event handling system
	bool Run = true;

	//Creates an event handler
	SDL_Event EventUnion;

	//Main "Game" loop
	while ( Run == true )
	{
		//Checks any input events and puts them in the poll
		while ( SDL_PollEvent ( &EventUnion ) != 0 )
		{
			//Breaks the Game Loop if the event is registered
			if ( EventUnion.type == SDL_QUIT )
			{
				Run = false;
			}
		}
		//Sets a color for renderering operations
		SDL_SetRenderDrawColor ( Renderer, 0x00, 0x00, 0x00, 0xFF );
		
		//Clears the screen with a color set with SDL_SetRenderDrawColor
		SDL_RenderClear ( Renderer );

		SDL_SetRenderDrawColor ( Renderer, 0xFF, 0x00, 0xFF, 0xFF );

		//ModelMatrix
		ModelTranslate.Translate ( 0.f, 0.f, 0.f );
		ModelRotation = Transformation::RotationZ ( 0.f ) * Transformation::RotationY ( Angle += 0.25 ) * Transformation::RotationX ( Angle += 0.25 );
		ModelScale.Scale ( 50.f, 50.f, 50.f );
		ModelMatrix = ModelTranslate * ModelRotation * ModelScale;
		//ModelMatrix

		//ViewMatrix
		CameraTranslate.Translate ( 0.f, 0.f, 5.f );
		CameraRotation = Transformation::RotationZ ( 0.f ) * Transformation::RotationY ( 0.f ) * Transformation::RotationX ( 0.f );
		CameraScale.Identity ();
		ViewMatrix = CameraTranslate * CameraRotation * CameraScale;
		ViewMatrix.Inverse ();
		//ViewMatrix
		
		//ProjectionMatrix
		ProjectionPerspective.Perspective ( 90.f, 1.f, 0.01f, 1.f );
		ProjectionMatrix = ProjectionPerspective;
		ProjectionMatrix.Inverse ();
		//ProjectionMatrix

		//ModelViewProjectionMatrix
		MVPMatrix = ProjectionMatrix * ViewMatrix * ModelMatrix;
		//ModelViewProjectionMatrix

		Vector VertexPosition1 = MVPMatrix * CubeVertexPosition1;
		Vector VertexPosition2 = MVPMatrix * CubeVertexPosition2;
		Vector VertexPosition3 = MVPMatrix * CubeVertexPosition3;
		Vector VertexPosition4 = MVPMatrix * CubeVertexPosition4;
		Vector VertexPosition5 = MVPMatrix * CubeVertexPosition5;
		Vector VertexPosition6 = MVPMatrix * CubeVertexPosition6;
		Vector VertexPosition7 = MVPMatrix * CubeVertexPosition7;
		Vector VertexPosition8 = MVPMatrix * CubeVertexPosition8;

		/*
		VertexPosition1 = VertexPosition1 / VertexPosition1.w;
		VertexPosition2 = VertexPosition2 / VertexPosition2.w;
		VertexPosition3 = VertexPosition3 / VertexPosition3.w;
		VertexPosition4 = VertexPosition4 / VertexPosition4.w;
		VertexPosition5 = VertexPosition5 / VertexPosition5.w;
		VertexPosition6 = VertexPosition6 / VertexPosition6.w;
		VertexPosition7 = VertexPosition7 / VertexPosition7.w;
		VertexPosition8 = VertexPosition8 / VertexPosition8.w;
		*/

		//Sets Vertices position on the screen
		Vertex1.x = (int) ( VertexPosition1.x + 320.f );
		Vertex1.y = (int) ( VertexPosition1.y + 240.f );
		//Fills an SDL_Rect structure with a color set with SDL_SetRenderDrawColor
		SDL_RenderFillRect ( Renderer, &Vertex1 );

		Vertex2.x = (int) ( VertexPosition2.x + 320.f );
		Vertex2.y = (int) ( VertexPosition2.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex2 );

		Vertex3.x = (int) ( VertexPosition3.x + 320.f );
		Vertex3.y = (int) ( VertexPosition3.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex3 );

		Vertex4.x = (int) ( VertexPosition4.x + 320.f );
		Vertex4.y = (int) ( VertexPosition4.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex4 );

		Vertex5.x = (int) ( VertexPosition5.x + 320.f );
		Vertex5.y = (int) ( VertexPosition5.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex5 );

		Vertex6.x = (int) ( VertexPosition6.x + 320.f );
		Vertex6.y = (int) ( VertexPosition6.y + 240.f);
		SDL_RenderFillRect ( Renderer, &Vertex6 );

		Vertex7.x = (int) ( VertexPosition7.x + 320.f );
		Vertex7.y = (int) ( VertexPosition7.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex7 );

		Vertex8.x = (int) ( VertexPosition8.x + 320.f );
		Vertex8.y = (int) ( VertexPosition8.y + 240.f );
		SDL_RenderFillRect ( Renderer, &Vertex8 );

		//Draws edges between vertices' positions
		SDL_RenderDrawLine ( Renderer, Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y );

		SDL_RenderDrawLine ( Renderer, Vertex1.x, Vertex1.y, Vertex5.x, Vertex5.y );

		SDL_RenderDrawLine ( Renderer, Vertex2.x, Vertex2.y, Vertex6.x, Vertex6.y );

		SDL_RenderDrawLine ( Renderer, Vertex6.x, Vertex6.y, Vertex5.x, Vertex5.y );

		SDL_RenderDrawLine ( Renderer, Vertex1.x, Vertex1.y, Vertex3.x, Vertex3.y );

		SDL_RenderDrawLine ( Renderer, Vertex2.x, Vertex2.y, Vertex7.x, Vertex7.y );

		SDL_RenderDrawLine ( Renderer, Vertex3.x, Vertex3.y, Vertex7.x, Vertex7.y );

		SDL_RenderDrawLine ( Renderer, Vertex3.x, Vertex3.y, Vertex4.x, Vertex4.y );

		SDL_RenderDrawLine ( Renderer, Vertex4.x, Vertex4.y, Vertex5.x, Vertex5.y );

		SDL_RenderDrawLine ( Renderer, Vertex4.x, Vertex4.y, Vertex8.x, Vertex8.y );

		SDL_RenderDrawLine ( Renderer, Vertex7.x, Vertex7.y, Vertex8.x, Vertex8.y );

		SDL_RenderDrawLine ( Renderer, Vertex6.x, Vertex6.y, Vertex8.x, Vertex8.y );


		//Renders everything to the front buffer
		SDL_RenderPresent ( Renderer );
	
	}

	/*
	Cleans up and quits SDL by destroying the window and the renderer, 
	setting them to NULL and using SDL_Quit
	*/
	SDL_DestroyRenderer ( Renderer );

	Renderer = NULL;

	SDL_DestroyWindow ( Window );

	Window = NULL;

	SDL_Quit ();

}