#include<iostream>
#include<queue>
#include <functional>

using namespace std;

bool myCmp(int a, int b) {
	return a % 10 < b % 10; //�Ƚϸ�λ����С
}

int main() {
	//�ײ�������

	priority_queue<int> pq;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int num = rand() % 100;
		pq.push(num);
		cout << "insert " << num << " in priority queue" << endl;

	}

	while (!pq.empty()) {
		cout << pq.top()<< " ";
		pq.pop();
	}
	cout << endl;

	//�ײ�����С��
	priority_queue<int, vector<int>, greater<int> > pq2;
	for (int i = 0; i < 10; i++) {
		int num = rand() % 100;
		pq2.push(num);
		cout << "insert " << num << " in priority queue" << endl;

	}
	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl;

	//ʹ���Զ����comparator��priority queue
	priority_queue<int, vector<int>, function<bool(int, int)> > pq3(myCmp);

	for (int i = 0; i < 10; i++) {
		int num = rand() % 100;
		pq3.push(num);
		cout << "insert " << num << " in priority queue" << endl;

	}
	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}