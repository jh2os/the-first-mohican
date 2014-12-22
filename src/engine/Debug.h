#ifndef DEBUG_H
	#define DEBUG_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Debug{
	public:
		Debug();
		void Destroy();
		void LogError(string message);
		void LogMessage(string message);

	private:
		ofstream fileStream;
};
#endif
