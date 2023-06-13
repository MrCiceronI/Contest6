Description of solution B
===========

We write down the number of wagons and their sequence. 

We compare the numbers of wagons with the order in which they should go (in ascending order). 
If the wagon number matches its position on the tracks, then we immediately transfer it to the next tracks. 
If not, then we get into a dead end. When the wagons on the first tracks run out, we begin to bring the wagons out of the dead end.

If the position of the wagons does not match the required one, 
then we stop the solution and inform the user that they cannot be positioned correctly.