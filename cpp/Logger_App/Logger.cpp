#include <iostream>

#include "Logger.hpp"

namespace App
{
    Logger::Logger(Levels logLevel, const std::string& logFileName, bool writeToConsole) : m_logLevel{logLevel}, m_isWriteToFileEnabled{logFileName.empty()}, m_isWriteToConsoleEnabled{writeToConsole}
    {
        if(m_isWriteToFileEnabled)
        {
            m_logFileHandle.open(logFileName, std::ios::app);
            if(!m_logFileHandle.is_open())
            {
                std::cerr << "Un-able to open the log file" << std::endl;
                m_isWriteToFileEnabled = false;
            }
        }
    }
    Logger::~Logger()
    {
        if(m_logFileHandle.is_open())
        {
            m_logFileHandle.close();
        }
    }
    /**
     * @brief helper function to convert enum value to string
     */
    std::string Logger::convertLvlsToString(Levels level)
    {
        switch(level)
        {
            case Levels::DEBUG:    return "DEBUG";
            case Levels::INFO:     return "INFO";
            case Levels::WARNING:  return "WARNING";
            case Levels::ERROR:    return "ERROR";
            case Levels::CRITICAL: return "CRITICAL";
            default:               return "UNKNOWN";
        }
    }
}
