#include "WebServer.h"

/**
 * @brief Constructor for WebServer.
 * @param server_id Unique identifier for the web server.
 */
WebServer::WebServer(int server_id) : id(server_id), current_time(0) {}

/**
 * @brief Process a web request.
 * @param req The web request to process.
 * @return True if the request is processed, otherwise false.
 */
bool WebServer::processRequest(Request& req) {
    if (current_time >= req.time) {
        current_time = 0;
        return true;
    } else {
        current_time++;
        return false;
    }
}

/**
 * @brief Get the current processing time of the server.
 * @return The current processing time.
 */
int WebServer::getCurrentTime() {
    return current_time;
}

/**
 * @brief Get the ID of the server.
 * @return The server ID.
 */
int WebServer::getId() {
    return id;
}
