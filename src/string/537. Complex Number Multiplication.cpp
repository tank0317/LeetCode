/**
 * 方法一
 * 方法二，使用sscanf(), 更加简便
 **/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int i = 0;
        while(i<a.size() && a[i] != '+') i++;
        int x1 = stoi(a.substr(0, i));
        int y1 = stoi(a.substr(i+1, a.size()-1));
        i = 0;
        while(i<b.size() && b[i] != '+') i++;
        int x2 = stoi(b.substr(0, i));
        int y2 = stoi(b.substr(i+1, b.size()-1));
        int x3 = x1*x2 - y1*y2;
        int y3 = x1*y2 + x2*y1;
        return "" + to_string(x3) + '+' + to_string(y3) + 'i';
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x1, y1;
        sscanf(a.c_str(), "%d+%di", &x1, &y1);
        int x2, y2;
        sscanf(b.c_str(), "%d+%di", &x2, &y2);
        return "" + to_string(x1*x2-y1*y2) + '+' + to_string(x1*y2+x2*y1) + 'i';
    }
};