#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
private:
 
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    int i, j;
    vector<int> answer;

    for(i = 0, j = 1; i < nums.size() - 1; )
    {
        int tmp = nums.at(i) + nums.at(j);
        if (tmp != target)
        {
            if (j < nums.size() - 1)
            {
                j++;
            }
            else
            {
                i++;
                j = i + 1;
            }
        }
        else
        {
            answer.push_back(i);
            answer.push_back(j);
            break;
        }
    }
    return answer;
}

int main()
{
    Solution s;
    vector<int> nums {3,2,4};
    vector<int> solution;
    solution = s.twoSum(nums, 6);
    cout << "[" << solution.at(0) << "," << solution.at(1) << "]" << endl;
}
