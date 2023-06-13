Description of solution C
===========

Record the number of tests. We write down the number of containers and their importance. 

Sort the containers in ascending order in a special array. 

Compare the container numbers with this array where they should go (in ascending order). 
If the container number matches its position on the tape, then we immediately transfer it to point B. 
If not, then we put it on the drive (on the stack). 

When the containers on the tape run out, we begin to remove the containers from the drive. 

If the position of the containers does not match the desired one, 
then we stop the solution and inform the user that they cannot be positioned correctly. 

Repeat with the next test.