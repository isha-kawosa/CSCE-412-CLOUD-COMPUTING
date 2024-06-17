#include "LoadBalancer.h"

/**
 * @brief Construct a new Load Balancer:: Load Balancer object
 * 
 * @param numServers Number of servers to initialize
 */
LoadBalancer::LoadBalancer(int numServers) : totalTaskTime(0), processedRequestsCount(0) {
    for (int i = 0; i < numServers; ++i) {
        servers.emplace_back(WebServer(i));
    }
    // Fill the request queue
    for (int i = 0; i < numServers * 100; ++i) {
        requestQueue.addRequest(Request("192.168.0.1", "192.168.0.2", rand() % 10 + 1));
    }
}

/**
 * @brief Balance the load by assigning requests to available servers
 * 
 */
void LoadBalancer::balanceLoad() {
    for (auto& server : servers) {
        if (!requestQueue.isEmpty()) {
            Request req = requestQueue.getRequest();
            server.processRequest(req);
            totalTaskTime += req.time;
            processedRequestsCount++;
        }
    }
    // Simulate adding new requests
    if (rand() % 2 == 0) {
        requestQueue.addRequest(Request("192.168.0.1", "192.168.0.2", rand() % 10 + 1));
    }
}

/**
 * @brief Get the current size of the request queue
 * 
 * @return int Size of the request queue
 */
int LoadBalancer::getQueueSize() const {
    return requestQueue.size();
}

/**
 * @brief Get the total task time
 * 
 * @return int Total task time
 */
int LoadBalancer::getTotalTaskTime() const {
    return totalTaskTime;
}

/**
 * @brief Get the number of processed requests
 * 
 * @return int Number of processed requests
 */
int LoadBalancer::getProcessedRequestsCount() const {
    return processedRequestsCount;
}
