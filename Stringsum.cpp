#include <iostream>
#include <string>
#include <algorithm>
#include "Stringsum.h"
using namespace std;

string removeZeros(string s) {
    int i = 0;

    while (i < s.length() - 1 && s[i] == '0') {
        i++;
    }

    return s.substr(i);
}

void logMessage(LogLevel level, string message) {
    switch (level) {
        case DEBUG:
            cout << "[DEBUG] ";
            break;
        case INFO:
            cout << "[INFO] ";
            break;
    }

    cout << message << endl;
}

string Stringsum(string a, string b) {
    a = removeZeros(a);
    b = removeZeros(b);

    int i = a.length() - 1;
    int j = b.length() - 1;

    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = 0;
        int digitB = 0;

        if (i >= 0) {
            digitA = a[i] - '0';
            i--;
        }

        if (j >= 0) {
            digitB = b[j] - '0';
            j--;
        }

        int sum = digitA + digitB + carry;
        int digitResult = sum % 10;
        carry = sum / 10;

        logMessage(
            DEBUG,
            "digitA = " + to_string(digitA) +
            ", digitB = " + to_string(digitB) +
            ", sum = " + to_string(sum) +
            ", result digit = " + to_string(digitResult) +
            ", carry = " + to_string(carry)
        );

        result.push_back(digitResult + '0');
    }

    reverse(result.begin(), result.end());
    logMessage(INFO, "Result = " + result);

    return result;
}
