#pragma once

#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

//=================================
// included dependencies

#include<map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>


template <typename Resource, typename Identifier>
class ResourceHolder
{

public:
	void load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);


	Resource& get(Identifier id);

	//  if we only have a pointer or reference to a const TextureHolder at hand, 
	//	we need to provide a const qualified overload. This new member function 
	//	returns a reference to a const sf::Texture, therefore the caller cannot 
	//	change the texture. The signature is slightly different

	const Resource& get(Identifier id) const;

private:
	void insertResource(Identifier id, std::unique_ptr<Resource> resource);


private:
	std::map <Identifier, std::unique_ptr<Resource>> mResourceMap;
	
	
};



#include"ResourceHolder.inl"

#endif // RESOURCEHOLDER_HPP
