#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::Draw(Particles& particles)
{
	// Main board
	int width = particles.getWidth();
	int height = particles.getHeight();
	const int xPad = (gfx.ScreenWidth - width * dimensions) / 2;
	const int yPad = (gfx.ScreenHeight - height * dimensions) / 2;
	DrawBorder(xPad, yPad, width, height, dimensions);
	for (int r = 0; r < particles.height; r++)
	{
		for (int c = 0; c < particles.width; c++)
		{
			if (particles.particleMatrix[int(r*width + c)] == Particles::State::Occupied)
			{
				int x0 = c * dimensions + xPad + dimensions/2;
				int y0 = r * dimensions + yPad + dimensions/2;
				gfx.DrawCircle(x0, y0, dimensions/2, particleColor);
				//gfx.DrawRectDim(x0+1, y0+1, dimensions-2, dimensions-2, particleColor);
			}
			if (particles.particleMatrix[int(r*width + c)] == Particles::State::Searched)
			{
				int x0 = c * dimensions + xPad + dimensions / 2;
				int y0 = r * dimensions + yPad + dimensions / 2;
				gfx.DrawCircle(x0, y0, dimensions/2, searchColor);
				//gfx.DrawRectDim(x0+1, y0+1, dimensions-2, dimensions-2, searchColor);
			}
			if (particles.particleMatrix[int(r*width + c)] == Particles::State::Path)
			{
				int x0 = c * dimensions + xPad + dimensions / 2;
				int y0 = r * dimensions + yPad + dimensions / 2;
				gfx.DrawCircle(x0, y0, dimensions/2, pathColor);
				//gfx.DrawRectDim(x0 + 1, y0 + 1, dimensions - 2, dimensions - 2, pathColor);
				particles.particleMatrix[int(r*width + c)] = Particles::State::Occupied;
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
