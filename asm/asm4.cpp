#include <string>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <math.h> 
#include <iomanip>
#include <queue>
#include <map>
#include <typeinfo>
using namespace std;

#define PI 3.1415926535897932384626

int main(void)
{
    ifstream fin("__.in");
    ofstream fout("__.out");
    
    string input = "picoCTF_fdb55";
    
    int ans = 0x260;
    
    for(int i = 1; i < 13 - 1; i++) {
    	ans += (input[i + 1] - input[i]) + (input[i] - input[i - 1]);
    }
    
    cout << ans << endl;
}



