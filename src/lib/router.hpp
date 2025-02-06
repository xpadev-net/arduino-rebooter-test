#ifndef ROUTER_H
#define ROUTER_H
#include <WString.h>
#include <Ethernet.h>
#include "http_parser.hpp"
#include "route_healthz.hpp"
#include "http_header.hpp"
     
class Router{
	public:
		void static Route(HttpRequest request, EthernetClient client);
};


#endif // ROUTER_H
