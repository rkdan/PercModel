#pragma once
#include "Location.h"
#include <random>
#include <queue>

class Particles
{
public:
	Particles(std::mt19937& rng);
	int getWidth();
	int getHeight();
	void pathFind();
	void populateMatrix(std::mt19937& rng);
	std::queue<Location> shortestQ;
	static constexpr int width = 50;
	static constexpr int height = 50;
	static constexpr int nParticlesMax = 2000;
	int nParticles = 0;
	int particleMatrix[width][height] = { 0 };
	int pathMatrix[width][height] = { 0 };
	int drawSearchMatrix[width][height] = { 0 };
	
private:
};