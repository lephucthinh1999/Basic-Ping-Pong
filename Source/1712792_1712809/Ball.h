
#ifndef GAME_BALL_H
#define GAME_BALL_H
#include<iostream>
#include "Entity.h"
#include <conio.h>

class Ball :
	public Entity
{	
	friend class Application;
public:
							Ball(const sf::Vector2f&, const sf::Vector2f&);

private:
	void					update(const sf::Time&) override;
	void					accelerate();
	void					bouncePaddle();
	void					bounceWall();

private:
	bool					isMoving;
	sf::Texture				ballTexture;
};


#endif // GAME_BALL_H

