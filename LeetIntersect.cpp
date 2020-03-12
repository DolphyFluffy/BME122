class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //iterate through both arrays testing for same values
        vector<int> intersect;
        bool same_value = false;
        int max_value = 0;
        for( int a = 0; a < nums1.size(); a++) {
            if(max_value < nums1[a])
                max_value = nums1[a];
        }
        
        for( int b = 0; b < nums2.size(); b++) {
            if(max_value < nums2[b])
                max_value = nums2[b];
        }
        
        for( int i = 0; i < max_value + 1; i++) {
            for( int j = 0; j < nums1.size(); j++){
                for( int k = 0; k < nums2.size(); k++) {
                    if( nums1[j] == nums2[k] && nums1[j] == i && same_value == false)
                        same_value = true;
                }
            }
            if(same_value){
                intersect.push_back(i);
                same_value = false;
            }
        }
        return intersect;
    }
};
