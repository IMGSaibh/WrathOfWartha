#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP


//=================================
// included dependencies

#include "Command.h"
#include <SFML\Window\Event.hpp>
#include<map>

class CommandQueue;


// represents the Players input
// for manupulating sceneNodes in SceneGraph

class Player
{

public:

	enum Action
	{
		MoveRight,
		MoveLeft,
		MoveUp,
		MoveDown,
		Fire,
		LunchMissiles,
		ActionCount
	};

public:
	Player();
	void										handleEvent(const sf::Event& event, CommandQueue& commands);
	void										handleRealtimeInput(CommandQueue& commands);
	void										assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key							getAssignedKey(Action action) const;

private:

	void										initializeActions();
	static bool									isRealtimeAction(Action action);


private:

	std::map<sf::Keyboard::Key, Action>			mKeyBinding;
	std::map<Action, Command>					mActionBinding;


};

#endif //PLAYER_HPP
