📌 Aim 

To implement and solve the 8-Puzzle Problem using heuristic search algorithms (A Search)* with admissible heuristics like Misplaced Tiles and Manhattan Distance. . The program finds a path from a given start state to the goal state by exploring all possible moves systematically. 

 

Shape 

📌 Problem Statement 

The 8-puzzle problem consists of a 3x3 grid with tiles numbered 1–8 and one empty space (denoted by 0). 
The objective is to move the tiles by sliding them into the empty space until the puzzle matches the goal configuration: 

Given an initial state from the user, the program must: 

Traverse the puzzle states using Heuristics 

Record all visited states. 

Print the traversal order. 

Reconstruct and display the final path from start to goal. 
 

Shape 

📌 Algorithm Used: Heuristics : No. of mIsplaced Tiles 

Input Start & Goal State 

Accept a 3×3 puzzle configuration from the user. 

Define the goal state (default: [ [1,2,3], [4,5,6], [7,8,0] ]). 

Initialize Data Structures 

Create a State object for the start puzzle. 

Set its heuristic value h(n) = number of misplaced tiles. 

Initialize a priority queue (min-heap) with the start state. 

Maintain: 

closed: set of visited states. 

state_map: map of state IDs to reconstruct the path. 

visited_states: list of traversal order. 

Search Process 

While the priority queue is not empty: 
a. Remove the state with the lowest heuristic value (h(n)). 
b. If already visited, skip it. 
c. Mark the state as visited (add to closed). 
d. If the current state equals the goal state → stop, reconstruct and print the path. 
e. Otherwise, generate all possible moves of the blank tile (up, down, left, right). 
f. For each neighbor: 

Compute heuristic h(n) (misplaced tiles). 

If not already visited, push into the priority queue. 

Reconstruct Final Path 

Trace back from goal state to start state using parent IDs stored in state_map. 

Reverse the sequence to display steps from start → goal. 

Output 

Print: 

Traversal Path (visited states in order with their heuristic values). 

Final Path (solution sequence with number of steps).
