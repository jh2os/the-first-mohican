#ifndef CONFIGURATION_H
	#define CONFIGURATION_H
	
#include <iostream>
#include <fstream>

using namespace std;

class Configuration{
	public:
		Configuration();
		bool LoadConfigurations();
		void Destroy();

	private:
		fstream fileStream;
		
		int screenWidth;
		int screenHeight;
		bool debugOn;
		int mixerVolume;
};
#endif
