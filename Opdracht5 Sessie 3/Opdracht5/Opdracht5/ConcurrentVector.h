#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class ConcurrentVector
{
	public:
		std::vector<int> vec;
		std::mutex myLock;

	void push_back_safe()
	{
		try
		{
			int amount = 0;

			for (int i = 0; i < 100; i++)
			{
				myLock.lock();

				amount++;

				vec.push_back(amount);

				//std::cout << vec[i] << std::endl;
				//std::this_thread::sleep_for(std::chrono::milliseconds(300));
				

				myLock.unlock();
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
};


