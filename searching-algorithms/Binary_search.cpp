#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

void process()
{
    int64 size;
    cin >> size;

    vector<int64> numbers(size);
    for (int64 i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    int64 target;
    cin >> target;

    int64 start = 0;
    int64 end = size - 1;
    bool exists = false;

    while (start <= end)
    {
        int64 center = start + (end - start) / 2;

        if (numbers[center] == target)
        {
            cout << "Found at index " << center << '\n';
            exists = true;
            break;
        }

        if (numbers[center] > target)
        {
            end = center - 1;
        }
        else
        {
            start = center + 1;
        }
    }

    if (!exists)
    {
        cout << "Not Found!!" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    process();

    return 0;
}
