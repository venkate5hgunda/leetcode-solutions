class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome;
        string stringOdd, stringEven;
        if(s.size()==1) return s;
        for(int i=0;i<s.size();i++) {
            stringOdd = longestPalindromeAt(s,i,i);
            stringEven = longestPalindromeAt(s,i+1,i);
            palindrome = stringOdd.size()>palindrome.size() ? stringOdd : palindrome;
            palindrome = stringEven.size()>palindrome.size() ? stringEven : palindrome;
        }
        return palindrome;
    }
private:
    string longestPalindromeAt(string s, int left, int right) {
        while((left-1)>=0 && (right+1)<s.size() && s[left-1]==s[right+1]) {
            left--;
            right++;
        }
        return s.substr(left,right-left+1);
    }
};
