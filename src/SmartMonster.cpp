#include "SmartMonster.h"
#include "QueueNode.h"


//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
SmartMonster::SmartMonster(std::string name, sf::Vector2f pos)
	:Monster(name, pos)
{
	direction = { 0,0 };
	destination = { 0,0 };
	m_moveStupid = false;
	m_CollWithBomb = false;
}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
SmartMonster::~SmartMonster()
{
}
//------------------------------------------------------------------------//
// ------------------------ moving the Monster --------------------------//
//----------------------------------------------------------------------//
void SmartMonster::move(const staticsV& m_statics, const std::unique_ptr<BomberMan>& bomber)
{
	if (isDead()) return;
	sf::Vector2i src = { this->getLocByDS().x, this->getLocByDS().y };
	sf::Vector2i dst = { bomber->getLocByDS().x, bomber->getLocByDS().y };

	if (abs((src.x - dst.x) + (src.y - dst.y) <= 6))
	{
		if (direction == sf::Vector2i{ 0,0 } || abs(destination.y - this->getPosition().y <= 1.f && abs(destination.x - this->getPosition().x) <= 1.f))
		{
			direction = BFS(m_statics, src, dst);
			auto temp = (direction)+this->getLocByDS();
			destination = { temp.x * m_boardScale.getcellWidth() + m_boardScale.getMarginX(),
				temp.y * m_boardScale.getcellWidth() + m_boardScale.getMarginY() };
		}
	}
	m_moveStupid = (m_CollWithBomb || direction == sf::Vector2i{ 0,0 }) ? true : false;
	m_moveStupid ? moveStupid() : moveSmart();

	if (runBomb.getElapsedTime().asMilliseconds() >= 3000.f)
		m_CollWithBomb = false;
}
//------------------------------------------------------------------------//
// --------------- moving the Monster smart move by bfs -----------------//
//-------------------- if differnce is <= 6 indexes --------------------//
//---------------------------------------------------------------------//
void SmartMonster::moveSmart()
{
	if (direction == sf::Vector2i{ 0,1 }) // moving Down
	{
		random = sf::Keyboard::Down;
		xAxisFix();
	}
	else if (direction == sf::Vector2i{ 0,-1 })// moving Up
	{
		xAxisFix();
		random = sf::Keyboard::Up;
	}
	else if (direction == sf::Vector2i{ 1,0 })// moving Right
	{
		yAxisFix();
		random = sf::Keyboard::Right;
	}
	else if (direction == sf::Vector2i{ -1,0 })// moving Left
	{
		yAxisFix();
		random = sf::Keyboard::Left;
	}

	this->moveSprite(sf::Vector2f(direction));
	m_movement = sf::Keyboard::Key(random);
}
//------------------------------------------------------------------------//
// ------------ moving the Monster stupid move randomly -----------------//
//--------- if differnce is >= 6 indexes or collided with bomb ---------//
//---------------------------------------------------------------------//
void SmartMonster::moveStupid()
{
	m_movement = sf::Keyboard::Key(random);
	sf::Vector2f v = keyToCoord(sf::Keyboard::Key(random));
	moveSprite(v);
	direction = { 0,0 };
}
//------------------------------------------------------------------------//
// -------- fixing the monster xPosition because by bfs -----------------//
//---------------- it moves by index not by pixel ----------------------//
//---------------------------------------------------------------------//
void SmartMonster::xAxisFix()
{
	auto dis = destination - this->getPosition();
	float rec = 0;
	rec = (abs(dis.x) <= 1) ? dis.x : dis.x / abs(std::floor(dis.x));
	moveSprite(sf::Vector2f{ rec, 0 });
}
//------------------------------------------------------------------------//
// -------- fixing the monster yPosition because by bfs -----------------//
//---------------- it moves by index not by pixel ----------------------//
//---------------------------------------------------------------------//
void SmartMonster::yAxisFix()
{
	auto dis = destination - this->getPosition();
	float rec = 0;
	rec = (abs(dis.y) <= 1) ? dis.y : dis.y / abs(std::floor(dis.y));
	moveSprite(sf::Vector2f{ 0, rec });
}
//------------------------------------------------------------------------//
// ----------- moving randomly whrn colliding with bomb -----------------//
//----------------------------------------------------------------------//
void SmartMonster::setRunFromBomb(const bool& b)
{
	m_CollWithBomb = b;
	m_moveStupid = true;
	runBomb.restart();
}
//------------------------------------------------------------------------//
// ----------- bfs function to shortest path to bomberMan ---------------//
//----------------------------------------------------------------------//
const sf::Vector2i SmartMonster::BFS(const staticsV& m_statics, sf::Vector2i src, sf::Vector2i dst)
{
	// initiallizing used parameters
	std::vector<std::vector<bool>> visited;
	visited.resize(BoardScale::instance().getBoardSize());
	for (auto& v : visited) {
		v.resize(BoardScale::instance().getBoardSize());
		std::fill(v.begin(), v.end(), false);
	}

	for (auto& i : m_statics)
		if (i->isDrawable())
			visited.at(i->getLocation().y).at(i->getLocation().x) = true;
	// Mark the source cell as visited 
	if (src.x < 0 || src.y < 0)
		return{ 0,0 };
	visited[src.x][src.y] = true;

	// Create a queue for BFS 
	std::queue<QueueNode> q;

	// Distance of source cell is 0 
	QueueNode s{ sf::Vector2i(src),{0,0} };//monster
	q.push(s);  // Enqueue source cell 

	// Do a BFS starting from source cell 
	while (!q.empty())
	{
		QueueNode curr = q.front();
		sf::Vector2i pt = curr.pt;

		// If we have reached the destination cell, 
		// we are done 
		if (pt.x == dst.x && pt.y == dst.y)
		{
			visited.clear();
			return curr.direction;
		}
		// Otherwise dequeue the front cell in the queue 
		// and enqueue its adjacent cells 
		if (!q.empty())
			q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			// checking if the cell is availible.
			if (row > 0 && row < BoardScale::instance().getBoardSize() && col >0 && col < BoardScale::instance().getBoardSize())
				if (!visited[row][col])
				{
					// mark cell as visited and enqueue it 
					visited[row][col] = true;
					QueueNode Adjcell{ sf::Vector2i{row,col} ,curr.pt == src ? sf::Vector2i{rowNum[i],colNum[i]} : curr.direction };
					q.push(Adjcell);
				}
		}
	}
	return { 0,0 };
}
//------------------------------------------------------------------------//
// ----------------------------------------------------------------------//
//----------------------------------------------------------------------//