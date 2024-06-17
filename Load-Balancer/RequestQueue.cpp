#include "RequestQueue.h"

/**
 * @brief Add a request to the queue.
 * 
 * @param req The request to add
 */
void RequestQueue::addRequest(const Request& req) {
    requests.push(req);
}

/**
 * @brief Get the next request from the queue.
 * 
 * @return The next request in the queue
 */
Request RequestQueue::getRequest() {
    Request req = requests.front();
    requests.pop();
    return req;
}

/**
 * @brief Check if the queue is empty.
 * 
 * @return True if the queue is empty, false otherwise
 */
bool RequestQueue::isEmpty() {
    return requests.empty();
}

/**
 * @brief Get the current size of the queue.
 * 
 * @return The size of the queue
 */
int RequestQueue::size() const {
    return requests.size();
}
