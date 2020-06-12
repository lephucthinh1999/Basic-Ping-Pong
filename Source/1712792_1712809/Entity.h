#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


#include <SFML/Graphics.hpp>



class Entity : public sf::Drawable, public sf::Transformable
{
public:
							Entity(const sf::Vector2f&, const sf::Vector2f&);

protected:
	virtual void			update(const sf::Time&) = 0;
	void					draw(sf::RenderTarget&, sf::RenderStates) const override;
	bool					collisionDetection(const Entity&);

protected:
	sf::Sprite				avatar;
	sf::Vector2f			velocity;
};


#endif // GAME_ENTITY_H
