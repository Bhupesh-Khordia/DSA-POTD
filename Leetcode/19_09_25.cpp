class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid;  // rows x 26

    // Helper: parse cell reference like "A1", "Z10"
    pair<int, int> parseCell(const string& cell) {
        char colChar = cell[0];
        int col = colChar - 'A'; // 0-indexed column
        int row = stoi(cell.substr(1)) - 1; // 0-indexed row
        return {row, col};
    }

    // Helper: get value of either integer or cell reference
    int getOperandValue(const string& token) {
        if (isdigit(token[0])) {
            return stoi(token); // numeric constant
        } else {
            auto [r, c] = parseCell(token);
            if (r >= 0 && r < rows && c >= 0 && c < 26)
                return grid[r][c];
            return 0; // out of bounds -> treated as 0
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        if (r >= 0 && r < rows && c >= 0 && c < 26)
            grid[r][c] = 0;
    }

    int getValue(string formula) {
        if (formula.empty() || formula[0] != '=') return 0;

        // Formula format: =X+Y
        string expr = formula.substr(1);
        size_t pos = expr.find('+');
        string left = expr.substr(0, pos);
        string right = expr.substr(pos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
