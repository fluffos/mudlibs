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
   object o, *a;
   string buf = "";
   
   a = all_inventory(PREV(0));
   if (!a || sizeof(a) == 0)
	 {
		message (CMD_MSG, 0,0,0, "You aren't carrying anything.", PREV(0));
		return 1;
	 }
   
   if (!str || str == "")
	 {
		foreach (o in a)
		  buf += o->query_short(PREV(0)) + ";";
		buf += "all;";
		
		if (sizeof(a) == 1)
		  {
			 main (a[0]->query_short(PREV(0)));
			 return 1;
		  }
		
		open_window (PREV(0), 0, 0, 0, 0, LTYPE_SELECT, "Drop which item?", "drop", buf);
		return 1;
	 }
   
   if(str == "all")
	 {
		foreach(object entry in a)
		  {
			 if(entry->is_wielded())
			   PREV(0)->remove_weapon(entry);
			 else if(entry->is_worn())
			   PREV(0)->strip(entry);
			 entry->move(MAPENV(PREV(0)), PREV(0)->query_gridx(), PREV(0)->query_gridy());
			 PREV(0)->update_inv();
		  }
		message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {drop} all of $s1 belongings.", MAPENV(PREV(0)), PREV(0));
		return 1;
	 }
   o = present(PREV(0), str, -1, -1);
   if(!o)
	 {
		message (CMD_MSG, 0,0,0, "You don't have "+str+"!", PREV(0));
		return 1;
	 }
   
   if (!str || str == "")
	 o = a[0];
   
   if(o->is_wielded())
	 PREV(0)->remove_weapon(o);
   if(o->is_worn())
	 PREV(0)->strip(o);
   
   o->move (MAPENV(PREV(0)), PREV(0)->query_gridx(), PREV(0)->query_gridy());
   PREV(0)->update_inv();
   message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {drop} $p2.", MAPENV(PREV(0)), ({ PREV(0), o }) );
   return 1;
}
