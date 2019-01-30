#include <bits/stdc++.h>

//*************************************************************************
// to count the all possible pair in the given std::string.
unsigned int countSubstring(const std::string &str, const std::string &sub)
{
    if (sub.length() == 0) return 0;
    unsigned int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
//*************************************************************************
// to count the length of required t symmetry,
unsigned twoCharaters(std::string s)
{
   // this for loop erases every char which occurs as a pair in given std::string.
   for(unsigned int i=1; i<s.length(); ++i)
      if(s.at(i-1)==s.at(i))
       s.erase(remove(s.begin(),s.end(), s.at(i-1)), s.end());

   // this makes all possible pairs from remaining std::string.
   char sbstr[3];
   std::string SBSTR, basic_t;
   unsigned int Count=0, frequency_SBSTR=0;
   for (unsigned int i = 0; i < s.length() - 1; ++i)
      for (unsigned int j = i + 1; j < s.length(); ++j)
         if(s.at(i)!=s.at(j))
         {
            // if they are same, do not need to make a pair of it.
            sbstr[0] = (char) s[i];
            sbstr[1] = (char) s[j];
            sbstr[2] = 0;
            // this is possible pair (a basic t).
            SBSTR=sbstr;
            // function calculates frequency.
            frequency_SBSTR=countSubstring(s, SBSTR);
            if(frequency_SBSTR>Count)
               {
                  Count=frequency_SBSTR;
                  basic_t=SBSTR;
                  // assign maximum counted pair to the basic t.
               }
         }
    // this loop deletes all unnecessary char's to make the std::string a unique t.
    for (unsigned int i = 0; i < s.length(); ++i)
      if(s.at(i)!= basic_t[0] && s.at(i)!=basic_t[1])
         {
            s.erase (s.begin()+i);
            // if we delete i, index should std::set back to previous index.
            i=i-1;
            if(s.length()==2) // in case of minimum size
               return 0;
         }

   if(s.length()==0)
      return 0;
   else
      return s.length();
}
//****************************************************************************
int main()
{
   unsigned int len; std::cin >> len; // a single integer denoting the length of s.
   std::string s;         std::cin >> s; // s only contains lowercase English alphabetic letters.
   if(len>=1 && len<=1000)
   {
      unsigned int result = twoCharaters(s);
      std::cout << result << std::endl;
   }
   return 0;
}

