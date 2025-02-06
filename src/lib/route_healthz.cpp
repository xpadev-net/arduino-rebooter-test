#include "route_healthz.hpp"
#include "http_header.hpp"

void RouteHealthz::Route(HttpRequest request, EthernetClient client){
	HttpHeader::Ok(client, "OK");
}
