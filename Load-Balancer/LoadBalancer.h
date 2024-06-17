#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"

/**
 * @brief The LoadBalancer class handles the distribution of requests to a set of web servers.
 * 
 */
class LoadBalancer {
public:
    /**
     * @brief Construct a new Load Balancer object
     * 
     * @param numServers Number of servers to initialize
     */
    LoadBalancer(int numServers);

    /**
     * @brief Balance the load by assigning requests to available servers
     * 
     */
    void balanceLoad();

    /**
     * @brief Get the current size of the request queue
     * 
     * @return int Size of the request queue
     */
    int getQueueSize() const;

    /**
     * @brief Get the total task time
     * 
     * @return int Total task time
     */
    int getTotalTaskTime() const;

    /**
     * @brief Get the number of processed requests
     * 
     * @return int Number of processed requests
     */
    int getProcessedRequestsCount() const;

private:
    std::vector<WebServer> servers; ///< List of web servers managed by the load balancer
    RequestQueue requestQueue; ///< Queue of incoming requests
    int totalTaskTime; ///< Total time spent processing tasks
    int processedRequestsCount; ///< Number of requests processed
};

#endif // LOADBALANCER_H
