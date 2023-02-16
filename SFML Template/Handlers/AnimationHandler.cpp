#include "AnimationHandler.h"

std::map<std::string, std::map<std::string, std::vector<sf::Texture*>>> AnimationHandler::m_animations;

void AnimationHandler::load(const std::string type, 
							const std::string animation_type, 
							const std::string animation_path, 
							const std::string file_formats)
{
	//Load frames
}

std::vector<sf::Texture*>* AnimationHandler::get(const std::string type, 
												 const std::string animation_type)
{
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
				m_animations[type].erase(animation_type);
			}
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
				delete textures.second.at(0);
		}
	}
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
