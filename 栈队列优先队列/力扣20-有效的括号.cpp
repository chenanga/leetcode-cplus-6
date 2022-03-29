#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {

		stack<char> record;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				record.push(s[i]);
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
				if (s[i] == record.top())
					record.pop();
				else
					return false;
			}
			else
				throw invalid_argument("Î¥¹æ×Ö·û");

		}
		if (record.empty())
			return true;
		else
			return false;
	}
};

int main() {

	system("pause");
	return 0;
}