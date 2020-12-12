#include <iostream>
#include <fstream>
using namespace std;

int numOfLines(ifstream &be)
{
    int num = 0;
    string line;
    while (getline(be, line))
        num++;

    return num;
}

int main()
{
    ifstream be("08_AoC.txt");
    int num = numOfLines(be);

    be.clear();
    be.seekg(0);

    int numbers[num] = {};
    for (int i = 0; i < num; i++)
    {
        be >> numbers[i];
    }

    int sum, magicNum;
    for (int i = 25; i < num; i++)
    {
        bool valid = false;
        for (int j = i - 25; j < i; j++)
        {
            for (int z = i - 25; z < i; z++)
            {
                sum = numbers[j] + numbers[z];
                if (sum == numbers[i] && numbers[j] != numbers[z])
                {
                    valid = true;
                }
            }
        }
        if (!valid)
        {
            magicNum = numbers[i];
            cout << "magic: " << magicNum << "\n";
        }
    }

    int sum2;
    for (int i = 0; i < num; i++)
    {
        sum2 = 0;
        for (int j = i; j < num; j++)
        {
            sum2 = sum2 + numbers[j];

            if (sum2 > magicNum)
            {
                break;
            }

            if (sum2 == magicNum)
            {
                int maxx = 0;
                int minn = 9999999999;

                for (int z = i; z < j; z++)
                {
                    if (numbers[z] > maxx)
                    {
                        maxx = numbers[z];
                    }
                    if (numbers[z] < minn)
                    {
                        minn = numbers[z];
                    }
                }

                cout << maxx + minn << "\n";
            }
        }
    }
}
