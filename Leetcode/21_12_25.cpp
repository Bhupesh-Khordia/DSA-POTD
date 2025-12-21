class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), prevMpSize = 0;
        unordered_set<int> delIndices;

        while (true) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < m; k++) {
                        if (delIndices.find(k) != delIndices.end())
                            continue;

                        if (strs[i][k] < strs[j][k])
                            delIndices.insert(k);
                        else if (strs[i][k] == strs[j][k])
                            continue;
                        else
                            break;
                    }
                }
            }
            if(delIndices.size() == prevMpSize)
              break;
            prevMpSize = delIndices.size();
        }

        return delIndices.size();
    }
};
