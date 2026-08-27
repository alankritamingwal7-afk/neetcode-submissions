class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m){
            return false;
        }
        else{
            int freq1[256]={0};
            int freq2[256]={0};
            for(auto i:s){
                freq1[i-'A']++;
            }
            for(auto j:t){
                freq2[j-'A']++;
            }
            int ans = true;
            for(int i = 0 ;i<256;i++){
                if(freq1[i]!=freq2[i]){
                    ans = false;
                    break;
                }
            }
            return ans;
        }    
    }
};
