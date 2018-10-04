//=================================
// included dependencies

#include "Utility.h"
//#include"Game.h"
#include "Application.h"

int main()
{

	try
	{
		std::cout << "Arbeitsverzeichnis " << getWorkingDir();
		//Game game;
		//game.run();

		Application app; 
		app.run();

	}
	catch (const std::exception& e)
	{
		std::cout << "\n EXCEPTION: " << e.what() << std::endl;
	}
	
	return 0;
}