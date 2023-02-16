#pragma once
#include <SFML/Graphics.hpp>

class Dynamic
{
public:
	virtual bool collision(const sf::FloatRect collision_rect, sf::Vector2f& velocity) = 0;

	virtual void update() = 0;
	virtual void updateEvents(const sf::Event& event) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates& states) = 0;
protected:
	bool m_dynamic;
};

