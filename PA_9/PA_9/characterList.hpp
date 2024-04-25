#pragma once


#include "characterNode.hpp"


class characterList
{
public:
	characterList();
	CharacterNode* get_pHead(void);
	void insertAtFront(Character* newCharacter);
	void deleteCharacter(Character* newCharacter);
private:
	CharacterNode* pHead;
	bool isEmpty(void);
	void deleteAtFront(void);
};