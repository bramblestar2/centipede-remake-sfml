#include "Animated.h"

Animated::Animated(const std::string path, const std::string format, 
    const int start_frames, const int end_frames, const sf::Time time)
{
    m_frame_time = time;
    m_file_format = end_frames - start_frames;
    m_path = path;

    m_current_frame = 0;
    m_max_frames = -1;

    loadFrames(start_frames, end_frames);
}

Animated::~Animated()
{
}

void Animated::update(sf::RectangleShape& sprite)
{
    if (m_updated)
    {
        sprite.setTexture(m_frames.at(m_current_frame));

        m_updated = false;
    }
}

void Animated::update(sf::Sprite& sprite)
{
    if (m_updated)
    {
        sprite.setTexture(*m_frames.at(m_current_frame));

        m_updated = false;
    }
}

int Animated::getFrame() const
{
    return m_current_frame;
}

void Animated::setFrame(const int frame)
{
    if (frame < m_max_frames && frame > 0)
        m_current_frame = frame;
}

void Animated::setFrameCount(const int count)
{
    m_max_frames = count;
}

int Animated::getFrameCount() const
{
    return m_max_frames;
}

std::string Animated::getFramePathString()
{
    std::string string_frame = m_file_format;
    size_t found = string_frame.find_last_of('#');

    if (found != std::string::npos)
        string_frame = string_frame.replace(found, 1, std::to_string(m_current_frame));
    else
        string_frame = "null";

    return m_path + "\\" + string_frame;
}

void Animated::updateFrame()
{
    if (m_max_frames > 0)
    {
        sf::Time time = m_frame_clock.getElapsedTime();

        if (time > m_frame_time)
        {
            if (m_current_frame < m_max_frames)
                m_current_frame++;
            else
                m_current_frame = 0;

            m_updated = true;

            m_frame_clock.restart();
        }
    }
    else
        m_frame_clock.restart();
}

void Animated::loadFrames(const int start, const int end)
{
    clearFrames();

    for (int i = start; i < end; i++)
    {
        sf::Texture* frame = new sf::Texture();
        frame->loadFromFile(getFramePathString());
    }
}

void Animated::clearFrames()
{
    while (m_frames.size() > 0)
    {
        delete m_frames.at(0);
        m_frames.erase(m_frames.begin());
    }
}
