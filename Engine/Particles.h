#pragma once
#include "Location.h"
#include <random>
#include <queue>
#include <vector>
using namespace std;

class Particles
{
public:
	enum State
	{
		Empty,
		Occupied,
		Searched,
		Path
	};
	Particles(std::mt19937& rng, int width, int height, int nParticlesMax);
	int getWidth();             // probably don't need these since I made the width and height public.
	int getHeight();
	void pathFind();
	void populateMatrix(std::mt19937& rng);
	std::queue<Location> shortestQ;
	const int width;
	const int height;
	const int size = width * height;
	const int nParticlesMax;
	int nParticles = 0;
	vector<int> particleMatrix = vector<int>(size);
	//vector<int> pathMatrix = vector<int>(size);
	vector<int> drawSearchMatrix = vector<int>(size);
private:
	
	void buildPath(std::queue<Location>& shortestQ);
	// The below function is possibly an abomination
	void searchNeighbours(bool& reachedEnd, 
		std::queue<Location>& mainQ, Location& current, 
		int& rr, int& cc, int& nodesNext, 
		vector<int>& searchMatrix, vector<Location>& cameFromMatrix);
	void findShortestPath(vector<Location>& cameFromMatrix, Location& current, std::queue<Location>& shortestQ);
};