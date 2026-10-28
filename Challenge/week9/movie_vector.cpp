#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Movie{
private:
    string name;
    double score;
public:
    Movie(string n, double s){
        name = n;
        score = s;
    }
    string GetName() { return name;}
    double GetScore() { return score;}
    void Print() {
        cout << name << " : " << score << endl;
    }
};

int main(){
    vector<Movie> list;

    list.push_back(Movie("titinic", 9.9));
    list.push_back(Movie("gone with the wind", 9.6));
    list.push_back(Movie("terminator", 9.7));

    for (auto& e : list){
        e.Print();
    }
    return 0;
}