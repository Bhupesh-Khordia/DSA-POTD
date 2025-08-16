class Solution {
public:
    int maximum69Number (int num) {
        int sixIndex = -1;
        int temp = num;
        int i = 0;
        while(temp> 0) {
            if(temp % 10 == 6) sixIndex = i;
            i++;
            temp /= 10;
        }

        return sixIndex == -1 ? num : num + (3 * pow (10, sixIndex));
    }
};
