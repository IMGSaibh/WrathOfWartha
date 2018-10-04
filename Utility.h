#pragma once
//=================================
// include guard

#ifndef UTILITY_HPP
#define UTILITY_HPP

//=================================
// included dependencies
#include <Windows.h>
#include <sstream>
#include <iostream>

namespace sf
{
	class Sprite;
	class Text;
}

std::string getWorkingDir();



void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);


#endif // UTILITY_HPP