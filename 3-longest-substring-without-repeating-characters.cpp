class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int asciimap[256] = {0};
        int left = 0;
        int longestSub = 1;
        int size = s.size();
        if(size==0) return 0;
        for(int i=0;i<size;i++) {
            asciimap[(int)s[i]]++;
            while(asciimap[(int)s[i]]>1) {
                asciimap[(int)s[left]]--;
                left++;
            }
            longestSub=max(longestSub,i-left+1);
        }
        return longestSub;
    }
};
