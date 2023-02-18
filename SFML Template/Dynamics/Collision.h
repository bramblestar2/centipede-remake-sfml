#pragma once
#include <SFML/Graphics.hpp>
class Collision
{
public:
	Collision();

	bool collision(const sf::FloatRect collision_rect);
	bool collisionVelocity(const sf::FloatRect collision_rect, sf::Vector2f& velocity);
	bool collisionPositionVelocity(const sf::FloatRect collision_rect, 
								   sf::Vector2f& position, sf::Vector2f& velocity);
private:
	sf::RectangleShape m_collision_box;
};

