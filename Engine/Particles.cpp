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
		//particleMatrix[0][5] = 1;
		//particleMatrix[1][5] = 1;
		//particleMatrix[2][5] = 1;
		//particleMatrix[3][5] = 1;
		//particleMatrix[4][5] = 1;
		//particleMatrix[4][6] = 1;
		//particleMatrix[5][5] = 1;
		//particleMatrix[6][5] = 1;
		//particleMatrix[7][5] = 1;
		//particleMatrix[3][4] = 1;
		//particleMatrix[3][3] = 1;
		//particleMatrix[4][3] = 1;
		//particleMatrix[8][5] = 1;
		//particleMatrix[9][5] = 1;
		//++nParticles;
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
	std::stack<Location> Q;
	std::stack<Location> shortestQ;
	int i = 0;
	for (int j = 0; j < height; ++j)
	{
		bool isEmpty = false;
		bool isEnd = false;
		
		if (particleMatrix[0][j] == 1)
		{
			std::stack<Location> currentQ;
			searchMatrix[i][j] = 1;
			//Location source = { i, j };
			Location current = { i , j };
			currentQ.push(current);
			//q.push(current);
			while (isEnd == false && isEmpty == false)
			{	
				bool pushed = false;
				searchMatrix[current.x][current.y] = 1;
				if (current.x == width - 1) 
				{ 
					isEnd = true;
					currentQ.push(current);
				}
				else
				{
					// Look right
					if (searchMatrix[current.x + 1][current.y] != 1 && 
						particleMatrix[current.x + 1][current.y] == 1)
					{
						Q.push({ current.x + 1, current.y });
						pushed = true;
					}
					// Look up
					if (current.y > 1 &&
						searchMatrix[current.x][current.y - 1] != 1 && 
						particleMatrix[current.x][current.y - 1] == 1 &&
						current.y != 0) 
					{
						Q.push({ current.x, current.y - 1 });
						pushed = true;
					}
					// Look down
					if (current.y < 40 &&
						searchMatrix[current.x][current.y + 1] != 1 && 
						particleMatrix[current.x][current.y + 1] == 1 &&
						current.y + 1 != height)
					{
						Q.push({ current.x, current.y + 1 });
						pushed = true;
					}
					if (!pushed && currentQ.size() > 1)
					{
						currentQ.pop();
						current = currentQ.top();
					}
					else if (currentQ.size() == 1)
					{
						currentQ.pop();
					}
				}
				if (Q.size() == 0)
				{
					isEmpty = true;
				}
				if (!pushed && !isEmpty && currentQ.size() == 0)
				{
					currentQ.pop();
					current = Q.top();
					currentQ.push(current);
					Q.pop();
				}
				if (isEnd == true)
				{
					if (shortestQ.size() == 0)
					{
						shortestQ = currentQ;
					}
					else if (currentQ.size() < shortestQ.size())
					{
						shortestQ = currentQ;
					}
				}
				else if (!Q.empty() && pushed)
				{
					current = Q.top();
					currentQ.push(current);
					Q.pop();
				}
			}
		}
	}
	while (!shortestQ.empty())
	{
		Location newLoc = shortestQ.top();
		shortestQ.pop();
		pathMatrix[newLoc.x][newLoc.y] = 1;
	}
	
}

void Particles::shortestPath()
{

}

