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
		std::uniform_int_distribution<int> xPos(0, width - 1);
		std::uniform_int_distribution<int> yPos(0, height - 1);
		int i = xPos(rng);
		int j = yPos(rng);
		if (particleMatrix[i][j] == 0)
		{
			particleMatrix[i][j] = 1;
			++nParticles;
		}
		else
		{
			populateMatrix(rng);
		}
	}
}

void Particles::pathFind()
{
	for (int ii = 0; ii < height; ++ii)
	{
		int searchMatrix[width][height] = { 0 };
		int rr = ii;
		int cc = 0;
		if (particleMatrix[cc][rr] == 1)
		{
			int dr[3] = { 0, 1, -1 };
			int dc[3] = { 1, 0, 0 };
			int nodesLeft = 1;
			int nodesNext = 0;
			bool reachedEnd = false;
			std::queue<Location> mainQ;
			Location current = { cc, rr };
			searchMatrix[0][rr] = 1;
			mainQ.push(current);
			Location cameFromMatrix[width][height] = { 0 };
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
					cc = current.x + dc[i];
					rr = current.y + dr[i];
					if (rr >= 0 && cc > 0 && rr < width && cc < height)
					{
						if (searchMatrix[cc][rr] != 1 &&
							particleMatrix[cc][rr] == 1)
						{
							cameFromMatrix[cc][rr].x = current.x;
							cameFromMatrix[cc][rr].y = current.y;
							mainQ.push({ cc, rr });
							searchMatrix[cc][rr] = 1;
							nodesNext++;
						}
					}
				}
				nodesLeft--;
				if (nodesLeft == 0)
				{
					nodesLeft = nodesNext;
					nodesNext = 0;
				}
			}
			if (reachedEnd)
			{
				int i = width - 1;
				for (int j = 0; j < height; j++)
				{
					if (cameFromMatrix[i][j].y != 0)
					{
						std::queue<Location> currentQ;
						current = cameFromMatrix[i][j];
						currentQ.push(current);
						while (current.x > 0)
						{
							int c = current.x;
							int r = current.y;
							current = cameFromMatrix[current.x][current.y];
							currentQ.push(current);
						}
						if (shortestQ.size() == 0)
						{
							shortestQ = currentQ;
						}
						else if (currentQ.size() < shortestQ.size())
						{
							shortestQ = currentQ;
						}
					}
				}
			}
		}
		for (int m = 0; m < width; m++)
		{
			for (int n = 0; n < height; n++)
				if (searchMatrix[m][n] == 1)
				{
					drawSearchMatrix[m][n] = 1;
				}
		}
	}
	if (!shortestQ.empty())
	{
		Location next;
		next = shortestQ.front();
		pathMatrix[next.x + 1][next.y] = 1;
		while (!shortestQ.empty())
		{
			next = shortestQ.front();
			shortestQ.pop();
			pathMatrix[next.x][next.y] = 1;

		}
	}
}
