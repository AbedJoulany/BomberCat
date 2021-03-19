#pragma once
#include <queue>

int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

class QueueNode
{
public:
	QueueNode(const sf::Vector2i p, const sf::Vector2i& d) :pt(p), direction(d) {}
	~QueueNode() {};
	sf::Vector2i pt;  // The cordinates of a cell 
	const sf::Vector2i direction;
};