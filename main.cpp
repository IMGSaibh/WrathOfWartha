//=================================
// included dependencies

#include"Game.h"
#include"Utils.h"

using namespace utils;

int main()
{
	Game game;
	std::cout << utils::getWorkingDir();
	game.run();
	return 0;
}