#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, std::unordered_map<std::string, sf::IntRect>> SpriteMap;
class SpriteMovement {
private:
	inline static SpriteMap& getMap() {
		static SpriteMap map;

		return map;
	}
public:
	inline static void setSprite(std::string klass, std::string s, sf::IntRect r) {
		auto val =  getSprite(klass, s);
		if (val == sf::IntRect{ -1,-1,-1,-1 }) {
			getMap()[klass][s] = r;
		}
	}
	inline static sf::IntRect getSprite(std::string klass, std::string s) {
		auto val = getMap().find(klass);
		if (val == getMap().end()) {
			return sf::IntRect{ -1,-1,-1,-1 };
		}
		auto state = (*val).second.find(s);
		if (state == (*val).second.end()) {
			return sf::IntRect{ -1,-1,-1,-1 };
			//----
		}
		return (*state).second;
	}
};