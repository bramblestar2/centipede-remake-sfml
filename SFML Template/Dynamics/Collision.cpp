#include "Collision.h"

Collision::Collision()
{
	m_prediction_mult = 1;
	m_sprite_ptr = nullptr;
	m_rect_ptr = nullptr;

	m_collision_box.setFillColor(sf::Color::Transparent);
	m_collision_box.setOutlineColor(sf::Color::Red);
	m_collision_box.setOutlineThickness(1);
}

bool Collision::collision(const sf::FloatRect& collision_rect)
{
	return m_collision_box.getGlobalBounds().intersects(collision_rect);
}

bool Collision::collisionVelocity(const sf::FloatRect& collision_rect, sf::Vector2f& velocity)
{
	if (collision(collision_rect))
	{
		sf::FloatRect rect = m_collision_box.getGlobalBounds();

		float r_left = rect.left;
		float r_right = rect.left + rect.width;
		float r_top = rect.top;
		float r_bottom = rect.top + rect.height;

		float left = collision_rect.left;
		float right = collision_rect.left + collision_rect.width;
		float top = collision_rect.top;
		float bottom = collision_rect.top + collision_rect.height;

		/*		 
		*		Top
		*		-------
		*		|	  |
		*	Left|	  |Right
		*		|	  |
		*		-------
		*		Bottom
		*/		

		//check if collision_rect is to the left of m_collision_box
		if (left > r_left)
		{
			velocity.x = 0;
		}
		
		//check if collision_rect is to the right of m_collision_box
		else if (right < r_right)
		{
			velocity.x = 0;
		}

		//check if collision_rect is to the top of m_collision_box
		if (top > r_top)
		{
			velocity.y = 0;
		}
		
		//check if collision_rect is to the bottom of m_collision_box
		else if (bottom > r_bottom)
		{
			velocity.y = 0;
		}
		
		return true;
	}
	return false;
}

bool Collision::collisionPositionVelocity(const sf::FloatRect& collision_rect, sf::Vector2f& position, sf::Vector2f& velocity)
{
	return false;
}

void Collision::setPredictionMult(const float prediction_mult)
{
	m_prediction_mult = prediction_mult;
}

float Collision::getPredictionMult() const
{
	return m_prediction_mult;
}

void Collision::setRectPtr(sf::RectangleShape* const rect_ptr)
{
	m_rect_ptr = rect_ptr;
	m_sprite_ptr = nullptr;
}

void Collision::setSpritePtr(sf::Sprite* const sprite_ptr)
{
	m_sprite_ptr = sprite_ptr;
	m_rect_ptr = nullptr;
}

void Collision::render(sf::RenderTarget& target, sf::RenderStates& states)
{
	target.draw(m_collision_box, states);
}

void Collision::updateHitbox()
{
	if (m_rect_ptr != nullptr)
	{
		m_collision_box.setSize(m_rect_ptr->getSize());
		m_collision_box.setPosition(m_rect_ptr->getPosition());
		m_collision_box.setOrigin(m_rect_ptr->getOrigin());
	}
	else if (m_sprite_ptr != nullptr)
	{
		m_collision_box.setSize(sf::Vector2f(m_sprite_ptr->getGlobalBounds().width, 
											 m_sprite_ptr->getGlobalBounds().height));
		m_collision_box.setPosition(m_sprite_ptr->getPosition());
		m_collision_box.setOrigin(m_sprite_ptr->getOrigin());
	}
}
