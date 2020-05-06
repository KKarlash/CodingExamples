//
//  MixedSolutions.cpp
//  CodingExamples
//
//  Created by Kostiantyn Karlash on 13.08.20.
//  Copyright © 2020 Kostiantyn Karlash. All rights reserved.
//

#include "MixedSolutions.hpp"

using namespace std;

MixedSolutions::MixedSolutions() {
}

double MixedSolutions::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    
    int l = 0;
    int r = m;
    
    while (l <= r) {
        int i = (l + r) / 2;
        int j = (m + n + 1) / 2 - i;
        if (i > 0 && nums1[i - 1] > nums2[j]) {
            r = i - 1;
        } else if (i < m && nums2[j - 1] > nums1[i]) {
            l = i + 1;
        } else {
            int lmax = i == 0 ? nums2[j - 1] :
                       j == 0 ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]);
            
            if ((m + n) % 2 != 0) return lmax;
            
            int rmin = i == m ? nums2[j] :
                       j == n ? nums1[i] : min(nums1[i], nums2[j]);
            return (lmax + rmin) / 2.0;
        }
    }
    return 0;
}
