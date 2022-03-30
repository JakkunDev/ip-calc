#pragma region LIBS
#include <iostream>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator
#include <bits/stdc++.h>
#include "headers/ipcalc.h"
#pragma endregion
using namespace std;
#pragma region VARIABLES
string ip; // ip address inputted by user
string mask; // mask address inputted by user
int amount;
int bit;
std::vector <std::string> ipSepVec[4]; // string ip vector
std::vector <std::string> maskSepVec[4]; // string mask vector

string ipSep[4]; // separated ip addres (dec)
string ipSepBin[4]; // separated ip addres (bin)
string maskSep[4]; // separeted mask address (dec)
string maskSepBin[4]; // separeted mask address (bin)
string subnetSepBin[4]; // separeted subnet address (bin)

#pragma endregion

void WriteIt() {
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
}

int main(int argc, char* argv[]) {

    // COMMAND-INPUT
    if (argc - 1 == 1) {
        if(string(argv[1]) == "--help" || string(argv[1]) == "-h") {
            #pragma endregion
            cout << "SYNTAX: ipcalc [OPTION]\n";
            cout << "SYNTAX: ipcalc [IP] [MASK]\n";
            cout << "SYNTAX: ipcalc [IP] [MASK] [AMOUNT]\n";
            cout << "Commands: \n";
            cout << "   -h   --help                     Displays this message on screen and ends.\n";
            cout << "   -i   --ip[=IP]                  You can input ip address after it.\n";
            cout << "   -m   --mask[=MASK]              You can input mask address after it.\n";
            cout << "   -b   --calculate-bin[=BIN]      Calculates binary mask/ip address from\n\
                                     passed decimal mask/ip address.\n";
            cout << "   -d   --calculate-dec[=DEC]      Calculates decimal mask/ip address from\n\
                                     passed binary mask/ip address.\n";
            cout << "   -n   --get-new-mask[=AMOUNT]    Outputs how many 1's you have to swap\n\
                                     with 0's in binary mask address and amount\n\
                                     of subnets.\n";
            cout << "   -a   --all[=IP][=MASK]          Displays info about all available subnets.\n";
            cout << "   -v   --version                  Outputs software version in terminal.\n\n";
        } else if(string(argv[1]) == "-v" || string(argv[1]) == "--version") {
                cout << "Version:   0.3.0\n";
                cout << "State:     Alpha\n";
        } else {
            cerr << "\033[31mERROR:\033[0m Such argument doesn't exist or command is incomplete!\n";
            cerr << "Try typing 'ipcalc \033[32m--help\033[0m' for more informations\n";
            exit(1);
        }
    } else if (argc - 1 >= 2 || argc - 1 <= 4) {
        if (argc - 1 == 2) {
            ip.assign(argv[1]);
            mask.assign(argv[2]); // when using -b or -d this is used for ip, mask
            
            if (string(argv[1]) == "-n" || string(argv[1]) == "--get-new-mask") {
                GetAmount(stoi(argv[2]));
                exit(0);
            }

            #pragma region wr-input-to-str
            WriteIt();
            #pragma endregion
            
            // Separated and converted mask/ip addresses
            string addressSepDecToBin[4] = { DecToBin(stoi(maskSep[0])), DecToBin(stoi(maskSep[1])),
                                                DecToBin(stoi(maskSep[2])), DecToBin(stoi(maskSep[3])) };
            int addressSepBinToDec[4] = { BinToDec(maskSep[0]), BinToDec(maskSep[1]),
                                                BinToDec(maskSep[2]), BinToDec(maskSep[3]) };   

            #pragma region commands

            if (string(argv[1]) == "-b" || string(argv[1]) == "--calculate-bin") {
                cout << addressSepDecToBin[0] << "." << addressSepDecToBin[1] << "." << addressSepDecToBin[2] << "." << addressSepDecToBin[3] << "\n";
                exit(0);
            } else if (string(argv[1]) == "-d" || string(argv[1]) == "--calculate-dec") {
                cout << addressSepBinToDec[0] << "." << addressSepBinToDec[1] << "." << addressSepBinToDec[2] << "." << addressSepBinToDec[3] << "\n";
                exit(0);
            }
            #pragma endregion
        }else if (argc - 1 == 3) {
            if(string(argv[1]) == "-a" || string(argv[1]) == "--all") {
                ip.assign(argv[2]);
                mask.assign(argv[3]);

                WriteIt();
                int i = 0;
                int temp;
                
                string maskSepBin[4] = { DecToBin(stoi(maskSep[0])), DecToBin(stoi(maskSep[1])),
                                        DecToBin(stoi(maskSep[2])), DecToBin(stoi(maskSep[3]))  };
                
                #pragma region calculations
                for (; i <= 3; i++)
                {
                    temp = GetBit(maskSepBin[i]);

                    if (temp != 0 && temp != 1) {
                        bit = temp;
                        break;
                    }
                }
                amount = GetAmountAll(maskSepBin[i]); // get's amount of subnets based on mask
                #pragma endregion
                // TODO: whole subnet generation
                cout << "   subnet number       Subnet Address       Begin Address        Last Address         Broadcast Address\n";
                for (int j = 0; j <= amount - 1; j++)
                {
                    cout << "         " << j + 1 << "             ";
                    int newAddress = stoi(GetAddress(j, bit)) + 1;
                    int newBroadcastAddress = stoi(GetAddress(j + 1, bit)) - 1;
                    #pragma region subnet-address
                    for (int k = 0; k <= 3; k++)
                    {
                        
                        if(k != i && k != 3 && i > k) {
                            cout << ipSep[k] << ".";
                        } else if (k != 3 && k == i) {
                            cout << newAddress - 1 << ".";
                        } else if (k == 3 && k == i) {
                            cout << newAddress - 1;
                        } else if (k == 3 && k != i && i > k) {
                            cout << ipSep[k];
                        } else if (i < k) {
                            if (k == 3) {
                                cout << 0;
                            } else {
                                cout << 0 << ".";
                            }
                        }
                        
                        // TODO: Assigning this addresses
                        
                    }
                    MakeEmtpty(j);
                    #pragma endregion

                    #pragma region begin-address
                    for (int k = 0; k <= 3; k++) {
                        if(k != 3 && k != i && i > k) {
                            cout << ipSep[k] << ".";
                        } else if (k != 3 && k == i) {
                            cout << newAddress - 1 << ".";
                        } else if (k == 3 && k == i) {
                            cout << newAddress - 1;
                        } else if (k == 3 && k != i && i > k) {
                            cout << ipSep[k];
                        } else if (i < k) {
                            if (k == 3) {
                                cout << 1;
                            } else {
                                cout << 0 << ".";
                            }
                        }
                    }
                    MakeEmtpty(j);
                    #pragma endregion
                    
                    #pragma region Last-Address
                    for (int k = 0; k <= 3; k++) {
                        if(k != 3 && k != i && i > k) {
                            cout << ipSep[k] << ".";
                        } else if (k != 3 && k == i) {
                            cout << newBroadcastAddress << ".";
                        } else if (k == 3 && k == i) {
                            cout << newBroadcastAddress - 1;
                        } else if (k == 3 && k != i && i > k) {
                            cout << ipSep[k];
                        } else if (i < k) {
                            if (k == 3) {
                                cout << 255 - 1;
                            } else {
                                cout << 255 << ".";
                            }
                        }
                    }
                    MakeEmtpty(j);
                    #pragma endregion

                    #pragma region Broadcast-Address
                    for (int k = 0; k <= 3; k++) {
                        if(k != 3 && k != i && i > k) {
                            cout << ipSep[k] << ".";
                        } else if (k != 3 && k == i) {
                            cout << newBroadcastAddress << ".";
                        } else if (k == 3 && k == i) {
                            cout << newBroadcastAddress;
                        } else if (k == 3 && k != i && i > k) {
                            cout << ipSep[k];
                        } else if (i < k) {
                            if (k == 3) {
                                cout << 255;
                            } else {
                                cout << 0 << ".";
                            }
                        }
                    }
                    MakeEmtpty(j);
                    #pragma endregion

                    cout << "\n";
                }
                exit(0);
            } else {
                exit(1);
            }
        } else if (argc - 1 == 4) {
            if(string(argv[1]) == "--ip" || string(argv[1]) == "-i") {
                ip.assign(argv[2]);
            } else if(string(argv[3]) == "--ip" || string(argv[3]) == "-i") {
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
        
            WriteIt();

            for (int i = 0; i < 4; i++)
            {
                if (maskSep[i].empty() || maskSep[i].empty()) {
                    cerr << "\033[31mERROR:\033[0m Invalid IP/Mask address\n";
                    exit(1);
                }
            }
            #pragma endregion
        }
        if (argc - 1 <= 0 || argc - 1 > 5) {
            cerr << "\033[31mERROR:\033[0m Null or too many arguments has been given!\n";
            exit(1);
        }

        #pragma region IP-MASK-DEC-TO-BIN
            for (int i = 0; i < 4; i++) // Separating and converting ip and mask addresses to binary
            {
                ipSepBin[i] = DecToBin(stoi(ipSep[i]));
                maskSepBin[i] = DecToBin(stoi(maskSep[i]));
            }
            
            // output: IP_DEC IP_BIN MASK_DEC MASK_BIN
            DisplayBasicNetworkData(ip, mask, ipSepBin, maskSepBin);

        #pragma endregion

        #pragma region SUBNET
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if(ipSepBin[i][j] == maskSepBin[i][j] && ipSepBin[i][j] == '1' && maskSepBin[i][j] == '1') {
                            subnetSepBin[i] += "1";
                        } else {
                            subnetSepBin[i] += "0";
                        }
                    }
                }

                // calculating decimal subnet address
                int netAddSep[4] = { BinToDec(subnetSepBin[0]), BinToDec(subnetSepBin[1]),
                                        BinToDec(subnetSepBin[2]), BinToDec(subnetSepBin[3]) };
                DsiplaySubentData(subnetSepBin, netAddSep);
                #pragma endregion
    }

    return 0;
}