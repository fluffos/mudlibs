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
   int x, y, uid;
   string name;
   object o, *a;
   
   if (!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Please select an object to name.", PREV(0));
		select_target (PREV(0), "name");
		return 1;
	 }
   else if (!x && !y && sscanf (str, "%d %s", uid, name) == 2 && sscanf (str, "%d %d", x, y) != 2)
	 {
		message (CMD_MSG, 0,0,0, "Done.", PREV(0));
		PREV(0)->add_known (uid, name);
		return 1;
	 }
   else if (sscanf (str, "%d %d", x, y) == 2)
	 {
		a = MAPENV(PREV(0))->get_obj (x, y);
		
		foreach (o in a)
		  {
			 if (o->is_living())
			   {
				  prompt_client (PREV(0), 0, "name "+o->query_uid()+"", "By what name do you wish to call "+o->query_name(PREV(0))+"? ");
				  break;
			   }
		  }
		return 1;
	 }
}
