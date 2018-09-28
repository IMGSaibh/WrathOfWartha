//=================================
// included dependencies
#include "Game.h"
#include"StringHelper.h"
#include<SFML/Window/Event.hpp>

//const float Game::PlayerSpeed = 200.f; 
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 380), "Wrath of Wartha", sf::Style::Close)
	//, myTexture()
	, mPlayer()
	, mWorld(mWindow)
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
{
	//if (myTexture.loadFromFile("Resources\\Images\\Eagle.png"))
	//{
	//	//handle Error
	//}
	
	//mPlayer.setTexture(myTexture);
	//mPlayer.setPosition(100.f, 100.f);

	mWindow.setKeyRepeatEnabled(false);

	mFont.loadFromFile("Resources\\Fonts\\Western Bang Bang.otf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(20);

}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{

		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processInput()
{
	CommandQueue& commands = mWorld.getCommandQueue();
	
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		mPlayer.handleEvent(event, commands);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}

	mPlayer.handleRealtimeInput(commands);
}


void Game::update(sf::Time elapsedTime)
{
	

	//sf::Vector2f movement(0.f, 0.f);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//	movement.y -= PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//	movement.y += PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	movement.x -= PlayerSpeed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//	movement.x += PlayerSpeed;

	//mPlayer.move(movement * elapsedTime.asSeconds());
	mWorld.update(elapsedTime);
}


void Game::render()
{
	mWindow.clear();
	mWorld.draw();


	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	//Display tells SFML we are down drawing the frame. Then upload all to Screen
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}


