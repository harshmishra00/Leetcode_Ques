class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string str1=strs[0];
    string str2=strs[strs.size()-1];
    int index=0;
    while(index<str1.size()){
        if(str1[index]==str2[index]){
            index++;
        }else{
            break;
        }
    }

    return index==0?"":str1.substr(0,index);
    }
};