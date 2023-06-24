class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> s_freqs;
        unordered_map<char, int> t_freqs;
        int i = 0;
        while (i < min(s.length(), t.length()))
        {
            s_freqs[s[i]] += 1;
            t_freqs[t[i]] += 1;
            i++;
        }

        if (s.length() > t.length())
        {
            while (i < s.length())
            {
                s_freqs[s[i]] += 1;
                i++;
            }
        }
        else
        {
            while (i < t.length())
            {
                t_freqs[t[i]] += 1;
                i++;
            }
        }
        
        for (auto const& [key, val] : s_freqs)
        {
            if (t_freqs[key] != val) 
            {
                return false;
            }
        }

        return true;
    }
};