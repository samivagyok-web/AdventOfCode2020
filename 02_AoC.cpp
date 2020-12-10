#include <iostream>
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

int numOfCharInLine(ifstream &f, int num)
{
    char a;
    int numOfChar;
    while (f >> a)
        numOfChar++;

    return numOfChar / num;
}

int main()
{
    ifstream f("02_AoC.txt");

    int num = numOfLines(f);

    f.clear();
    f.seekg(0);

    int charInLine = numOfCharInLine(f, num);

    f.clear();
    f.seekg(0);

    char field[num][charInLine];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < charInLine; j++)
        {
            f >> field[i][j];
        }
    }

    int treeFind = 0;
    int startPointRow = 0;
    int startPointCollumn = 0;

    while (startPointRow <= num)
    {
        if (field[startPointRow][startPointCollumn % charInLine] == '#')
        {
            cout << " " << startPointRow << " " << startPointCollumn % charInLine << "\n";
            cout << field[startPointRow][startPointCollumn % charInLine] << "\n";
            treeFind++;
        }
        startPointRow = startPointRow + 2;
        startPointCollumn = startPointCollumn + 1;
    }
    cout << treeFind;
}
