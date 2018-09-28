#pragma once


#ifndef COMMAND_HPP
#define COMMAND_HPP

//=================================
// included dependencies

#include "Category.h"
#include <SFML/System/Time.hpp>
#include <functional>
#include <cassert>

class SceneNode;


struct Command
{
	Command();
	//function object
	std::function<void(SceneNode&, sf::Time)>		action; 
	unsigned int									category;
};


template<typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
	return [=] (SceneNode& node, sf::Time dt)
	{
		//check if cast is safe
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		//Downcast node and invoke function on it
		fn(static_cast<GameObject&>(node), dt);
	
	};


}


#endif //COMMAND_HPP 
