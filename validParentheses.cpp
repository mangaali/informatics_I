#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> m;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            m.push(s[i]);
        }
        else if (s[i] == ']' && !m.empty() && m.top() == '[') {
            m.pop();
        }
        else if (s[i] == '}' && !m.empty() && m.top() == '{') {
            m.pop();
        }
        else if (s[i] == ')' && !m.empty() && m.top() == '(') {
            m.pop();
        }
        else {
            cout << "invalid" << "\n";
            return 0;
        }
    }

    if (m.empty()) {
        cout << "valid" << "\n";
    }
    else {
        cout << "invalid" << "\n";
    }

    return 0;
}
