// Own Approach. O(N2) Time, O(N) Space (One Map, One Set, One Bool)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> matches;
        for(auto word:words) {
            map<char,char> charMap; bool flag=false; set<char> seenChars;
            for(int i=0;i<word.size();i++) {
                if(charMap.find(pattern[i])==charMap.end()) {
                    if(seenChars.find(word[i])==seenChars.end()) {
                        charMap[pattern[i]]=word[i];
                        seenChars.insert(word[i]);
                    }
                    else {
                        flag=true;
                    }
                }
                else if (charMap[pattern[i]]!=word[i]) flag=true;  
            }
            if(!flag) matches.push_back(word);
        }
        return matches;
    }
};


// LEETCODE ANSWER APPROACH. CREATE A CIPHER WITH THE GIVEN PATTERN, AND TRANSLATE ALL THE STRINGS AND THEN COMPARE. SAVES ON SPACE. O(N2) TIME, O(1) SPACE
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> matches;
        cipher=pattern;
        for(int i=0;i<pattern.size();i++) {
            cipher[i]=translate(cipher[i]);
        }
        for(int i=0;i<words.size();i++) {
            compareAndAdd(words[i],matches);
        }
        return matches;
    }
    map<char,char> codex;
    string cipher;
    char translate(char c) {
        if(codex.find(c)==codex.end()) codex[c]=(char)('a'+codex.size());
        return codex[c];
    }
    void compareAndAdd(string word, vector<string>& matches) {
        codex.clear();
        for(int i=0;i<word.size();i++) {
            if(translate(word[i])!=cipher[i]) return;
        }
        matches.push_back(word);
    }
};
