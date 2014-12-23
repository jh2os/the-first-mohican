#ifndef CONFIGURATION_H
	#define CONFIGURATION_H
	
#include <iostream>
#include <fstream>

using namespace std;

class Configuration{
	public:
		Configuration(string filename);
		bool LoadConfigurations();
		void Destroy();
		int getScreenWidth();
		int getScreenHeight();
		bool isDebugOn();
		int getMixerVolume();
		string getLoggerDirectory();
		bool parseBoolean(string str);

	private:
		fstream fileStream;
		
		int screenWidth;
		int screenHeight;
		bool debugOn;
		int mixerVolume;
		string loggerDirectory;
};
#endif
