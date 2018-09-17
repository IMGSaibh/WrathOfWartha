#include "Aircraft.h"
#include "ResourceHolder.h"

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
	}

	return Textures::Eagle;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	// Origin of Sprite is upper left corner in SFML
	// we set origin to middle with dividing by 2
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}


void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Aircraft::~Aircraft()
{
}
