#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i=digits.size()-1; i >= 0; i--) //check from least significant
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;

                if (i == 0) //most significant
                    digits.insert(digits.begin(), 1);
            }
            else
            {
                digits[i]++;
                break; //no carry digit
            }
        }

        return digits;
    }
};

int main()
{
    Solution sol;

    //input
    vector<int> digits = {9, 9, 9, 9};

    vector<int> result = sol.plusOne(digits);

    //output
    for (int i=0; i<result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
}