#pragma once

namespace myGdiplusGame {

	const int g_nTileSize = 16;
	const int g_nTileXCount = 8;

	void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int *pMap)
	{
		int nTileIndex = pMap[nPosX + nPosY*g_nTileXCount];

		pGrp->DrawImage(pImgBasicTile, Rect(nPosX * 16, nPosY * 16, g_nTileSize, g_nTileSize),
			g_nTileSize * (nTileIndex % g_nTileXCount), g_nTileSize * (nTileIndex / g_nTileXCount), g_nTileSize, g_nTileSize, UnitPixel);
	}

}