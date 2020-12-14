#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int numOfLines(ifstream &f)
{
    int num = 0;
    string line;
    while (getline(f, line))
        num++;

    return num;
}

int main()
{
    ifstream be("09_AoC.txt");
    int num = numOfLines(be);

    be.clear();
    be.seekg(0);

    int jolts[num];
    for (int i = 0; i < num; i++)
    {
        be >> jolts[i];
    }

    int n = sizeof(jolts) / sizeof(jolts[0]);
  //  int freq[4] = { 0, 0, 0, 1};
    sort(jolts, jolts + n);

   /* for (int i = 0; i < num - 1; i++)
    {
        int sum = jolts[i+1] - jolts[i];
        freq[sum]++;
    }

    cout << freq[1] * freq[3]; */
    for (int i = 0; i < num; i++)
    {
        cout << jolts[i] << "\n";
    }


    int fixedP = 1;
    long long tree = 1;
    for (int i = 0; i < num - 1; i++)
    {
        if (jolts[i+1] - jolts[i] == 1)
        {
            fixedP++;
        }
        else
        {
            if (fixedP >= 3)
            {
                if (fixedP == 3)
                {
                    tree = tree * 2;
                    cout << "x2" << "\n";
                }
                else if (fixedP == 4)
                {
                    tree = tree * 4;
                    cout << "x4" << "\n";
                }
                else if (fixedP == 5)
                {
                    tree = tree * 7;
                    cout << "x7" << "\n";
                }
            }
            fixedP = 1;
        }
    }
    cout << tree;
}
