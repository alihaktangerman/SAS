#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct aav {
    int a1, a2;
    long double v;
};
//not bu işe bir de sürekli kesirlerle bak.
int main(){
    long double s3 = sqrt(3), s5 = sqrt(5);
    vector<long double> vec1(1001), vec2(1001);
    vec1[1] = s3;
    vec2[1] = s5;
    for (int i=1; i<1000; i++) {
        vec1[i] = vec1[i-1]+s3;
        vec2[i] = vec2[i-1]+s5;
    }
    vector<aav> closest;
    closest.push_back(aav{1,1,s5-s3});
    int a1 = 1, a2 = 1;
    while (a1 < 100001 && a2 < 100001) {
        if (abs(vec1[a1]-vec2[a2])<closest.back().v) {
            closest.push_back(aav{a1,a2,abs(vec1[a1]-vec2[a2])});
        }
        if (vec1[a1] < vec2[a2]) a1++;
        else a2++;
    }
    for (auto a: closest) {
        cout << a.a1 << "sqrt(3) " <<  -a.a2 << "sqrt(5) = " << a.v << "\n";
    }
}