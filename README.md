# Maze_Problem
### Question
Maze game is a well-known problem, where we are given a grid of 0’s and 1’s, 0’s correspond to a place that can be traversed, and 1 corresponds to a place that cannot be
traversed (i.e. a wall); the problem is to find a path from bottom left corner of grid to top right corner; immediate right, immediate left, immediate up and immediate down only are possible (no diagonal moves). We consider a variant of the maze problem where a cost is attached to visiting each location in the maze, and the problem is to find a path of least cost through the maze.
### Solution
Consider a maze given by a cost c ij such that c ij takes a finite value for traversable locations and ∞ for walls (non-traversable locations), with n rows and m columns.
We convert the maze to a weighted graph G(V, E) as follows: each location (i, j) in the maze corresponds to a node in the graph v ij , and V = ⋃ v ij and E =  { (u, v) | u, v ∈ V }. Each node v ij is connected to other nodes with weights in the following manner:
<br>d(v ij , v i,j+1 ) = c i,j+1
<br>d(v ij , v i+1,j ) = c i+1,j
<br>d(v ij , v i,j-1 ) = c i,j-1
<br>d(v ij , v i-1,j ) = c i-1,j
<br>d(v ij , v rs ) = ∞ otherwise
<br>This also means that the weight for an adjacent location in the maze (e.g. d(v ij , v i,j+1 )) takes the value ∞ if the destination ( v i,j+1 ) represents a wall. Now, consider a path t 0 , t 1 , t 2 , … t k in the maze, where t i ∈ Z + x Z + is a 2D tuple indicating the location (row, col)  in the maze); this has corresponding nodes in G(V, E) (say) u 0 , u 1 , u 2 , … u k . Then,  the cost of the path t 0 , t 1 , t 2 , … t k in the maze is 
<br>c0,0+i=0k-1d(ui, ui+1) 
<br>where c 0,0 remains the same for all paths and may be ignored. So, the optimal path minimizes i=0k-1d(ui, ui+1) where u 0 = v n,1 and u k = v 1,m . This can be accomplished by computing the optimal path from v n,1 to v 1,m using  Djikstra’s algorithm on the graph G(V, E).
### Output
![image](https://user-images.githubusercontent.com/52855622/132000259-bc61d5e4-d5c1-45be-ac80-965a41a66cf6.png)
