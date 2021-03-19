#pragma once
#include "SettingOptions.h"
#include <string>
#include "Resources.h"

class SoundPlayer :
	public SettingOptions
{
public:
	SoundPlayer();
	virtual ~SoundPlayer();
	static void addMusic(const std::string&musicFile);
	static void PlayMusic();
	static void play(const std::string&sound);
	static bool playing(const std::string&sound);
	template<typename Y>//menu's type
	static void set(Y & menu);
private:
	static std::string &getMusicFile();
	static bool &getIsSound();
};

inline SoundPlayer::SoundPlayer(){} //---- c-tor --------------------------

inline SoundPlayer::~SoundPlayer() {} //-----d tor ------------------------
//-------- addMusic function -------------------------------------------------
inline void SoundPlayer::addMusic(const std::string & musicFile)
{
	getMusicFile() = musicFile;
	SoundPlayer::PlayMusic();
}

//--------------- playMusic function ------------------------------------------
inline void SoundPlayer::PlayMusic()
{
	if (getMusicFile() == "")
		return;
	if (!getIsSound())
	{ Resources::instance().getMusic(getMusicFile()).pause(); return; }

	if(Resources::instance().getMusic(getMusicFile()).getStatus() ==
		sf::SoundSource::Status::Playing)
		return;
	Resources::instance().getMusic(getMusicFile()).play();
}

//--------------- play function -----------------------------------------------
inline void SoundPlayer::play(const std::string & sound)
{
	if (!getIsSound())
		Resources::instance().getSound(sound)->setVolume(0.f);
	Resources::instance().getSound(sound)->play();
}

//--------- playing sound -----------------------------------------------------
inline bool SoundPlayer::playing(const std::string & sound)
{
	return(Resources::instance().getSound(sound)->getStatus() !=
		sf::SoundSource::Status::Paused &&
		Resources::instance().getSound(sound)->getStatus() !=
		sf::SoundSource::Status::Stopped);
}		   								

//------------ getMusicFile function ------------------------------------------
inline std::string & SoundPlayer::getMusicFile()
{
	static std::string MusicFile = "";

	return MusicFile;
}

//---------- getIsSound function ----------------------------------------------
inline bool &SoundPlayer::getIsSound()
{
	static bool m_soundVolume = true;
	
	return m_soundVolume;
}

//-------- register function --------------------------------------------------
template<typename Y>
inline void SoundPlayer::set(Y & menu)
{
	menu.set(SOUND, []{
		getIsSound() = !getIsSound(); 
		SoundPlayer::PlayMusic(); });
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------