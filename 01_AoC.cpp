#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("01_AoC.txt");
    int a, b;
    char betu;
    string pass, asd;

    int num = 0;
    string line;

    while (getline(f, line))
        num++;

 //   cout << num;
    f.clear();
    f.seekg(0);

    int valid = 0;

    for (int i = 0; i < num; i++)
    {
        f >> a >> b >> betu >> asd >> pass;
        b = -b;

        int len = pass.length();

        if (!(pass[a-1] == betu) != !(pass[b-1] == betu))
        {
            valid++;
        }
    }
    cout << valid;
}
