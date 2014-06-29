// This #include statement was automatically added by the Spark IDE.


#include "DNSClient.h"


IPAddress dnsServerIP(8,8,8,8);
char serverName[] = "api.pushingbox.com";
IPAddress remote_addr;
DNSClient dns;



void setup() {
    Serial.begin(9600);
    while (!Serial.available()) SPARK_WLAN_Loop();
    while (Serial.available()) Serial.read(); //throw it away
    
    Serial.print("Host to lookup: ");
    Serial.println(serverName);
    
    int ret = 0;
    dns.begin(dnsServerIP);
    ret = dns.getHostByName(serverName, remote_addr);
    if (ret == 1) {
        Serial.print("Host to lookup: ");
        Serial.println(serverName);
        Serial.print("IP Address is: ");
        Serial.println(remote_addr);
    } else {
        Serial.println("Error code: ");
        Serial.println(ret);
    }
    

}

void loop() {

}