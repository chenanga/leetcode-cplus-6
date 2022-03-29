#include<iostream>
#include<vector>
#include<stack>
#include<cassert>

using namespace std;

//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//
//        stack<int> record;
//        for (int i = 0; i < tokens.size(); i++) {
//            if (!(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-"))
//                record.push(atoi(tokens[i].c_str()));
//            else {
//                //由于表达式有效，故此处不再作判断是否有效等
//                int nums1 = record.top();
//                record.pop();
//                int nums2 = record.top();
//
//                record.pop();
//                char symbol = tokens[i][0];
//                int nums3 = 0;
//                switch (symbol) { //此处是由于题目保证了只有下面四种符号
//                case '/': //此处注意nums2是靠前的，运算也是放前面
//                    nums3 = nums2 / nums1; break;
//                case '*':
//                    nums3 = nums2 * nums1; break;
//                case '+':
//                    nums3 = nums2 + nums1; break;
//                case '-':
//                    nums3 = nums2 - nums1; break;
//                }
//
//                record.push(nums3);
//
//            }
//
//        }
//
//        return record.top();
//    }
//};

//去除一些不必要的变量
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> record;
        for (int i = 0; i < tokens.size(); i++) {
            if (!(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-"))
                record.push(atoi(tokens[i].c_str()));
            else {
                //由于表达式有效，故此处不再作判断是否有效等
                int nums1 = record.top();
                record.pop();
                int nums2 = record.top();

                record.pop();


                switch (tokens[i][0]) { //此处是由于题目保证了只有下面四种符号
                case '/': //此处注意nums2是靠前的，运算也是放前面
                    record.push(nums2 / nums1); break;
                case '*':
                    record.push(nums2 * nums1); break;
                case '+':
                    record.push(nums2 + nums1); break;
                case '-':
                    record.push(nums2 - nums1); break;
                }



            }

        }

        return record.top();
    }
};



int main() {

    string strArr[] = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    vector<string> vec(strArr, strArr + sizeof(strArr) / sizeof(string));
    cout<<Solution().evalRPN(vec);

    system("pause");
    return 0;
}