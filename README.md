# IP and Subnet Analyzer

This C++ program allows users to input an IP address and subnet mask to analyze and calculate various network properties. The tool is useful for network engineers, IT students, or anyone learning about IP addressing and subnetting.

## Features

- **Binary Representation**: Converts IP addresses and subnets to their binary forms.
- **Network Address**: Calculates and displays the network address.
- **Broadcast Address**: Determines and displays the broadcast address.
- **Class Identification**: Identifies the network class (A, B, or C).
- **Host Calculation**: Computes the number of usable hosts in the subnet.

## How It Works

1. The user inputs an IP address (e.g., `192.168.1.1`).
2. The user inputs a subnet mask (e.g., `255.255.255.0`).
3. The program performs the following:
   - Displays the binary representation of the IP and subnet.
   - Calculates and outputs the network address in both binary and decimal forms.
   - Determines the broadcast address in binary and decimal.
   - Identifies the IP class (A, B, or C).
   - Calculates the total number of hosts in the subnet.

## Example Output

### Input
```
Enter IP: 192.168.1.1
Enter Subnet: 255.255.255.0
```

### Output
```
IP Binary: 11000000.10101000.00000001.00000001
Subnet Binary: 11111111.11111111.11111111.00000000
Hosts: 254
Class: C
Subnet: 255.255.255.0
Network Binary: 11000000.10101000.00000001.00000000
Network: 192.168.1.0
Broadcast Binary: 11000000.10101000.00000001.11111111
Broadcast: 192.168.1.255
```

## Installation and Usage

1. Clone the repository:
   ```bash
   git clone <repository_url>
   ```
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o ip_analyzer main.cpp
   ```
3. Run the program:
   ```bash
   ./ip_analyzer
   ```
