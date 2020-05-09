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
	static constexpr int width = 30;
	static constexpr int height = 30;
	static constexpr int nParticlesMax = 700;
	int nParticles = 0;
	int particleMatrix[width][height] = { 0 };
	int pathMatrix[width][height] = { 0 };
	int drawSearchMatrix[width][height] = { 0 };
	
private:
};