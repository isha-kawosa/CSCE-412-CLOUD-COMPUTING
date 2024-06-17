#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @class WebServer
 * @brief Represents a web server that processes web requests.
 */
class WebServer {
private:
    int id; ///< Unique identifier for the web server
    int current_time; ///< Current processing time of the web server

public:
    /**
     * @brief Constructor for WebServer.
     * @param server_id Unique identifier for the web server.
     */
    WebServer(int server_id);

    /**
     * @brief Process a web request.
     * @param req The web request to process.
     * @return True if the request is processed, otherwise false.
     */
    bool processRequest(Request& req);

    /**
     * @brief Get the current processing time of the server.
     * @return The current processing time.
     */
    int getCurrentTime();

    /**
     * @brief Get the ID of the server.
     * @return The server ID.
     */
    int getId();
};

#endif // WEBSERVER_H
