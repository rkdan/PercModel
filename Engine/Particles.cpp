#include "Particles.h"


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
	std::queue<Location> q;
	int i = 0;
	bool isEnd = false;
	for (int j = 5; j < 10; ++j)
	{
		if (particleMatrix[0][j] == 1)
		{
			searchMatrix[i][j] = 1;
			Location source = { i, j };
			Location current = { i , j };
			while (isEnd == false)
			{
				searchMatrix[current.x][current.y] = 1;
				if (current.x == 39) { isEnd = true; }
				else
				{
					// Look right
					if (searchMatrix[current.x + 1][current.y] != 1 && 
						particleMatrix[current.x + 1][current.y] == 1)
					{
						q.push({ current.x + 1, current.y });
					}
					// Look up
					if (current.y > 1 &&
						searchMatrix[current.x][current.y - 1] != 1 && 
						particleMatrix[current.x][current.y - 1] == 1)
					{
						q.push({ current.x, current.y - 1 });
					}
					// Look down
					if (current.y < 40 &&
						searchMatrix[current.x][current.y + 1] != 1 && 
						particleMatrix[current.x][current.y + 1] == 1)
					{
						q.push({ current.x, current.y + 1 });
					}
				}
				if (!q.empty())
				{
					current = q.front();
					q.pop();
				}
				else { isEnd = true; }
			}
		}
	}
}

