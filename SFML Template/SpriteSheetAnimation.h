#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SpriteSheetAnimation
{
public:
	~SpriteSheetAnimation();

	void setup(sf::Texture* sheet, sf::Time frame_time, const int start_frame, const int end_frame);

	void addFrame(sf::IntRect frame);
	void setFrameTime(sf::Time frame_time);
	void setFrames(const int start_frame, const int end_frame);
	void setCurrentFrame(const int frame);
	void setSpriteSheet(sf::Texture* texture);

	sf::Texture* getSpriteSheet() const;
	int getCurrentFrame() const;

	void update(sf::Sprite&);
	void update(sf::RectangleShape&);
private:
	void updateFrame();

	std::vector<sf::IntRect*> m_frames;
	sf::Texture* m_sprite_sheet;
	sf::Clock m_frame_clock;
	sf::Time m_frame_time;

	int m_current_frame, m_start_frame, m_end_frame;
	bool m_updated;
};

