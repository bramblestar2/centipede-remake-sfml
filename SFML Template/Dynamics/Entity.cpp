#include "Entity.h"

Entity::Entity(const sf::Vector2f& position)
{
	m_prediction_multiplier = 1;
	m_dynamic = true;
	m_health = -1;
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineColor(sf::Color::Red);
}

sf::RectangleShape& Entity::getSprite()
{
	return m_sprite;
}

sf::Vector2f& Entity::getVelocity()
{
	return m_velocity;
}

int Entity::getHealth() const
{
	return m_health;
}

sf::FloatRect Entity::getHitbox() const
{
	return m_hitbox.getGlobalBounds();
}

void Entity::setVelocity(const sf::Vector2f& velocity)
{
	m_velocity = velocity;
}

void Entity::setHealth(const int health)
{
	m_health = health;
}


void Entity::updateHitbox()
{
	m_hitbox.setSize(m_sprite.getSize());
	m_hitbox.setOrigin(m_sprite.getOrigin());
	m_hitbox.setPosition(m_sprite.getPosition() + m_velocity);
}
