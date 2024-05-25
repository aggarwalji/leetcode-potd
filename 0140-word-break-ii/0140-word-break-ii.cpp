class Solution 
{
public:
   bool isValidWord(const string& word, const unordered_set<string>& wordDict) {
    return wordDict.find(word) != wordDict.end();
}

// Recursive function to generate valid sentences
void backtrack(const string& s, int start, const unordered_set<string>& wordDict, vector<string>& result, string& current) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int end = start + 1; end <= s.length(); ++end) {
        string word = s.substr(start, end - start);
        if (isValidWord(word, wordDict)) {
            // Add the valid word to the current sentence
            string temp = current;
            if (!temp.empty()) temp += " ";
            temp += word;
            backtrack(s, end, wordDict, result, temp);
        }
    }
}

vector<string> wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<string> result;
    string current;
    backtrack(s, 0, wordSet, result, current);
    return result;

    }
};