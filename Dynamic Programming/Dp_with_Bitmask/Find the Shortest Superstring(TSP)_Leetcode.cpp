class Solution
{
public:
    int min_append(string s1, string s2)
    {
        int n = s1.length(), m = s2.length(), i = 0, j = 0, k;
        for (j = 0; j < n; j++)
        {
            if (s1[j] == s2[0])
            {
                k = j;
                i = 0;
                while (j < n && i < m && s1[j] == s2[i])
                {
                    j++;
                    i++;
                }
                if (j == n || i == m)
                    return m - i;
                j = k;
            }
        }
        return m;
    }

    int tsp(vector<vector<int>> &graph, int n, int mask, int curr, vector<vector<int>> &dp, vector<vector<int>> &path)
    {

        if (mask == ((1 << n) - 1))
            return 0;

        if (dp[curr][mask] != -1)
            return dp[curr][mask];

        int ans = INT_MAX, best = -1;
        for (int choice = 0; choice < n; choice++)
        {
            if ((mask & (1 << choice)) == 0)
            {
                int temp = graph[curr][choice] + tsp(graph, n, mask | (1 << choice), choice, dp, path);
                if (ans > temp)
                {
                    ans = temp;
                    best = choice;
                }
            }
        }
        path[curr][mask] = best;
        return dp[curr][mask] = ans;
    }
    string construct_path(vector<vector<int>> &path, int i, vector<string> &words, vector<vector<int>> &graph)
    {

        int mask = (1 << i);
        string ans = words[i];
        int curr = path[i][mask], prev = i;
        while (curr != -1)
        {

            ans += words[curr].substr(words[curr].length() - graph[prev][curr], graph[prev][curr]);
            prev = curr;
            mask = mask | (1 << prev);
            curr = path[curr][mask];
        }

        return ans;
    }
    string shortestSuperstring(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                graph[i][j] = min_append(words[i], words[j]);
            }
        }

        int ans = INT_MAX;
        string result;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> dp(n, vector<int>(1 << n, -1));
            vector<vector<int>> path(n, vector<int>(1 << n, -1));

            tsp(graph, n, (1 << i), i, dp, path);
            string retrace = construct_path(path, i, words, graph);
            if (ans > retrace.length())
            {
                ans = retrace.length();
                result = retrace;
            }
        }
        return result;
    }
};