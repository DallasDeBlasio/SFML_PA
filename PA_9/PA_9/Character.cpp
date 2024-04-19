#include "Character.hpp"


Character::Character():Sprite()
{
	this->speed = 0.2;
	this->mHP = 30;
	this->mDamage = 0;
	this->movmentSpeed = 0.2;
	this->facing = 1;
	this->mScale = 1;
	this->height = 50;
	this->width = 50;
	this->setScale(this->mScale, this->mScale);

	this->setOrigin(this->width / 2.f, this->height / 2.f);

	this->movementDirection = sf::Vector2f(0.f, 0.f);

}

Character::Character(int scale,int width, int height)
{
	this->speed = 0.2;
	this->mHP = 30;
	this->mDamage = 0;
	this->movmentSpeed = 0.2;
	this->facing = 1;
	this->mScale = scale;
	this->width = width;
	this->height = height;
	this->setOrigin(this->width / 2.0, this->height / 2.0);//sets origin to center of object

	this->setScale(this->mScale, this->mScale);

	this->movementDirection = sf::Vector2f(0.f, 0.f);
	this->hitbox.setSize(this->getGlobalBounds().getSize());
	this->hitbox.setPosition(this->getGlobalBounds().getPosition());

}

void Character::moveV(void)
{
	static int cycle = 0;
	sf::Vector2f unitVector(getUnitVector(this->movementDirection));
	sf::Vector2f speed_in_direction_unitVector = unitVector * this->speed;

	if (speed_in_direction_unitVector.x < 0)//left side boundry
	{
		if (this->getPosition().x - this->width / 2.f * this->mScale < 0)
		{
			this->setPosition(0 + this->width/2.f * this->mScale, this->getPosition().y);
		}
		else
		{
			this->move(speed_in_direction_unitVector.x, 0);
		}
	}
	
	if(speed_in_direction_unitVector.x > 0)//right side boundry
	{
		if (this->getPosition().x + this->width / 2.f * this->mScale > 960)//hardcoding window size as of right now
		{
			this->setPosition(960 - this->width / 2.f * this->mScale, this->getPosition().y);
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
		}
		else
		{
			this->move(0, speed_in_direction_unitVector.y);
		}
	}
	
	if(speed_in_direction_unitVector.y > 0)//bottom boundry
	{
		if (this->getPosition().y + this->height / 2.f * this->mScale > 960)//hardcoding window size right now
		{
			this->setPosition(this->getPosition().x, 960 - this->height / 2.f * this->mScale);
		}
		else
		{
			this->move(0, speed_in_direction_unitVector.y);
		}
	}

	if (cycle > 200 && getVectorManitude(speed_in_direction_unitVector) != 0)
	{
		cycle = 0;
		this->nextWalkFrame();
	}
	//std::cout << cycle << std::endl;

	this->shouldITurnAround(unitVector);

	
	//update hitbox
	this->hitbox.setSize(this->getGlobalBounds().getSize());
	this->hitbox.setPosition(this->getGlobalBounds().getPosition());

	decayMovment();
	cycle++;

}

void Character::decayMovment(void)
{
	if (this->movementDirection.x > 1)
	{
		this->movementDirection.x -= 0.95;//this->movementSpeed
	}
	else if (this->movementDirection.y < -1)
	{
		this->movementDirection.x += 0.95;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.x = 0;
	}

	if (this->movementDirection.y > 1)
	{
		this->movementDirection.y -= 0.95;//this->movmentSpeed;
	}
	else if (this->movementDirection.y < -1)
	{
		this->movementDirection.y += 0.95;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.y = 0;
	}
}


// true for horizontal spacing, false for verticle
// gap is the gap between corners
void Character::fillTextureList(int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename)
{
	int frameIndex = 0;
	sf::Vector2f gapVector(0.f,0.f);

	//set gap vector
	if (horizontal)
	{
		gapVector.x = gap;
	}
	else
	{
		gapVector.y = gap;
	}

	//sf::Texture wholeSheet;
	//wholeSheet.loadFromFile(filename);
	this->currentFrame = new textureNode;
	this->currentFrame->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, width, height));
	
	frameIndex++;
	
	textureNode* pCur = this->currentFrame;
	while (frameIndex < numFrames-1)
	{
		pCur->pNext = new textureNode;
		pCur->pNext->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, width, height));
		pCur = pCur->pNext;
		frameIndex++;
	}

	pCur->pNext = this->currentFrame;
	this->setTexture(this->currentFrame->frame);

}

void Character::firstTexture(int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename)
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

	//sf::Texture wholeSheet;
	//wholeSheet.loadFromFile(filename);
	this->currentFrame = new textureNode;
	this->currentFrame->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.x * frameIndex, width, height));

	//frameIndex++;
	//textureNode* pCur = this->currentFrame;
	//while (frameIndex < numFrames)
	//{
	//	pCur->pNext = new textureNode;
	//	pCur->pNext->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.x * frameIndex, width, height));
	//	pCur = pCur->pNext;
	//}

	//pCur->pNext = this->currentFrame;
	this->setTexture(this->currentFrame->frame);

}

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

void Character::nextWalkFrame(void)
{
	this->currentFrame = this->currentFrame->pNext;
	this->setTexture(this->currentFrame->frame);
}
