#include "Ball.h"



Ball::Ball(const sf::Vector2f& pos, const sf::Vector2f& v)
	: Entity::Entity(pos, v)
{
	ballTexture.loadFromFile("ball.png");
	avatar.setTexture(ballTexture);
	avatar.scale(0.1f, 0.1f);
	avatar.setPosition(pos);
	velocity = v;
	isMoving = false;
}

void Ball::update(const sf::Time& dt)
{
	if (!isMoving)
		return;

	
	if (avatar.getPosition().x > 600.0 || avatar.getPosition().x < 0)
		bounceWall();
	
	avatar.move(velocity.x * (float)dt.asSeconds(), velocity.y * (float)dt.asSeconds());
}

void Ball::accelerate()
{
	if (abs(velocity.x) < 2500)
	{
		velocity.x *= 1.1f;
		velocity.y *= 1.1f;
	}
}

void Ball::bouncePaddle()
{
	velocity.y *= -1;
}

void Ball::bounceWall()
{
	velocity.x *= -1;
}