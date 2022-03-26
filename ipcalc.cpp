#pragma region code-libs
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include <bits/stdc++.h>
#pragma endregion

using namespace std;

#pragma region variables
string ip;
string mask;
std::vector <std::string> ipSepVec[4]; // string ip vector
std::vector <std::string> maskSepVec[4]; // string mask vector

string ipSep[4]; // separated ip addres (dec)
string maskSep[4]; // separeted mask address (dec)
string netAddSepBin[4]; // separeted subnet address (bin)
#pragma endregion

#pragma region supp-functions
// Calculates binary value of decimal input
string DecToBin(int dec) {
    int a[10];
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
#pragma endregion

int main(int argc, char* argv[]) {

    // command input
    if (argc - 1 == 1) {
        if(string(argv[1]) == "--help" || string(argv[3]) == "-h") {
            #pragma region info
            cout << "====================================\n";
            cout << "|   subnet IP Address Calculator   |\n";
            cout << "====================================\n";
            cout << "| With this calculator you can     |\n";
            cout << "| calculate subnet IP address by   |\n";
            cout << "| getting one of existing subnet   |\n";
            cout << "| IP host addresses.               |\n";
            cout << "====================================\n\n";
            #pragma endregion
            cout << "SYNTAX: ipCalc [OPTION]\n";
            cout << "SYNTAX: ipCalc [IP] [MASK]\n";
            cout << "Commands: \n";
            cout << "-h   --help            Displays this message on screen and ends\n";
            cout << "-i   --ip[=IP]         You can input ip address after it\n";
            cout << "-m   --mask[=MASK]     You can input mask address after it\n";
        } else {
            cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
            cerr << "Try typing ipcalc \033[32m--help\033[0m for more informations\n";
        }
    } else if (argc - 1 == 2 || argc - 1 == 4) {
        if (argc - 1 == 2) {
            ip.assign(argv[1]);
            mask.assign(argv[2]);
        } else {
            if(string(argv[1]) == "-ip" || string(argv[1]) == "-i") {
                ip.assign(argv[2]);
            } else if(string(argv[3]) == "-ip" || string(argv[3]) == "-i") {
                ip.assign(argv[4]);
            } else {
                cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
                cerr << "Try typing ipcalc \033[32m--help\033[0m for more informations\n";
                exit(1);
            }

            if (string(argv[3]) == "--mask" || string(argv[3]) == "-m") {
                mask.assign(argv[4]);
            } else if (string(argv[1]) == "--mask" || string(argv[1]) == "-m") {
                mask.assign(argv[2]);
            } else {
                cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
                cerr << "Try typing ipcalc \033[32m--help\033[0m for more informations\n";
                exit(1);
            }
        }
        
        #pragma region wr-input-to-str
        istringstream issIP(ip);
        string partIP;
        while (std::getline(issIP, partIP, '.')) {
            if (!partIP.empty())
                ipSepVec->push_back(partIP);
        }

        stringstream issMask(mask);
        string partMask;
        while (std::getline(issMask, partMask, '.')) {
            if (!partMask.empty())
                maskSepVec->push_back(partMask);
        }

        std::copy(maskSepVec->begin(), maskSepVec->end(), maskSep);
        std::copy(ipSepVec->begin(), ipSepVec->end(), ipSep);
        #pragma endregion

        #pragma region ip-mask-bin
        string ipSepBin[4] = { DecToBin(stoi(ipSep[0])), DecToBin(stoi(ipSep[1])), 
                                DecToBin(stoi(ipSep[2])), DecToBin(stoi(ipSep[3])) }; 
        string maskSepBin[4] = { DecToBin(stoi(maskSep[0])), DecToBin(stoi(maskSep[1])), 
                                    DecToBin(stoi(maskSep[2])), DecToBin(stoi(maskSep[3])) }; 

        cout << "================================================================\n";
        cout << "| IP address in Binary: " << ipSepBin[0] << "." << ipSepBin[1] << "." << ipSepBin[2] << "." << ipSepBin[3] << "\n";
        cout << "================================================================\n";
        cout << "| Mask address in Binary: " << maskSepBin[0] << "." << maskSepBin[1] << "." << maskSepBin[2] << "." << maskSepBin[3] << "\n";
        cout << "================================================================\n";
        #pragma endregion

        #pragma region subnet
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(ipSepBin[i][j] == maskSepBin[i][j] && ipSepBin[i][j] == '1' && maskSepBin[i][j] == '1') {
                netAddSepBin[i] += "1";
            } else {
                netAddSepBin[i] += "0";
            }
        }
    }
    
    cout << "| Network address in Binary: " << netAddSepBin[0] << "." << netAddSepBin[1] << "." << netAddSepBin[2] << "." << netAddSepBin[3] << "\n";
    cout << "================================================================\n";

    string netAddSep[4] = { to_string(BinToDec(netAddSepBin[0])), to_string(BinToDec(netAddSepBin[1])),
                            to_string(BinToDec(netAddSepBin[2])), to_string(BinToDec(netAddSepBin[3])) };
    
    cout << "| Subnet address: " << netAddSep[0] << "." << netAddSep[1] << "." << netAddSep[2] << "." << netAddSep[3] << "\n";
    cout << "================================================================\n";
    #pragma endregion
    } else {
        cerr << "\033[31mERROR:\033[0m Null or more arguments has been given!\n";
    }
}