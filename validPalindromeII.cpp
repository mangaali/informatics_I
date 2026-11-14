#include <bits/stdc++.h>
using namespace std;

bool check(string &x, int first, int last, int chances) {
    if (first >= last) {
        return true;
    }

    if (x[first] == x[last]) {
        return check(x, first + 1, last - 1, chances);
    }

    if (chances > 0) {
        return check(x, first + 1, last, chances - 1) || 
               check(x, first, last - 1, chances - 1);
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    if (check(s, 0, s.size() - 1, 1)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }

    return 0;
}
