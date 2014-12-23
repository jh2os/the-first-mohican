#include "Configuration.h"

Configuration::Configuration(string filename){
	// open the filestream
	fileStream.open("config.txt", ios::binary | fstream::in | fstream::out | fstream::app);
}

void Configuration::Destroy(){
	fileStream.close();
}

bool Configuration::LoadConfigurations(){
	if(fileStream.is_open()){
		string data;
		string search;
		size_t found;
		while(getline(fileStream,data)){
			// TODO note that the config options need to have {= (space) value}. This needs to support more.
			// case: screenWidth
			search = "screenWidth = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				this->screenWidth = stoi(data);
				cout << data << endl;
				continue;
			}
			// case: screenHeight
			search = "screenHeight = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				this->screenHeight = stoi(data);
				cout << data << endl;
				continue;
			}
			// case: debugOn
			search = "debugOn = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				this->debugOn = parseBoolean(data);
				cout << data << endl;
				continue;
			}
			// case: maxVolume
			search = "mixerVolume = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				this->mixerVolume = stoi(data);
				cout << data << endl;
				continue;
			}
			// case: loggerDirectory
			search = "loggerDirectory = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				loggerDirectory = data;
				cout << data << endl;
				continue;
			}
			cout << "something went wrong" << endl;
			// default
			return false;
		}
	}
	return true;
}

bool Configuration::parseBoolean(string str){
	// NOTE this defaults this to false
	if(str.compare("true") == 0){
		return true;
	}
	else{
		return false;
	}
}

int Configuration::getScreenWidth(){
	return this->screenWidth;
}

int Configuration::getScreenHeight(){
	return this->screenHeight;
}

bool Configuration::isDebugOn(){
	return this->debugOn;
}

int Configuration::getMixerVolume(){
	return this->mixerVolume;
}

string Configuration::getLoggerDirectory(){
	return this->loggerDirectory;
}
