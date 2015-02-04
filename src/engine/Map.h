#ifndef MAP_H
#define MAP_H

#include "Texture.h"

class Map {
 private:
	int tileSize;
	int displaySize;
	Texture mapSheet;
	std::vector<std::vector<int>> textureArray;

 public:
	Map();
	void loadMapSheet(std::string);
	void setDisplaySize(int size);
	void render();
};
#endif
