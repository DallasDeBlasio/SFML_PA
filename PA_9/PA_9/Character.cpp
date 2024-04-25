#include "Character.hpp"
#include "player.hpp"
#include "Snail.hpp"

int speedFactor = 2000;//because delta time is such a small number, we must in turn multiply the characters speed by an aposing large number to movement to be where we want it

//default character constructor
Character::Character(): Character(1,50,50,0.2) 
{
}

// characater constructor with scale, width, and height as parameters
Character::Character(int scale, int width, int height) :Character(scale, width, height, 0.2) 
{
}

//character constructor with scale, width,height, and initials speed as parameters
//called by other character constructors
Character::Character(int scale, int width, int height, float initialSpeed):Sprite()
{
	this->maxHP = 30;
	this->currentHP = this->maxHP;//character dies when this reaches 0
	this->mDamage = 5;//damage the character does to others
	this->movmentSpeed = initialSpeed * speedFactor; //maximum speed the character should be moving under their own power
	this->speed = this->movmentSpeed; //current speed the character is moving
	this->facing = 1; //which direction the character is facing, -1 for left 1 for right
	this->mScale = scale; //a size multiplier for desplaying height and width
	this->width = width;
	this->height = height;
	this->walkFrame = 0;//increments everytime moveV is called, after it reaches the desired number gets set back to 0 and switches to next walk frame
	this->invinciblityTime = 0.f;// = 0.f;//0 if not invincible
	this->lengthOfInvincibility = 0.25f;//maximum invisibility time

	this->currentWalkFrame = nullptr;//leaves the currentWalkFrame nullptr
	this->movementDirection = sf::Vector2f(0.f, 0.f);//sets movement direction to no desired movement


	this->setOrigin(this->width / 2.0, this->height / 2.0);//sets origin to center of character
	this->setScale(this->mScale, this->mScale); 

	//set hitbox to character size
	this->hitbox.setSize(this->getGlobalBounds().getSize());


	//set health bar sizes
	this->mHealthBar.mBottomRectangle.setSize(sf::Vector2f(scale * this->width, 3.f)); 
	this->mHealthBar.mTopRectangle.setSize(sf::Vector2f(scale * this->width, 4.f));

	this->mHealthBar.mBottomRectangle.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 30));
	this->mHealthBar.mTopRectangle.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 30));

}
int Character::getCurrentHP(void)
{
	return this->currentHP;
}
float Character::getMovementSpeed(void)
{
	return this->movmentSpeed;
}
bool Character::isInvincible(void)
{
	bool isCurrentlyInvincible = true;
	if (this->invinciblityTime == 0)
	{
		isCurrentlyInvincible = false;
	}
	return isCurrentlyInvincible;
}
void Character::setSpeed(float newSpeed)
{
	this->speed = newSpeed;
}
void Character::makeInvincible(void)
{
	this->invinciblityTime = 0.01;
}
void Character::takeDamage(int Damage)
{
	this->currentHP -= Damage;
}
//

void Character::moveV(float  deltaTime)// moves chracater speed distance along movementDirection
{
	this->setTexture(this->currentWalkFrame->frame, true);//makes sure that if the character can move, they are in the current walking animation
	if (this->speed < this->movmentSpeed)//always reset speed to movement speed if it was made too small
	{
		this->speed = this->movmentSpeed;
	}
	sf::Vector2f unitVector(getUnitVector(this->movementDirection));
	sf::Vector2f speed_in_direction_unitVector = unitVector * this->speed;
	speed_in_direction_unitVector *= deltaTime;//removes frame rate as an aspect of speed : martin helped a lot with this

	if (speed_in_direction_unitVector.x < 0)//left side boundry
	{
		if (this->getPosition().x - this->width / 2.f * this->mScale < 0)
		{
			this->setPosition(0 + this->width/2.f * this->mScale, this->getPosition().y);
			this->movementDirection.x = 0;
		}
		else
		{
			this->move(speed_in_direction_unitVector.x, 0);
		}
	}
	
	if(speed_in_direction_unitVector.x > 0)//right side boundry
	{
		if (this->getPosition().x + this->width / 2.f * this->mScale > 1920)//hardcoding window size as of right now
		{
			this->setPosition(1920 - this->width / 2.f * this->mScale, this->getPosition().y);
			this->movementDirection.x = 0;
		}
		else
		{
			this->move(speed_in_direction_unitVector.x, 0);
		}
	}

	if (speed_in_direction_unitVector.y < 0)//top side boundry
	{
		if (this->getPosition().y - this->height / 2.f * this->mScale < 0)
		{
			this->setPosition(this->getPosition().x, 0 + this->height / 2.f * this->mScale);
			this->movementDirection.y = 0;

		}
		else
		{
			this->move(0, speed_in_direction_unitVector.y);
		}
	}
	
	if(speed_in_direction_unitVector.y > 0)//bottom boundry
	{
		if (this->getPosition().y + this->height / 2.f * this->mScale > 1080)//hardcoding window size right now
		{
			this->setPosition(this->getPosition().x, 1080 - this->height / 2.f * this->mScale);
			this->movementDirection.y = 0;
		}
		else
		{
			this->move(0, speed_in_direction_unitVector.y);
		}
	}

	if (this->walkFrame > 200)//change walk frames
	{
		this->walkFrame = 0;
		this->nextWalkFrame();
	}

	this->shouldITurnAround(unitVector);//turns the character around when unit Vector points in the direction the character is not facing

	//update hitbox
	this->hitbox.setSize(this->getGlobalBounds().getSize());
	this->hitbox.setPosition(this->getGlobalBounds().getPosition());

	//update health bar location
	this->mHealthBar.mTopRectangle.setPosition(sf::Vector2f(this->getPosition().x - width*this->mScale/2, this->getPosition().y - 10 - height*this->mScale/2));
	this->mHealthBar.mBottomRectangle.setPosition(sf::Vector2f(this->getPosition().x - width*this->mScale/2, this->getPosition().y - 10 - height*this->mScale/2));
	
	//update width of the actual health portion of health bar
	this->mHealthBar.mTopRectangle.setSize(sf::Vector2f(this->mScale * this->width * ((float)this->currentHP / (float)this->maxHP), 4.f));


	//decays movement and speed back to starting values
	this->decayMovment(deltaTime);
	this->decaySpeed(deltaTime);


	//increment walk frame if character is moving
	if (getVectorManitude(speed_in_direction_unitVector) != 0)
	{
		this->walkFrame++;
	}
}

