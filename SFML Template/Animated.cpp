#include "Animated.h"
#include <iostream>

void Animated::setup(std::vector<sf::Texture*>* frames,
    const int start_frames, const int end_frames, const sf::Time frame_time)
{
    m_frame_time = frame_time;

    m_current_frame = start_frames;
    m_start_frame = start_frames;
    m_end_frame = end_frames;
    m_max_frames = end_frames - start_frames;

    m_frames = frames;

    //m_frame_clock = std::chrono::high_resolution_clock::now();

    m_dt = 1;

    m_updated = true;
}

void Animated::update(sf::RectangleShape& sprite)
{
    if (m_updated)
    {
        sprite.setTexture(m_frames->at(m_current_frame-1));

        m_updated = false;
    }

    updateFrame();
}

void Animated::update(sf::Sprite& sprite)
{
    if (m_updated)
    {
        sprite.setTexture(*m_frames->at(m_current_frame-1));

        m_updated = false;
    }

    updateFrame();
}

int Animated::getCurrentFrame() const
{
    return m_current_frame;
}

sf::Texture* Animated::getFrame() const
{
    return m_frames->at(m_current_frame-1);
}

void Animated::setDT(const double dt)
{
    m_dt = dt;
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

void Animated::updateFrame()
{
    if (m_max_frames > 0)
    {
        sf::Time time = m_frame_clock.getElapsedTime();
        //double time = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - m_frame_clock).count();

        if (time > m_frame_time)
        {
            if (m_current_frame < m_max_frames)
                m_current_frame++;
            else
                m_current_frame = m_start_frame;

            m_updated = true;

            //m_frame_clock = std::chrono::high_resolution_clock::now();
            m_frame_clock.restart();
        }
    }
}
