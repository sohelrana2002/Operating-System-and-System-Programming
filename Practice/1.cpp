//write a program to copy a file named "file.txt" from dir1 to dir2

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string sourcePath = "dir1/file.txt";  
    string destinationPath = "dir2/file.txt";

    ifstream sourceFile(sourcePath, ios::binary);

    if (!sourceFile) {
        cerr << "Error opening source file: " << sourcePath << endl;
        return 1;
    }

    ofstream destinationFile(destinationPath, ios::binary);

    if (!destinationFile) {
        cerr << "Error opening destination file: " << destinationPath << endl;
        return 1; 
    }


    destinationFile << sourceFile.rdbuf(); 

    sourceFile.close();
    destinationFile.close();

    cout << "File copied successfully from " << sourcePath << " to " << destinationPath << endl;
    return 0; 
}
