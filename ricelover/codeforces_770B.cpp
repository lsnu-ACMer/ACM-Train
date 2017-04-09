
/*
 *题目大意
 给定一个正整数x（< 10^18） 求比x小但每位数加起来和最大的数字  如果有多个答案 取最大值
 *
 *解题思路：
 *  当除第一位外的每一位都为9时  所有位数的和依旧不大于x的所有位和  便原样输出
 * 
 *  遍历每一位  1、当该位数值小于8且不为第一位  向前一位借1 当前位结果置为9
 *              2、当该位数值等于9且后面向其借位   记录下当前位置的下标  置当前位结果为8  如果在后续遍历中遇到相同情况  置该位结果为9
 *              3、若当前位为第一位且后面向其借位   该位值减1借出去  如果有第二种情况  将其下标所对应的结果值置为9
 *              4、否则结果和当前位值相同
 */


#include<iostream>
using namespace std;

int main(){
    string s;
    int res[20];
    cin >> s;
    int len = s.size();
    int temp = 0;       //标记是否借位
    int val = 0;
    int de9 = -1;       //记录位值为9 且有借位的下标

    /**
     *  判断除第一位其他位均取9时  是否大于x的所有位和
     */
    for(int i = len - 1; i >= 0; i--){
        if(s[i] - '0' < 9){
            temp = 1;
        }
        if(temp == 1 && i == 0){
            val -= 1;
        }else {
            val += (9 - (s[i] - '0'));
        }
    }
    if(val < 1){
        cout << s << endl;
        return 0;
    }
    for(int i = len - 1; i >= 0; i--){
       
        if(s[i] - '0' <= 8 && i >= 1){
            res[i] = 9;
            temp = 1;
        }else if(s[i] == '9' && temp == 1){
            if(de9 != -1){
                res[de9] = 9;
            }
            de9 = i;
            temp = 0;
            res[i] = s[i]- '0' - 1;
        }else if(i == 0 && temp == 1){
            if(de9 != -1){
                res[de9] = 9;
            }
            res[i] = s[i] - '0' - 1;
        }else{
            res[i] = s[i] - '0';
        }
    }
    int flag = 0;
    for(int i = 0; i < len; i++){
        if(flag == 0 && res[i] == 0){
            continue;
        }else{
            cout << res[i];
        }
    }
    cout << endl;
    return 0;
}
