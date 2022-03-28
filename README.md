# Subnet IP Address Calculator
### subnet ip calculator in c++

Version:   0.2.2

With this calculator you can calculate subnet IP address by getting one of existing subnet IP host addresses.

**1. installation**
* to intstall it you will need to clone git:
```
$ git clone https://github.com/jakkundev/ipcalc.git
```
* after cloning it you will need to move to it's directory:
```
$ cd ipcalc
```
* after moving there you can finally use makefile **(remember to use sudo while performing it)**:
```
$ sudo make all
```
**after done with that, ipcalc has been successfuly added to your linux machine commands**

**2. Syntax of this is:**

```
$ ipcalc [OPTION]
```

**3. or:**

```
$ ipcalc [IP] [MASK]
```

**4. for the moment being there's only six options:**

```
-h or --help                     Displays info about avaible options
                                  and version of software.
-i or --ip[=IP]                  You can input ip address after it
-m or --mask[=MASK]              You can input mask address after it
-b or --calculate-bin[=BIN]      Calculates binary mask/ip address 
                                  from passed decimal mask/ip address
-d or --calculate-dec[=DEC]      Calculates decimal mask/ip address
                                  from passed binary mask/ip address
-n   --get-new-mask[=AMOUNT]     Outputs how many 1's you have to swap
                                  with 0's in binary mask address and
                                  amount of subnets.
-v or --version[=DEC]            Outputs software version in terminal.
```

**5. example of usage (with output):**
```
 $ ipcalc -i 192.168.1.0 -m 255.255.255.0
   ================================================================
 > | IP address: 192.168.1.0
   ================================================================
 > | Mask address: 255.255.255.0
   ================================================================
 > | IP address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Mask address in Binary: 11111111.11111111.11111111.00000000
   ================================================================
 > | Network address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Subnet address: 192.168.1.0
   ================================================================

 $ ipcalc -m 255.255.255.0 -i 192.168.1.0
   ================================================================
 > | IP address: 192.168.1.0
   ================================================================
 > | Mask address: 255.255.255.0
   ================================================================
 > | IP address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Mask address in Binary: 11111111.11111111.11111111.00000000
   ================================================================
 > | Network address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Subnet address: 192.168.1.0
   ================================================================

$ ipcalc 192.168.1.0 255.255.255.0
   ================================================================
 > | IP address: 192.168.1.0
   ================================================================
 > | Mask address: 255.255.255.0
   ================================================================
 > | IP address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Mask address in Binary: 11111111.11111111.11111111.00000000
   ================================================================
 > | Network address in Binary: 11000000.10101000.00000001.00000000
   ================================================================
 > | Subnet address: 192.168.1.0
   ================================================================

$ ipcalc -b 192.168.1.0
11000000.10101000.00000001.00000000

$ ipcalc -d 11000000.10101000.00000001.00000000
192.168.1.0

$ ipcalc -n 10
You will need to swap: 4 '0' in mask
amount of subnets will be: 16
```
