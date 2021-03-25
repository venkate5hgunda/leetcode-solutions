class Solution {
public:
    string convert(string s, int numRows) {
        map<int,string> zigzag;
        int zForm = 2*(numRows-1);
        int size = s.size();
        if(size == 0 || size == 1 || numRows == 1) return s;
        for(int i=0;i<size;i++) {
            zigzag[(numRows-1)-abs(i%zForm-(numRows-1))].push_back(s[i]);
        }
        string result;
        for(int i=0;i<numRows;i++) {
            result.append(zigzag[i]);
        }
        return result;
    }
};
