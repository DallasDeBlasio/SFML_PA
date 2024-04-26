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
	if(this->mCharacter != nullptr)
	{
		delete this->mCharacter;
	}
	if(this->pNext!= nullptr)
	{
		delete this->pNext;
	}
}
