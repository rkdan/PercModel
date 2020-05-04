#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::Draw(Particles& particles)
{
	int width = particles.getWidth();
	int height = particles.getHeight();
	const int xPad = (gfx.ScreenWidth - width * dimensions) / 2;
	const int yPad = (gfx.ScreenHeight - height * dimensions) / 2;
	DrawBorder(xPad, yPad, width, height, dimensions);
	for (int i = 0; i < particles.width; i++)
	{
		for (int j = 0; j < particles.height; j++)
		{
			if (particles.particleMatrix[i][j] == 1)
			{
				int x0 = i * dimensions + xPad;
				int y0 = j * dimensions + yPad;
				gfx.DrawRectDim(x0, y0, dimensions, dimensions, particleColor);
			}
			if (particles.searchMatrix[i][j] == 1)
			{
				int x0 = i * dimensions + xPad;
				int y0 = j * dimensions + yPad;
				gfx.DrawRectDim(x0, y0, dimensions, dimensions, pathColor);
				particles.searchMatrix[i][j] = 0;
			}
				
		}
	}
	
	
}

void Board::DrawBorder(int xPad, int yPad, int width, int height, int dimensions)
{
	gfx.DrawRectDim(xPad - borderThick, yPad-borderThick,         height * dimensions + 2 * borderThick, borderThick, borderColor);
	gfx.DrawRectDim(xPad - borderThick, yPad + height*dimensions, height * dimensions + 2 * borderThick, borderThick, borderColor);
	gfx.DrawRectDim(xPad - borderThick, yPad, borderThick, width * dimensions, borderColor);
	gfx.DrawRectDim(xPad + height * dimensions, yPad, borderThick, width*dimensions, borderColor);
}
