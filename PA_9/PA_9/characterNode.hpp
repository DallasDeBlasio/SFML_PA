#pragma once


//#include "source.cpp"
#include "character.hpp"


class CharacterNode
{
public:

	CharacterNode* pNext;
	Character* mCharacter;

	CharacterNode();
	CharacterNode(Character* newCharacter);
	~CharacterNode();
};