#include "characterList.hpp"

void characterList::insertAtFront(Character* newCharacter)
{
	CharacterNode* newCharacterNode = new CharacterNode(newCharacter);
	newCharacterNode->pNext = this->pHead;
	this->pHead = newCharacterNode;
}

void characterList::deleteAtFront(void)
{
	CharacterNode* pCur = this->pHead;
	this->pHead = this->pHead->pNext;
	pCur->pNext = nullptr;
	delete pCur;
}

void characterList::deleteCharacter(Character* newCharacter)
{
	CharacterNode* pCur = this->pHead;
	if (pCur->mCharacter == newCharacter)
	{
		this->deleteAtFront();
	}
	else
	{
		while (pCur->pNext != nullptr && pCur->pNext->mCharacter != newCharacter)
		{
			pCur = pCur->pNext;
		}
		if (pCur->pNext != nullptr)
		{
			CharacterNode* pDeleteMe = pCur->pNext;
			pCur->pNext = pCur->pNext->pNext;
			pDeleteMe->pNext = nullptr;
			delete pDeleteMe;
		}
	}
}

bool characterList::isEmpty(void)
{
	bool empty = false;
	if (this->pHead = nullptr)
	{
		empty = true;
	}
	return empty;
}

characterList::characterList()
{
	this->pHead = nullptr;
}

characterList::~characterList()
{
	if (this->pHead != nullptr)
	{
		delete this->pHead;
	}

}

CharacterNode* characterList::get_pHead(void)
{
	return this->pHead;
}
