class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int sizeS = size1+size2;
        int medianIndex = sizeS/2;
        int i1=0,i2=0;
        
        double nums3[medianIndex+1];
        
        for(int i=0;i<(medianIndex+1);i++) {
            if(i1>=size1 && i2<size2) {
                nums3[i] = (nums2[i2]+0.0);
                i2++;
            }
            else if(i2>=size2 && i1<size1) {
                nums3[i] = (nums1[i1]+0.0);
                i1++;
            }
            else if(nums1[i1]<=nums2[i2]) {
                nums3[i] = (nums1[i1]+0.0);
                i1++;
            }
            else {
                nums3[i] = (nums2[i2]+0.0);
                i2++;
            }
        }
        if((sizeS)%2) {
            return nums3[medianIndex];
        }
        else {
            return (nums3[medianIndex-1] + nums3[medianIndex])/2.0;
        }
    }
};
