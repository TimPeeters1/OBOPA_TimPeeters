#pragma once
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <vector>

template <class T>
class TQueue
{
	public:
		T* queue;
		int size;
		
		TQueue(T arr[]) {
			queue = arr;
			size = sizeof(arr) / sizeof(arr[0]) + 1;
		}

		virtual ~TQueue() {
		};

		void put(T element) {
			int newSize = size + 1;
			T* tempQueue = new T[newSize];

			for (int i = 0; i < newSize; i++)
			{
				if (i == size) 
				{
					tempQueue[i] = element;
				}
				else 
				{
					tempQueue[i] = queue[i];
				}
			}

			size++;
			queue = tempQueue;
		}

		T get() {
			T value = queue[0];
			return value;
		}

		void print() {
			for (int i = 0; i < size; i++)
			{
				std::cout << queue[i] << " ";
			}
			std::cout << std::endl;
		}
};

