# PercModel

A simple toy percolation model with a shortest path finder. Mainly to facilitate learning C++.

I used the Chili Framework in order to visually represent particles being randomly deposited on a n x n substrate.

Particle locations are drawn from a uniform distribution and then "deposited" on the board.

![perc1](https://github.com/rkdan/PercModel/blob/master/Images/perc1.jpg)

As the particles are being deposited, the ``pathFind()`` algorithm performs a breadth first search of potential paths from one side to the other.

![perc2](https://github.com/rkdan/PercModel/blob/master/Images/perc2.jpg)

Once a path is found, the ``findShortestPath()`` algorithm compares potential paths and finds the shortest (as you can probably tell from the function name).

![perc3](https://github.com/rkdan/PercModel/blob/master/Images/perc3.jpg)

To find the code written by me, check out particles, board, and location. In the Chili Framework, Game.cpp and Game.h have been changed to Simulation.cpp and Simulation.h respectively (and the contents altered).

This program uses the Chili Framework as featured in the excellent C++ tutorials by ChiliTomatoNoodle. Check out his tutorials here:

https://www.youtube.com/user/ChiliTomatoNoodle
