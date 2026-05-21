#ifndef STRINGSUM_H
#define STRINGSUM_H

#include <string>

using namespace std;

enum LogLevel {
    DEBUG,
    INFO
};

string removeZeros(string s);
void logMessage(LogLevel level, string message);
string Stringsum(string a, string b);

#endif