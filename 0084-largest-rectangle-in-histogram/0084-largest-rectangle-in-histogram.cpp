class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxarea = 0;
        stack<int> st;
       
        for(int i = 0; i < heights.size();i++){
            
            while(!st.empty() && heights[st.top()] > heights[i]){
                int bar = heights[st.top()];
                st.pop();
                int a = st.empty() ? -1 : st.top();
                int b = i;
                maxarea = max(maxarea,bar*(b-a-1));
  
            }
            st.push(i);
        }
         while(!st.empty()) {

            int height = heights[st.top()];
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int right = heights.size();

            maxarea = max(maxarea,
                          height * (right - left - 1));
        }
        return maxarea;
    }
};