#include <iostream>
using namespace std;

// Calculates binary value of decimal input
string DecToBin(int dec) {
    string stringBin;
    for (int i = 7; i >= 0; i--) {
        int k = dec >> i;
        if (k & 1)
            stringBin += "1";
        else
            stringBin += "0";
    }
    
    return stringBin;
}

// Calculates decimal value of binary input
int BinToDec(string str) {
   string n = str;
   int val = 0;
   int temp = 1;
   int len = n.length();
   for (int i = len - 1; i >= 0; i--) {
      if (n[i] == '1')
      val += temp;
      temp = temp * 2;
   }
   return val;
}

// Displays inputted, by user, network data
void DisplayBasicNetworkData(string ip, string mask, string ipBin[4], string maskBin[4]) {
    cout << "   ================================================================\n";
    cout << " > | IP address: " << ip << "\n";
    cout << "   ================================================================\n";
    cout << " > | Mask address: " << mask << "\n";
    cout << "   ================================================================\n";
    cout << " > | IP address in Binary: " << ipBin[0] << "." << ipBin[1] << "." << ipBin[2] << "." << ipBin[3] << "\n";
    cout << "   ================================================================\n";
    cout << " > | Mask address in Binary: " << maskBin[0] << "." << maskBin[1] << "." << maskBin[2] << "." << maskBin[3] << "\n";
    cout << "   ================================================================\n";
}

// Displays calculated (in main function) subnet data
void DsiplaySubentData(string subnetBin[4], int subnetDec[4]) {
    // output: SUB_BIN
    cout << " > | Subnet address in Binary: " << subnetBin[0] << "." << subnetBin[1] << "." << subnetBin[2] << "." << subnetBin[3] << "\n";
    cout << "   ================================================================\n";
    
    // output: SUB_DEC
    cout << " > | Subnet address: " << subnetDec[0] << "." << subnetDec[1] << "." << subnetDec[2] << "." << subnetDec[3] << "\n";
    cout << "   ================================================================\n";
}
// Calculates amount of '0' that you have to swap in mask address and amount of subnets.
void GetAmount(int amount) {
    int i = 0;
    int a = 1;

    for ( ; amount >= a; i++ )
    {
        a = 2 * a;
    }
    
    cout << "You will need to swap: " << i << " '0' in mask\namount of subnets will be: " << a << "\n";
}