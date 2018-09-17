#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP


//=================================
// included dependencies

#include<SFML\Graphics.hpp>
#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	
	Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;

	void updateCurrent(sf::Time dt);

	~Entity();


private:

	sf::Vector2f			mVelocity;


};

#endif // ENTITY_HPP
