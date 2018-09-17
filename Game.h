#pragma once

#ifndef GAME_HPP
#define GAME_HPP

//=================================
// included dependencies
#include"World.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{

public:
								Game();
	void						run();

								~Game();

private:
	void						processEvents();
	void						update(sf::Time elapsedTime);
	void						render();
	void						handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void						updateStatistics(sf::Time elapsedTime);

private:
	sf::RenderWindow			mWindow;
	World						mWorld;
	//sf::Texture					myTexture;
	//sf::Sprite					mPlayer;



	//Statistics

	sf::Font					mFont;
	sf::Text					mStatisticsText;
	sf::Time					mStatisticsUpdateTime;
	std::size_t					mStatisticsNumFrames;
	
	static const float			PlayerSpeed;
	static const sf::Time		TimePerFrame;

	bool						mIsMovingUp;
	bool						mIsMovingDown;
	bool						mIsMovingRight;
	bool						mIsMovingLeft;



};

#endif // !GAME_HPP
