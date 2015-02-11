#include "Map.h"

Map::Map() {
	tileSize = 8;
	displaySize = 100;
	int mapwidth;
	int mapheight;
	/*int mrow[mapheight][mapwidth];
	int mrow[0] =  {0,0, 1,0, 2,0, 1,1, 0,0, 1,0, 2,0, 1,1};
	int mrow[1] =  {0,1, 1,1, 2,1, 1,1, 0,1, 1,1, 2,1, 1,1};
	int mrow[2] =  {0,2, 1,2, 2,2, 1,1, 0,2, 1,2, 2,2, 1,1};
	int mrow[3] =  {0,3, 1,3, 2,3, 1,1, 0,3, 1,3, 2,3, 1,1};
	int mrow[4] =  {0,4, 1,4, 2,4, 1,1, 0,4, 1,4, 2,4, 1,1};
	int mrow[5] =  {0,5, 1,5, 2,5, 1,1, 0,5, 1,5, 2,5, 1,1};
	int mrow[6] =  {1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1};

	for( int i = 0; i < mapheight; i++) {
		textureArray.push_back(std::vector<int> ());
	}*/
	
	FILE* FileHandle = fopen((char*)"assets/maps/1.level", "r");

	if (FileHandle == NULL) {
		std::cout << "Could not open level file" << std::endl;
	}

	fscanf(FileHandle, "%dx%d\n", &mapwidth, &mapheight);
	for(int my = 0; my < mapheight; my++) {
		std::vector<int> currentrow;
		for(int mx = 0; mx < mapwidth; mx++) {
			int sheetx;
			int sheety;
			fscanf(FileHandle, "%d,%d ", &sheetx, &sheety);
			currentrow.push_back(sheetx);
			currentrow.push_back(sheety);
		}
		fscanf(FileHandle, "\n");
		textureArray.push_back(currentrow);
		currentrow.clear();
	}

	fclose(FileHandle);

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
