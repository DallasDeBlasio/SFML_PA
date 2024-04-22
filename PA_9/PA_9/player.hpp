#include "source.hpp"
#include "Character.hpp"


class Player : public Character
{
public:
	textureNode* initalAttackNode;
	int numAttackFrames;
	float attackLength;
	float attackCoolDown;
	bool attacking;
	sf::RectangleShape weaponHitBox;
	//textureNode* currentAttackNode;


	Player(int scale, int width, int height, float initialSpeed);




	void attackOne(void);
	void setWeaponHitBox(void);
};