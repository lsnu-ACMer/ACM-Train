
/*
 * Σ�� - ��ȫ ��= 2
 * ��ȫ+1 Ϊ��Ϳ���ˤ��
 * Σ��-1   ��߿��ܰ�ȫ
 *
 *             == 1
 *����
 * */

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;


int main(){
    int c, b;
    int sa=0, brek=0;
    int saffe[107], breakk[107];
    cin >> c >> b;
    for(int i = 0 ; i < c; i++){
        int bn;
        string mes;
        cin >> bn >> mes;
        if("SAFE" == mes){
            saffe[sa++] = bn;
        }else{
            breakk[brek++] = bn;
        }
    }
    saffe[sa++] = 1;
    breakk[brek++] = b;
    sort(saffe, saffe + sa);
    sort(breakk, breakk + brek);
    if(breakk[0] - saffe[sa - 1] >= 2){
        cout << saffe[sa - 1] + 1 << " " << breakk[0] - 1 << endl;
    }else if(breakk[0] - saffe[sa - 1] == 1){
        cout << breakk[0] << " " << saffe[sa - 1] << endl;
    }
    return 0;
}