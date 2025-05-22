// write a program to copy a file named "file.txt" from dir1 to dir2

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string sourcePath = "./dir1/text.txt";
    string targetPath = "./dir2/text2.txt";

    ifstream sourceFile(sourcePath, ios::binary);

    if (!sourceFile)
    {
        cerr << "Error: Could not open the source file!" << endl;
        return 1;
    }

    ofstream targetFile(targetPath, ios::binary | ios::app);

    if (!targetFile)
    {
        cerr << "Error: Could not open the target file!" << endl;
        return 1;
    }

    targetFile << sourceFile.rdbuf();

    cout << "File content appended successfully." << endl;

    sourceFile.close();
    targetFile.close();

    return 0;
}
