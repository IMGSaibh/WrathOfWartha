//=================================
// included dependencies
#include "Game.h"
#include"StringHelper.h"
#include<SFML/Window/Event.hpp>

const float Game::PlayerSpeed = 200.f; 
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 380), "Wrath of Wartha", sf::Style::Close)
	//, myTexture()
	//, mPlayer()
	, mWorld(mWindow)
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp()
	, mIsMovingDown()
	, mIsMovingRight()
	, mIsMovingLeft()
{
	//if (myTexture.loadFromFile("Resources\\Images\\Eagle.png"))
	//{
	//	//handle Error
	//}
	
	//mPlayer.setTexture(myTexture);
	//mPlayer.setPosition(100.f, 100.f);

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

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
		case sf::Event::Closed:
			mWindow.close();
		default:
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	//sf::Vector2f movement(0.0f, 0.0f);

	//if (mIsMovingUp)
	//	movement.y -= PlayerSpeed;
	//if (mIsMovingDown)
	//	movement.y += PlayerSpeed;
	//if (mIsMovingLeft)
	//	movement.x -= PlayerSpeed;
	//if (mIsMovingRight)
	//	movement.x += PlayerSpeed;

	//mPlayer.move(movement * elapsedTime.asSeconds());
	mWorld.update(elapsedTime);
}


void Game::render()
{
	mWindow.clear();
	mWorld.draw();


	//mWindow.draw(mPlayer);
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
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


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

Game::~Game()
{

}
