//=================================
// included dependencies

#include"Game.h"
#include"Utils.h"

using namespace utils;

int main()
{

	try
	{
		Game game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::cout << "\n EXCEPTION: " << e.what() << std::endl;
	}
	
	return 0;
}