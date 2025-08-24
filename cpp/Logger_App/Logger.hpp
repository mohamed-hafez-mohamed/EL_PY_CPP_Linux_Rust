
#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>
#include <mutex>

namespace App
{
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
            Logger(Levels logLevel, const std::string& logFileName, bool writeToConsole);
            virtual ~Logger();
        private:
            Levels m_logLevel;
            std::vector<std::string> m_buffer;
            mutable std::mutex logMutex;
            std::string m_logFileName;
            std::ofstream m_logFileHandle;
            bool m_isWriteToFileEnabled;
            bool m_isWriteToConsoleEnabled;
            /**
             * @brief helper function to convert enum value to string
             */
            std::string convertLvlsToString(Levels level);
    };
}
