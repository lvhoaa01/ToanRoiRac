#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm> 
#include <cctype>    

using namespace std;

bool isNumber(const string& s) {
    return !s.empty() && isdigit(s[0]);
}

bool customCompare(const string& a, const string& b) {
    bool aIsNum = isNumber(a);
    bool bIsNum = isNumber(b);

    
    if (aIsNum != bIsNum) {
        return aIsNum; 
    }

    return a < b;
}

vector<string> readAndProcessSet() {
    int n;
    cin >> n;
    vector<string> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }

    set<string> s(temp.begin(), temp.end());

    vector<string> result(s.begin(), s.end());
    return result;
}

vector<string> setDifference(const vector<string>& a, const vector<string>& b) {
    vector<string> hieu;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            ++i;
            ++j;
        } else if (a[i] < b[j]) {
            hieu.push_back(a[i]);
            ++i;
        } else {
            ++j;
        }
    }
    while (i < a.size()) {
        hieu.push_back(a[i]);
        ++i;
    }
    return hieu;
}


vector<string> setUnion(const vector<string>& a, const vector<string>& b) {
    vector<string> hop;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            hop.push_back(a[i]);
            ++i;
            ++j;
        } else if (a[i] < b[j]) {
            hop.push_back(a[i]);
            ++i;
        } else {
            hop.push_back(b[j]);
            ++j;
        }
    }
    
    while (i < a.size()) {
        hop.push_back(a[i]);
        ++i;
    }
    
    while (j < b.size()) {
        hop.push_back(b[j]);
        ++j;
    }
    return hop;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> A = readAndProcessSet();
    vector<string> B = readAndProcessSet();
    vector<string> C = readAndProcessSet();

    vector<string> D = setDifference(A, B);

    vector<string> E = setDifference(A, C);

    vector<string> result_lex = setUnion(D, E);

    sort(result_lex.begin(), result_lex.end(), customCompare);

    if (result_lex.empty()) {
        cout << "none\n";
    } else {
        for (size_t i = 0; i < result_lex.size(); ++i) {
            cout << result_lex[i] << (i == result_lex.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}