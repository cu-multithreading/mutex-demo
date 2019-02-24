#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using std::cout;
using std::endl;

std::mutex consoleAccess;

bool useMutex = true;

void func(int threadNo)
{
	if(useMutex) consoleAccess.lock();
	cout << "Thread " << threadNo << endl;
	if(useMutex) consoleAccess.unlock();
}

int main(int argc, char * argv[])
{
	std::vector<std::thread> threads;
	for(int i = 0; i < 50; i++)
	{
		threads.push_back(std::thread(func, i));
	}

	for(auto & iter : threads)
	{
		iter.join();
	}
	return 0;
}
