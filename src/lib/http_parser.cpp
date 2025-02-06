#include "http_parser.hpp"

HttpParser::HttpParser(){}

HttpParser::~HttpParser(){}

String HttpParser::ReadAll(EthernetClient client){
	String request;
	int blankCount = 0;
	char lastChar = 0;
	while(client.connected()){
		if(client.available()){
			char c = client.read();
			request +=c;
			if(c == '\n' && lastChar == '\r'){
				blankCount++;
			}else if(c != '\n'){
				blankCount = 0;
			}
			if(blankCount >= 2){
				break;
			}
		}else{
			break;
		}
	}
	return request;
}

HttpRequest HttpParser::ParseRequest(String request){
	HttpRequest httpRequest;
	int methodEnd = request.indexOf(' ');
	if(methodEnd == -1){
		httpRequest.method = "";
		httpRequest.path = "";
		httpRequest.body = "";
		return httpRequest;
	}
	httpRequest.method = request.substring(0, methodEnd);
	int pathEnd = request.indexOf(' ', methodEnd + 1);
	if(pathEnd == -1){
		httpRequest.path = "";
		httpRequest.body = "";
		return httpRequest;
	}
	httpRequest.path = request.substring(methodEnd + 1, pathEnd);
	int bodyStart = request.indexOf("\r\n\r\n");
	if(bodyStart == -1){
		httpRequest.body = "";
		return httpRequest;
	}
	httpRequest.body = request.substring(bodyStart + 4);
	return httpRequest;
}
