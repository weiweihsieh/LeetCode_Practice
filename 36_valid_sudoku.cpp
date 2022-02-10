#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0; i<9; i++)
        {
            bool row[9] = {false};
            bool col[9] = {false};
            bool box[9] = {false};
            
            for(int j=0; j<9; j++)
            {
                //check row
                if(board[i][j] != '.')
                {
                    if(row[int(board[i][j] - '1')] == true) //repetition
                        return false;
                    else
                        row[int(board[i][j] - '1')] = true;
                }

                //check column
                if(board[j][i] != '.')
                {
                    if(col[int(board[j][i] - '1')] == true) //repetition
                        return false;
                    else
                        col[int(board[j][i] - '1')] = true;
                }

                //check box
                int row_index = (i/3)*3 + j/3;
                int col_index = (i%3)*3 + j%3;
                
                if(board[row_index][col_index] != '.')
                {
                    if(box[int(board[row_index][col_index] - '1')] == true) //repetition
                        return false;
                    else
                        box[int(board[row_index][col_index] - '1')] = true;
                }
            }
        }
        
        return true;
    }
};

int main()
{  
    Solution sol;

    //input
    vector<vector<char>> board = 
    {{'5','.','.','.','.','.','.','.','.'}
    ,{'.','.','.','2','.','.','.','.','.'}
    ,{'.','.','.','.','.','3','.','.','.'}
    ,{'8','.','.','.','.','.','.','.','.'}
    ,{'3','.','1','5','2','.','.','.','.'}
    ,{'.','.','.','.','.','.','.','4','.'}
    ,{'.','.','6','.','.','.','.','.','.'}
    ,{'.','.','.','.','.','.','.','9','.'}
    ,{'.','.','.','.','.','.','.','.','.'}};

    bool ans = sol.isValidSudoku(board);

    //output
    cout << ans << endl;

    return 0;
}