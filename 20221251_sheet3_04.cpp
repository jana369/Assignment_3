#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
vector <string> sign = {"RED","GREEN"};
vector <string> res;
void printVector(vector<string> const& out)
{
    for (auto it = out.begin(); it != out.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void findCombinations(string arr[], vector<string>& out, int k, int i, int n)
{
    if (out.size() == k)
    {
        printVector(out);
        return;
    }

    for (int j = 0; j < n; j++)
    {

        out.push_back(arr[j]);
        findCombinations(arr, out, k, j, n);
        out.pop_back();
    }
}

int main()
{
    string arr[] = { "RED","GREEN","YELLOW"};
    int k = 3;

    int n = sizeof(arr) / sizeof(arr[0]);

    vector<string> out;
    findCombinations(arr, out, k, 0, n);

    return 0;
}
