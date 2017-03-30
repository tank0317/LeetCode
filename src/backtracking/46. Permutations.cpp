/**
 * 方法一：典型的回溯求解方式
 **/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        vector<int> list;
        vector<bool> used(num.size(), false);
        solve(num, ans, list, used);
        return ans;
    }
    
    void solve(vector<int>& num, vector<vector<int>>& ans, vector<int>& list, vector<bool>& used){
        if(list.size() == num.size()){
            ans.push_back(list);
            return ;
        }
        for(int i=0; i<num.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            list.push_back(num[i]);
            solve(num, ans, list, used);
            list.pop_back();
            used[i] = false;
        }
    }
    
};

/**
 * 方法二：更加巧妙，无论时间还是空间上都要更加优于第一种算法。
 * 但是方法一的方式，更加通用，属于遍历所有可能，然后通过约束去掉部分不符合要求的解，属于回溯法的通常思想
 **/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        permuteRecursive(num, 0, result);
        return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};