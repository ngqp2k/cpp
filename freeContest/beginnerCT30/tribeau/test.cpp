#include <bits/stdc++.h>
using namespace std;

vector<string> testCase(10);

void init(){
    testCase[1] = "001"; testCase[2] = "002"; testCase[3] = "003";
    testCase[4] = "004"; testCase[5] = "005"; testCase[6] = "006";
    testCase[7] = "007"; testCase[8] = "008"; testCase[9] = "009";
}

int main()
{
    srand(time(NULL));
    init();
    for (int iTest = 1; iTest <= 9; iTest++)
    {
        // system((NAME + ".exe").c_str());
        // system((NAME + "_trau.exe").c_str());
        system(("sol.exe<test/input." + testCase[iTest] + ">ouBL").c_str());
        if (system(("fc ouBL test/output." + testCase[iTest]).c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
