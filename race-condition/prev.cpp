#include <iostream>
using namespace std;

int process(int a) {
    a++;
    return a;
}

int process2(int b){
    b++;
    return b;
}

int main() {

    int counter = 10;

    int p1 = process(counter);
    int p2 = process2(counter);

    cout << "P1 process counter value: " << p1 <<endl;
    cout << "P2 process counter value: " << p2;

    return 0;
}
