# include <iostream>
# include <vector>

using namespace std;

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int end = s.size() - 1;

        for(int i=0; i<s.size()/2; i++)
            swap(s[i], s[end-i]);
    }
};

int main()
{
    Solution sol;
    
    //input
    vector<char> string = {'i', 'h', 'j'};

    sol.reverseString(string);

    //output
    for (int i=0; i<string.size(); i++)    
        cout << string[i];
    cout << endl;

    return 0;
}