class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());

        int v_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[v_index++];
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return string("AEIOUaeiou").find(c) != string::npos;
    }
};

/*
class Solution {
private:
    bool isVowel (char ch) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        return vowels.find(ch) != vowels.end();
    }
public:
    string sortVowels(string s) {
        string t = s;
        vector<int> vowelIndices; // This is not needed
        vector<char> vowels;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (isVowel(ch)) {
                vowelIndices.push_back(i);
                vowels.push_back(ch);
            }
        }

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for(int i : vowelIndices) {
            t[i] = vowels[idx++];
        }

        return t;
    }
};
*/
