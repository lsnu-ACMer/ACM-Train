/*
 *��Ŀ����
 ����n�����ֵ�Բ������  �Ͱ뾶
 ��һ��Ϊ��ʼ����  ���һ��Ϊ��������  ��ת����һ�� ���һ���᲻��ת��
 �����  ����ת���ı����Ƕ��٣����һ��ת3Ȧ  ���һ��ת��Ȧ  ��������-2:3��
 �������ת��  �ǿ����˲���ת  ���ǵ�һ�����ֵ�ת������Ӱ�쵽���һ��

 ˼·��
 �ӵ�һ�����ֿ�ʼ�Һ������ŵ�  �ٰѺ������ŵļӵ���������   ����ȥ�ҺͶ�����Щ���ְ��ŵ�
 ���һ�������ܵ������������ֵ�Ӱ��  ��������Ӱ��ķ���һ��  �ǾͿ�����  ���еĶ�������  ��can not move 
 ����Ϳ����һ������  ����û�б�Ӱ�쵽  ���û�� ���޷����� 
 * */





#include<iostream>
#include<queue>
using namespace std;

int d[1007][1007];          //����������ֵ�Ӱ���ϵ�ѱ��ҵ���
long long cor[1007][2];     //Բ������
long long r[1007];          //�뾶
int sta[1007];              //ÿ������ת��״̬   1���͵�һ������ͬ��ת��  -1���͵�һ�����ַ���ת��  0������
queue<int> q;

int gcd(int x, int y){
    int z = y;
    while(x % y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

int abs(int x){
    if(x < 0) return -x;
    return x;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cor[i][0] >> cor[i][1];
        cin >> r[i];
    }
    sta[0] = 1;
    for(int j = 1; j < n; j++){
        d[0][j] = 1;
        if(((cor[j][0] - cor[0][0]) * (cor[j][0] - cor[0][0])) + ((cor[j][1] - cor[0][1]) * (cor[j][1] - cor[0][1])) == ((r[0] + r[j]) * (r[0] + r[j]))){//�ҳ��͵�һ�����ְ��ŵ����г���  ��Բ�ĵľ���һ�������������ֵİ뾶��
             sta[j] = -sta[0];      //�������ŵģ��໥��Ӱ��ģ�����һ����˳���෴�ķ���ת��
             q.push(j);               
        }
    }
    int flag = 0;
    while(q.size()){
        int f = q.front();
        q.pop();
        for(int j = 1; j < n; j++){
            if(d[f][j] == 1 || f == j) continue;
            d[f][j] = 1;
            d[j][f] = 1;
            if(((cor[j][0] - cor[f][0]) * (cor[j][0] - cor[f][0])) + ((cor[j][1] - cor[f][1]) * (cor[j][1] - cor[f][1])) == ((r[f] + r[j]) * (r[f] + r[j]))){
                int temp = -sta[f];
                if(sta[j] != 0 && sta[j] != temp){//�����ǰ�����Ѿ�����һ����Ӱ�콫��һ������ת��  ����f����Ӱ�콫����һ������ת��  ���ֿ���  ���г��ֶ�������ת��
                    flag = 1;
                    cout << "The input gear cannot move." << endl;
                    break;
                }
                sta[j] = temp;
                q.push(j);               
            }
        }
        if(flag != 0) break;
    }
    if(flag == 0){
        if(sta[n - 1] == 1){   //������һ�����ֵ�״ֵ̬Ϊ1  ˵���͵�һ�������ǳ�ͬһ��ת��
            int z = gcd(r[n - 1], r[0]);
            cout << abs(r[0] / z) << ":" << r[n - 1] / z << endl;
        }else if(sta[n - 1] == -1){  //������һ�����ֵ�״ֵ̬Ϊ-1  ˵���͵�һ�������ǳ�������ת��
            int z = gcd(r[n - 1], r[0]);
            cout << -abs(r[0] / z )<< ":" << r[n - 1] / z << endl;
        }else{          //״ֵ̬����Ϊ0 ˵�������յ�Ӱ��
            cout << "The input gear is not connected to the output gear." << endl;
        }
    }
    return 0;
}

