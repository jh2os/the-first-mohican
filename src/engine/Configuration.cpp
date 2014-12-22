#include "Configuration.h"

Configuration::Configuration(){
	// open the filestream
	fileStream.open("test.txt", ios::binary | fstream::in | fstream::out | fstream::app);
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
				cout << data << endl;
			}
			// case: screenHeight
			search = "screenHeight = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				cout << data << endl;
			}
			// case: debugOn
			search = "debugOn = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				cout << data << endl;
			}
			// case: maxVolume
			search = "maxVolume = ";
			found = data.find(search);
			if (found!=string::npos){
				data = data.substr(search.length(), data.length());
				cout << data << endl;
			}
		}
	}
	return false;
}
