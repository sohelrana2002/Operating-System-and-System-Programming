#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string sourcePath = "./orginal.txt";
    string targetPath = "./copy.txt";

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
