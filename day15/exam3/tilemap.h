#pragma once

struct S_GAMEMAP
{
	//map
	int m_nWidth, m_nHeight;
	int m_Map[1024];
	//tile
	Image *m_ImageObj;
	int m_TileWidth;
	int m_TileHeight;
	irr::core::vector2di m_TilePositions[256];
};

extern void InitMap(S_GAMEMAP *pMap, int width, int height, TCHAR *szImgFile, int nTileWidth, int nTileHeight);
extern void SetMapIndex(S_GAMEMAP *pMap, int x, int y, int index);
extern void SetTilePosition(S_GAMEMAP *pMap, int x, int y, int index);
extern void DrawTile(S_GAMEMAP *pMap, Graphics *pGrp, int x, int y, int nTileIndex);
extern void DrawMap(S_GAMEMAP *pMap, Graphics *pGrp, int xOrg, int yOrg);
extern void DrawTilePalette(S_GAMEMAP *pMap, Graphics *pGrp, int xOrg, int yOrg);