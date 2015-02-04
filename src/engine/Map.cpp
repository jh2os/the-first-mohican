#include "Map.h"

Map::Map() {
	tileSize = 8;
	displaySize = 100;
	int row1[] = {0,0, 1,0, 2,0, 1,1, 0,0, 1,0, 2,0, 1,1};
	int row2[] = {0,1, 1,1, 2,1, 1,1, 0,1, 1,1, 2,1, 1,1};
	int row3[] = {0,2, 1,2, 2,2, 1,1, 0,2, 1,2, 2,2, 1,1};
	int row4[] = {0,3, 1,3, 2,3, 1,1, 0,3, 1,3, 2,3, 1,1};
	int row5[] = {0,4, 1,4, 2,4, 1,1, 0,4, 1,4, 2,4, 1,1};
	int row6[] = {0,5, 1,5, 2,5, 1,1, 0,5, 1,5, 2,5, 1,1};
	int row7[] = {1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1};
	textureArray.push_back(std::vector<int> (row1, row1 + sizeof(row1) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row2, row2 + sizeof(row2) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row3, row3 + sizeof(row3) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row4, row4 + sizeof(row4) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row5, row5 + sizeof(row5) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row6, row6 + sizeof(row6) / sizeof(int)) );
	textureArray.push_back(std::vector<int> (row7, row7 + sizeof(row7) / sizeof(int)) );
}

void Map::loadMapSheet(std::string filename) {
	mapSheet.LoadTexture(filename);
}

void Map::setDisplaySize(int size) {
	displaySize = size;
}

void Map::render() {
	int mapWidth = textureArray[0].size();
	int mapHeight = textureArray.size();

	
	for( int i = 0; i < mapHeight; i++) {
		for ( int j = 0; j < mapWidth; j += 2) {
			int tileX = j / 2  * displaySize;
			int tileY = (mapHeight + 1 - i) * displaySize;
			int sourceX = textureArray[i][j] * tileSize;
			int sourceY = textureArray[i][j+1] * tileSize;

			mapSheet.SetSourceRect( sourceX, sourceY, tileSize, tileSize);
			mapSheet.SetDestRect(
							 E.Gcamera.convertX((int)tileX, E.GetWindowWidth()),
							 E.Gcamera.convertY((int)tileY, E.GetWindowWidth()),
							 displaySize,
							 displaySize
							 );
			mapSheet.DisplayTexture((float)0.0);
		}
	}


}
