#pragma once

#ifndef SCENENODE_HPP
#define SCENENODE_HPP

//=================================
// included dependencies

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <vector>
#include <memory>
#include <cassert>


struct Command;

class SceneNode : public sf::Transformable, public sf::Drawable, public sf::NonCopyable
{

public:
	
	typedef					std::unique_ptr<SceneNode> Ptr;




public:
	SceneNode();
	void					attachChild(Ptr child);
	Ptr						deattachChild(const SceneNode& node);
	void					update(sf::Time dt);

	sf::Vector2f			getWorldPosition() const;
	sf::Transform			getWorldTransform() const;

	void					onCommand(const Command& command, sf::Time dt);
	virtual unsigned int	getCategory() const;


private:

	virtual void			updateCurrent(sf::Time dt);
	void					updateChildren(sf::Time dt);

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


	//sf::Transform			getWorldTransform() const;
	//sf::Vector2f			getWorldPosition()const;


private:

	std::vector<Ptr>		mChildren;
	SceneNode*				mParent;

};

#endif // SCENENODE_HPP