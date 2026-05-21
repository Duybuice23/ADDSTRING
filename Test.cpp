#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include "Addstring.h"

using namespace std;


void runTest(string a, string b, string expected) {
    string result = Stringsum(a, b);

    cout << a << " + " << b << " = " << result;

    if (result == expected) {
        cout << "  [PASS]" << endl;
    } else {
        cout << "  [FAIL]"
             << " expected: " << expected << endl;
    }

    assert(result == expected);
}

int main() {
    runTest("1234", "2213", "3447");
    runTest("111", "222", "333");
    runTest("500", "400", "900");

    runTest("9", "1", "10");
    runTest("99", "1", "100");
    runTest("999", "1", "1000");
    runTest("123", "789", "912");

    runTest("1234", "56", "1290");
    runTest("99999", "1", "100000");
    runTest("1", "99999", "100000");
    runTest("12345678", "876", "12346554");

    runTest("0", "0", "0");
    runTest("0", "1234", "1234");
    runTest("999", "0", "999");

    runTest(
        "9999999999999999999999999999999",
        "1",
        "10000000000000000000000000000000"
    );

    runTest(
        "9223372036854775807",
        "1",
        "9223372036854775808"
    );

    cout << "All tests passed!" << endl;

    return 0;
}