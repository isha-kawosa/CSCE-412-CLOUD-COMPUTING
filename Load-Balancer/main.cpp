// #include <iostream>
// #include <fstream>
// #include "LoadBalancer.h"

// int main() {
//     int numServers;
//     int numCycles;

//     std::cout << "Enter the number of web servers: ";
//     std::cin >> numServers;

//     std::cout << "Enter the number of clock cycles to run the load balancer: ";
//     std::cin >> numCycles;

//     LoadBalancer lb(numServers);

//     int startingQueueSize = lb.getQueueSize();
//     std::cout << "Starting queue size: " << startingQueueSize << std::endl;

//     std::ofstream logFile("load_balancer_log.txt");
//     logFile << "Starting simulation with " << numServers << " servers and " << numCycles << " clock cycles." << std::endl;
//     logFile << "Starting queue size: " << startingQueueSize << std::endl;

//     for (int cycle = 0; cycle < numCycles; ++cycle) {
//         lb.balanceLoad();
//         if ((cycle + 1) % 1000 == 0) {
//             logFile << "Cycle: " << cycle + 1 << ", Current queue size: " << lb.getQueueSize() << std::endl;
//         }
//     }

//     int endingQueueSize = lb.getQueueSize();
//     std::cout << "Ending queue size: " << endingQueueSize << std::endl;

//     logFile << "Ending queue size: " << endingQueueSize << std::endl;
//     logFile << "Range for task times: 1 - 10 cycles" << std::endl;

//     logFile.close();

//     std::cout << "Simulation finished. Log file created: load_balancer_log.txt" << std::endl;

//     return 0;
// }
#include <iostream>
#include <fstream>
#include "LoadBalancer.h"

/**
 * @brief Main function to run the load balancer simulation
 * 
 * @return int Exit status
 */
int main() {
    int numServers;
    int numCycles;

    std::cout << "Enter the number of web servers: ";
    std::cin >> numServers;

    std::cout << "Enter the number of clock cycles to run the load balancer: ";
    std::cin >> numCycles;

    LoadBalancer lb(numServers);

    int startingQueueSize = lb.getQueueSize();
    std::cout << "Starting queue size: " << startingQueueSize << std::endl;

    std::ofstream logFile("load_balancer_log.txt");
    logFile << "Starting simulation with " << numServers << " servers and " << numCycles << " clock cycles." << std::endl;
    logFile << "Starting queue size: " << startingQueueSize << std::endl;

    int totalTaskTime = 0;
    int totalRequestsProcessed = 0;
    int peakQueueSize = startingQueueSize;

    for (int cycle = 0; cycle < numCycles; ++cycle) {
        lb.balanceLoad();

        // Collect statistics
        totalTaskTime += lb.getTotalTaskTime();
        totalRequestsProcessed += lb.getProcessedRequestsCount();
        int currentQueueSize = lb.getQueueSize();
        if (currentQueueSize > peakQueueSize) {
            peakQueueSize = currentQueueSize;
        }

        if ((cycle + 1) % 1000 == 0) {
            logFile << "Cycle: " << cycle + 1 << ", Current queue size: " << currentQueueSize << std::endl;
        }
    }

    int endingQueueSize = lb.getQueueSize();
    std::cout << "Ending queue size: " << endingQueueSize << std::endl;

    logFile << "Ending queue size: " << endingQueueSize << std::endl;
    logFile << "Range for task times: 1 - 10 cycles" << std::endl;
    
    // Calculate average task time
    double averageTaskTime = static_cast<double>(totalTaskTime) / totalRequestsProcessed;
    logFile << "Average task time: " << averageTaskTime << " cycles" << std::endl;
    logFile << "Total number of requests processed: " << totalRequestsProcessed << std::endl;
    logFile << "Peak queue size: " << peakQueueSize << std::endl;

    logFile.close();

    std::cout << "Simulation finished. Log file created: load_balancer_log.txt" << std::endl;

    return 0;
}
