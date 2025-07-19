// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2025-07-19

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i = 1; i < folder.size(); i++) {
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            // Compare current folder with last added folder
            // compare(0, lastFolder.size(), lastFolder) checks if folder[i] starts with lastFolder
            // If it doesn't start with lastFolder (returns != 0), then it's not a subfolder
            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                // If not a subfolder, add to result
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
