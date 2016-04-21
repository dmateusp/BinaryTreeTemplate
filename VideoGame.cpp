#include "VideoGame.h"
VideoGame::VideoGame(std::string name, int price): m_name(name), m_price(price)
{}
VideoGame::~VideoGame()
{}
std::ostream &operator<<(std::ostream &osm, const VideoGame &videogame) {
	osm << videogame.m_name << " : price ->" << videogame.m_price << ";";
	return osm;
}
bool VideoGame::operator<(const VideoGame &videogame) {
	return m_price < videogame.m_price;
}
bool VideoGame::operator>(const VideoGame &videogame) {
	return m_price > videogame.m_price;
}
bool VideoGame::operator==(const VideoGame &videogame) {
	return m_name == videogame.m_name;
}