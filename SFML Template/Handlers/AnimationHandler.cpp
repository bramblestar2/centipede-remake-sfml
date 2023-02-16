#include "AnimationHandler.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::map<std::string, std::map<std::string, std::vector<sf::Texture*>>> AnimationHandler::m_animations;

void AnimationHandler::load(const std::string type,
							const std::string animation_type, 
							const std::string animation_path, const std::string file_formats,
							const int start_frame, const int end_frame)
{
	//Load frames
	if (fs::exists(animation_path))
	{
		for (int i = start_frame; i < end_frame; i++)
		{
			sf::Texture* texture = new sf::Texture();
			
			//Load file, if failed, delete texture ptr
			if (!texture->loadFromFile(animation_path + "/"
				+ formatToString(file_formats, i)))
				delete texture;
			else
				m_animations[type][animation_type].push_back(texture);
		}
	}
}

std::vector<sf::Texture*>* AnimationHandler::get(const std::string type, 
												 const std::string animation_type)
{
	auto foundType = m_animations.find(type);

	if (foundType != m_animations.end())
	{
		auto foundAnimation = m_animations[type].find(animation_type);
		if (foundAnimation != m_animations[type].end())
			return &m_animations[type][animation_type];
	}

	return nullptr;
}

void AnimationHandler::free(const std::string type, const std::string animation_type)
{
	auto foundType = m_animations.find(type);

	if (foundType != m_animations.end())
	{
		auto foundAnimation = m_animations[type].find(animation_type);
		if (foundAnimation != m_animations[type].end())
		{
			while (m_animations[type][animation_type].size() > 0)
			{
				delete m_animations[type][animation_type].at(0);
				m_animations[type][animation_type].erase(m_animations[type][animation_type].begin());
			}
			m_animations[type].erase(animation_type);
			if (m_animations[type].size() <= 0)
				m_animations.erase(type);
		}
	}
}

void AnimationHandler::freeAll()
{
	for (auto& s : m_animations)
	{
		for (auto& textures : s.second)
		{
			while (textures.second.size() > 0)
			{
				delete textures.second.at(0);
				textures.second.erase(textures.second.begin());
			}
		}
	}

	std::cout << "Handler pointers have been cleared.\n";
}

std::string AnimationHandler::formatToString(const std::string format, const int frame)
{
	std::string string_frame = format;
	size_t found = string_frame.find_last_of('#');

	if (found != std::string::npos)
		string_frame = string_frame.replace(found, 1, std::to_string(frame));
	else
		string_frame = "null";

	return string_frame;
}
