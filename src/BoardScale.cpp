#include "BoardScale.h"
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
BoardScale::BoardScale()
{
	m_size = 0;
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
BoardScale::~BoardScale()
{
}
//------------------------------------------------------------------------//
// ------------------------ singlton ------------------------------------//
//----------------------------------------------------------------------//
BoardScale& BoardScale::instance()
{
	static BoardScale board_scale;
	return board_scale;
}
//------------------------------------------------------------------------//
// ------------------------ setting the scale --------------------------//
//----------------------------------------------------------------------//
void BoardScale::setBoardScale(const int &size)
{
	this->setBoardSize(size);
	this->resetBoardScale();
}
//------------------------------------------------------------------------//
// ------------------------ resetting the scale -------------------------//
//----------------------------------------------------------------------//
void BoardScale::resetBoardScale()
{
	this->setMarginY();
	this->setBoardWidth();
	this->setMarginX();
	this->setcellWidth();
	this->setScale();
}
//------------------------------------------------------------------------//
// ------------------------ saving the board size -----------------------//
//----------------------------------------------------------------------//
void BoardScale::setBoardSize(const int& size)
{
	m_size = size;
}
//------------------------------------------------------------------------//
// ------------------------ saving the Xmargin --------------------------//
//----------------------------------------------------------------------//
void BoardScale::setMarginX()
{
	margin.x = m_window.getWidth() < board_width ? 0 : std::abs(board_width - m_window.getWidth()) / 2;
}
//------------------------------------------------------------------------//
// ------------------------ saving the Ymargin --------------------------//
//----------------------------------------------------------------------//
void BoardScale::setMarginY()
{
	margin.y = m_window.getHeight() / WINDOW_DIV;
}
//------------------------------------------------------------------------//
// ------------------------ saving the cell width -----------------------//
//----------------------------------------------------------------------//
void BoardScale::setcellWidth()
{
	cell_width = board_width / m_size;
}
//------------------------------------------------------------------------//
// ------------------------ saving board width --------------------------//
//----------------------------------------------------------------------//
void BoardScale::setBoardWidth()
{
	board_width = std::min(m_window.getWidth(), m_window.getHeight() - margin.y);
}
//------------------------------------------------------------------------//
// ------------------------ saving the scale ----------------------------//
//----------------------------------------------------------------------//
void BoardScale::setScale()
{
	scale = { cell_width, cell_width };
}
//------------------------------------------------------------------------//
// ---------- to check if screen mode changed ---------------------------//
//----------------------------------------------------------------------//
void BoardScale::setReScale(const bool& re)
{
	m_reScale = re;
}
//------------------------------------------------------------------------//
// ------------ rescaling when maximizing or minimizing the screen ------//
//----------------------------------------------------------------------//
bool BoardScale::reScale() const
{
	return m_reScale;
}
//------------------------------------------------------------------------//
// ---------- getting cell width to calculate the scale -----------------//
//----------------------------------------------------------------------//
const float& BoardScale::getcellWidth()
{
	return cell_width;
}
//------------------------------------------------------------------------//
// ---------- getting board width to calculate the scale ----------------//
//----------------------------------------------------------------------//
const float& BoardScale::getBoardWidth()
{
	return board_width;
}
//------------------------------------------------------------------------//
// ------ getting margin X to move the board to the mid of screen -------//
//----------------------------------------------------------------------//
const float& BoardScale::getMarginX()
{
	return margin.x;
}
//------------------------------------------------------------------------//
// ------ getting margin Y to move the board down for gameStatus --------//
//----------------------------------------------------------------------//
const float& BoardScale::getMarginY()
{
	return margin.y;
}
//------------------------------------------------------------------------//
// ------------------------ getting boardSize ---------------------------//
//----------------------------------------------------------------------//
const float& BoardScale::getBoardSize()
{
	return m_size;
}
//------------------------------------------------------------------------//
// ------------------------ getting BoardScale --------------------------//
//----------------------------------------------------------------------//
sf::Vector2f BoardScale::getScale() const
{
	return scale;
}
//------------------------------------------------------------------------//
// ----------------------------------------------------------------------//
//----------------------------------------------------------------------//



