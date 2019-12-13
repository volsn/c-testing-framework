#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <exception>
#include <cassert>
#include <sstream>

using namespace std;

template <class T>
ostream& operator<< (ostream& out, const vector<T>& vi);

template <class T, class U>
void AssertEqual (const T& t, const U& u, const string& Hint = "") {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (Hint != "")
            os << " Hint: " << Hint;
        throw runtime_error(os.str());
    }
}

template <class T>
void custom_sort(vector<T>& arr) {
    
}

template <class T>
string Join(const T& vi, char delimiter) {
    stringstream ss;
    bool first = true;
    for (auto i : vi) {
        ss << i << delimiter << ' '; 
    }
    string str = ss.str();

    // Delete 2 last chars from the string 
    str = str.substr(0, str.size() - 1);
    str = str.substr(0, str.size() - 1);
    return str;
}

template <class T>
ostream& operator<< (ostream& out, const vector<T>& vi) {
    return out << '[' << Join(vi, ',') << ']';
}

template <class TestFunc>
void RunTest (TestFunc func, const string& test_name) {
    try {
        func();
    } catch(runtime_error& e) {
        std::cout << test_name << " fail: " << e.what() << std::endl;
    }
}

void TestAreEqual() {
    {
        vector<int> arr {5, 4, 3};
        vector<int> excepted {3, 4, 5};
        //std::sort(begin(arr), end(arr));
        custom_sort(arr);

        AssertEqual(arr, excepted);
    }
}

int main() {

    RunTest(TestAreEqual, "TestAreEqual");

    return 0;
}

