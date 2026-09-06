string mymap;

string *bottom_row = ({
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|:::|",
 "|:::.",
 "|:::|",
 "|::::",
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|:::|",
 "|:::.",
 "|:::|",
 "|::::",
 "----'",
 "-----",
 "----'",
 "-----",
 ".:::|",
 ".:::.",
 ".:::|",
 ".::::",
 "----'",
 "-----",
 "----'",
 "-----",
 "::::|",
 "::::.",
 "::::|",
 ":::::" });

string *top_row = ({
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|:::|",
 "|:::'",
 "|:::|",
 "|::::",
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|:::|",
 "|:::'",
 "|:::|",
 "|::::",
 "----.",
 "-----",
 "----.",
 "-----",
 "':::|",
 "':::'",
 "':::|",
 "'::::",
 "----.",
 "-----",
 "----.",
 "-----",
 "::::|",
 "::::'",
 "::::|",
 ":::::" });

string *middle_row = ({
 "|:::|",
 "|::::",
 "::::|",
 ":::::" });

int bottom_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y+1][x+1]<<1) + (map[y+1][x]<<2) + (map[y+1][x-1]<<3) + (map[y][x-1]<<4);
}

int top_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y-1][x+1]<<1) + (map[y-1][x]<<2) + (map[y-1][x-1]<<3) + (map[y][x-1]<<4);
}

int middle_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y][x-1]<<1);
}

string new_map() {
   mixed base_map;
   string map_str;
   int ix, iy, map_width, map_height;

   // Note the edge padding.
   base_map =
   ({
     ({ 1, 1, 1, 1, 1, 1, 1 }),
     ({ 1, 1, 0, 0, 0, 0, 1 }),
     ({ 1, 0, 1, 1, 1, 0, 1 }),
     ({ 1, 1, 1, 0, 1, 0, 1 }),
     ({ 1, 0, 1, 1, 1, 0, 1 }),
     ({ 1, 0, 0, 0, 0, 0, 1 }),
     ({ 1, 1, 1, 1, 1, 1, 1 })
   });

   map_width = 5;
   map_height = 5;

   // Upper-left corner
   if( base_map[1][1] ) map_str = ":"; else map_str = ".";
   // Top row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += bottom_row[bottom_index(ix, 0, base_map)];
   // Upper-right corner
   if( base_map[1][map_width] ) map_str += ":\n"; else map_str += ".\n";

   // Loop through map rows
   for( iy = 1; iy <= map_height; iy++ ) {
      // Leftmost column, top row
      if( base_map[iy][1] )
         map_str += base_map[iy-1][1]?":":"'";
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
         map_str += base_map[iy-1][map_width]?":\n":"'\n";
      else
         map_str += "|\n";

      // Leftmost column, middle row
      if( base_map[iy][1] )
         map_str += ":";
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
         map_str += ":\n";
      else
         map_str += "|\n";

      // Leftmost column, bottom row
      if( base_map[iy][1] )
         map_str += base_map[iy+1][1]?":":".";
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
         map_str += base_map[iy+1][map_width]?":\n":".\n";
      else
         map_str += "|\n";
   }

   // Bottom-left corner
   if( base_map[map_height][1] ) map_str += ":"; else map_str += "'";
   // Bottom row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += top_row[top_index(ix, map_height+1, base_map)];
   // Bottom-right corner
   if( base_map[map_height][map_width] ) map_str += ":\n"; else map_str += "'\n";


   return map_str;
}

void map_make() {
   string newmap;
   int line, i, ix, iy, mapx, mapy;

   // Can figure out how to calc these later
   mapx = 25 + 3;
   mapy = 15 + 2;

   newmap = tab( tab(":", mapx-1) + "\n", mapy );
   ix = 0; iy = 0;
   for( i = 0; i < strlen(mymap); i++ ) {
      if( mymap[i] == '.' ) {
         for( line = (iy*3+1)*mapx; line < (iy*3+4)*mapx; line += mapx)
            newmap[ix*5+1+line..ix*5+5+line] = "     ";
      }
      if( mymap[i] == '\n' ) {
         ix = 0;
         iy++;
      }
      else
         ix++;
   }
   for( iy = 1; iy < mapy - 1; iy++ )
   for( ix = 1; ix < mapx - 2; ix++ ) {
      i = iy*mapx + ix;
      if( newmap[i] == ' ' ) {
         if( newmap[i-1] != ' ' ) newmap[i-1] = '|';
         if( newmap[i+1] != ' ' ) newmap[i+1] = '|';
         if( newmap[i-mapx] != ' ' ) newmap[i-mapx] = '-';
         if( newmap[i+mapx] != ' ' ) newmap[i+mapx] = '-';
      }
   }

   for( iy = 0; iy < mapy; iy++ )
   for( ix = 0; ix < mapx - 1; ix++ ) {
      if( ix < mapx && iy < mapy-1 && newmap[iy*mapx+ix+1] == '-' &&
          newmap[(iy+1)*mapx+ix] == '|' )
         newmap[ix+iy*mapx] = '.';
      if( ix > 0 && iy < mapy-1 && newmap[iy*mapx+ix-1] == '-' &&
          newmap[(iy+1)*mapx+ix] == '|' )
         newmap[ix+iy*mapx] = '.';
      if( ix < mapx && iy > 0 && newmap[iy*mapx+ix+1] == '-' &&
          newmap[(iy-1)*mapx+ix] == '|' )
         newmap[ix+iy*mapx] = '\'';
      if( ix > 0 && iy > 0 && newmap[iy*mapx+ix-1] == '-' &&
          newmap[(iy-1)*mapx+ix] == '|' )
         newmap[ix+iy*mapx] = '\'';
   }
   msg( "Newmap is:\n" + newmap );
}

void create() {
   mymap =
". . .\n"+
" . .\n"+
". . .\n"+
" . .\n"+
". . .";
}