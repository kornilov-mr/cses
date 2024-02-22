#include<iostream>
#include<set>

using namespace std;

int main() {
    set<int> numbers;
    int n;
    cin >> n;
    int n1 = n;
    int step = 2;
    int curr = -1;
    int lastLoop=0;
    int firstElement=0;
    while (n1 != 0) {
        if(n1==1){
            cout<<firstElement+1;
            break;
        }
        for (int i = 0; i < (n1 +lastLoop)/ 2; i++) {
            curr += step;
            curr %= n;
            cout << curr + 1 << " ";
        }
        if(lastLoop==1){
            firstElement+=step/2;
        }
        step *= 2;
        if ((n1+lastLoop) % 2 == 0) {
            curr = -1 * step / 2 +firstElement;
            n1/=2;
            lastLoop=0;
        }else{
            curr = -1 * step + firstElement;
            n1=n1-(n1+lastLoop)/2;
            lastLoop=1;
        }
    }
}