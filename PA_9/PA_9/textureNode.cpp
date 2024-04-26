#include "textureNode.hpp"

textureNode::textureNode()
{
	this->pNext = nullptr;
}

textureNode::~textureNode()
{
	if (this->pNext != nullptr)
	{
		delete this->pNext;
	}
}
