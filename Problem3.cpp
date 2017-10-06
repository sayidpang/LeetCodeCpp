/*
LeetCode Problem 3:Longest Substring Without Repeating Characters   
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
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