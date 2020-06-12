#include "Entity.h"




bool Entity::collisionDetection(const Entity& object)//detect collided object using bounded-box
{
	if (avatar.getGlobalBounds().intersects(object.avatar.getGlobalBounds()))
		return true;

	return false;
}

Entity::Entity(const sf::Vector2f& pos, const sf::Vector2f& v)
	: velocity(v) {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const//use in rendering
{
	states.transform *= getTransform();
	target.draw(avatar, states);
}
