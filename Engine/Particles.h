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
	static constexpr int width = 30;
	static constexpr int height = 30;
	static constexpr int nParticlesMax = 600;
	int nParticles = 0;
	int particleMatrix[width][height] = { 0 };
	int searchMatrix[width][height] = { 0 };
private:
};