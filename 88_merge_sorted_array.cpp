#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pos1 = m - 1, pos2 = n - 1, pos_sort = m + n - 1;
        // sort from the end of the arrays
        while (pos1 >= 0 && pos2 >= 0)
        {
            if (nums1[pos1] > nums2[pos2])
                nums1[pos_sort--] = nums1[pos1--];
            else
                nums1[pos_sort--] = nums2[pos2--];
        }

        // nums1 has already been sorted
        if (pos1 < 0)
        {
            // put the rest of elements in nums2 into nums1
            for (int i = pos_sort; i >= 0; i--)
                nums1[i] = nums2[pos2--];
        }
    }
};

int main()
{
    Solution sol;

    // input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    // output
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i];
    }
    cout << endl;

    return 0;
}