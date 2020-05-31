#pragma once
#include "Location.h"
#include <random>
#include <queue>
#include <vector>
using namespace std;

class Particles
{
public:
	Particles(std::mt19937& rng, int width, int height, int nParticlesMax);
	int getWidth();             // probably don't need these since I made the width and height public.
	int getHeight();
	void pathFind();
	void populateMatrix(std::mt19937& rng);
	std::queue<Location> shortestQ;
	const int width;
	const int height;
	const int nParticlesMax;
	int nParticles = 0;
	vector<int> particleMatrix = vector<int>(height*width);
	vector<int> pathMatrix = vector<int>(height*width);
	vector<int> drawSearchMatrix = vector<int>(height*width);
private:
	//void 
	void buildPath(std::queue<Location>& shortestQ);
	// The below function is possibly an abomination
	void searchNeighbours(bool& reachedEnd, 
		std::queue<Location>& mainQ, Location& current, 
		int& rr, int& cc, int& nodesNext, 
		vector<int>& searchMatrix, vector<int> particleMatrix, vector<Location>& cameFromMatrix);
	void findShortestPath(vector<Location>& cameFromMatrix, Location& current, std::queue<Location>& shortestQ);
};