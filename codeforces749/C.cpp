/*
 *
 * 
#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag = 0;
    int tempd = 0;  //由前方R指定无法投票的D的个数
    int tempr = 0;  //由前方D指定无法投票的R的个数
    while(s.size() > 1){
        string s1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'D'){
                if(tempd > 0){  //当前为D但已被前方R消灭掉
                    tempd -= 1;
                    continue;
                }else{          //当前为D而且没被之前的R指定无法投票  把当前D留下 并消灭一个R
                    s1 += 'D';
                    tempr += 1;  
                }
            }else{
               if(tempr > 0){
                    tempr -= 1;
                    continue;
                }else{ 
                    s1 += 'R';
                    tempd += 1;  
                } 
            }
        }
        if(s == s1){
            flag = 1;
            break;
        }
        s = s1;
    }
    if(flag == 1){
        cout << s[0] << endl;
    }else{
        cout << s << endl;
    }
    
    return 0;
}

*/