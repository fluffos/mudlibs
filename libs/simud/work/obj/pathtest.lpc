#include <const.h>

//varargs int valid_heap( int *heap, int i );


string find_path( string map, int startx, int starty, int goalx, int goaly, mapping costs ) {
   // split_map will be an array of equal-length
   //strings (will pad spaces to assure this)
   string *split_map;

   // i is for generic loops, map_width is width
   // of split_map, goal is the destination point
   // (All coordinates are stored as x + y *
   // width). currpos is where the algorithm is
   // looking, currcost is cost at currpos, newx,
   // newy, newpos, and newcost are temps for
   // figuring out where to look next.
   int i, map_width, start, goal, currpos, currcost, newx, newy, newpos, newcost;

   int ineighbor, iparent, iheap;

   // closed is mapping from (int)coordinate:
   // (int) cost & direction. Note that costs
   // > 2^28 will cause undetected overflow
   // problems -- if you keep costs reasonable,
   // you shouldn't have a problem.
   mapping closed;

   // The open list, stored as a heap.
   // Even-numbered elements hold coordinate information,
   // odd-numbered ones give the cost for the previous
   // even numbered coordinate. Kind of a squinky heap
   // hack, and the indexing is a nightmare, but LPC
   // doesn't have a structure type, and I don't want
   // the overhead of using a mapping or array for
   // individual elements.
   int *open;
   string path;

   mixed tmp;

//   log_file( "path", "map="+as_lpc(map)+", startx="+startx+", starty="+starty+", goalx="+goalx+", goaly="+goaly+", costs="+as_lpc(costs) );

   // Process the map into an easier-to-use format.
   split_map = explode( map, "\n" );
   map_width = 0;

   // Find the length of the longest line in the "map"
   for( i = sizeof(split_map); i-- ; )
      if( map_width < strlen(split_map[i]) ) map_width = strlen(split_map[i]);

   // Make all the lines that length by padding with escape characters.
   // (Note: I use escapes because they are an unlikely character to be
   // chosen for walking over, and unused characters are 'walls'). This uses
   // a rather odd technique involving sprintf, similar to the way tab()
   // works.
   for( i = sizeof(split_map); i-- ; )
      split_map[i] += sprintf( "%" + (map_width-strlen(split_map[i])) + "'\27's", "" );

   // Sanity check
   if( goalx < 0  || goalx >= map_width || goaly < 0 || goaly >= sizeof(split_map) )
      return 0;
   // Setup initial state.
   start = startx + starty * map_width;
   goal = goalx + goaly * map_width;
   open = ({ (abs(startx-goalx) + abs(starty-goaly)) << 2, start });
   closed = ([ start:0 ]);

   while( sizeof(open) && !member(closed, goal) ) {
      currcost = open[0];
      currpos = open[1];
      // Check if done.
      if( currpos == goal ) {
         closed[currpos] = currcost;
         break;
      }

      // Pop the top cell off the heap.
      // Copy the final element over the top one...
      open[0] = open[<2];
      open[1] = open[<1];
      // Clip off the final element...
      open = open[0..<3];
      // Set an index at the top for bubble down
      iparent = 0;
      iheap = 2;
      // Bubble down. iparent is the parent node, iheap
      // is the left of the two child nodes.
      while( iheap < sizeof(open) ) {
         // If left child should be bubbled up
         if( open[iparent] > open[iheap] && (iheap + 2 >= sizeof(open) || open[iheap] < open[iheap + 2]) ) {
            tmp = open[iparent..iparent+1];
            open[iparent..iparent + 1] = open[iheap..iheap + 1];
            open[iheap..iheap + 1] = tmp;
         }
         // else if right child should be bubbled up
         else {
            iheap += 2;
            if( iheap < sizeof(open) && open[iparent] > open[iheap] ) {
               tmp = open[iparent..iparent+1];
               open[iparent..iparent + 1] = open[iheap..iheap + 1];
               open[iheap..iheap + 1] = tmp;
            }
            // Didn't need to bubble either child, quit looping.
            else break;
         }
         // Slide 'em down the heap.
         iparent = iheap;
         iheap = (iparent + 1) << 1;
      }
//      if( !valid_heap(open) ) {
//         log_file("path", "HEAP INVALID AFTER BUBBLE-DOWN\n");
//         return 0;
//      }

      // Add the neighbors of the popped cell to the heap
      // 0 = east, 1 = north, 2 = west, 3 = south
//      log_file("path", "ADDING NEIGHBORS FOR "+(currpos%map_width)+", "+(currpos/map_width)+"\n");
      for( ineighbor = 0; ineighbor < 4; ineighbor++ ) {
         // Calculate x, y coords of the about-to-be-considered cell.
         newx = (currpos % map_width) + ({ 1, 0, -1, 0 })[ineighbor];
         newy = (currpos / map_width) + ({ 0, -1, 0, 1 })[ineighbor];
         // Costs encode the direction into the least significant bits.
         newcost = ({ 0x0, 0x1, 0x2, 0x3 })[ineighbor];
         // Out of bounds, ignore it.
         if( newx < 0 || newx >= map_width || newy < 0 || newy >= sizeof(split_map) )
            continue;
         newpos = newx + newy * map_width;
         // Solid wall, ignore it. Make an exception for the goal (which may be solid).
         if( !member(costs, split_map[newy][newx]) && newpos != goal ) continue;
         // Already checked, ignore it.
         if( member(closed, newpos) ) continue;
         // Ok, it's legit. Add it to the heap:
         // The new cost is the old cost, plus the current tile cost. The Manhattan
         // distance to the goal is also included, by subtracting the old distance
         // (the -=) and adding the new distance (the +=).
         newcost |= (currcost & 0xFFFC) + (costs[split_map[newy][newx]] << 2);
         newcost -= (abs(goalx - currpos % map_width) + abs(goaly - currpos / map_width)) << 2;
         newcost += (abs(goalx - newx) + abs(goaly - newy)) << 2;
//         log_file("path", "Cost for pos "+newx+", "+newy+" is "+(newcost >> 2)+"\n");
//         if( newcost < 0 ) {
//            log_file( "path", "Info on cost: newcost = "+(newcost>>2)+", currcost = "+(currcost>>2)+", currpos = "+(currpos%map_width)+", "+(currpos/map_width)+"\n");
//            log_file( "path", "First: "+((currcost & 0xFFFC) + (costs[split_map[newy][newx]]))+"\n");
//            log_file( "path", "Second: "+((abs(goalx - currpos % map_width) + abs(goaly - currpos / map_width)))+"\n");
//            log_file( "path", "Third: "+((abs(goalx - newx) + abs(goaly - newy)))+"\n");
//         if( newcost < 0 )
//            return 0;
//         }
         // Mark this cell as 'considered'
         closed[newpos] = newcost;
         iheap = sizeof(open);
         // Tack it on the end, and prepare to bubble up.
         open += ({ newcost, newpos });
//         log_file( "path", "NEW BU: iheap="+iheap+", heap="+implode(explode(as_lpc(open),"\n")," ")+"\n");
         if( iheap > 0 )
         // While iheap's parent is greater than the child, bubble up.
         // Note: &-2 drops odd numbers to the next lowest even number.
         while( iheap > 0 && open[iparent = ((iheap >> 1) - 1) & -2] > open[iheap] ) {
            // Set iheap to left child
            iheap = (iparent + 1) << 1;
            // If there is a right child, and if the right child is
            // the smaller of the two, shift iheap to the right child.
            if( iheap + 2 < sizeof(open) && open[iheap + 2] < open[iheap] )
               iheap += 2;
            // iheap now points to the smaller of the two children. Move it
            // up.
            tmp = open[iparent..iparent+1];
            open[iparent..iparent+1] = open[iheap..iheap+1];
            open[iheap..iheap+1] = tmp;
//            log_file( "path", "   Loop: iheap="+iheap+" swapped w/ iparent="+iparent+", heap="+implode(explode(as_lpc(open),"\n")," ")+"\n");
            iheap = iparent;
         }
//         if( !valid_heap(open) ) {
//            log_file("path", "HEAP INVALID AFTER BUBBLE-UP\n");
//            return 0;
//         }
      }
   }
   i = goal;
   if( !member(closed, i) ) return 0;
   path = "";
   while( i != start ) {
      path = ({ "e", "n", "w", "s" })[closed[i]&0x3] + path;
      i += ({ -1, map_width, 1, -map_width })[closed[i]&0x3];
   }
   return path;
}


string test() {
   return
find_path(
"########\n"+
"#  s   #\n"+
"#      #\n"+
"#      #\n"+
"#      #\n"+
"#      #\n"+
"#      #\n"+
"#      #\n"+
"#  g   #\n"+
"########\n",
3, 8, 3, 1, ([ ' ': 1 ]) );
}

varargs int valid_heap( int *heap, int i ) {
   int ileft, iright;
   if( i >= sizeof(heap) ) return 1;
   ileft = (i + 1) * 2;
   iright = (i + 1) * 2 + 2;
   if( ileft < sizeof(heap) && heap[ileft] < heap[i] )
      return 0;
   if( iright < sizeof(heap) && heap[iright] < heap[i] )
      return 0;
   return valid_heap( heap, ileft ) && valid_heap( heap, iright );
}