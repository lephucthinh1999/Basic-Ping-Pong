#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include "Entity.h"



class Player :
	public Entity
{
	friend class Application;
public:
							Player(const sf::Vector2f&, const sf::Vector2f&);
	void					handleRealTimeInput(sf::Keyboard::Key, sf::Keyboard::Key); // NEED INPUT DETECTION

private:
	void					update(const sf::Time&) override;

private:
	bool					moveLeft;
	bool					moveRight;
	sf::Texture				playerTexture;
};


#endif // GAME_PLAYER_H
