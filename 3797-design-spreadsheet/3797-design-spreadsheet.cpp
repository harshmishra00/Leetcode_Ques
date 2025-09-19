class Spreadsheet {
public:
    unordered_map<string, int> cells;
    int rows;

    Spreadsheet(int rows) {
        this->rows = rows;
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        if (cells.find(cell) != cells.end()) {
            cells.erase(cell);
        }
    }
    
    int getValue(string formula) {
        // Formula is always of the form "=X+Y"
        string expr = formula.substr(1); // remove '='
        int plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        auto resolve = [&](const string &tok) -> int {
            if (!tok.empty() && isalpha(tok[0])) {
                // it's a cell reference
                if (cells.find(tok) != cells.end()) return cells[tok];
                return 0;
            }
            return stoi(tok); // numeric literal
        };

        return resolve(left) + resolve(right);
    }
};