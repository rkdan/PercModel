#pragma once
#include "Location.h"
#include <random>
#include <queue>
#include <vector>
using namespace std;

class Particles
{
public:
	Particles(std::mt19937& rng);
	int getWidth();             // probably don't need these since I made the width and height public.
	int getHeight();
	void pathFind();
	void populateMatrix(std::mt19937& rng);
	std::queue<Location> shortestQ;
	static const int width = 20;
	static constexpr int height = 20;
	static constexpr int nParticlesMax = 300;
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
		int searchMatrix[width][height], vector<int> particleMatrix, vector<Location>& cameFromMatrix);
	void findShortestPath(vector<Location>& cameFromMatrix, Location& current, std::queue<Location>& shortestQ);
};