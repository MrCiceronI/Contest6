Description of solution D
===========

Record the number of columns. 
Push the height onto the stack. 

We start from the last column and calculate the area of the rectangle and write down its height. 
If this area is greater than the maximum, then assign it to the maximum. 

If the next column is smaller than the rectangle, then set the height of the rectangle to the height of the column. 
We recalculate the area. 

We go through all the columns. 
After all the passes, we find out the maximum area.