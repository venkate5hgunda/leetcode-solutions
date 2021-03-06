class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if(x<10) return true;
        string xStr = to_string(x);
        int left=0,right=xStr.size();
        while(left<=right) {
            if(xStr[left]!=xStr[right-1]) return false;
            left++;
            right--;
        }
        return true;
    }
};


// ALTERNATE SOLUTION :: WITHOUT USING STRING DATA TYPE
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if(x<10) return true;
        long int xRev=0;
        int temp=x;
        while(xRev<x && temp>0) {
            xRev = xRev*10 + temp%10;
            temp = temp/10;
        }
        if(xRev==x) return true;
        else {
            return false;
        }
    }
};
