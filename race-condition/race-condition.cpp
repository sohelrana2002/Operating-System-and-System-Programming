#include <iostream>
using namespace std;

int process1(int count)
{
    int x = count;
    x++;
    count = x;
    return count;
};

int process2(int count)
{
    int y = count;
    y--;
    count = y;
    return count;
};

int main()
{
    int count = 10;

    int p1 = process1(count);
    int p2 = process2(count);

    cout << "process 1 count value: " << p1 << endl;
    cout << "process 2 count value: " << p2 << endl;
    cout << "Final count value: " << count;
}