#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animated
{
public:
	~Animated();

	/* filename_format: # will be replaced with numbers */
	void setup(const std::string path, const std::string filename_format,
			const int start_frames, const int end_frames, const sf::Time frame_time);

	void update(sf::RectangleShape& sprite);
	void update(sf::Sprite& sprite);


	int getCurrentFrame() const;
	sf::Texture* getFrame() const;
	void setFrame(const int frame);

	void setFrameCount(const int count);
	int getFrameCount() const;

private:
	std::string getFramePathString(int frame);
	void updateFrame();
	void loadFrames(const int start, const int end);
	void clearFrames();

	sf::Clock m_frame_clock;
	sf::Time m_frame_time;
	std::vector<sf::Texture*> m_frames;
	std::string m_path, m_file_format;
	int m_max_frames;
	int m_start_frame, m_end_frame;
	int m_current_frame;
	bool m_updated;
};

