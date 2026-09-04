#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int start = 0;
    int maxlen = 0;

    for (int i = 0; i < s.length(); i++) {
        int zeros = 0, ones = 0;

        for (int j = i; j < s.length(); j++) {
            if (s[j] == '0')
                zeros++;
            else if (s[j] == '1')
                ones++;

            if (zeros == ones) {
                int len = j - i + 1;
                if (len > maxlen) {
                    start = i;
                    maxlen = len;
                }
            }
        }
    }

    if (maxlen > 0)
        cout << "The longest substring is " << s.substr(start, maxlen) << endl;
    else
        cout << "Not found" << endl;

    return 0;
}