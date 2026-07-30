#include <bits/stdc++.h>
using namespace std;

vector<int> closeBracket;

int convert(string s)
{
    reverse(s.begin(), s.end());

    int ans = 0;
    int mul = 1;

    for (char c : s)
    {
        ans += (c - '0') * mul;
        mul *= 10;
    }

    return ans;
}

int calculate(string s)
{
    char op = '+';

    int ans = 0;
    int last = 0;

    for (int i = 0; i < s.size(); i++)
    {
        string num = "";

        while (i < s.size() && isdigit(s[i]))
        {
            num += s[i];
            i++;
        }

        int cur = convert(num);

        if (op == '+')
        {
            ans += last;
            last = cur;
        }
        else if (op == '-')
        {
            ans += last;
            last = -cur;
        }
        else if (op == '*')
        {
            last *= cur;
        }
        else if (op == '/')
        {
            last /= cur;
        }

        if (i < s.size())
            op = s[i];
    }

    return ans + last;
}

void matchBrackets(string &s)
{
    closeBracket.assign(s.size(), -1);

    stack<int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(i);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            int x = st.top();
            st.pop();

            closeBracket[x] = i;
            closeBracket[i] = x;
        }
    }
}

int solve(string &s, int l, int r)
{
    string temp = "";

    for (int i = l; i < r;)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            int val = solve(s, i + 1, closeBracket[i]);

            temp += to_string(val);

            i = closeBracket[i] + 1;
        }
        else
        {
            temp += s[i];
            i++;
        }
    }

    return calculate(temp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    matchBrackets(s);

    cout << solve(s, 0, s.size());

    return 0;
}
