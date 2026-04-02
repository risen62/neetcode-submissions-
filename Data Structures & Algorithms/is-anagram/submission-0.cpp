class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length())
    {
        cout << "The strings are not anagram." << endl;
        return 0;
    }
    int H[26] = {0};
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
    }

    for (i = 0; t[i] != '\0'; i++)
    {
        H[t[i] - 97]--;
    }

    bool isAnagram = true;
    for (i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            isAnagram = false;
            break;
        }
    }
    if (isAnagram == false)
    {
        return false;
    }
    else
    {
        return true;
    }
  }
};
