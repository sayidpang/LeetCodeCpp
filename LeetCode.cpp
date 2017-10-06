#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
int main()
{
    string str = "";
    // lengthOfLongestSubstring("abcabcbb");
    vector<int> nums1;
    nums1.push_back(1);nums1.push_back(2);//nums1.push_back(3);
    vector<int> nums2;
    nums2.push_back(1);nums2.push_back(2);//nums2.push_back(6);
    double median = findMedianSortedArrays(nums1, nums2);
    cout<<median<<endl;
    cin>>str;
    return 0;
}

/*
LeetCode Problem 2
*/
int lengthOfLongestSubstring(string s)
{
    int max = 0;
    for (size_t i = 0; i < s.length() && max <(s.length()-i); i++)
    {
        string sub = "";
        sub.append(1, s[i]);
        int cur_length = 1;
        for (size_t j = i+1; j < s.length(); j++)
        {
            string s_char = "";
            s_char.append(1, s[j]);
            if (sub.find(s_char) == string::npos)
            {
                sub += s_char;
                cur_length++;
            }
            else
            {
                break;
            }
        }
        if (cur_length > max)
        {
            max = cur_length;
        }
        cout<<sub<<",长度"<<cur_length<<endl;
    }
    return max;
}

/*
LeetCode Problem 4
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