#include "SceneNode.h"
#include "Foreach.h"
#include "Command.h"
#include <algorithm>
#include <cassert>


SceneNode::SceneNode()
: mChildren()
, mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child) 
{
	child->mParent = this;
	// used to indicate that an object t may be "moved from". 
	// Allowing the efficient transfer of resources from t 
	// to another Object
	
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::deattachChild(const SceneNode& node) 
{
	// Lambda expression
	// creates an anonymous function object

	// The lambda expression is invoked with each container element and returns true if
	// the element's pointer p.get() is equal to the address of the wanted node. The STL
	// algorithm std::find_if() returns an iterator to the found element, which we check
	// for validity using assert.

	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) -> bool { return p.get() == &node; });
	assert( found != mChildren.end() );


	// we move the found node out of the container
	// into the variable result. We set the node's parent pointer to nullptr, erase the
	// empty element from the container, and return the smart pointer containing the
	// detached node.

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;

}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);

	// draw all childnodes 
	for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
	{
		(*itr)->draw(target, states);
	}

}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
		child->draw(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Do nothing by default
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
	FOREACH(Ptr& child, mChildren)
		child->update(dt);
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node->mParent)
	{
		transform = node->getTransform() * transform;
	}

	return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
	// Command current node, if category matches
	if (command.category & getCategory())
		command.action(*this, dt);

	// Command children
	FOREACH(Ptr& child, mChildren)
		child->onCommand(command, dt);
}

unsigned int SceneNode::getCategory() const
{
	return Category::Scene;
}