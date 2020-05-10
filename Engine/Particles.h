#pragma once
#include "Location.h"
#include <random>
#include <queue>

class Particles
{
public:
	Particles(std::mt19937& rng);
	int getWidth();             // probably don't need these since I made the width and height public.
	int getHeight();
	void pathFind();
	void populateMatrix(std::mt19937& rng);
	std::queue<Location> shortestQ;
	static constexpr int width = 40;
	static constexpr int height = 40;
	static constexpr int nParticlesMax = 1200;
	int nParticles = 0;
	int particleMatrix[width][height] = { 0 };
	int pathMatrix[width][height] = { 0 };
	int drawSearchMatrix[width][height] = { 0 };
private:
	//void 
	void buildPath(int pathmatrix[width][height], std::queue<Location>& shortestQ);
	// The below function is possibly an abomination
	void searchNeighbours(bool& reachedEnd, 
		std::queue<Location>& mainQ, Location& current, 
		int& rr, int& cc, int& nodesNext, 
		int searchMatrix[width][height], int particleMatrix[width][height], Location cameFromMatrix[width][height]);
	void findShortestPath(Location cameFromMatrix[width][height], Location& current, std::queue<Location>& shortestQ);
};