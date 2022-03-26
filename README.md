# Subnet IP Address Calculator
### subnet ip calculator in c++

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
**after done with that, you can freely use ipcalc command on linux**

**2. Syntax of this is:**

```
$ ipcalc [OPTION]
```

**3. or:**

```
$ ipcalc [IP] [MASK]
```

**4. for the moment being there's only three options:**

```
-h or --help      Displays info about avaible options.

-i or --ip        You can input ip address after it.

-m or --mask      You can input mask address after it.
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
```

**!!! YOU CAN'T SWAP THE MASK AND IP ADDRESS IN THE LAST EXAMPLE !!!**
