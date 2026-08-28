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
   object o, *u;
   string buf = "";
   
   u = all_inventory(PREV(0));
   
   if (str && strlen(str) > 0)
	 {
		foreach (o in u)
		  {
			 if (lower_case(o->query_short(PREV(0))) == lower_case(str))
			   break;
		  }
   
		if (!o)
		  message (CMD_MSG, 0,0,0, "No such item.", PREV(0));
		else if (o->query_default())
		  PREV(0)->force_us(o->query_default() + " " + o->query_name() + "");
		else
		  message (CMD_MSG, 0,0,0, "This item has nothing special you could apply.", PREV(0));
		
		return 1;
	 }
   
   if (!u || sizeof(u) == 0)
	 {
		message (CMD_MSG, 0,0,0, "You aren't carrying anything.", PREV(0));
		return 1;
	 }
   
   foreach (o in u)
	 if (o->query_default())
	   buf += o->query_short(PREV(0)) + ";";
   
   if (buf == "")
	 message (CMD_MSG, 0,0,0, "You don't seem to have anything you could apply.", PREV(0));
   else
	 open_window (PREV(0), 0, 0, 0, 0, LTYPE_SELECT, "Which item do you want to apply?", "apply", buf);
   
   return 1;
}
