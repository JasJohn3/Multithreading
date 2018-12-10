// Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

static const int num_threads = 10;
mutex mtx;

string append_message = "";
void mutex_action(int tid);
int main()
{
	thread t[num_threads];


	//create threads
	for (int i = 0; i < num_threads; i++)
	{
		t[i] = thread(mutex_action, i);
	}
	//join threads
	for (int i = 0; i < num_threads; i++)
	{
		
		t[i].join();
		cout << "Thread #"<<i<<" Joined"<<endl;
	}

	cout << append_message;
    system("pause"); 
}

void mutex_action(int tid) {
	mtx.lock();
	append_message.append("Thread #").append(to_string(tid)).append(" message appended successfully.\n");
	mtx.unlock();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
