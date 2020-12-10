#include <iostream>
#include <cmath>
#include <fstream>
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
    ifstream be("04_AoC.txt");
    string pass;

    int num = numOfLines(be);

    be.clear();
    be.seekg(0);

    int rowLowBound, rowHighBound, colLowBound, colHighBound;
    int maxId = 0;
    int arr[1023] = {};

    for (int i = 0; i < num; i++)
    {
        rowLowBound = 0;
        rowHighBound = 127;

        colLowBound = 0;
        colHighBound = 7;

        be >> pass;

        for (int i = 0; i < 7; i++)
        {
            if (pass[i] == 'F')
            {
                rowHighBound = (rowHighBound+rowLowBound)/2;
            }
            else
            {
                rowLowBound = (rowHighBound+rowLowBound)/2 + 1;
            }
        }

        for (int i = 7; i < 10; i++)
        {
            if (pass[i] == 'L')
            {
                colHighBound = (colHighBound+colLowBound)/2;
            }
            else
            {
                colLowBound = (colHighBound+colLowBound)/2 + 1;
            }
        }
        int id = rowLowBound*8 + colLowBound;
        arr[id]++;

        if (id > maxId)
            maxId = id;
    }
    cout << maxId << "\n";

    for (int i = 0; i < 1023; i++)
    {
        if (arr[i-1] > 0 && arr[i] == 0 && arr[i+1] > 0)
        {
            cout << i << "\n";
        }
    }
}
