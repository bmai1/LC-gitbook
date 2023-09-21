# 👑 N-Queens (51.)

#### Classic example of conditional recursive backtracking:

```cpp
class Solution {
private:
    vector<vector<string>> ans;
    vector<string> state;

    // see if any queens in vision
    bool valid(int row, int col, int n) {
        // check col
        for (int i = 0; i < row; ++i) {
            if (state[i][col] == 'Q') return false;
        }
        // left diag
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (state[i][j] == 'Q') return false;
        }
        // right diag
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (state[i][j] == 'Q') return false;
        }
        return true;
    }

    void bt(int row, int n) {
        // placed a queen on each row, therefore satisfied n queens
        if (row == n) {
            ans.push_back(state);
            return;
        }
        // for each col, place queen if valid
        for (int col = 0; col < n; ++col) {
            if (valid(row, col, n)) {
                // state check & reversion
                state[row][col] = 'Q';
                bt(row + 1, n);
                state[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // states = size n vector of n-length '.' strings
        state = vector<string> (n, string(n, '.'));
        bt(0, n);
        return ans;
    }
};
```

#### Laaksonen approach (separate conditional arrays):

```cpp
#define vc vector<char>
#define vs vector<string>

class Solution {
private:
    vector<vs> ans;
    vs board;

    void search(int row, int n, vector<char>& col, vector<char>& d1, vector<char>& d2) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int x = 0; x < n; ++x) {
            if (col[x] == '.' && d1[x + row] == '.' && d2[x - row + n - 1] == '.') {
                // Place a queen
                col[x] = d1[x + row] = d2[x - row + n - 1] = 'Q';
                board[row][x] = 'Q';

                // Continue with the next row
                search(row + 1, n, col, d1, d2);

                // Backtrack
                col[x] = d1[x + row] = d2[x - row + n - 1] = '.';
                board[row][x] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vc col(n, '.');
        vc d1(2 * n - 1, '.');
        vc d2(2 * n - 1, '.');
        board = vs(n, string(n, '.'));

        search(0, n, col, d1, d2);

        return ans;
    }
};
```
