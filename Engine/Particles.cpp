#include "Particles.h"
#include <stdio.h>

Particles::Particles(std::mt19937& rng)
{
	populateMatrix(rng);
}

int Particles::getWidth()
{
	return width;
}

int Particles::getHeight()
{
	return height;
}

void Particles::populateMatrix(std::mt19937& rng)
{
	if (nParticles < nParticlesMax)
	{
		particleMatrix[0][4] = 1;
		particleMatrix[1][4] = 1;
		particleMatrix[2][4] = 1;
		particleMatrix[3][4] = 1;
		particleMatrix[4][4] = 1;
		particleMatrix[5][4] = 1;
		particleMatrix[5][3] = 1;
		particleMatrix[5][3] = 1;
		particleMatrix[5][2] = 1;
		particleMatrix[6][2] = 1;
		particleMatrix[7][2] = 1;
		particleMatrix[8][2] = 1;
		particleMatrix[9][2] = 1;
		particleMatrix[9][3] = 1;
		particleMatrix[6][4] = 1;
		particleMatrix[7][4] = 1;
		particleMatrix[8][4] = 1;
		particleMatrix[9][4] = 1;
		//std::uniform_int_distribution<int> xPos(0, width - 1);
		//std::uniform_int_distribution<int> yPos(0, height - 1);
		//int i = xPos(rng);
		//int j = yPos(rng);
		//if (particleMatrix[i][j] == 0)
		//{
		//	particleMatrix[i][j] = 1;
		//	++nParticles;
		//}
		//else
		//{
		//	populateMatrix(rng);
		//}
	}
}

void Particles::pathFind()
{
	int moveCount = 0;
	int nodesLeft = 1;
	int nodesNext = 0;
	bool reachedEnd = false;
	int dr[3] = {-1, 1, 0};
	int dc[3] = { 0, 0, 1 };
	int rr = 0;
	int cc = 0;
	std::queue<Location> mainQ;
	std::queue<Location> pathQ;
	Location source = { rr, cc };
	Location current;
	searchMatrix[0][cc] == 1;
	mainQ.push(source);
	pathQ.push(source);
	while (mainQ.size() > 0)
	{
		current = mainQ.front();
		mainQ.pop();
		if (current.x == width - 1)
		{
			reachedEnd = true;
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			rr = current.x + dr[i];
			cc = current.y + dc[i];
			if (rr >= 0 && cc >= 0 && rr < width && cc < height)
			{
				if (searchMatrix[rr][cc] != 1 &&
					particleMatrix[rr][cc] != 1)
				{
					current = { rr, cc };
					mainQ.push(current);
					searchMatrix[rr][cc] = 1;
					nodesNext++;
				}
			}
		}
		nodesLeft--;
		if (nodesLeft == 0)
		{

			nodesLeft = nodesNext;
			nodesNext = 0;
			moveCount++;
		}

	}
	if (reachedEnd)
	{
		while (!pathQ.empty())
		{
			Location pathElem = pathQ.front();
			pathQ.pop();
			pathMatrix[pathElem.x][pathElem.y] = 1;
		}
	}
}
