#include "Particles.h"
#include <stdio.h>

Particles::Particles(std::mt19937& rng, int width, int height, int nParticlesMax)
	:
	width(width),
	height(height),
	nParticlesMax(nParticlesMax)
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
		if (particleMatrix[i*width + j] == State::Empty)
		{
			particleMatrix[i*width + j] = State::Occupied;
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
		vector<int> searchMatrix(width*height);
		int rr = ii;
		int cc = 0;
		//int elem = ii*width;
		if (particleMatrix[ii] == State::Occupied)
		{
			int nodesLeft = 1;
			int nodesNext = 0;
			bool reachedEnd = false;
			std::queue<Location> mainQ;
			Location current = { 0, ii };
			vector<Location> cameFromMatrix(width*height);
			searchMatrix[ii] = 1;
			mainQ.push(current);
			while (mainQ.size() > 0)
			{
				searchNeighbours(reachedEnd, mainQ, current, rr, cc, nodesNext, searchMatrix, cameFromMatrix);
			}
			if (reachedEnd)
			{
				findShortestPath(cameFromMatrix, current, shortestQ);
			}
		}
		// Have to build a seperate matrix to feed to the board drawing method.
		for (int m = 0; m < width; m++)
		{
			for (int n = 0; n < height; n++)
				if (searchMatrix[m*width + n] == 1)
				{
					drawSearchMatrix[m*width + n] = 1;
				}
		}
	}
	if (!shortestQ.empty())
	{
		buildPath(shortestQ);
	}
}

void Particles::buildPath(std::queue<Location>& shortestQ)
{
	Location next;
	next = shortestQ.front();
	particleMatrix[(next.x + 1)*width + next.y] = State::Path;
	while (!shortestQ.empty())
	{
		next = shortestQ.front();
		shortestQ.pop();
		particleMatrix[next.x * width + next.y] = State::Path;
	}
}

void Particles::searchNeighbours(bool& reachedEnd, 
	std::queue<Location>& mainQ, Location& current, 
	int& rr, int& cc, int& nodesNext, 
	vector<int>& searchMatrix, vector<Location>& cameFromMatrix)
{
	int dr[3] = { 0, 1, -1 };
	int dc[3] = { 1, 0, 0 };
	current = mainQ.front();
	mainQ.pop();
	if (current.x == width - 1)
	{
		reachedEnd = true;
	}
	for (int i = 0; i < 3; i++)
	{
		cc = current.x + dc[i];
		rr = current.y + dr[i];
		if (rr >= 0 && cc > 0 && cc < width && rr < height)
		{
			if (searchMatrix[cc*width + rr] != 1 &&
				particleMatrix[cc * width + rr] == State::Occupied)
			{
				cameFromMatrix[cc*width + rr].x = current.x;
				cameFromMatrix[cc*width + rr].y = current.y;
				mainQ.push({ cc, rr });
				searchMatrix[cc*width + rr] = 1;
				nodesNext++;
			}
		}
	}
}

void Particles::findShortestPath(vector<Location>& cameFromMatrix, Location& current, std::queue<Location>& shortestQ)
{
	int i = width - 1;
	for (int j = 0; j < height; j++)
	{
		if (cameFromMatrix[i*width + j].y != 0)
		{
			std::queue<Location> currentQ;
			current = cameFromMatrix[i*width + j];
			currentQ.push(current);
			while (current.x > 0)
			{
				int c = current.x;
				int r = current.y;
				current = cameFromMatrix[c * width + r];
				currentQ.push(current);
			}
			if (shortestQ.size() == 0 || currentQ.size() < shortestQ.size())
			{
				shortestQ = currentQ;
			}
		}
	}
}
