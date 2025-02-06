#include "router.hpp"
#include "route_healthz.cpp"
#include "http_header.cpp"

void Router::Route(HttpRequest request, EthernetClient client){
	if (request.path == "/healthz" && request.method == "GET" ){
		RouteHealthz::Route(request, client);
		return;
	}
	HttpHeader::NotFound(client, "Not Found");
}
