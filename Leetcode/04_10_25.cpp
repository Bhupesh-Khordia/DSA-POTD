class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 , right = height.size()-1;
        int maximum =0 ;
        while(left<right){
            int height1 = min(height[left] , height[right]);
            int width = right -left;
            int area = height1 * width ;
            maximum = max(maximum ,area );
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maximum ;
    }
};
