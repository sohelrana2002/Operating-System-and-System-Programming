#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string sourcePath = "./text2.txt";
    string targetPath = "./hi.txt";

    if (rename(sourcePath.c_str(), targetPath.c_str()) == 0)
    {
        cout << "File moved successfully." << endl;
    }
    else
    {
        perror("Error moving the file");
    }

    return 0;
}
