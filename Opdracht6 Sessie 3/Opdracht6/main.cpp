#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

std::condition_variable flag;
std::mutex mutex;

int counter = 0;
bool done = false;
std::queue<int> goods;



void producer() {

	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		counter++;
	}

	done = true;
	flag.notify_one();
}

void consumer() {
	std::unique_lock<std::mutex> lock(mutex);

	while (!done) {
		flag.wait(lock);

		while (!goods.empty()) {
			
			goods.pop();
			counter--;
		}
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;
}