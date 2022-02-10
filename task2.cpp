#include<iostream>
#include<vector>
#include <algorithm>

void DFS(std::vector<int>& candidates,int target,std::vector<int> out,int start,std::vector<std::vector<int>> &res){
        if(target<0){
            return;
        }else if(target==0){
            res.push_back(out);
        }else{
            for(int i=start;i<candidates.size();i++){
                if(i>start&&candidates[i]==candidates[i-1]){
                    continue;
                }
                out.push_back(candidates[i]);
                DFS(candidates,target-candidates[i],out,i+1,res);
                out.pop_back();
            }
        }
    }


std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> out;
        sort(candidates.begin(),candidates.end());
        DFS(candidates,target,out,0,res);
        return res;
    }

int main(){
    int candLength, targets, i;
    std::vector<int> candidates;
    std::cin >> candLength;
    for(i = 0;i < candLength;i++){
        std::cin >> candidates[i];
    }
    std::vector<std::vector<int>> res = combinationSum2(candidates,targets);
    for(i = 0; i < res.size(); i++){
         for(int y = 0; y <res[i].size();y++){
             std::cout << res [i][y];
         }
         std::cout << std::endl;
    }
}
