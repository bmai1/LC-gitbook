# 🎭 mask

Efficient way to process elements or states that satisfy a condition by removing/keeping specific bits.

Example problem (Kattis tictacstate):

```cpp
#include <bits/stdc++.h>

using namespace std;

// Predefined win bitmasks for a 3x3 Tic-Tac-Toe grid
const int win_masks[] = {
    0b111000000, // top row
    0b000111000, // middle row
    0b000000111, // bottom row
    0b100100100, // left column
    0b010010010, // middle column
    0b001001001, // right column
    0b100010001, // diagonal top-left to bottom-right
    0b001010100  // diagonal bottom-left to top-right
};

bool check_win(int player_mask) {
    for (int win_mask : win_masks) {
        // check if masks are equivalent
        if ((player_mask & win_mask) == win_mask) return true;
    }
    return false;
}

string analyze_state(int state) {
    int played = state & 0x1FF; // 0-8 denotes positions played
    int x = (state >> 9) & 0x1FF; // 9-17 denotes players, x if bit is set
    int o = played & ~x;

    if (check_win(x)) return "X wins";
    else if (check_win(o)) return "O wins";
    else if (played == 0x1FF) return "Cat's";
    else return "In progress";
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;

    while (c--) {
        int state;
        cin >> oct >> state;
        cout << analyze_state(state) << endl;
    }
}
```
