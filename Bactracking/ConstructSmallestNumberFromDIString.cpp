class Solution {
public:
    int n;
    int m;

    string num = "";
    vector<bool> used;
    bool found = false;

    void rec(int level, string& pattern) {
        // base case
        if (level >= m) {
            found = true;
            return;
        }

        // choices
        for (int i = 1; i <= m; i++) {
            // check if used
            if (used[i])
                continue;

            int x = num[level - 1] - '0';

            if ((pattern[level - 1] == 'D' && x > i) ||
                (pattern[level - 1] == 'I' && x < i)) {
                // try
                num.push_back(i + '0');
                used[i] = true;
                // explore
                rec(level + 1, pattern);
                if(found)return;
                // undo
                num.pop_back();
                used[i] = false;
            }
        }
    }

    string smallestNumber(string pattern) {
        n = pattern.size();
        m = n + 1;
        used.assign(m + 1, false);
        
        for (int start = 1; start <= m; start++) {
            num = string(1, start + '0'); //created:-> " start + '0' "
            used[start] = true;
            rec(1, pattern);
            if (found) return num;
            used[start] = false;
        }

        return num;
    }
};
