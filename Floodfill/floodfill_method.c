 #include floodfill_c/Floodfill/floofill_move.h
#include floodfill_c/floodfill/stack.h
#include floodfill_c/Floodfill/DataComponents.h




void floodfill(int mazecells[][16], char a){
int level=0;
Struct llstack stack1;
Struct llstack stack2;
init_stack(stack1);
init_stack(stack2);
	if(a=='C'){
	//	setValue(mazecells[MAZEHEIGHT/2][MAZEWIDTH/2],0);
		push(&stack1,mazecells[MAZEHEIGHT/2][MAZEWIDTH/2],0)
		//setValue(mazecells[MAZEHEIGHT/2+1][MAZEWIDTH/2],0);
		push(&stack1,mazecells[MAZEHEIGHT/2+1][MAZEWIDTH/2],0)
		//setValue(mazecells[MAZEHEIGHT/2][MAZEWIDTH/2+1],0);
		push(&stack1,mazecells[MAZEHEIGHT/2][MAZEWIDTH/2+1],0)
		//setValue(mazecells[MAZEHEIGHT/2+1][MAZEWIDTH/2+1],0);
		push(&stack1,mazecells[MAZEHEIGHT/2+1][MAZEWIDTH/2+1],0)
	}
	else 
		//{setValue(mazecells[0][MAZEHEIGHT]);
		push(&stack1,mazecells[0][MAZEHEIGHT],0);}
while(!stackIsEmpty(&stack1))
{
  int *temp= top(*stack1);
  
  pop(&stack1);
	
  if (getN(temp) == 0)
         { //Check to see if it should be added to queue
            if ( ( (getDist(temp) + 1) < getDist))
            {
               queue.add(cell.plusY(-1));
               setDistance(cell.plusY(-1), currentDistance + 1);
            }
         }

         //Check to see if accessible
         if (maze.getWall(cell, Direction.South).isSet() == false)
         { //Check to see if it should be added to queue
            if ( ( (currentDistance + 1) < getNeighborDistance(cell, Direction.South)) &&
                ( (speedy == false) || (getNeighborExplored(cell, Direction.South))))
            {
               queue.add(cell.plusY(1));
               setDistance(cell.plusY(1), currentDistance + 1);
            }
         }

         //Check to see if accessible
         if (maze.getWall(cell, Direction.West).isSet() == false)
         { //Check to see if it should be added to queue
            if ( ( (currentDistance + 1) < getNeighborDistance(cell, Direction.West)) &&
                ( (speedy == false) || (getNeighborExplored(cell, Direction.West))))
            {
               queue.add(cell.plusX(-1));
               setDistance(cell.plusX(-1), currentDistance + 1);
            }
         }

         //Check to see if accessible
         if (maze.getWall(cell, Direction.East).isSet() == false)
         { //Check to see if it should be added to queue
            if ( ( (currentDistance + 1) < getNeighborDistance(cell, Direction.East)) &&
                ( (speedy == false) || (getNeighborExplored(cell, Direction.East))))
            {
               queue.add(cell.plusX(1));
               setDistance(cell.plusX(1), currentDistance + 1);
            }

}

Array 
