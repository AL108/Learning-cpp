# reading files
Use ifstream object

````
include <fstream>
using namespace std;
ifstream inFile;
string str;
int main() {
    inFile.open("test.txt");
    if (inFile.fail()) cout << "file not found << endl;
    else {
        while (!inFile.eof()) {
            getline(inFile, str);
            cout << str << endl;
        }
        inFile.close();
    }
    return 0;
}
````

# writing to files
use outfile object
````
#include <fstream>
using namespace std;
ofstream outFile;

int main() {
    outFile.open("test.txt");
    if (outFile.fail()) 
        cout << "failed to open file" << "\n";
    else {
        outFile << "some text to write to file" << endl;
        outFile.close();
        cout << "file write successful!" << endl;
    }
    return 0;
}
````