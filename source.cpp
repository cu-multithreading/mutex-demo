#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>

using std::cout;
using std::endl;
using std::string;

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
	if(argc > 1 && string(argv[1]) == "noMutex") useMutex = false;

	std::vector<std::thread> threads;
	for(int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread(func, i));
	}

	for(auto & iter : threads)
	{
		iter.join();
	}
	return 0;
}
