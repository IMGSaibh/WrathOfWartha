#pragma once

#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP


//=================================
// included dependencies

#include "Entity.h"
#include "ResourceIdentifiers.h"

class Aircraft : public Entity
{
public:

	enum Type
	{
		Eagle, Raptor
	};


public:
	
	// cannot be used for implicit conversations
	// Aircraft airCft = Eagle; ist not possible
	// Aircraft airCft(Eagle); ist possible
	explicit Aircraft(Type type, const TextureHolder& textures);
	
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;

	~Aircraft();

private:
	Type			mType;
	sf::Sprite		mSprite;

};

#endif // !AIRCRAFT_HPP
