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


