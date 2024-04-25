#pragma once


#include "characterNode.hpp"


class characterList
{
public:
	characterList();
	CharacterNode* get_pHead(void);
	void insertAtFront(Character* newCharacter);
	void deleteAtFront(void);
	void deleteCharacter(Character* newCharacter);
	bool isEmpty(void);
private:
	CharacterNode* pHead;
};