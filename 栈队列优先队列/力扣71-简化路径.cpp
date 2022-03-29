#include<iostream>
#include<stack>
#include<vector>


using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> names = mySplit(path, '/');
        stack<string> record;
        for (int i = 0; i < names.size(); i++) {

            if (names[i] == "..") {
                if (!record.empty())
                    record.pop();
            }
            else if (names[i] == ".")
                continue;
            else
                record.push(names[i]);
        }
        string res = "";
        while (!record.empty()) {
            string str = record.top();

            record.pop();
            res = "/" + str + res;
        }
        if (res == "") return "/";
        return res;
    }
private:
    vector<string> mySplit(string path, char splitSymbol) {
        path += "/";
        vector<string>record;
        int left = 1;

        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (i != left)
                    record.push_back(path.substr(left, i - 1 - left + 1));
                left = i + 1;
            }
        }
        return record;
    }
};




int main() {
    string str = "/a/./b/../../c/"  ;
    cout<< Solution().simplifyPath(str);
    system("pause");
    return 0;
}