void Character::moveV(Character target, float deltaTime)//by default just calles moveV
{
	this->moveV(deltaTime);
}

void Character::invincibilityManager(float DeltaTime)//takes care of all invincibiliy backwork
{
	if (this->isInvincible())//if is invincible
	{
		if (this->invinciblityTime > this->lengthOfInvincibility)//if invincibility time should be over set it to 0
		{
			this->invinciblityTime = 0.f;
		}
		else //add time to invincibile
		{
			this->invinciblityTime += DeltaTime;
		}
	}
}




// true for horizontal spacing, false for verticle
// gap is the gap between corners
//creates a singlyly linked list in the place of a textureNode
//creates a circularly linked list by default
void Character::fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename)
{
	this->fillTextureList(startFrame, numFrames, XCoordinateFirstFrame, YCoordinateFirstFrame, this->width, this->height, horizontal, gap, filename, true);
}

// true for horizontal spacing, false for verticle
// gap is the gap between corners
//creates a singlyly linked list in the place of a textureNode
//allows for the changing of the textures height and width
void Character::fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, float frameWidth, float frameHeight, bool horizontal, int gap, const char* filename , bool loop)
{
	{
		int frameIndex = 0;
		sf::Vector2f gapVector(0.f, 0.f);

		//set gap vector
		if (horizontal)
		{
			gapVector.x = gap;
		}
		else
		{
			gapVector.y = gap;
		}


		startFrame = new textureNode;
		startFrame->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, frameWidth, frameHeight));

		frameIndex++;

		textureNode* pCur = startFrame;
		while (frameIndex < numFrames)
		{
			pCur->pNext = new textureNode;
			pCur->pNext->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, frameWidth, frameHeight));
			pCur = pCur->pNext;
			frameIndex++;
		}

		if (loop)//loops if that is required (ie for walk frame) (creates circularly linked list)
		{
			pCur->pNext = startFrame;
		}

	}
}


//interaction between this character and a player// by default just prints if there was intersection
void Character::interacts(Player& hero)//default 
{
	if (hero.getGlobalBounds().intersects(this->getGlobalBounds()))
	{
		std::cout << "Character has touched hero";
	}
}

//interaction between this character and a snail// by default just prints if there was intersection
void Character::interacts(Snail& hero)
{
	if (hero.getGlobalBounds().intersects(this->getGlobalBounds()))
	{
		std::cout << "Character has touched snail";
	}
}

//changes x and y to the position that would place the character's upper left corner at 0,0
void Character::X_and_Y_Spawn_Locations(float& x, float& y)
{
	this->X_and_Y_Spawn_Locations(x, y, rand());
}

//changes x and y to the position that would place the character's upper left corner at 0,0/spawnPoint is ignored
void Character::X_and_Y_Spawn_Locations(float& x, float& y, int spawnPoint)
{
	x = 0 + this->width * this->mScale / 2.f;
	y = 0 + this->width * this->mScale / 2.f;
}


//turns the character around when unit Vector points in the direction the character is not facing
void Character::shouldITurnAround(sf::Vector2f directionVector)
{
	//changing direction
	if (directionVector.x > 0 && this->facing == -1)
	{
		this->scale(-1.f, 1.f);
		this->facing = 1;
	}
	else if (directionVector.x < 0 && this->facing == 1)
	{
		this->scale(-1.f, 1.f);
		this->facing = -1;
	}
}

//changes the characters texture to the next walk frame
void Character::nextWalkFrame(void)
{
	if (this->currentWalkFrame != nullptr)
	{
		this->currentWalkFrame = this->currentWalkFrame->pNext;
		this->setTexture(this->currentWalkFrame->frame, true);
	}
}


//work in tandem to decay speed and the movement vector such that if an outside force moves the character, they eventually set themselves back to default
void Character::decaySpeed(float  deltaTime)
{

	//this->speed -= this->speed * 0.001;
	this->speed -= this->speed * deltaTime;
}
void Character::decayMovment(float  deltaTime)
{
	float decayRate = 0.2f;
	if (this->movementDirection.x > 0.1 )
	{
		this->movementDirection.x -= decayRate * deltaTime;
	}
	else if (this->movementDirection.x < -0.1)
	{
		this->movementDirection.x += decayRate * deltaTime;
	}
	else
	{
		this->movementDirection.x = 0;
	}

	if (this->movementDirection.y > 0.1)
	{
		this->movementDirection.y -= decayRate * deltaTime;
	}
	else if (this->movementDirection.y < -0.1)
	{
		this->movementDirection.y += decayRate * deltaTime;
	}
	else
	{
		this->movementDirection.y = 0;
	}
}