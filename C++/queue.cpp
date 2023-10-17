#include <iostream>
#include <vector>

class CafeQueue {
public:
    void enqueue(const std::string& customer) {
        queue.push_back(customer);
        std::cout << customer << " entered the queue." << std::endl;
    }

    void dequeue() {
        if (!isEmpty()) {
            std::string customer = queue[0];
            queue.erase(queue.begin());
            std::cout << customer << " left the queue." << std::endl;
        } else {
            std::cout << "The queue is empty." << std::endl;
        }
    }

    bool isEmpty() {
        return queue.empty();
    }

    void viewQueue() {
        std::cout << "Current queue:";
        for (const std::string& customer : queue) {
            std::cout << " " << customer;
        }
        std::cout << std::endl;
    }

private:
    std::vector<std::string> queue;
};

int main() {
    CafeQueue cafeQueue;

    cafeQueue.enqueue("Customer 1");
    cafeQueue.enqueue("Customer 2");
    cafeQueue.enqueue("Customer 3");

    cafeQueue.viewQueue();

    cafeQueue.dequeue();

    cafeQueue.viewQueue();

    return 0;
}
