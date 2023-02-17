#pragma once
#include "Dynamic.h"

class Entity : public Dynamic
{
public:
	sf::RectangleShape& getSprite();
	sf::Vector2f& getVelocity();
	int getHealth() const;
	sf::FloatRect getHitbox() const;

	void setVelocity(const sf::Vector2f& velocity);
	void setHealth(const int health);

	virtual bool collision(const sf::FloatRect collision_rect, sf::Vector2f& velocity) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates& states) override;
protected:
	Entity(const sf::Vector2f& position);
	void updateHitbox();

	float m_prediction_multiplier;
private:
	sf::Vector2f m_velocity;
	sf::RectangleShape m_sprite;
	sf::RectangleShape m_hitbox;
	int m_health;
};

