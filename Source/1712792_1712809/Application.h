#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H



#include "Player.h"
#include "Ball.h"
#include <random>
#include <map>
#include <vector>



class Application
{
	friend class Player;
public:
						Application();
	void				run();
	void				autoPlay();
	  
private:
	void				processInput();
	void				update(const sf::Time&);
	void				render();

private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow								gWindow;
	Player											gPlayer1;
	Player											gPlayer2;
	Ball											gBall; 
	std::map<std::string, std::vector<Entity*>>		gObjects;
	bool											autoPlayEnabled;
};

#endif // GAME_APPLICATION_H

