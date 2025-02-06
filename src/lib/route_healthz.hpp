#ifndef ROUTE_HEALTHZ_HPP
#define ROUTE_HEALTHZ_HPP
#include <WString.h>
#include <Ethernet.h>
#include "http_parser.hpp"
#include "http_header.hpp"

class RouteHealthz{
	public:
		void static Route(HttpRequest request, EthernetClient client);
};

#endif // ROUTE_HEALTHZ_HPP