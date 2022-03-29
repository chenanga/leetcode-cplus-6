#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// class Solution {
// public:
//     int numSquares(int n) {

//         queue<pair<int,int>>que;
//         que.push(make_pair(n, 0));
//         vector<bool>visited(n+1, false);//�����������飬�ж�ÿ���ڵ��Ƿ񱻷���
//         visited[n] = true;
//         while(!que.empty()){
//             int num = que.front().first;
//             int distance = que.front().second;
//             que.pop();
//             if(num == 0) return distance;
//             for(int i = 1; num -i*i>=0; i++){
//                 if(!visited[num-i*i]){
//                     que.push(make_pair((num -i*i),distance+1));
//                     visited[num-i*i] = true;
//                 }
//             }
//         }
//         return -1;;
//     }
// };
//һЩϸ���Ż�
class Solution {
public:
    int numSquares(int n) {

        queue<pair<int, int>>que;
        que.push(make_pair(n, 0));
        vector<bool>visited(n + 1, false);//�����������飬�ж�ÿ���ڵ��Ƿ񱻷���
        visited[n] = true;
        while (!que.empty()) {
            int num = que.front().first;
            int distance = que.front().second;
            que.pop();

            for (int i = 1; ; i++) {
                int a = num - i * i;
                if (a < 0) break;
                if (a == 0) return distance + 1;

                if (!visited[num - i * i]) {
                    que.push(make_pair((num - i * i), distance + 1));
                    visited[num - i * i] = true;
                }
            }
        }
        return -1;;
    }
};

int main() {

    
	system("pause");
	return 0;
}