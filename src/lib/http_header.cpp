#include "http_header.hpp"

void HttpHeader::Ok(EthernetClient client){
	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text/plain");
	client.println("Connection: close");
	client.println();
}

void HttpHeader::Ok(EthernetClient client, String body){
	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text/plain");
	client.println("Connection: close");
	client.println();
	client.println(body);
}

void HttpHeader::NotFound(EthernetClient client, String body){
	client.println("HTTP/1.1 404 Not Found");
	client.println("Content-Type: text/plain");
	client.println("Connection: close");
	client.println();
	client.println(body);
}
