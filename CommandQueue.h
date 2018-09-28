#pragma once

#ifndef COMMANDQUEUE_HPP
#define COMMANDQUEUE_HPP

//=================================
// included dependencies

#include "Command.h"
#include <queue>


class CommandQueue
{
public:

	void						push(const Command& command);
	Command						pop();
	bool						isEmtpy() const;


private:

	std::queue<Command>			mQueue;

};


#endif // COMMANDQUEUE_HPP
