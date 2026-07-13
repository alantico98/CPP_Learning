#include <iostream>

// Key Note: This is not how you should structure a Log class, and it also (in the words of Cherno) pretty terrible code. However, this does convey logically what the class is intended for and what it's meant for
class Log {
    public:
        // Refer to the 'Enums_in_C++' file for a more detailed explanation of enums and how they work. In this case, we can use an enum to define the log levels instead of using integer values. This makes the code more readable and maintainable.
        enum Level {
            LevelError = 0,
            LevelWarning = 1,
            LevelInfo = 2
        };
        // const int LogLevelError = 0;
        // const int LogLevelWarning = 1;
        // const int LogLevelInfo = 2;

    private:
        // int m_LogLevel = LogLevelInfo; // the 'm_' convention lets us know that this is a class member variable that's intended to be private
        Level m_LogLevel = Level::LevelInfo; // the 'm_' convention lets us know that this is a class member variable that's intended to be private

    public:
        void SetLevel(Level level) {
            m_LogLevel = level;
        }

        void Error(const char* message) {
            if (m_LogLevel >= Level::LevelError)
                std::cout << "[ERROR]:" << message << std::endl;
        }

        void Warn(const char* message) {
            if (m_LogLevel >= Level::LevelWarning)
                std::cout << "[WARNING]:" << message << std::endl;
        }

        void Info(const char* message) {
            if (m_LogLevel >= Level::LevelInfo)
                std::cout << "[INFO]:" << message << std::endl;
        }
};

int main() {
    Log log;
    log.SetLevel(log.Level::LevelWarning);
    log.Warn("Hello!");
    log.Error("Hello!");
    log.Info("Hello!"); // This one shouldn't print anything
    std::cin.get();
}