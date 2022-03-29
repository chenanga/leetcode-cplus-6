#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq; //（元素，频率）
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        //pair （频率，元素）
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (pq.size() == k) {
                //此时需要比较
                if ((*iter).second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair((*iter).second, (*iter).first));
                }
            }
            else
                pq.push(make_pair((*iter).second, (*iter).first));
        }

        vector<int>res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();

        }
        return res;
    }
};

int main() {

	system("pause");
	return 0;
}