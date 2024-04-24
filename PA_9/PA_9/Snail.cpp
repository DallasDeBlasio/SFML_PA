#include "Snail.hpp"
#include "player.hpp"

Snail::Snail(int scale, int width, int height) : Character(scale, width, height, 0.1f)
{
	this->fillTextureList(this->currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
	this->mergeLevel = 0;
}

Snail::Snail(int scale, int width, int height, float initialSpeed) : Character(scale, width, height, initialSpeed)
{
	//this->speed = initialSpeed * 1000;
	this->fillTextureList(this->currentFrame, 3, 0, 72, true, 32, "Assets/snail.png");
	this->setTexture(this->currentFrame->frame);
	this->mergeLevel = 0;
	//sf::Vector2f()
}

void Snail::moveV(Character target, float  deltaTime)
{
	sf::Vector2f moveToTargetVector(target.getPosition().x - this->getPosition().x, target.getPosition().y - this->getPosition().y);

	if (abs(moveToTargetVector.x) > abs(moveToTargetVector.y)) // move horozontaly
	{
		if (moveToTargetVector.x > 0) // move right
		{
			this->movementDirection.x += 1;
		}
		else 
		{
			this->movementDirection.x -= 1; // move left
		}
	}
	else // move verticaly
	{
		if (moveToTargetVector.y > 0) // move down
		{
			this->movementDirection.y += 1;
		}
		else
		{
			this->movementDirection.y -= 1; // move up
		}
	}

	Character::moveV(deltaTime);

}

void Snail::X_and_Y_Spawn_Locations(float& x, float& y)
{
	this->X_and_Y_Spawn_Locations(x, y, rand() % 4 + 1);
}

void Snail::X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint)
{
	switch (spawnPoint)
	{
	case 1:
	{
		x =  0 + this->width * this->mScale / 2.f;
		y = 0 + this->width * this->mScale / 2.f;
		break;
	}
	case 2:
	{
		x = 0 + this->width * this->mScale / 2.f;
		y = 1080 - this->width * this->mScale / 2.f;
		break;
	}	
	case 3:
	{
		x = 1920 - this->width * this->mScale / 2.f;
		y = 0 + this->width * this->mScale / 2.f;
		break;
	}	
	case 4:
	{
		x = 1920 - this->width * this->mScale / 2.f;
		y = 1080 - this->width * this->mScale / 2.f;
		break;
	}

	}
}

void Snail::interacts(Player &hero)
{
	if (hero.invinciblityTime == 0 && this->getGlobalBounds().intersects(hero.hitbox.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(hero.getPosition().x - this->getPosition().x, hero.getPosition().y - this->getPosition().y);
		float bounceSpeed = getVectorManitude(bounceDirection);
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
		hero.movementDirection = unitBounceDirection * 100.f;
		hero.speed = 700;
		hero.currentHP -= hero.mDamage;
		hero.invinciblityTime = 0.01f;


	}
}

/*
if (herotest.invinciblityTime == 0 && bert.getGlobalBounds().intersects(herotest.hitbox.getGlobalBounds()))
{
	sf::Vector2f bounceDirection(herotest.getPosition().x - bert.getPosition().x, herotest.getPosition().y - bert.getPosition().y);
	float bounceSpeed = getVectorManitude(bounceDirection);
	sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
	herotest.movementDirection = unitBounceDirection * 100.f;
	herotest.speed = 700;
	herotest.currentHP -= bert.mDamage;
	herotest.invinciblityTime = 0.01f;

}
*/