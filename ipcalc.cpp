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
bool canCalculate = true;

string ipSep[4]; // separated ip addres (dec)
string maskSep[4]; // separeted mask address (dec)
string netAddSepBin[4]; // separeted subnet address (bin)
string ipSepBin[4];
string maskSepBin[4];
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
        if(string(argv[1]) == "--help" || string(argv[1]) == "-h") {
            #pragma endregion
            cout << "SYNTAX: ipCalc [OPTION]\n";
            cout << "SYNTAX: ipCalc [IP] [MASK]\n";
            cout << "Commands: \n";
            cout << "   -h   --help                     Displays this message on screen and ends\n";
            cout << "   -i   --ip[=IP]                  You can input ip address after it\n";
            cout << "   -m   --mask[=MASK]              You can input mask address after it\n";
            cout << "   -b   --calculate-bin[=BIN]      Calculates decimal mask/ip address from passed binary mask/ip address\n";
            cout << "   -d   --calculate-dec[=DEC]      Calculates binary mask/ip address from passed decimal mask/ip address\n\n";
            
            cout << "Version:   0.2.0\n";
            cout << "State:     Alpha\n";
        } else {
            cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
            cerr << "Try typing 'ipcalc \033[32m--help\033[0m' for more informations\n";
        }
    } else if (argc - 1 == 2 || argc - 1 == 4) {
        if (argc - 1 == 2) {
            ip.assign(argv[1]);
            mask.assign(argv[2]); // when using -b, -g or -d this is used for ip, mask and amount of subnets
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

            for (int i = 0; i < 4; i++)
            {
                if(string(argv[1]) == "-g" || string(argv[1]) == "--get-subnets") {
                    canCalculate = false;
                    break;
                }
                if (maskSep[i].empty() || maskSep[i].empty()) {
                    cerr << "\033[31mERROR:\033[0m Invalid IP/Mask address\n";
                    exit(1);
                }
            }
            #pragma endregion
            
            string addressSepDecToBin[4] = { DecToBin(stoi(maskSep[0])), DecToBin(stoi(maskSep[1])),
                                                DecToBin(stoi(maskSep[2])), DecToBin(stoi(maskSep[3])) };
            int addressSepBinToDec[4] = { BinToDec(maskSep[0]), BinToDec(maskSep[1]),
                                                BinToDec(maskSep[2]), BinToDec(maskSep[3]) };   

            #pragma region address-calculations
            if (string(argv[1]) == "-b" || string(argv[1]) == "--calculate-bin") {
                cout << addressSepDecToBin[0] << "." << addressSepDecToBin[1] << "." << addressSepDecToBin[2] << "." << addressSepDecToBin[3] << "\n";
                exit(0);
            } else if (string(argv[1]) == "-d" || string(argv[1]) == "--calculate-dec") {
                cout << addressSepDecToBin[0] << "." << addressSepBinToDec[1] << "." << addressSepBinToDec[2] << "." << addressSepBinToDec[3] << "\n";
                exit(0);
            }
            #pragma endregion

            canCalculate = true;
        } else if (canCalculate) {
            if(string(argv[1]) == "-ip" || string(argv[1]) == "-i") {
                ip.assign(argv[2]);
            } else if(string(argv[3]) == "-ip" || string(argv[3]) == "-i") {
                ip.assign(argv[4]);
            } else {
                cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
                cerr << "'Try typing 'ipcalc \033[32m--help\033[0m' for more informations\n";
                exit(1);
            }

            if (string(argv[3]) == "--mask" || string(argv[3]) == "-m") {
                mask.assign(argv[4]);
            } else if (string(argv[1]) == "--mask" || string(argv[1]) == "-m") {
                mask.assign(argv[2]);
            } else {
                cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
                cerr << "Try typing 'ipcalc \033[32m--help\033[0m' for more informations\n";
                exit(1);
            }
        }

        #pragma region ip-mask-bin
        for (int i = 0; i < 4; i++)
        {
            ipSepBin[i] = DecToBin(stoi(ipSep[i]));
            maskSepBin[i] = DecToBin(stoi(maskSep[i]));
        }

        cout << "   ================================================================\n";
        cout << " > | IP address: " << ip << "\n";
        cout << "   ================================================================\n";
        cout << " > | Mask address: " << mask << "\n";
        cout << "   ================================================================\n";
        cout << " > | IP address in Binary: " << ipSepBin[0] << "." << ipSepBin[1] << "." << ipSepBin[2] << "." << ipSepBin[3] << "\n";
        cout << "   ================================================================\n";
        cout << " > | Mask address in Binary: " << maskSepBin[0] << "." << maskSepBin[1] << "." << maskSepBin[2] << "." << maskSepBin[3] << "\n";
        cout << "   ================================================================\n";
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
    
    cout << " > | Network address in Binary: " << netAddSepBin[0] << "." << netAddSepBin[1] << "." << netAddSepBin[2] << "." << netAddSepBin[3] << "\n";
    cout << "   ================================================================\n";

    string netAddSep[4] = { to_string(BinToDec(netAddSepBin[0])), to_string(BinToDec(netAddSepBin[1])),
                            to_string(BinToDec(netAddSepBin[2])), to_string(BinToDec(netAddSepBin[3])) };
    
    cout << " > | Subnet address: " << netAddSep[0] << "." << netAddSep[1] << "." << netAddSep[2] << "." << netAddSep[3] << "\n";
    cout << "   ================================================================\n";
    #pragma endregion
    } else {
        cerr << "\033[31mERROR:\033[0m Null or too many arguments has been given!\n";
    }
}