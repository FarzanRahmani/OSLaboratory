#!/bin/bash

echo -n "Enter the MAC address of the interface: "
read mac_address

# Get interface name based on MAC address
interface_name=$(ip -o link | awk -v mac="$mac_address" '$17==mac {print $2}' | awk -F':' '{print $2}')

# Get IP address based on interface name
ip_address=$(ip -o -4 addr show dev $interface_name | awk '{split($4, a, "/"); print a[1]}')

# Print the IP address and interface name
echo "IP Address: $ip_address"
echo "Interface Name: $interface_name"

