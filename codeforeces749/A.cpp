/*
 *
 * 只可能有两种情况  要么全是2  要么最后一个是3
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = n / 2;
    int temp = n % 2;
    if(temp != 0){
        cout << ans << endl;
        for(int i = 0; i < ans - 1; i++){
            cout << 2 << " ";
        }
        cout << 3 << endl;
    }else{
        cout << ans << endl;
         for(int i = 0; i < ans; i++){
             if(i == ans - 1){
                cout << 2 << endl;
             }else{
                cout << 2 << " ";
             }
         }
    }
    return 0;
}*/
