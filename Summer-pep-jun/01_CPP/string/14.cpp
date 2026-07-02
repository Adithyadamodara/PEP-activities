// https://leetcode.com/problems/valid-anagram/



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size()!=s.size()) return false;
        int arr[26] = {0};
        
        for(int i:s){
            arr[i-'a']++;
        }

        for(int i:t){
            arr[i-'a']--;
        }
        for(int i: arr){
            if(i!=0) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        n = str.size();
        string str2 = str;
        int j=n-1;
        int i=0;
        while(i<=j){
            swap(str2[i++], str2[j--]);
        } 
        return str==str2;
    }
};


// https://leetcode.com/problems/valid-palindrome-ii/ 


class Solution {
public:
    bool isPalindrome(string& str, int left, int right){
        while(left<right){
            if(str[left]==str[right]){
                left++; 
                right--;
            } else return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;    
        int j = s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++; 
                j--;
            } else {
                return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0) return true;
        int p=0;
        for(int i=0;i<n;i++){
            if(p<m && s[p] == t[i]){
                p++;
                if(p==m) return true;
            }
        }
        return false;
    }
};


// https://www.geeksforgeeks.org/problems/find-first-repeated-character4108/1

class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        bool arr[26] = {0};
        int n = s.size();
        for(int i=0;i<n;i++){
            if(arr[s[i]-'a']){
                return {s[i]};
            } 
            arr[s[i]-'a'] = 1;
        }
        return "-1";
    }
};