#include "Player.h"



Player::Player(const sf::Vector2f& pos, const sf::Vector2f& v)
	: Entity::Entity(pos, v)
	, moveLeft(false)
	, moveRight(false)
{
	avatar.setPosition(pos);
	playerTexture.loadFromFile("player.png");
	avatar.setTexture(playerTexture);
	avatar.scale(0.3f, 0.1f);
}

void Player::handleRealTimeInput(sf::Keyboard::Key key1, sf::Keyboard::Key key2)//handle real time input
{
	if (sf::Keyboard::isKeyPressed(key1))
		moveLeft = true;
	else
		moveLeft = false;

	if (sf::Keyboard::isKeyPressed(key2))
		moveRight = true;
	else
		moveRight = false;

}

void Player::update(const sf::Time& dt)
{
	if (avatar.getPosition().x < 0)
	{
		avatar.setPosition(0, avatar.getPosition().y);
		return;
	}
	if (avatar.getPosition().x > 550)
	{
		avatar.setPosition(550, avatar.getPosition().y);
		return;
	}
	if (moveLeft)
		avatar.move(-velocity.x * (float)dt.asSeconds(), 0.f);

	if (moveRight)
		avatar.move(velocity.x * (float)dt.asSeconds(), 0.f);
}
