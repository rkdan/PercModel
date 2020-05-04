#pragma once

#include "Graphics.h"
#include "Particles.h"

class Board
{
public:
	Board(Graphics& gfx);
	void Draw(Particles& particles);
private:
	void DrawBorder(int xPad, int yPad, int width, int height, int dimensions);
	static constexpr int dimensions = 10;
	static constexpr int borderThick = 5;
	static constexpr Color borderColor = Colors::Blue;
	static constexpr Color particleColor = Colors::Green;
	static constexpr Color pathColor = Colors::Red;
	Graphics& gfx;
};