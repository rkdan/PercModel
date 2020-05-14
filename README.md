# PercModel

A simple toy percolation model with a shortest path finder. Mainly to facilitate learning C++.

I used the Chili Framework in order to visually represent particles being randomly deposited on a n x n substrate. As the particles are deposited, the pathFind() algorithm is constantly probing for path from one side to the other using a breadth-first search. Once a path is found, the findShortestPath() function compares the current path with the shortest path. In this way, we find the path that covers the shortest distance from one side to the other.

To find the code written by me, check out particles, board, and location. In the Chili Framework, Game.cpp and Game.h have been changed to Simulation.cpp and Simulation.h respectively (and the contents altered).

This program uses the Chili Framework as featured in the excellent C++ tutorials by ChiliTomatoNoodle. Check out his tutorials here:

https://www.youtube.com/user/ChiliTomatoNoodle
