class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        vector<int> output;
        boo same = false;
        //find which of the values are found on both arrays
        for( int i = 0; i < nums1.size(); i++) {
            for( int j = 0; j < nums2.size(); j++) {
                if( nums1[i] == nums2[j])
                    intersect.push_back(nums2[j]);
            }
        }
        for(int k = 0; k < intersect.size() - 1; k++)
            if( intersect[k] == intersect[k+1])
                same = true;
        
        boolean to check
            else
                output.push_back(intersect[i]
        return intersect;
    }
};
