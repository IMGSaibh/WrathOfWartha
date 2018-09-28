#pragma once

#ifndef GAME_HPP
#define GAME_HPP

//=================================
// included dependencies
#include "World.h"
#include "Player.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game : private sf::NonCopyable
{

public:
								Game();
	void						run();

private:
	void						processInput();
	void						update(sf::Time elapsedTime);
	void						render();
	void						updateStatistics(sf::Time elapsedTime);

private:
	sf::RenderWindow			mWindow;
	World						mWorld;
	Player						mPlayer;



	//Statistics

	sf::Font					mFont;
	sf::Text					mStatisticsText;
	sf::Time					mStatisticsUpdateTime;
	std::size_t					mStatisticsNumFrames;
	
	//static const float			PlayerSpeed;
	static const sf::Time		TimePerFrame;




};

#endif // !GAME_HPP
