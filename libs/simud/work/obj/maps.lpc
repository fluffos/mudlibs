string mymap;

/** An object for generating ASCII maps.
 */

string *bottom_row = ({
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|   |",
 "|   .",
 "|   |",
 "|    ",
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|   |",
 "|   .",
 "|   |",
 "|    ",
 "----'",
 "-----",
 "----'",
 "-----",
 ".   |",
 ".   .",
 ".   |",
 ".    ",
 "----'",
 "-----",
 "----'",
 "-----",
 "    |",
 "    .",
 "    |",
 "     " });

string *top_row = ({
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|   |",
 "|   '",
 "|   |",
 "|    ",
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|   |",
 "|   '",
 "|   |",
 "|    ",
 "----.",
 "-----",
 "----.",
 "-----",
 "'   |",
 "'   '",
 "'   |",
 "'    ",
 "----.",
 "-----",
 "----.",
 "-----",
 "    |",
 "    '",
 "    |",
 "     " });

string *middle_row = ({
 "|   |",
 "|    ",
 "    |",
 "     " });

int bottom_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y+1][x+1]<<1) + (map[y+1][x]<<2) + (map[y+1][x-1]<<3) + (map[y][x-1]<<4);
}

int top_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y-1][x+1]<<1) + (map[y-1][x]<<2) + (map[y-1][x-1]<<3) + (map[y][x-1]<<4);
}

int middle_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y][x-1]<<1);
}

string make_map( string map_src, int map_width, int map_height ) {
   mixed base_map;
   string map_str;
   int ix, iy;

   base_map = allocate( map_height + 2 );
   for( iy = sizeof(base_map); iy--; )
      base_map[iy] = allocate( map_width + 2 );

   // Create the grid from the map_src
   for( iy = map_height + 2; iy--; )
   for( ix = map_width + 2; ix--; )
   if( iy == 0 || iy > map_height || ix == 0 || ix > map_width || map_src[(ix-1) + (iy-1) * map_width] != ' ' ) {
      base_map[iy][ix] = 1;
   }
//   else
//      msg("Clear base_map for ix="+ix+", iy="+iy);

   // Upper-left corner
   if( base_map[1][1] ) map_str = " "; else map_str = ".";
   // Top row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += bottom_row[bottom_index(ix, 0, base_map)];
   // Upper-right corner
   if( base_map[1][map_width] ) map_str += " \n"; else map_str += ".\n";

   // Loop through map rows
   for( iy = 1; iy <= map_height; iy++ ) {
      // Leftmost column, top row
      if( base_map[iy][1] )
         map_str += base_map[iy-1][1]?" ":"'";
      else
         map_str += "|";
      // Top cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += top_row[top_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, top row
      if( base_map[iy][map_width] )
         map_str += base_map[iy-1][map_width]?" \n":"'\n";
      else
         map_str += "|\n";

      // Leftmost column, middle row
      if( base_map[iy][1] )
         map_str += " ";
      else
         map_str += "|";
      // Middle cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += middle_row[middle_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, middle row
      if( base_map[iy][map_width] )
         map_str += " \n";
      else
         map_str += "|\n";

      // Leftmost column, bottom row
      if( base_map[iy][1] )
         map_str += base_map[iy+1][1]?" ":".";
      else
         map_str += "|";
      // Bottom cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += bottom_row[bottom_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, top row
      if( base_map[iy][map_width] )
         map_str += base_map[iy+1][map_width]?" \n":".\n";
      else
         map_str += "|\n";
   }

   // Bottom-left corner
   if( base_map[map_height][1] ) map_str += " "; else map_str += "'";
   // Bottom row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += top_row[top_index(ix, map_height+1, base_map)];
   // Bottom-right corner
   if( base_map[map_height][map_width] ) map_str += " \n"; else map_str += "'\n";


   return map_str[..<2]; // Drop trailing \n
}
