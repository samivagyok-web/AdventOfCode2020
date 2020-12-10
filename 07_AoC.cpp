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

int main()
{
    int acc = 0;

    ifstream be("07_AoC.txt");
    string inst;
    int value;

    int num = numOfLines(be);

    be.clear();
    be.seekg(0);

    string instArr[num] = { };
    int valueArr[num] = { };
    int freq[num] = { };
    for (int i = 0; i < num; i++)
    {
        be >> inst >> value;
        instArr[i] = inst;
        valueArr[i] = value;
    }

    bool gotIt = false;
    int freqCopy[num] = {};
    int copyAcc = 0;

    for (int i = 0; i < num; i++)
    {
        freq[i]++;

        for (int i = 0; i < num; i++)
        {
            freqCopy[i] = freq[i];
        }

        copyAcc = acc;

        if (freq[i] == 2)
        {
            break;
        }

        if (instArr[i] == "acc")
        {
            acc = acc + valueArr[i];
        }

        if (instArr[i] == "jmp")
        {
            for (int j = i + 1; j < num; j++)
            {
                freqCopy[j]++;

                if (freqCopy[j] == 2)
                    break;

                if (instArr[j] == "acc")
                {
                    copyAcc = copyAcc + valueArr[j];
                }

                if (instArr[j] == "jmp")
                {
                    j = j + valueArr[j] - 1;
                }

                if (j == num - 1)
                    gotIt = true;
            }

            i = i + valueArr[i] - 1;
        }

        if (gotIt)
            break;

        for (int i = 0; i < num; i++)
        {
            freqCopy[i] = freq[i];
        }

        if (instArr[i] == "nop")
        {
            for (int j = valueArr[i] + i; j < num; j++)
            {
                freqCopy[j]++;
                if (freqCopy[j] == 2)
                    break;

                if (instArr[j] == "acc")
                {
                    copyAcc = copyAcc + valueArr[j];
                }

                if (instArr[j] == "jmp")
                {
                    j = j + valueArr[j] - 1;
                }
            }
        }

        if (gotIt)
            break;
    }
    cout << copyAcc;
}
