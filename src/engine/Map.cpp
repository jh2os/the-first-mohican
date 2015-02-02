#include "Map.h"

Map::Map() {
	tileSize = 100;
	int row1[] = {0,0,0,0,4,3,4,0,0,0,0,0,4,3,4,0};
	int row2[] = {0,0,0,0,4,3,4,0,0,0,0,0,4,3,4,0};
	int row3[] = {0,0,0,0,4,3,4,0,0,0,0,0,4,3,4,0};
	int row4[] = {4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4};
	int row5[] = {1,1,1,1,1,2,1,1,1,1,1,1,1,2,1,1};
	int row6[] = {4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4};
	int row7[] = {0,0,0,0,4,3,4,0,0,0,0,0,4,3,4,0};
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

void Map::render() {
	int mapWidth = textureArray[0].size();
	int mapHeight = textureArray.size();

	
	for( int i = 0; i < mapHeight; i++) {
		for ( int j = 0; j < mapWidth; j++) {
			int tileX = j * tileSize;
			int tileY = (mapHeight + 1 - i) * tileSize;
			int sourceX = textureArray[i][j] * tileSize;
			int sourceY = 0;

			mapSheet.SetSourceRect( sourceX, sourceY, tileSize, tileSize);
			mapSheet.SetDestRect(
							 E.Gcamera.convertX((int)tileX, E.GetWindowWidth()),
							 E.Gcamera.convertY((int)tileY, E.GetWindowWidth()),
							 tileSize,
							 tileSize
							 );
			mapSheet.DisplayTexture((float)0.0);
		}
	}


}
