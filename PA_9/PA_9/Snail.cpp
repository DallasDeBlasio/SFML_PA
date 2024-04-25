#include "Snail.hpp"
#include "player.hpp"


//snail constructor with pr-eset initial speed
Snail::Snail(int scale, int width, int height)
{
	Snail(scale, width, height, 0.1f);
}

//snail constructor with initial speed as a parameter
Snail::Snail(int scale, int width, int height, float initialSpeed) : Character(scale, width, height, initialSpeed)
{
	this->fillTextureList(this->currentWalkFrame, 3, 0, 72, true, 32, "Assets/snail.png");
	this->setTexture(this->currentWalkFrame->frame);
	//this->speed = 700;
}

//Overridden Snail moveV (moves snail towards whatever target is selected
void Snail::moveV(Character target, float  deltaTime)
{
	sf::Vector2f moveToTargetVector(target.getPosition().x - this->getPosition().x, target.getPosition().y - this->getPosition().y);

	if (abs(moveToTargetVector.x) > abs(moveToTargetVector.y)) // move horozontaly
	{
		if (moveToTargetVector.x > 0) // move right
		{
			this->movementDirection.x += 0.1 * deltaTime;
		}
		else 
		{
			this->movementDirection.x -= 0.1 * deltaTime; // move left
		}
	}
	else // move verticaly
	{
		if (moveToTargetVector.y > 0) // move down
		{
			this->movementDirection.y += 0.1 * deltaTime;
		}
		else
		{
			this->movementDirection.y -= 0.1 * deltaTime; // move up
		}
	}

	Character::moveV(deltaTime);

}

//changes x and y to spawning locations randomly
void Snail::X_and_Y_Spawn_Locations(float& x, float& y)
{
	this->X_and_Y_Spawn_Locations(x, y, rand() % 4 + 1);
}


//if snail is touching player, attack player
void Snail::interacts(Player &hero)
{
	if (!hero.isInvincible() && this->getGlobalBounds().intersects(hero.hitbox.getGlobalBounds()))
	{
		sf::Vector2f bounceDirection(hero.getPosition().x - this->getPosition().x, hero.getPosition().y - this->getPosition().y);
		float bounceSpeed = getVectorManitude(bounceDirection);
		sf::Vector2f unitBounceDirection = getUnitVector(bounceDirection);
		hero.setSpeed(hero.getMovementSpeed() * 2);
		hero.movementDirection = unitBounceDirection * 0.25f;
		hero.takeDamage(this->mDamage);
		hero.makeInvincible();

		//std::cout << hero.movementDirection.x << "," << hero.movementDirection.y << "\n";
	}
}

//changes x and y to predetermined spawnPoints based on an integer (1-4) passed in
void Snail::X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint)
{
	switch (spawnPoint)
	{
	case 1:
	{
		x = 0 + this->width * this->mScale / 2.f;
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
