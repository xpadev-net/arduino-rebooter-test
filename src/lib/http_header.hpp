#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP
#include <WString.h>
#include <Ethernet.h>
#include "http_parser.hpp"
#include "route_healthz.hpp"

class HttpHeader{
	public:
		void static Ok(EthernetClient client);
		void static Ok(EthernetClient client, String body);
		void static NotFound(EthernetClient client, String body);
};

#endif // HTTP_HEADER_HPP