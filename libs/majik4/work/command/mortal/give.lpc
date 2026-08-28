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
main (string str)
{
   int x = PREV(0)->query_gridx(), y = PREV(0)->query_gridy();
   object *a, o, *a2, o2;
   string buf = "", to, what;
   
   if (!str || str == "")
	 {
		for (int i=y-1;i<y+2;i++)
		  {
			 for (int j=x-1;j<x+2;j++)
			   {
				  a = MAPENV(PREV(0))->get_obj(j, i);
				  
				  foreach (o in a)
					{
					   if (o->query_physical() && o->is_living() && o != PREV(0))
						 {
							a2 = all_inventory(PREV(0));
							
							foreach (o2 in a2)
							  buf += o2->query_short (PREV(0)) + ";";
							
							open_window (PREV(0), 0,0,0,0, LTYPE_SELECT, "Give which item to "+o->query_cap_name()+"?", "give "+o->query_cap_name()+"", buf);
							return 1;
						 }
					}			 
			   }
		  }
		message (CMD_MSG, 0,0,0, "There is no-one you could give something to.", PREV(0));
		return 1;
	 }
   else
	 {
		if (sscanf (str, "%s %s", to, what) == 2)
		  {
			 o = present (MAPENV(PREV(0)), lower_case(to), x, y, 1);
			 
			 if (!o)
			   {
				  message (CMD_MSG, 0,0,0, "There is no "+to+" nearby.", PREV(0));
				  return 1;
			   }
			 else
			   {
				  o2 = present (PREV(0), lower_case (what), -1, -1);
				  
				  if (!o2)
					{
					   message (CMD_MSG, 0,0,0, "You don't have "+what+".", PREV(0));
					   return 1;
					}
				  else
					{
					   if (interactive(o2))
						 {
							message (CMD_MSG, 0,0,0, "You can't give that!", PREV(0));
							return 1;
						 }
					   
					   if(o2->is_wielded())
						 PREV(0)->remove_weapon(o2);
						 					   
					   if(o2->is_worn())
						 PREV(0)->strip(o2);
											   
					   o2->move (o, -1, -1);
					   PREV(0)->update_inv();
					   o->update_inv();
					   
					   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$n1 {give} $p2 to $n3.", MAPENV(PREV(0)), ({ PREV(0), o2, o }));
					   return 1;
					}
			   }
		  }
		else
		  {
			 message (CMD_MSG, 0,0,0, "Usage: give <recipient> <item>\n", PREV(0));
			 return 1;
		  }
	 }
   return 1;
}
