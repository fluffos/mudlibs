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

int
main (string str)
{
   object o;
   string type, material, item;
   int x, y, *dx;
   
   if (!str || str == "")
	 {		
		message (CMD_MSG, 0,0,0, "Usage: generate <type>,<material>,<item>", PREV(0));
		return 1;
	 }
  
   if (sscanf (str, "%s,%s,%s", type, material, item) == 3)
	 {
		o = GENERIC_D->generate (type, material, item);
		
		if (o)
		  {
			 if (o->query_physical())
			   {
				  dx = MAPENV(PREV(0))->get_near_location(PREV(0)->query_gridx(), PREV(0)->query_gridy(), 3);
				  if (dx[0] == 0 && dx[1] == 0)
					   {
						  message(CMD_MSG, 0,0,0, "There's no room!", PREV(0));
						  destruct(o);
						  return 1;
					   }
				  x = dx[0];
				  y = dx[1];
			   }
			 else
			   {
				  x = PREV(0)->query_gridx();
				  y = PREV(0)->query_gridy();
			   }

			 o->move (MAPENV(PREV(0)), x, y);
			 message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {invoke} $p2.", MAPENV(PREV(0)), ({ PREV(0), o }));
		  }
	 }
   else
	 message (CMD_MSG, 0,0,0, "Usage: generate <type>,<material>,<item>", PREV(0));
   
   return 1;
}
