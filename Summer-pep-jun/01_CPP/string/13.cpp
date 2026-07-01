// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1


class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        unordered_set<char> seen;
        string res = "";
        for(char c:s){
            if(seen.count(c)){
                continue;
            } 
            res += c;
            seen.insert(c);
        }
        return res;
    }
};