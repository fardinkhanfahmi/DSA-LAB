#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

void execute()
{
    int64 length;
    cin >> length;

    vector<int64> values(length);

    for (int64 index = 0; index < length; index++)
    {
        cin >> values[index];
    }

    int64 key;
    cin >> key;

    bool found = false;

    for (int64 position = 0; position < length; position++)
    {
        if (values[position] == key)
        {
            cout << "Found at index " << position << '\n';
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Not Found!!" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    execute();

    return 0;
}
