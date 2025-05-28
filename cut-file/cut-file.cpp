#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main()
{
    string sourcePath = "./text2.txt";
    string targetPath = "./hi.txt";

    try
    {
        fs::rename(sourcePath, targetPath);
        cout << "File moved successfully." << endl;
    }
    catch (const fs::filesystem_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
