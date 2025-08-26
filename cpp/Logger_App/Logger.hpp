/**
 ********************************************************************************
 * @file    Logger.hpp
 * @author  MHafez
 * @date    26 August 2025
 * @brief   This file headers for the Logger class interfaces
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>
#include <mutex>

/************************************
 * NAMESPACES
 ************************************/

/**
 * @namespace App
 * @brief A collection of various application utilities.
 */
namespace App
{
    /**
     * @class   Logger
     * @brief   A thread-safe logging utility.
     *
     * This class provides a logging mechanism that is safe for use in
     * a multi-threaded environment. It supports logging messages to
     * both console and file outputs.
     */
    class Logger
    {
        public:
            /**
             * @brief enum class Levels is a local type represents log levels
             */
            enum class Levels : uint8_t 
            {
                DEBUG    = UINT8_C(0),
                INFO     = UINT8_C(1),
                WARNING  = UINT8_C(2),
                ERROR    = UINT8_C(3),
                CRITICAL = UINT8_C(4)
            };
            /**
             * @brief Constructs a Logger instance.
             * @param logLevel The logging level.
             * @param logFileName The name of the log file.
             * @param writeToConsole Flag indicating whether to write to console.
             */
            Logger(Levels logLevel, const std::string& logFileName, bool writeToConsole);
            /**
             * @brief Destroys the Logger instance.
             */
            virtual ~Logger();
            void debug(const std::string& message)
            {
                logMessage(Levels::DEBUG, message);
            }
            void info(const std::string& message)
            {
                logMessage(Levels::INFO, message);
            }
            void warning(const std::string& message)
            {
                logMessage(Levels::WARNING, message);
            }
            void error(const std::string& message)
            {
                logMessage(Levels::ERROR, message);
            }
            void critical(const std::string& message)
            {
                logMessage(Levels::CRITICAL, message);
            }
            inline void setLogLevel(Levels logLevel)
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                m_logLevel = logLevel;
            }
            inline Levels getLogLevel() const
            {
                return m_logLevel;
            }
            inline void setWriteToConsole(bool enabled)
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                m_isWriteToConsoleEnabled = enabled;
            }
            inline std::vector<std::string> getLogBuffer() const
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                return m_buffer;
            }
            inline size_t getBufferSize(void) const
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                return m_buffer.size();
            }
            inline void clearLogBuffer(void)
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                m_buffer.clear();
                std::cout << "Log buffer cleared." << std::endl;
            }
            inline void flushLogfile(void)
            {
                std::lock_guard<std::mutex> lock(m_logMutex);
                if(m_logFileHandle.is_open())
                {
                    m_logFileHandle.flush();
                }
                
            }
            void setWriteToFile(bool enabled, const std::string& fileName = "");
            void printBuffer(void);
            void dumpLogBufferToLogFile(const std::string& fileName = "");
            void printStatistics(void);
        private:
            Levels m_logLevel;
            std::vector<std::string> m_buffer;
            mutable std::mutex m_logMutex;
            std::string m_logFileName;
            std::ofstream m_logFileHandle;
            bool m_isWriteToFileEnabled;
            bool m_isWriteToConsoleEnabled;
            /**
             * @brief helper function to convert enum value to string
             */
            std::string convertLevelToString(Levels level);
            std::string getCurrentTimestamp(void) const;
            std::string formatMessage(Levels level, const std::string& message);
            void logMessage(Levels level, const std::string& message);
    };
}
