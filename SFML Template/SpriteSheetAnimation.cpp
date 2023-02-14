#include "SpriteSheetAnimation.h"

SpriteSheetAnimation::~SpriteSheetAnimation()
{
	while (m_frames.size() > 0)
	{
		delete m_frames.at(0);
		m_frames.erase(m_frames.begin());
	}
}

void SpriteSheetAnimation::setup(sf::Texture* const sheet, sf::Time frame_time,
	const int start_frame, const int end_frame)
{


	setFrames(start_frame, end_frame);
}

void SpriteSheetAnimation::addFrame(sf::IntRect& frame)
{
	m_frames.push_back(new sf::IntRect(frame));
}

void SpriteSheetAnimation::setFrameTime(sf::Time frame_time)
{
	m_frame_time = frame_time;
}

void SpriteSheetAnimation::setFrames(const int start_frame, const int end_frame)
{
	m_start_frame = start_frame;
	m_end_frame = end_frame;

	m_current_frame = start_frame;
}

void SpriteSheetAnimation::setCurrentFrame(const int frame)
{
	if (frame < m_frames.size() && frame >= 0)
		m_current_frame = frame;
}

void SpriteSheetAnimation::loadSpriteSheet(std::string path)
{
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile(path))
	{
		m_sprite_sheet = texture;
	}
	else
		delete texture;
}

int SpriteSheetAnimation::getCurrentFrame() const
{
	return m_current_frame;
}

void SpriteSheetAnimation::update(sf::Sprite& sprite)
{
	if (m_updated)
	{
		sprite.setTexture(*m_sprite_sheet);
		sprite.setTextureRect(*m_frames.at(m_current_frame));

		m_updated = false;
	}

	updateFrame();
}

void SpriteSheetAnimation::update(sf::RectangleShape& sprite)
{
	if (m_updated)
	{
		sprite.setTexture(m_sprite_sheet);
		sprite.setTextureRect(*m_frames.at(m_current_frame));

		m_updated = false;
	}

	updateFrame();
}

void SpriteSheetAnimation::updateFrame()
{
	if (m_frames.size() > 0)
	{
		sf::Time time = m_frame_clock.getElapsedTime();

		if (time > m_frame_time)
		{
			if (m_current_frame < m_end_frame)
				m_current_frame++;
			else
				m_current_frame = m_start_frame;

			m_updated = true;

			m_frame_clock.restart();
		}
	}
}
