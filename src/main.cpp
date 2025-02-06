/*
 * entrypoint.cpp
 * setup関数、loop関数の実装
 */
#include "main.hpp"
#include "lib/http_parser.cpp"
#include "lib/router.cpp"
/*!
 * @file Webcontrol.ino
 * @brief This demo implements the change of IO port 2 and 3 output state through the web page
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [yangfeng]<feng.yang@dfrobot.com>
 * @version  V1.0
 * @date  2021-07-14
 * @get from https://www.dfrobot.com
 */

//Define digital output IO port
uint8_t D2 =2;
uint8_t D3 =13;
int value = LOW;
int value1 = LOW;

// Enter a MAC address and IP address for your controller below.
byte mac[] = {0xDE, 0xCD, 0xAE, 0x0F, 0xFE, 0xED };

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

HttpParser httpParser;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect. Needed for Leonardo only
  //Set digital IO port to output mode
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  // start the Ethernet connection:
  if(Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;);
  }
  // print your local IP address:
  Serial.print("My IP address: ");
  for(byte thisByte = 0; thisByte < 4; thisByte++){
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }
  Serial.println();

  // start the Ethernet connection and the server:

  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  String request;
  if(client){
    Serial.println("new client");
    String request = httpParser.ReadAll(client);
    HttpRequest data = httpParser.ParseRequest(request);
    Router::Route(data, client);
    delay(1);
    client.stop();
    Serial.println("client disonnected");
  }
}