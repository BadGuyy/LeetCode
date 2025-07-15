#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> findCoins(vector<int> &numWays)
{
    map<int, bool> map;
    vector<int> res;
    int tempMax;

    for (int i = 0; i < numWays.size(); ++i)
        if (numWays[i] == 1)
        {
            tempMax = i + 1;
            break;
        }

    for (int i = 0; i < numWays.size(); ++i)
    {
        if (numWays[i] == 0)
            map[i + 1] = false;
        if (numWays[i] == 1)
        {
            map[i + 1] = true;
            tempMax = max(numWays[i], tempMax);
        }

        if (numWays[i] > 1)
        {
            bool flag = false;;
            while (numWays[i] > 1)
            {
                if (i + 1 - tempMax > 0)
                {
                    map[i + 1 - tempMax] = true;
                    flag = true;
                }

                --numWays[i];
            }
            tempMax = i + 1;
            if(flag == false)
                map[i + 1] = true;
        }
    }

    for (auto begin = map.begin(); begin != map.end(); ++begin)
        if (begin->second == true)
            res.push_back(begin->first);

    return res;
}

int main()
{
    vector<int> nums = {0, 1, 0, 2, 0, 3, 0, 4, 0};
    for (auto c : findCoins(nums))
        cout << c << " ";

    system("pause");
    return 0;
}