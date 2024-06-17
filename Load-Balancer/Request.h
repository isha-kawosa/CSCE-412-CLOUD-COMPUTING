#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @brief Structure representing a network request.
 */
struct Request {
    std::string ip_in;  ///< Input IP address
    std::string ip_out; ///< Output IP address
    int time;           ///< Time required to process the request

    /**
     * @brief Construct a new Request object.
     * 
     * @param in Input IP address
     * @param out Output IP address
     * @param t Time required to process the request
     */
    Request(std::string in, std::string out, int t) : ip_in(in), ip_out(out), time(t) {}
};

#endif // REQUEST_H


