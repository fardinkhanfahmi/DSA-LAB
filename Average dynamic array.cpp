#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    double average = (double)sum / n;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    delete[] arr;
    return 0;
}
