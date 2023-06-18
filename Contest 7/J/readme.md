Description of solution J
===========

Reading user data. 
Using the Number function, we move along the matrix and move from one vertex to another. 
In doing so, we assign 0 to the backward path so that the bypass is not infinite. 
When moving to a new vertex, we increase the count by 1.

Output the number of vertices.