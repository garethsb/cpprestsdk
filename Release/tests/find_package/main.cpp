#include <cpprest/http_client.h>
#include <cpprest/json.h>
#if !defined(CPPREST_EXCLUDE_WEBSOCKETS)
#include <cpprest/ws_client.h>
#endif
#include <iostream>

int main()
{
    // Constructing the clients links the HTTP client and the websocket client, and with them OpenSSL
    web::http::client::http_client client(U("https://localhost/"));
#if !defined(CPPREST_EXCLUDE_WEBSOCKETS)
    web::websockets::client::websocket_client ws;
#endif
    std::cout << utility::conversions::to_utf8string(web::json::value::parse(U("{\"ok\":true}")).serialize())
              << std::endl;
}
