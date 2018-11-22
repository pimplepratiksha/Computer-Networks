#include<stdio.h>
#include<stdlib.h>
int main()
{
  system("sudo ifconfig wlo1 down");
  system("sudo iwconfig wlo1 mode ad-hoc");
  system("sudo iwconfig wlo1 channel 1 essid MYNETWORK mode ad-hoc");
  system("sudo ifconfig wlo1 up");
  system("sudo ifconfig wlo1 192.168.1.213 netmask 255.255.255.0");
}
