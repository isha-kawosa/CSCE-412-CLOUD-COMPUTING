#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

/**
 * @brief Class representing a queue of requests.
 */
class RequestQueue {
public:
    /**
     * @brief Add a request to the queue.
     * 
     * @param req The request to add
     */
    void addRequest(const Request& req);

    /**
     * @brief Get the next request from the queue.
     * 
     * @return The next request in the queue
     */
    Request getRequest();

    /**
     * @brief Check if the queue is empty.
     * 
     * @return True if the queue is empty, false otherwise
     */
    bool isEmpty();

    /**
     * @brief Get the current size of the queue.
     * 
     * @return The size of the queue
     */
    int size() const;

private:
    std::queue<Request> requests; ///< The underlying queue of requests
};

#endif // REQUESTQUEUE_H


