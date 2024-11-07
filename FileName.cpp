#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t, n, m, s = 0;
int q[30][30] = { 0 };
int vis[30][30] = { 0 };
int px[8] = { -1,0,1,-1,1,-1,0,1 };
int py[8] = { -1,-1,-1,0,0,1,1,1 };
void dfs(int x, int y, int sum)
{
    if (y == m + 1)
    {
        dfs(x + 1, 1, sum);
        return;
    }
    if (x == n + 1)
    {
        s = max(s, sum);
        return;
    }
    dfs(x, y + 1, sum);
    if (vis[x][y] == 0)
    {
        for (int i = 0; i < 8; i++)
            vis[x + px[i]][y + py[i]]++;
        dfs(x, y + 1, sum + q[x][y]);
        for (int i = 0; i < 8; i++)
            vis[x + px[i]][y + py[i]]--;
    }
}
int main()
{
    memset(q, 0, sizeof(s));
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> q[i][j];
    s = 0;
    dfs(1, 1, 0);
    cout << s << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getMaxNonAdjacentSum(const vector<vector<int>>& matrix, int N, int M) {
    vector<vector<int>> dp(N, vector<int>(M, 0)); 
    int maxSum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int currentMax = 0;
            for (int di = -2; di <= 2; ++di) {
                for (int dj = -2; dj <= 2; ++dj) {
                    if (abs(di) + abs(dj) > 1) { 
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            currentMax = max(currentMax, dp[ni][nj]);
                        }
                    }
                }
            }
            dp[i][j] += currentMax;
            maxSum = max(maxSum, dp[i][j]);
        }
    }
    return maxSum;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }
    int result = getMaxNonAdjacentSum(matrix, N, M);
    cout<< result << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int findShortestSubArray(const vector<int>& nums) {
    unordered_map<int, int> count_map;      
    unordered_map<int, int> first_index;    
    unordered_map<int, int> last_index;     
    int degree = 0;                         
    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        count_map[num]++;
        if (first_index.find(num) == first_index.end()) {
            first_index[num] = i;
        }
        last_index[num] = i;
        degree = max(degree, count_map[num]);
    }
    int min_length = nums.size();
    for (const auto& [num, count] : count_map) {
        if (count == degree) {
            int length = last_index[num] - first_index[num] + 1;
            min_length = min(min_length, length);
        }
    }

    return min_length;
}

int main() {
    int n;
    cin >> n;
    vector<int> results;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> nums(m);
        for (int j = 0; j < m; ++j) {
            cin >> nums[j];
        }
        results.push_back(findShortestSubArray(nums));
    }
    for (const int result : results) {
        cout << result << endl;
    }
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); ++j) {
        if (nums[j] != nums[i]) {
            ++i;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
int main() {
    vector<int> nums;
    int num;
    while (cin >> num) { 
        nums.push_back(num);
    }
    int newLength = removeDuplicates(nums);
    cout <<newLength << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a = 0;
        vector<int>nums;
        cin >> a;
        unordered_map<int, int>hash{ {0,0} };
        for (int j = 0; j < a; j++) {
            int num;
            cin >> num;
            nums.push_back(num);
            hash[num]++;
        }
        int mx = 0;
        for (auto& h : hash) {
            mx = max(h.second, mx);
        }
        int len = 0;
        unordered_map<int, int>hash2{ {0,0} };
        for (auto& h : nums) {
            hash2[h]++;
            len++;
            int mm = 0;
            for (auto& l : hash2) {
                mm = max(mm, l.second);
            }
            if (mm == mx)
            {
                cout << len << endl;
                break;
            }
        }
    }
    return 0;
}
