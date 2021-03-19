#pragma once
#include "Window.h"
#include <algorithm>

const int WINDOW_DIV = 9;

class BoardScale
{
public:
	static BoardScale& instance();
	void setBoardScale(const int& size);
	void resetBoardScale();
	void setBoardSize(const int& size);
	void setMarginX();
	void setMarginY();
	void setcellWidth();
	void setBoardWidth();
	void setScale();
	void setReScale(const bool& re);
	bool reScale() const;
	const float& getcellWidth();
	const float& getBoardWidth();
	const float& getMarginX();
	const float& getMarginY();
	const float& getBoardSize();
	sf::Vector2f getScale() const;


private:
	BoardScale();
	~BoardScale();
	Window &m_window = Window::instance();
	bool m_reScale;
	int m_size;
	sf::Vector2f scale;
	sf::Vector2f margin;
	float board_width;
	float cell_width;
};