#pragma once
#include <string>
class VideoGame
{
	friend std::ostream &operator<<(std::ostream &osm, const VideoGame &videogame);
private:
	std::string m_name;
	int m_price;
public:
	VideoGame(std::string name, int price);
	~VideoGame();
	bool operator<(const VideoGame &videogame);
	bool operator>(const VideoGame &videogame);
	bool operator==(const VideoGame &videogame);
};
// overloaded output
std::ostream &operator<<(std::ostream &osm, const VideoGame &videogame);
