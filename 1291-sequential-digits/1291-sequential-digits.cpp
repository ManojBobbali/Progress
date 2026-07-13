class Solution {
public:
   
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seq;
        for(int i = 1; i < 10;i++){
            int num = 0;
            for(int j = i;j < 10;j++){
              num = num * 10 + j; 
              seq.push_back(num);
            }  
        }
        sort(seq.begin(),seq.end());
        vector<int> res;
        for(int i: seq){
            if(i > high)break;
            if( i >= low && i <= high)res.push_back(i);
        }
        return res;
    }
};