class Solution {
public:
    int minLength(string s) {
        if(s.length() == 1)
        {
            return s.length();
        }

        while(true)
        {
            std::cout << s << std::endl;
            if(s.find("AB") != string::npos)
            {
                s.erase(s.find("AB"), 2);
            }
            else if(s.find("CD") != string::npos)
            {
                s.erase(s.find("CD"), 2);
            }
            else
            {
                return s.length();
            }
        }
    }
};
