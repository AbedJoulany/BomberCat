#pragma once
#include <fstream>
#include <string>
#include <Window.h>
#include "Definitions.h"

class LogFile
{
public:
	static LogFile& instance();
	void write(const std::string& text);
private:
	LogFile();
	virtual ~LogFile();
	std::fstream m_file;
};

//------------- singlton ---------------------------------------------
inline LogFile& LogFile::instance()
{
	static LogFile m_logger;

	return m_logger;
}

//------------- Wrting to the file  --------------------------------------------
inline void LogFile::write(const std::string& text)
{
	m_file << text;
}

//--------- constructor -------------------------------------------------------------
inline LogFile::LogFile()
{
	m_file.open(LOG_FILE_PATH, std::ios::out);
}

//------------ destructor ----------------------------------------------------------
inline LogFile::~LogFile()
{
	m_file.close();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//----------------------------------------------------------------------------