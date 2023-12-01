#include <iostream>
#include <vector>

using namespace std;
    string longest_common_substring(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    int longest = 0;  
    string result; 

   
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                    result = s1.substr(i - longest, longest);
                }
            }
        }
    }

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}

int main() {
    
    string string1;
    string string2;
	cout<<"Enter first String";
    cin>>string1;
    cout<<"Enter second string";
    cin>>string2;

    string common_substring = longest_common_substring(string1, string2);

    cout << "Longest common substring: " << common_substring << std::endl;

    return 0;
}
