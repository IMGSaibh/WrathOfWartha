#pragma once

#ifndef SPRITENODE_HPP
#define SPRITENODE_HPP

//=================================
// included dependencies


#include "SceneNode.h"
#include <SFML/Graphics/Sprite.hpp>



class SpriteNode : public SceneNode
{
public:
	explicit		SpriteNode(const sf::Texture& texture);
					SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);


private:
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite		mSprite;

};


#endif // !SPRITENODE_HPP
