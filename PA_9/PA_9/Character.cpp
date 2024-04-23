#include "Character.hpp"

int speedFactor = 2000;

Character::Character(): Character(1,50,50,0.2)
{
	//this->maxHP = 30;
	//this->mDamage = 5;
	//this->movmentSpeed = 0.2 * speedFactor;
	//this->speed = this->movmentSpeed;
	//this->facing = 1;
	//this->mScale = 1;
	//this->height = 50;
	//this->width = 50;
	//this->setScale(this->mScale, this->mScale);
	//this->currentFrame = nullptr;


	//this->setOrigin(this->width / 2.f, this->height / 2.f);
	//this->walkFrame = 0;


	//this->movementDirection = sf::Vector2f(0.f, 0.f);

}

Character::Character(int scale, int width, int height) :Character(scale, width, height, 0.2) //: Sprite()
{
	//this->maxHP = 30;
	//this->mDamage = 5;
	//this->movmentSpeed = 0.2 * speedFactor;
	//this->speed = this->movmentSpeed;
	//this->facing = 1;
	//this->mScale = scale;
	//this->width = width;
	//this->height = height;
	//this->setOrigin(this->width / 2.0, this->height / 2.0);//sets origin to center of object
	//this->walkFrame = 0;
	//this->currentFrame = nullptr;

	//this->setScale(this->mScale, this->mScale);

	//this->movementDirection = sf::Vector2f(0.f, 0.f);
	//this->hitbox.setSize(this->getGlobalBounds().getSize());
	//this->hitbox.setPosition(this->getGlobalBounds().getPosition());

}

Character::Character(int scale, int width, int height, float initialSpeed):Sprite()
{
	this->maxHP = 30;
	this->currentHP = this->maxHP;
	this->mDamage = 5;
	this->movmentSpeed = initialSpeed * speedFactor;
	this->speed = this->movmentSpeed;

	this->facing = 1;
	this->mScale = scale;
	this->width = width;
	this->height = height;
	this->setOrigin(this->width / 2.0, this->height / 2.0);//sets origin to center of object
	this->walkFrame = 0;
	this->currentFrame = nullptr;


	this->setScale(this->mScale, this->mScale);

	this->movementDirection = sf::Vector2f(0.f, 0.f);
	this->hitbox.setSize(this->getGlobalBounds().getSize());
	this->hitbox.setPosition(this->getGlobalBounds().getPosition());
	this->invinciblityTime = 0.f;


	this->mHealthBar.mBottomRectangle.setSize(sf::Vector2f(scale * this->width, 3.f)); 
	this->mHealthBar.mTopRectangle.setSize(sf::Vector2f(scale * this->width, 4.f));

	this->mHealthBar.mBottomRectangle.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 30));
	this->mHealthBar.mTopRectangle.setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + 30));

}
//

void Character::moveV(float  deltaTime)
{
	//static int cycle = 0;
	if (this->speed < this->movmentSpeed)
	{
		this->speed = this->movmentSpeed;
	}
	sf::Vector2f unitVector(getUnitVector(this->movementDirection));
	sf::Vector2f speed_in_direction_unitVector = unitVector * this->speed;
	speed_in_direction_unitVector *= deltaTime;

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

	if (this->walkFrame > 200)
	{
		this->walkFrame = 0;
		this->nextWalkFrame();
	}
	//std::cout << cycle << std::endl;

	this->shouldITurnAround(unitVector);

	
	//update hitbox
	this->hitbox.setSize(this->getGlobalBounds().getSize());
	this->hitbox.setPosition(this->getGlobalBounds().getPosition());

	this->mHealthBar.mTopRectangle.setPosition(sf::Vector2f(this->getPosition().x - width*this->mScale/2, this->getPosition().y - 10 - height*this->mScale/2));
	this->mHealthBar.mBottomRectangle.setPosition(sf::Vector2f(this->getPosition().x - width*this->mScale/2, this->getPosition().y - 10 - height*this->mScale/2));

	this->mHealthBar.mTopRectangle.setSize(sf::Vector2f(this->mScale * this->width * ((float)this->currentHP / (float)this->maxHP), 4.f));

	this->decayMovment(deltaTime);
	this->decaySpeed(deltaTime);


	if (getVectorManitude(speed_in_direction_unitVector) != 0)
	{
		this->walkFrame++;
	}
	//std::cout << this->height << std::endl;
	//std::cout << speed_in_direction_unitVector.x << std::endl;
	//std::cout << speed_in_direction_unitVector.y << std::endl << std::endl;


}




// true for horizontal spacing, false for verticle
// gap is the gap between corners
void Character::fillTextureList(textureNode*& startFrame, int numFrames, float XCoordinateFirstFrame, float YCoordinateFirstFrame, bool horizontal, int gap, const char* filename)
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
	startFrame = new textureNode;
	startFrame->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, width, height));
	
	frameIndex++;
	
	textureNode* pCur = startFrame;
	while (frameIndex < numFrames)
	{
		pCur->pNext = new textureNode;
		pCur->pNext->frame.loadFromFile(filename, sf::IntRect(XCoordinateFirstFrame + gapVector.x * frameIndex, YCoordinateFirstFrame + gapVector.y * frameIndex, width, height));
		pCur = pCur->pNext;
		frameIndex++;
	}

	pCur->pNext = startFrame;
	//this->setTexture(startFrame->frame);

}

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

		//sf::Texture wholeSheet;
		//wholeSheet.loadFromFile(filename);
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

		if (loop)
		{
			pCur->pNext = startFrame;
		}
		//this->setTexture(startFrame->frame);

	}
}

//void Character::moveV(float deltaTime)
//{
//	this->movmentSpeed 
//}

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
	if (this->currentFrame != nullptr)
	{
		this->currentFrame = this->currentFrame->pNext;
		this->setTexture(this->currentFrame->frame, true);
	}
}

void Character::decaySpeed(float  deltaTime)
{

	this->speed -= this->speed * 0.001;

	//if (this->speed < this->movmentSpeed)
	//{
	//	this->speed = this->movmentSpeed;
	//}
}

void Character::decayMovment(float  deltaTime)
{
	if (this->movementDirection.x > 1)
	{
		this->movementDirection.x -= 0.1 * deltaTime;
		//this->movementDirection.x -= this->movementDirection.x * 0.000001f;//this->movementSpeed
	}
	else if (this->movementDirection.x < -1)
	{
		this->movementDirection.x += 0.1;
		//this->movementDirection.x += this->movementDirection.x * 0.000001f;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.x = 0;
	}

	if (this->movementDirection.y > 1)
	{
		this->movementDirection.y -= 0.1;
		//this->movementDirection.y -= this->movementDirection.y * 0.000001f;//this->movmentSpeed;
	}
	else if (this->movementDirection.y < -1)
	{
		this->movementDirection.y += 0.1;
		//this->movementDirection.y += this->movementDirection.y * 0.000001f;//this->movmentSpeed;
	}
	else
	{
		this->movementDirection.y = 0;
	}
}