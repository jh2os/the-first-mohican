#include "Debug.h"

Debug::Debug(){
	// load the file here
	fileStream.open("../../highScores.txt", fstream::out | ios::trunc);
}

void Debug::Destroy(){
	fileStream.close();
}

void Debug::LogError(string message){
	fileStream << message << endl;
	fileStream.flush();
}

void Debug::LogMessage(string message){
	fileStream << message << endl;
	fileStream.flush();
}
