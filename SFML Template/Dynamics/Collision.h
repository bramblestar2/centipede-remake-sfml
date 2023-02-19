#pragma once
#include <SFML/Graphics.hpp>
class Collision
{
public:
	//Initializes the hitbox
	Collision();

	//Returns true if two rects are intersecting
	bool collision(const sf::FloatRect& collision_rect);
	//Returns true if two rects are intersecting, changes velocity to 0 depending on where
	//the rect is colliding
	bool collisionVelocity(const sf::FloatRect& collision_rect, sf::Vector2f& velocity);
	//Returns true if two rects are intersecting, changes velocity to 0 depending on where
	//the rect is colliding, and also corrects the position
	bool collisionPositionVelocity(const sf::FloatRect& collision_rect, 
								   sf::Vector2f& position, sf::Vector2f& velocity);

	void setPredictionMult(const float prediction_mult);
	float getPredictionMult() const;

	void setRectPtr(sf::RectangleShape* const rect_ptr);
	void setSpritePtr(sf::Sprite* const sprite_ptr);

	void render(sf::RenderTarget& target, sf::RenderStates& states);
private:
	void updateHitbox();

	sf::Sprite* m_sprite_ptr;
	sf::RectangleShape* m_rect_ptr;

	sf::RectangleShape m_collision_box;

	float m_prediction_mult;
};

