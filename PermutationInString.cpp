#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> f_string;
        unordered_map<char, int> s_string;

        if(s1.size()> s2.size()){
            return false;
        }        

        for(int i = 0; i < s1.size(); i++){
            f_string[s1[i]]++;
            s_string[s2[i]]++;
        }

        if(f_string == s_string){
            return true;
        }

        int left = 0;
        for(int right = s1.size(); right < s2.size(); right++){
            s_string[s2[right]]++;
            s_string[s2[left]]--;

            if(s_string[s2[left]] == 0){
                s_string.erase(s2[left]);
            }
            left++;
            if(f_string == s_string){
                return true;
            }
        }
        return false;
    }
};