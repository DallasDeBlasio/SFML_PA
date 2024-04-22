#include "characterNode.hpp"

CharacterNode::CharacterNode()
{
	this->mCharacter = nullptr;
	this->pNext = nullptr;
}

CharacterNode::CharacterNode(Character* newCharacter)
{
	this->mCharacter = newCharacter;
	this->pNext = nullptr;
}

CharacterNode::~CharacterNode()
{
	delete this->mCharacter;
	if(this->pNext!= nullptr)
	{
		delete this->pNext;
	}
}
