#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>

class Animated
{
public:
	/* filename_format: # will be replaced with numbers */
	void setup(std::vector<sf::Texture*>* frames,
		const int start_frames, const int end_frames, const sf::Time frame_time);

	void update(sf::RectangleShape& sprite);
	void update(sf::Sprite& sprite);

	int getCurrentFrame() const;
	sf::Texture* getFrame() const;
	int getFrameCount() const;

	void setDT(const double dt);
	void setFrame(const int frame);
	void setFrameCount(const int count);

private:
	void updateFrame();

	sf::Clock m_frame_clock;
	//std::chrono::steady_clock::time_point m_frame_clock;
	sf::Time m_frame_time;
	std::vector<sf::Texture*>* m_frames;
	std::string m_path, m_file_format;
	int m_max_frames;
	int m_start_frame, m_end_frame;
	int m_current_frame;
	bool m_updated;

	double m_dt;
};

