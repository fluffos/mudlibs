/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <list.h>

int
main(string str)
{
   int middle;
   int radius;
   int start;
   int i, j;
   int x, y;
   int l, r;
   string *slices;
   string buf = "";
  
   if(!str || str == "")
	 radius = 10;
   else
	 {
		radius = to_int(str);
		if(radius < 1)
		  radius = 2;
		else if(radius > 20)
		  radius = 20;
	 }
   
   if(radius % 2) 
	 radius++;
      
   x = PREV(0)->query_gridx() / 100;
   y = PREV(0)->query_gridy() / 100;
   
   l = x - radius;
   r = x + radius;
   if(l < 0)
	 l = 0;
   
   start = y - radius / 2;
   if(start < 0)
	 start = 0;
   
   slices = explode(read_file("/world/WORLDMAP", start, radius), "\n");
   for(i=0,j=sizeof(slices);i<j;i++)
	 buf += slices[i][l..r]+";";
   middle = strlen(buf) / 2 + radius;
   buf[middle-1..middle+1] = "^cW@^c0";
   open_window(PREV(0), 0,0,0,0, LTYPE_TEXT, "Worldmap view:", "noop", buf);
   return 1;
}
