#include <iostream>
#include <queue>
#include <vector>

// Structure to represent a request
struct Request {
    Request(int arrival_time, int process_time) :
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time; // Time when the request arrives
    int process_time; // Time taken to process the request
};

// Structure to represent a response to a request
struct Response {
    Response(bool dropped, int start_time) :
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped; // Indicates whether the request is dropped or not
    int start_time; // Start time of the request processing
};

// Class to implement a buffer for processing requests
class Buffer {
public:
    Buffer(int size) :
        size_(size),
        finish_time_()
    {}

    // Method to process a request and return a response
    Response Process(const Request& request) {
        // Remove finished requests from the buffer
        while (!finish_time_.empty() && finish_time_.front() <= request.arrival_time)
            finish_time_.pop();

        if (finish_time_.size() == size_) {
            // The buffer is full, so the request is dropped
            return Response(true, -1);
        }
        else {
            int start_time;
            if (finish_time_.empty()) {
                // Buffer is empty, request can start immediately
                start_time = request.arrival_time;
            }
            else {
                // There are ongoing requests in the buffer, start time is the finish time of the last request
                start_time = finish_time_.back();
            }

            // Calculate finish time of the current request
            int finish_time = start_time + request.process_time;

            // Add finish time of the current request to the buffer
            finish_time_.push(finish_time);

            return Response(false, start_time);
        }
    }
private:
    int size_; // Size of the buffer
    std::queue<int> finish_time_; // Queue to store finish times of ongoing requests
};

// Function to read requests from input
std::vector<Request> ReadRequests() {
    std::vector<Request> requests;
    int count;
    std::cin >> count; // Input the number of requests
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time; // Input arrival time and process time of each request
        requests.push_back(Request(arrival_time, process_time)); // Add request to the vector
    }
    return requests;
}

// Function to process requests using the buffer
std::vector<Response> ProcessRequests(const std::vector<Request>& requests, Buffer* buffer) {
    std::vector<Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i])); // Process each request and store the response
    return responses;
}

// Function to print responses
void PrintResponses(const std::vector<Response>& responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl; // Print start time or -1 if request is dropped
}

// Main function
int main() {
    int size;
    std::cin >> size; // Input the size of the buffer
    std::vector<Request> requests = ReadRequests(); // Read requests from input

    Buffer buffer(size); // Create a buffer object with given size
    std::vector<Response> responses = ProcessRequests(requests, &buffer); // Process requests using the buffer

    PrintResponses(responses); // Print responses
    return 0;
}
