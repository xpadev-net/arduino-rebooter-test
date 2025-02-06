#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H
#include <WString.h>
#include <Ethernet.h>
     
struct HttpRequest
{
	String method;
	String path;
	String body;
};


class HttpParser{
	public:
		HttpParser();
		~HttpParser();
		String ReadAll(EthernetClient client);
		HttpRequest ParseRequest(String request);
};



#endif // HTTP_PARSER_H
