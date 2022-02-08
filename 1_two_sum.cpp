#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash_table;
        vector<int> ans;

        for (int i=0; i<nums.size(); i++)
        {
            int num_to_find = target - nums[i];
            
            if (hash_table.count(num_to_find)) //determine whether exists in the table
            {
                ans.push_back(hash_table[num_to_find]);
                ans.push_back(i);
                break;
            }
            hash_table[nums[i]] = i; //key: value of the number, value: index of the number
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    //input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    //output
    cout << result[0] << result[1] << endl;
}