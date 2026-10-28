#include <vector>
#include <iostream>
using namespace std;

void print(auto v){
    for ( auto e : v){
        cout << e << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
    }

    cout << "현재의 v = ";
    for(auto &e : v)
        cout << e << " ";
    cout << endl;

    auto it = v.begin() + 5;
    v.insert(it, 100);

    cout << "5번 인덱스에 값을 추가한 후v = ";
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return 0;
}