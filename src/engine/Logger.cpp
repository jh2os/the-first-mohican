#include "Logger.h"

Logger::Logger(string dir){
	string dt = getDate();
	string filename = dir + string("logFile-") + dt + string(".txt");
	fileStream.open(filename.c_str(), fstream::out | ios::trunc);
	LogMessage("Logger has been initialized.");
}

void Logger::Destroy(){
	fileStream.close();
}

void Logger::LogError(string message){
	string dt = getDate("%m/%d/%Y %H:%M:%S");
	fileStream << string("[") + ENGINENAME + " - " "Error] " << dt << " - " << message << endl;
	fileStream.flush();
}

void Logger::LogMessage(string message){
	string dt = getDate("%m/%d/%Y %H:%M:%S");
	fileStream << string("[") + ENGINENAME + " - " "Message] " << dt << " - " << message << endl;
	fileStream.flush();
}

string Logger::getDate(string format){
	if (format.empty()){
		// default format
		format = "%m-%d-%Y-%H:%M:%S";
	}
	
	time_t rawtime;
	tm* timeinfo;
	char buffer [80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, format.c_str(), timeinfo);
	
	return buffer;
}
