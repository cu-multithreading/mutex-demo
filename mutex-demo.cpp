#include <iostream>
#include <thread>
#include <vector>

void fakeSleep(int a, int b)
{
	int cntr = 0;
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			cntr = 1;
		}
	}
}

void myFunc(int i)
{
	fakeSleep(i, 10000);
	std::cout << "thread " << i << std::endl;
}

int main(int argc, char * argv[])
{
	std::vector<std::thread> threads;
	for(int i = 0; i < 5; i++)
	{
		threads.push_back(std::thread(myFunc, i));
	}

	for(auto & iter : threads)
	{
		iter.join();
	}
	return 0;
}
