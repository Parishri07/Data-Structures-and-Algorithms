#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s1, s2;

    cout << "Enter the first string: ";
    getline(cin, s1);

    cout << "Enter the second string: ";
    getline(cin, s2);

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << "Length of LCS is: " << lcs[m][n] << endl;

    cout << "LCS Table is: " << endl;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j)
            cout << lcs[i][j] << " ";
        cout << endl;
    }

    int index = lcs[m][n];
    int temp = index;

    vector<char> lcsString(index + 1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsString[index - 1] = s1[i - 1];
            --i;
            --j;
            --index;
        } else if (lcs[i - 1][j] > lcs[i][j - 1])
            --i;
        else
            --j;
    }

    cout << "LCS is: ";
    for (int k = 0; k <= temp; ++k)
        cout << lcsString[k];
    cout << endl;

    return 0;
}
