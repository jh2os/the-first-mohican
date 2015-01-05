#ifndef LOGGER_H
	#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

class Logger{
	public:
		Logger(string dir);
		void Destroy();
		void LogError(string message);
		void LogMessage(string message);
		string getDate(string format="");

	private:
		ofstream fileStream;

		const string ENGINENAME = "eflat";

		string getTime(string format="");
};
#endif
