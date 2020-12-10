#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("00_AoC.txt");
    int a;

    int num = 0;
    string line;

    while (getline(f, line))
        num++;

    f.clear();
    f.seekg(0);

    int n[num];

    for (int i = 0; i < num; i++)
    {
        f >> n[i];
    }
    int s = 0;
    for (int i = 0; i < num; i++)                 // first level
    {
        for (int j = 0; j < num; j++)
        {
            if (n[i] + n[j] == 2020)
            {
                cout << n[i] << " " << n[j] << "\n";
                cout << n[i]*n[j] << "\n";
                s++;
            }
            if (s > 0)
                break;
        }
        if (s > 0)
            break;
    }
    s = 0;
    for (int i = 0; i < num; i++)               // second level
    {
        for (int j = 0; j < num; j++)
        {
            for (int z = 0; z < num; z++)
            {
                if (n[i] + n[j] + n[z] == 2020)
                {
                    cout << n[i] << " " << n[j] << " " << n[z] << "\n";
                    cout << n[i]*n[j]*n[z] << "\n";
                    s++;
                }

                if (s > 0)
                    break;
            }
            if (s > 0)
                break;
        }
        if (s > 0)
            break;
    }
}

