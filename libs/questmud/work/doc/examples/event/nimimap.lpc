/* This has been diractly taken from the actual
   outworld files. I wanted to create a nice-looking
   map. So, even I use copy&paste sometimes -- Rag */

#define MAP "/room/out/outmap"
#include <ansi.h>

int abs(int i) {
  if(i < 0) return -i;
  else return i;
}

string generate_minimap(int x, int y, string ldesc) {
  string terrain, *line, minimap, empty, d;
  int i, j, map_size, *x_length;

  minimap = "";
  empty = "                                                         ";
  map_size = 5;
 
  x_length = ({ 16,16,16,14,10,4, });
  line = allocate(map_size*2+1);
  if(ldesc) {
    i = 1;
    while(i < 7 && ldesc && i < sizeof(line)) {
      if(sscanf(ldesc, "%s\n%s", line[i], ldesc) == 2) { }
      else if(sscanf(ldesc, "%s\n", line[i]) == 1) {
        ldesc = 0;
      }
      i += 1;
    }
  }
  for(j = y + sizeof(x_length)-1; j > y - sizeof(x_length); j--) {
    terrain = "";
    for(i = x - x_length[abs(y - j)]/2 +1; i < x + x_length[abs(y - j)]/2; i++) {
        terrain += MAP->get_map_char(i,j,x,y,1);
    }
    if(j==y) terrain = " "+terrain;
    if(y != j)
      terrain = empty[0..(x_length[0] - x_length[abs(y - j)])/2] + terrain +
        empty[0..(x_length[0] - x_length[abs(y - j)])/2];
    else
        terrain += " ";
    d = line[ abs(y+map_size-1 - j) ];
    if(!d) d = ""; else d = "    " + d;
    minimap += terrain + d + "\n";
  }
  if(this_player()->query_terminal()) minimap += OFF;
  return minimap;
}
