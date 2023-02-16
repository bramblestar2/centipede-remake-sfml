#pragma once
#include "../Animated.h"
#include <vector>
class AnimationHandler// : public Handler<std::string, std::map<std::string, std::vector<sf::Texture*>>>
{
public:
	static void load(const std::string type, 
					 const std::string animation_type,
					 const std::string animation_path,
					 const std::string file_formats);
	static std::vector<sf::Texture*>* get(const std::string type,
										  const std::string animation_type);
	static void free(const std::string type, const std::string animation_type);
	static void freeAll();

private:
	static std::string formatToString(const std::string format, const int frame);

	//			Type		Animation Type			PNG's
	static std::map<std::string, std::map<std::string, std::vector<sf::Texture*>>> m_animations;
};

