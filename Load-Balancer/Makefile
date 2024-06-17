CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

all: main

main: main.o RequestQueue.o WebServer.o LoadBalancer.o
	$(CXX) $(CXXFLAGS) -o main main.o RequestQueue.o WebServer.o LoadBalancer.o

main.o: main.cpp RequestQueue.h WebServer.h LoadBalancer.h
	$(CXX) $(CXXFLAGS) -c main.cpp

RequestQueue.o: RequestQueue.cpp RequestQueue.h
	$(CXX) $(CXXFLAGS) -c RequestQueue.cpp

WebServer.o: WebServer.cpp WebServer.h Request.h
	$(CXX) $(CXXFLAGS) -c WebServer.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h RequestQueue.h WebServer.h
	$(CXX) $(CXXFLAGS) -c LoadBalancer.cpp

clean:
	rm -f main *.o
