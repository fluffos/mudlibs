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

varargs int
main (string str)
{
   object ob, *obs;
   int x, y;
   string name, buf = "";
   
   if (!str || str == "")
	 {
		THIS->notify_fail ("Look at what?");
		return 0;
	 }
   
   if (sscanf (str, "%d %d %s", x, y, name) != 3)
	 {
		if (sscanf (str, "%d %d", x, y) == 2)
		  obs = MAPENV(THIS)->get_obj(x, y);
	 }
   else
	 {
		ob = present(MAPENV(THIS), name, x, y);
		if (!ob)
		  {
			 message (CMD_MSG, 0,0,0, "You can't see "+str+" here anymore.");
			 return 1;
		  }
	 }
   
   if (sizeof(obs) > 0)
	 {
		foreach (object entry in obs)
		  buf += entry->query_name(PREV(0)) + ";";
		
		open_window (PREV(0), 0,0,0,0, LTYPE_SELECT, "Look at what?", "vlook "+x+" "+y+"", buf);
	 }
   else
	 {
		open_window (PREV(0), 0,0,0,0, LTYPE_TEXT, capitalize(ob->query_short(PREV(0))) + ":", "noop", replace_string(wrap(capitalize(ob->query_long()), 50), "\n", ";") + ";");
	 }
   return 1;
}
