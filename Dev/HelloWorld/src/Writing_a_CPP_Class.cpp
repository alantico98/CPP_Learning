#include <iostream>

// Key Note: This is not how you should structure a Log class, and it also (in the words of Cherno) pretty terrible code. However, this does convey logically what the class is intended for and what it's meant for
class Log {
    public:
        const int LogLevelError = 0;
        const int LogLevelWarning = 1;
        const int LogLevelInfo = 2;

    private:
        int m_LogLevel = LogLevelInfo; // the 'm_' convention lets us know that this is a class member variable that's intended to be private

    public:
        void SetLevel(int level) {
            m_LogLevel = level;
        }

        void Error(const char* message) {
            if (m_LogLevel >= LogLevelError)
                std::cout << "[ERROR]:" << message << std::endl;
        }

        void Warn(const char* message) {
            if (m_LogLevel >= LogLevelWarning)
                std::cout << "[WARNING]:" << message << std::endl;
        }

        void Info(const char* message) {
            if (m_LogLevel >= LogLevelInfo)
                std::cout << "[INFO]:" << message << std::endl;
        }
};

int main() {
    Log log;
    log.SetLevel(log.LogLevelWarning);
    log.Warn("Hello!");
    log.Error("Hello!");
    log.Info("Hello!"); // This one shouldn't print anything
    std::cin.get();
}