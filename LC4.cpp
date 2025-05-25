#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 

         if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;

        while (left <= right) {
            int X = (left + right) / 2;
            int Y = halfLen - X;

            int maxLeftX = (X == 0) ? INT_MIN : nums1[X - 1];
            int minRightX = (X == m) ? INT_MAX : nums1[X];

            int maxLeftY = (Y == 0) ? INT_MIN : nums2[Y - 1];
            int minRightY = (Y == n) ? INT_MAX : nums2[Y];


            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {

                if ((m + n) % 2 == 0) {

                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {

                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {

                right = X - 1;
            } else {

                left = X + 1;
            }
        }


        return 0.0;

    }
