/*
LeetCode Problem 4:Median of Two Sorted Arrays   
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int m = nums1.size(), n=nums2.size();
    int destination1 =0;
    int old_even = 1;
    if((m+n)%2 == 1)
    {
        destination1 =  (m+n+1)/2;
    }
    else
    {
        old_even = 2;
        destination1 = (m+n)/2;
    }
    int pos1=0, pos2=0;
    int val1 =0, val2=0;
    for(int count=0; count <= (destination1-1); count++)
    {
        if(pos1<m && pos2<n)
        {
            if(nums1[pos1] <= nums2[pos2])
            {
                if(count != (destination1 -1))
                    pos1++;
                else
                {
                    val1 = nums1[pos1];
                    pos1++;
                    if(old_even == 1)
                    {
                        val2 = val1;
                    }
                    else
                    {
                        if(pos1<m && nums1[pos1] <= nums2[pos2])
                            val2 = nums1[pos1];
                        else
                            val2 = nums2[pos2];
                    }
                    break;
                }
            }
            else
            {
                if(count != (destination1 - 1))
                    pos2++;
                else
                {
                    val1 = nums2[pos2];
                    pos2++;
                    if(old_even == 1)
                    {
                        val2 = val1;
                    }
                    else
                    {
                        if(pos2<n && nums2[pos2] <= nums1[pos1])
                            val2 = nums2[pos2];
                        else
                            val2 = nums1[pos1];
                    }
                    break;
                }
            }
        }
        else if(pos1 == m)
        {
            val1 = nums2[destination1 - m -1];
            if(old_even == 1)
                val2 = val1;
            else
                val2 = nums2[destination1 - m];
            break;
        }
        else
        {
            val1 = nums1[destination1 -n -1];
            if(old_even == 1)
                val2 = val1;
            else
                val2 = nums1[destination1 - n];
            break;
        }
    }
    return (val1*1.0+val2*1.0)/2;
}