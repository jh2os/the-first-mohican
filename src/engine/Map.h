#ifndef MAP_H
#define MAP_H

#include "Texture.h"

class Map {
 private:
	int tileSize;
	Texture mapSheet;
	std::vector<std::vector<int>> textureArray;

 public:
	Map();
	void loadMapSheet(std::string);
	void render();
};
#endif
