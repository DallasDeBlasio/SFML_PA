#pragma once


//#include "source.hpp"
#include "characterNode.hpp"


class characterList
{
public:
	CharacterNode* pHead;
	void insertAtFront(Character* newCharacter);
	void deleteAtFront(void);
	void deleteCharacter(Character* newCharacter);
	characterList();
};