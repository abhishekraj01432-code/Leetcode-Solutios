class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     unordered_set<string> seen;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];

                if(c == '.') continue;

                string row = "r" + to_string(i)+c;
                string col = "c" + to_string(j)+c;
                string box = "b" + to_string((i/3)* 3 + (j/3)) + c;

                if (seen.count(row) || seen.count(col) || seen.count(box))
                return false;

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }

        return true;
    }
};