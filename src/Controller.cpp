#include "Controller.h"
#include "Exit.h"
#include "Play.h"
#include "Help.h"
#include "Resolution.h"
#include "CollissionFun.h"
//------------------------------------------------------------------------//
// ------------------------ constructor ---------------------------------//
//----------------------------------------------------------------------//
Controller::Controller()
{

}
//------------------------------------------------------------------------//
// ------------------------ destructor ----------------------------------//
//----------------------------------------------------------------------//
Controller::~Controller()
{
}
//------------------------------------------------------------------------//
// ----------------- setting the menu labels ----------------------------//
//----------------------------------------------------------------------//
void Controller::runGame()
{
	Exit exitOpt;
	Play <Game> playOpt;
	Settings<Menu> settings_label;
	Help help_label;
	Resolution<Window> resolution_label;
	playOpt.set(m_mainMenu);
	help_label.set(m_mainMenu);
	resolution_label.set(settings_label);
	SoundPlayer::addMusic(TITLE_MUSIC);
	SoundPlayer::set(settings_label);
	settings_label.set(m_mainMenu, SETTINGS);
	exitOpt.set(m_mainMenu);
	setBomberColissions();
	StageData::instance();

	upateMenu();
}
//------------------------------------------------------------------------//
// ------------------------ Update Menu ---------------------------------//
//----------------------------------------------------------------------//
void Controller::upateMenu()
{
	m_mainMenu.run();
}
