#include <iostream>
#include "Logger.hpp"

std::unique_ptr<App::Logger> App::GlobalLogger::instance = nullptr;
std::mutex App::GlobalLogger::instanceMutex;
int main()
{
    std::cout << "=== Logger Class Demonstration ===" << std::endl;
    
    // Create a logger instance
    App::Logger logger(App::Logger::Levels::DEBUG, "test.log", true);
    
    // Test different log levels
    logger.debug("This is a debug message");
    logger.info("Application started successfully");
    logger.warning("This is a warning message");
    logger.error("An error occurred");
    logger.critical("Critical system failure!");
    
    // Show logger statistics
    logger.printStatistics();
    
    // Test buffer operations
    std::cout << "\nBuffer size: " << logger.getBufferSize() << std::endl;
    
    // Dump logs to another file
    logger.dumpLogBufferToLogFile("dump.log");
    
    // Test log level filtering
    std::cout << "\n=== Testing Log Level Filtering ===" << std::endl;
    logger.setLogLevel(App::Logger::Levels::WARNING);
    logger.debug("This debug message should not appear");
    logger.info("This info message should not appear");
    logger.warning("This warning should appear");
    logger.error("This error should appear");
    
    // Reset log level
    logger.setLogLevel(App::Logger::Levels::DEBUG);
    
    // Test console output disable
    std::cout << "\n=== Testing Console Output Disable ===" << std::endl;
    logger.setWriteToConsole(false);
    logger.info("This message goes only to file and buffer");
    logger.setWriteToConsole(true);
    logger.info("Console output re-enabled");
    
    // Print current buffer
    logger.printBuffer();
    
    // Test global logger
    std::cout << "\n=== Testing Global Logger ===" << std::endl;
    LOG_INFO("Using global logger macro");
    LOG_ERROR("Global error message");

    // Clear buffer
    logger.clearLogBuffer();
    std::cout << "Buffer size after clear: " << logger.getBufferSize() << std::endl;

    return 0;
}